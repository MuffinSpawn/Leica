# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging

import CESAPI.connection
import CESAPI.command
import CESAPI.packet
import CESAPI.refract

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def initialize(command, forceinit=False, manualiof=False):
    units = CESAPI.packet.SystemUnitsDataT()
    units.lenUnitType = CESAPI.packet.ES_LU_Millimeter  # ES_LengthUnit
    # units.angUnitType = ES_AU_Radian  # ES_AngleUnit
    # units.tempUnitType = ES_TU_Celsius  # ES_TemperatureUnit
    # units.pressUnitType = ES_PU_Mbar  # ES_PressureUnit
    # units.humUnitType = ES_HU_RH  # ES_HumidityUnit
    logger.debug('Setting units...')
    command.SetUnits(units)
    
    status = command.GetSystemStatus()
    logger.debug('Tracker Processor Status: {}'.format(status.trackerProcessorStatus))
    if forceinit or status.trackerProcessorStatus != CESAPI.packet.ES_TPS_Initialized:  # ES_TrackerProcessorStatus
        logger.debug('Initializing...')
        command.Initialize()
    
    logger.debug('setting measurement mode...')
    command.SetMeasurementMode(CESAPI.packet.ES_MM_Stationary)  # ES_MeasMode (only choice for AT4xx)

    logger.debug('setting stationary mode parameters...')
    mode_params = CESAPI.packet.StationaryModeDataT()
    mode_params.lMeasTime = 1000  # 1 second
    command.SetStationaryModeParams(mode_params)

    logger.debug('setting coordinate system type to Right-Handed Rectangular...')
    command.SetCoordinateSystemType(CESAPI.packet.ES_CS_SCC)  # one of ES_CoordinateSystemType

    logger.debug('setting system settings...')
    settings = CESAPI.packet.SystemSettingsDataT()
    # one of ES_WeatherMonitorStatus
    if manualiof:
        settings.weatherMonitorStatus = CESAPI.packet.ES_WMS_ReadOnly
    else:
        settings.weatherMonitorStatus = CESAPI.packet.ES_WMS_ReadAndCalculateRefractions
    settings.bApplyStationOrientationParams = int(1)
    settings.bKeepLastPosition = int(1)
    settings.bSendUnsolicitedMessages = int(1)
    settings.bSendReflectorPositionData = int(0)
    settings.bTryMeasurementMode = int(0)
    settings.bHasNivel = int(1)
    settings.bHasVideoCamera = int(1)
    command.SetSystemSettings(settings)

def measure(command, rialg=None):
        CESAPI.refract.SetRefractionIndex(command, rialg)
        return command.StartMeasurement()

def main():
    connection = CESAPI.connection.Connection()
    try:
        connection.connect()
        command = CESAPI.command.CommandSync(connection)
        
        initialize(command, manualiof=False)
        
        # ri_algorithm = CESAPI.refract.AlgorithmFactory(CESAPI.refract.RI_ALG_CiddorAndHill)
        ri_algorithm = CESAPI.refract.AlgorithmFactory(CESAPI.refract.RI_ALG_Leica)
        
        logger.info('Measuring reflector..')
        measurement = measure(command, rialg=ri_algorithm)
        print('theta:       {} rad'.format(measurement.dVal1))
        print('phi:         {} rad'.format(measurement.dVal2))
        print('r:           {} mm'.format(measurement.dVal3))
        print('SD[theta]:   {} rad'.format(measurement.dStd1))
        print('SD[phi]:     {} rad'.format(measurement.dStd2))
        print('SD[r]:       {} mm'.format(measurement.dStd3))
        print('Temperature: {} C'.format(measurement.dTemperature))
        print('Pressure:    {} mbar'.format(measurement.dPressure))
        print('Humidity:    {} %RH'.format(measurement.dHumidity))
    finally:
        connection.disconnect()

if __name__ == '__main__':
    main()
