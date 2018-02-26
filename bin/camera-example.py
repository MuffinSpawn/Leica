# -*- coding: utf-8 -*-
"""
Created on Sun Feb 25 22:11:22 2018

@author: peter
"""

import io
import logging
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import numpy
from PIL import Image
from PIL import ImageFile
import signal
import sys
import time

import CESAPI.connection
import CESAPI.command
from CESAPI.packet import *
import CESAPI.video

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

def initialize(command, forceinit=False, manualiof=False):
    units = SystemUnitsDataT()
    units.lenUnitType = ES_LU_Millimeter  # ES_LengthUnit
    # units.angUnitType = ES_AU_Radian  # ES_AngleUnit
    # units.tempUnitType = ES_TU_Celsius  # ES_TemperatureUnit
    # units.pressUnitType = ES_PU_Mbar  # ES_PressureUnit
    # units.humUnitType = ES_HU_RH  # ES_HumidityUnit
    logger.debug('Setting units...')
    command.SetUnits(units)
    
    status = command.GetSystemStatus()
    logger.debug('Tracker Processor Status: {}'.format(status.trackerProcessorStatus))
    if forceinit or status.trackerProcessorStatus != ES_TPS_Initialized:  # ES_TrackerProcessorStatus
        logger.debug('Initializing...')
        command.Initialize()
        # At least the AT401 seems to complain about an unknown command failing due to "the sensor" not being stable
        # on the next command after an initialize. The tracker is fine after that, so just ignore this as a bug in the firmware.
        try:
            status = command.GetSystemStatus()
            logger.debug('Tracker Processor Status: {}'.format(status.trackerProcessorStatus))
        except Exception as e:
            if not 'Command 64' in str(e):
                raise e
    
    logger.debug('setting measurement mode...')
    command.SetMeasurementMode(ES_MM_Stationary)  # ES_MeasMode (only choice for AT4xx)

    logger.debug('setting stationary mode parameters...')
    mode_params = StationaryModeDataT()
    mode_params.lMeasTime = 1000  # 1 second
    command.SetStationaryModeParams(mode_params)

    logger.debug('setting coordinate system type to Right-Handed Rectangular...')
    command.SetCoordinateSystemType(ES_CS_RHR)  # one of ES_CoordinateSystemType

    logger.debug('setting system settings...')
    settings = SystemSettingsDataT()
    # one of ES_WeatherMonitorStatus
    if manualiof:
        settings.weatherMonitorStatus = ES_WMS_ReadOnly
    else:
        settings.weatherMonitorStatus = ES_WMS_ReadAndCalculateRefractions
    settings.bApplyStationOrientationParams = int(1)
    settings.bKeepLastPosition = int(1)
    settings.bSendUnsolicitedMessages = int(1)
    settings.bSendReflectorPositionData = int(0)
    settings.bTryMeasurementMode = int(0)
    settings.bHasNivel = int(1)
    settings.bHasVideoCamera = int(1)
    command.SetSystemSettings(settings)

if __name__ == '__main__':
    running = True
    
    def signal_handler(signal, frame):
            print('You pressed Ctrl+C!')
            sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)
    
    '''
    with open('C:/Users/peter/Pictures/pier.jpg', 'br') as f:
        image_data = f.read()
    '''
    
    '''
    stream = io.BytesIO(image_data)
    img = Image.open(stream)
    
    plt.imshow(numpy.asarray(img))
    '''


    control_connection = CESAPI.connection.Connection()
    control_connection.connect()
    command = CESAPI.command.CommandSync(control_connection)
    try:
        command.ActivateCameraView()
    finally:
        control_connection.disconnect()


    video_connection = CESAPI.video.Connection()
    video_stream = video_connection.connect()
    try:
        video_stream.set_frame_rate(16)
    
        fig = plt.figure()
    
        def get_next_image():
            image = video_stream.next()
            image_matrix = None
            if image != None:
                logger.debug('Updating image...')
                image_matrix = numpy.array(image.getdata(), dtype=numpy.uint8).reshape((image.size[1],image.size[0],3))
            else:
                logger.debug('No image!')
                image_matrix = numpy.ones((240,320,3))
            return image_matrix
    
        im = plt.imshow(get_next_image(), animated=True)
        
        def update_image(*args):
            logger.debug("!!!")
            im.set_array(get_next_image())
            return im,
    
        ImageFile.LOAD_TRUNCATED_IMAGES = True
        video = anim.FuncAnimation(fig, update_image, interval=16, blit=True)
        plt.show()
    finally:
        video_connection.disconnect()
        control_connection.disconnect()
        