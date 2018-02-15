# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import time

from CESAPI.connection import *
from CESAPI.command import *
from CESAPI.packet import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def initialize(command, manualiof=False):
    logger.info('Setting system units..')
    units = SystemUnitsDataT()
    units.lenUnitType = ES_LU_Millimeter  # ES_LengthUnit
    # units.angUnitType = ES_AU_Radian  # ES_AngleUnit
    # units.tempUnitType = ES_TU_Celsius  # ES_TemperatureUnit
    # units.pressUnitType = ES_PU_Mbar  # ES_PressureUnit
    # units.humUnitType = ES_HU_RH  # ES_HumidityUnit
    command.SetUnits(units)
    
    logger.info('Initializing laser tracker...')
    command.Initialize()
    
    logger.info('Setting other system settings..')
    command.SetMeasurementMode(ES_MM_Stationary)  # ES_MeasMode (only choice for AT4xx)
    command.SetCoordinateSystemType(ES_CS_SCC)  # one of ES_CoordinateSystemType
    settings = SystemSettingsDataT()
    # one of ES_WeatherMonitorStatus
    if manualiof:
        settings.weatherMonitorStatus = ES_WMS_ReadOnly
    else:
        settings.weatherMonitorStatus = ES_WMS_ReadAndCalculateRefractions
    settings.bSendUnsolicitedMessages = 1
    settings.bSendReflectorPositionData = 1
    settings.bHasNivel = 1
    settings.bHasVideoCamera = 1
    command.SetSystemSettings(settings)

# TODO: implement Ciddor & Hill with IOF update trick
def ciddor_and_hill(env_params):
    return 0.0

def set_refraction_index(command):
    min_refraction_index = 1.000150
    max_refraction_index = 1.000331
    mid_refraction_index = (min_refraction_index + max_refraction_index)/2.0
    refraction_params = command.GetRefractionParams()
    if refraction_params.dIfmRefractionIndex <= mid_refraction_index:
        refraction_params.dIfmRefractionIndex = max_refraction_index
    else:
        refraction_params.dIfmRefractionIndex = min_refraction_index
    command.SetRefractionParams(refraction_params)

    env_params = command.GetEnvironmentParams()
    index_of_refraction = ciddor_and_hill(env_params)
    command.SetRefractionParams(refraction_params)

def measure(command, setiof=False):
        if setiof:
            set_refraction_index(command)

        return command.StartMeasurement()

def main():
    connection = LTConnection()
    try:
        connection.connect()
        command = CommandSync(connection)
        
        initialize(command, manualiof=False)
        
        logger.info('Measuring reflector..')
        measurement = measure(command, setiof=False)

if __name__ == '__main__':
    main()
