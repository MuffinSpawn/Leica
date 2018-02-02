import struct

# enum ES_LengthUnit:
ES_LU_Meter = 0
ES_LU_Millimeter = 1
ES_LU_Micron = 2
ES_LU_Foot = 3
ES_LU_Yard = 4
ES_LU_Inch = 5

# enum ES_AngleUnit:
ES_AU_Radian = 0
ES_AU_Degree = 1
ES_AU_Gon = 2

# enum ES_TemperatureUnit:
ES_TU_Celsius = 0
ES_TU_Fahrenheit = 1

# enum ES_PressureUnit:
ES_PU_Mbar = 0
ES_PU_HPascal = 1
ES_PU_KPascal = 2
ES_PU_MmHg = 3
ES_PU_Psi = 4
ES_PU_InH2O = 5
ES_PU_InHg = 6

# enum ES_HumidityUnit:
ES_HU_RH = 0

# enum ES_CoordinateSystemType:
ES_CS_RHR = 0
ES_CS_LHRX = 1
ES_CS_LHRY = 2
ES_CS_LHRZ = 3
ES_CS_CCW = 4
ES_CS_CCC = 5
ES_CS_SCW = 6
ES_CS_SCC = 7

# enum ES_DataType:
ES_DT_Command = 0
ES_DT_Error = 1
ES_DT_SingleMeasResult = 2
ES_DT_NivelResult = 6
ES_DT_ReflectorPosResult = 7
ES_DT_SystemStatusChange = 8
ES_DT_SingleMeasResult2 = 9

# enum ES_Command:
ES_C_ExitApplication = 0
ES_C_GetSystemStatus = 1
ES_C_GetTrackerStatus = 2
ES_C_SetUnits = 5
ES_C_GetUnits = 6
ES_C_Initialize = 7
ES_C_ActivateCameraView = 9
ES_C_Park = 10
ES_C_SetStationOrientationParams = 12
ES_C_GetStationOrientationParams = 13
ES_C_SetTransformationParams = 14
ES_C_GetTransformationParams = 15
ES_C_SetEnvironmentParams = 20
ES_C_GetEnvironmentParams = 21
ES_C_SetRefractionParams = 22
ES_C_GetRefractionParams = 23
ES_C_SetMeasurementMode = 24
ES_C_GetMeasurementMode = 25
ES_C_SetCoordinateSystemType = 26
ES_C_GetCoordinateSystemType = 27
ES_C_SetStationaryModeParams = 28
ES_C_GetStationaryModeParams = 29
ES_C_SetReflector = 40
ES_C_GetReflector = 41
ES_C_GetReflectors = 42
ES_C_SetSearchParams = 43
ES_C_GetSearchParams = 44
ES_C_SetSystemSettings = 47
ES_C_GetSystemSettings = 48
ES_C_StartMeasurement = 49
ES_C_StartNivelMeasurement = 51
ES_C_StopMeasurement = 52
ES_C_ChangeFace = 53
ES_C_GoBirdBath = 54
ES_C_GoPosition = 55
ES_C_GoPositionHVD = 56
ES_C_PositionRelativeHV = 57
ES_C_PointLaser = 58
ES_C_PointLaserHVD = 59
ES_C_MoveHV = 60
ES_C_GoNivelPosition = 61
ES_C_GoLastMeasuredPoint = 62
ES_C_FindReflector = 63
ES_C_Unknown = 64
ES_C_GetDirection = 66
ES_C_CallOrientToGravity = 67
ES_C_SetCompensation = 79
ES_C_SetStatisticMode = 80
ES_C_GetStatisticMode = 81
ES_C_SetCameraParams = 83
ES_C_GetCameraParams = 84
ES_C_GetCompensation = 85
ES_C_GetCompensations = 86
ES_C_GetTPInfo = 90
ES_C_GetNivelInfo = 91
ES_C_SetLaserOnTimer = 92
ES_C_GetLaserOnTimer = 93
ES_C_GoBirdBath2 = 95
ES_C_GetFace = 98
ES_C_SetLongSystemParameter = 120
ES_C_GetLongSystemParameter = 121
ES_C_GetMeasurementStatusInfo = 122
ES_C_GetCompensations2 = 123
ES_C_SetDoubleSystemParameter = 125
ES_C_GetDoubleSystemParameter = 126
ES_C_GetObjectTemperature = 127
ES_C_GetOverviewCameraInfo = 129
ES_C_ClearCommandQueue = 130
ES_C_GetADMInfo2 = 131
ES_C_GetTrackerInfo = 132
ES_C_GetNivelInfo2 = 133
ES_C_RestoreStartupConditions = 134
ES_C_GoAndMeasure = 135
ES_C_GetATRInfo = 138
ES_C_GetMeteoStationInfo = 139
ES_C_GetAT4xxInfo = 140
ES_C_GetSystemSoftwareVersion = 142

# enum ES_MeasMode:
ES_MM_Stationary = 0

# enum ES_TargetType:
ES_TT_Unknown = 0
ES_TT_CornerCube = 1
ES_TT_CatsEye = 2
ES_TT_GlassPrism = 3
ES_TT_RFIPrism = 4
ES_TT_RRR15 = 5
ES_TT_RRR05 = 6
ES_TT_BRR15 = 7
ES_TT_BRR05 = 8
ES_TT_TBR05 = 9

# enum ES_TrackerStatus:
ES_TS_NotReady = 0
ES_TS_Busy = 1
ES_TS_Ready = 2

# enum ES_ResultStatus:
ES_RS_AllOK = 0
ES_RS_ServerBusy = 1
ES_RS_NotImplemented = 2
ES_RS_WrongParameter = 3
ES_RS_WrongParameter1 = 4
ES_RS_WrongParameter2 = 5
ES_RS_WrongParameter3 = 6
ES_RS_WrongParameter4 = 7
ES_RS_WrongParameter5 = 8
ES_RS_WrongParameter6 = 9
ES_RS_WrongParameter7 = 10
ES_RS_Parameter1OutOfRangeOK = 11
ES_RS_Parameter1OutOfRangeNOK = 12
ES_RS_Parameter2OutOfRangeOK = 13
ES_RS_Parameter2OutOfRangeNOK = 14
ES_RS_Parameter3OutOfRangeOK = 15
ES_RS_Parameter3OutOfRangeNOK = 16
ES_RS_Parameter4OutOfRangeOK = 17
ES_RS_Parameter4OutOfRangeNOK = 18
ES_RS_Parameter5OutOfRangeOK = 19
ES_RS_Parameter5OutOfRangeNOK = 20
ES_RS_Parameter6OutOfRangeOK = 21
ES_RS_Parameter6OutOfRangeNOK = 22
ES_RS_WrongCurrentReflector = 23
ES_RS_NoTPFound = 26
ES_RS_NoWeathermonitorFound = 27
ES_RS_NoLastMeasuredPoint = 28
ES_RS_NoVideoCamera = 29
ES_RS_NoAdm = 30
ES_RS_NoNivel = 31
ES_RS_WrongTPFirmware = 32
ES_RS_UsageConflict = 35
ES_RS_Unknown = 36
ES_RS_NoDistanceSet = 37
ES_RS_NoTrackerConnected = 38
ES_RS_TrackerNotInitialized = 39
ES_RS_ModuleNotStarted = 40
ES_RS_ModuleTimedOut = 41
ES_RS_NotInCameraPosition = 44
ES_RS_WrongParameter8 = 47
ES_RS_WrongParameter9 = 48
ES_RS_WrongParameter10 = 49
ES_RS_WrongParameter11 = 50
ES_RS_WrongParameter12 = 51
ES_RS_WrongParameter13 = 52
ES_RS_WrongParameter14 = 53
ES_RS_WrongParameter15 = 54
ES_RS_WrongParameter16 = 55
ES_RS_NoSuchCompensation = 56
ES_RS_MeteoDataOutOfRange = 57
ES_RS_NoDataToImport = 90
ES_RS_NoTemperatureFromWM = 94
ES_RS_NoPressureFromWM = 95
ES_RS_NoHumidityFromWM = 96
ES_RS_InvalidInputData = 98
ES_RS_NoValidADMCompensation = 10002
ES_RS_PressureSensorProblem = 10003
ES_RS_MeasurementStatusNotReady = 10004
ES_RS_ADMStartUpBusy = 10005
ES_RS_NoAtr = 10007
ES_RS_NoOVC = 10008
ES_RS_NoStationaryResult = 10009
ES_RS_SensorNotLeveled = 10010
ES_RS_MultiConnectionsNotAllowed = 10011
ES_RS_SensorNotStable = 10013
ES_RS_SystemNotReadyForMeasurement = 10014
ES_RS_CommunicationWithSensorFailed = 10015
ES_RS_No_Sensor_Battery = 10016
ES_RS_CompensatorNotAllowed = 10017
ES_RS_WarmedUpStateReached = 10018
ES_RS_NotLeveledForInitialization = 10019
ES_RS_ADMHardwareProblem = 10020
ES_RS_ATRHardwareProblem = 10021

# enum ES_TrackerProcessorStatus:
ES_TPS_NoTPFound = 0
ES_TPS_TPFound = 1
ES_TPS_Booted = 3
ES_TPS_CompensationSet = 4
ES_TPS_Initialized = 5

# enum ES_LaserProcessorStatus:
ES_LPS_LaserReady = 3

# enum ES_ADMStatus:
ES_AS_ADMReady = 2

# enum ES_NivelStatus:
ES_NS_AllOK = 0
ES_NS_OutOfRangeOK = 1
ES_NS_OutOfRangeNOK = 2
ES_NS_NoNivel = 3

# enum ES_WeatherMonitorStatus:
ES_WMS_NotConnected = 0
ES_WMS_ReadOnly = 1
ES_WMS_ReadAndCalculateRefractions = 2

# enum ES_SystemStatusChange:
ES_SSC_EnvironmentParamsChanged = 2
ES_SSC_RefractionParamsChanged = 3
ES_SSC_SearchParamsChanged = 4
ES_SSC_AdmParamsChanged = 5
ES_SSC_UnitsChanged = 6
ES_SSC_ReflectorChanged = 7
ES_SSC_SystemSettingsChanged = 8
ES_SSC_TemperatureRangeChanged = 9
ES_SSC_CameraParamsChanged = 10
ES_SSC_CompensationChanged = 11
ES_SSC_CoordinateSystemTypeChanged = 12
ES_SSC_StationOrientationParamsChanged = 15
ES_SSC_TransformationParamsChanged = 16
ES_SSC_MeasurementModeChanged = 17
ES_SSC_StationaryModeParamsChanged = 18
ES_SSC_StatisticModeChanged = 24
ES_SSC_MeasStatus_NotReady = 25
ES_SSC_MeasStatus_Busy = 26
ES_SSC_MeasStatus_Ready = 27
ES_SSC_IsFace1 = 30
ES_SSC_IsFace2 = 31
ES_SSC_ObjectTemperatureChanged = 105
ES_SSC_ProbeButton1Down = 110
ES_SSC_ProbeButton1Up = 111
ES_SSC_ProbeButton2Down = 120
ES_SSC_ProbeButton2Up = 121
ES_SSC_ProbeButton3Down = 130
ES_SSC_ProbeButton3Up = 131
ES_SSC_ProbeButton4Down = 140
ES_SSC_ProbeButton4Up = 141
ES_SCC_InitializationStatusChanged = 151
ES_SCC_TiltSensorStatusChanged = 152
ES_SSC_EmsysFilesImported = 820
ES_SSC_SensorDetected = 850
ES_SSC_SensorDisconnected = 851
ES_SSC_CompensatorStatusChanged = 852
ES_SSC_BatteryStatusChanged = 853
ES_SSC_TPConnectionClosing = 997
ES_SSC_ServerClosing = 998
ES_SSC_ServerStarted = 999

# enum ES_NivelPosition:
ES_NP_Pos1 = 0
ES_NP_Pos2 = 1
ES_NP_Pos3 = 2
ES_NP_Pos4 = 3

# enum ES_StatisticMode:
ES_SM_Standard = 0
ES_SM_Extended = 1

# enum ES_TrackerProcessorType:
ES_TT_Undefined = 0
ES_TT_ATC400 = 20

# enum ES_TPMicroProcessorType:
ES_TPM_Undefined = 0
ES_TPM_PXA250 = 20

# enum ES_LTSensorType:
ES_LTS_Undefined = 0
ES_LTS_AT401 = 70
ES_LTS_NoSensor = 99

# enum ES_TrackerFace:
ES_TF_Unknown = 0
ES_TF_Face1 = 1
ES_TF_Face2 = 2

# enum ES_ProbeButtonEvent:
ES_PBE_DisableEvents = 0
ES_PBE_EnableEvents = 1

# enum ES_PowerLockMode:
ES_PLM_InDoor = 0
ES_PLM_OutDoor = 1
ES_PLM_OutDoor_LongRange = 2

# enum ES_SystemParameter:
ES_SP_KeepLastPositionFlag = 0
ES_SP_WeatherMonitorSetting = 1
ES_SP_DisplayReflectorPosition = 10
ES_SP_ProbeConfig_ButtonEvent = 51
ES_SP_TcpCommandQueueSize = 200
ES_SP_PowerLockFunctionAvailable = 410
ES_SP_PowerLockFunctionActive = 411
ES_SP_PowerLockMode = 450
ES_SP_D_SystemLongest3DDistanceADM = 1101
ES_SP_AT4xxControllerBatteryStatus = 5000
ES_SP_AT4xxSensorBatteryStatus = 5001
ES_SP_AT4xxInclinationSensorState = 5002

# enum ES_MeasurementStatusInfo:
ES_MSI_Unknown = 0
ES_MSI_TrackerFound = 1
ES_MSI_TrackerCompensationFound = 2
ES_MSI_ADMFound = 4
ES_MSI_ADMCompensationFound = 8
ES_MSI_ReflectorFound = 2048
ES_MSI_InFace1 = 4096
ES_MSI_SensorBatteryMounted = 16384
ES_MSI_NivelInWorkingRange = 32768
ES_MSI_Initialized = 65536

# enum ES_ClearCommandQueueType:
ES_CCQ_ClearOwnOnly = 0
ES_CCQ_ClearAll = 1

# enum ES_OverviewCameraType:
ES_OCT_Unknown = 0
ES_OCT_Classic = 1
ES_OCT_AT4xx_Integrated = 20

# enum ES_ADMType:
ES_AMT_Unknown = 0
ES_AMT_LeicaADM2 = 3

# enum ES_ATRType:
ES_ATR_None = 0
ES_ATR_4 = 1
ES_ATR_5i = 2

# enum ES_TrkAccuracyModel:
ES_TAM_Unknown = 0
ES_TAM_2005 = 1

# enum ES_NivelType:
ES_NT_Unknown = 0
ES_NT_NivelAT4xx = 3

# enum ES_MeteoStationType:
ES_MST_None = 0
ES_MST_Thommen = 1
ES_MST_AT = 2

# enum ES_WLANType:
ES_WLAN_None = 0
ES_WLAN_OWL211 = 1
ES_WLAN_OWL221 = 2

# enum ES_InclinationSensorState:
ES_ISS_Off = 0
ES_ISS_ApplyCorrections = 2

class PacketHeaderT(object):
  def __init__(self):
    self.__packet_size = 12
    self.__sizes = [12]
    self.__formats = [('<q I ')]
    self.lPacketSize = int(0)
    self.type = int(0)  # ES_DataType

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.lPacketSize = packet_elements[0]
    self.type = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.lPacketSize,)
    packet_elements += (self.type,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class ReturnDataT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetHeader = PacketHeaderT()
    self.status = int(0)  # ES_ResultStatus

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.status = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetHeader.pack()
    packet_elements = ()
    packet_elements += (self.status,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class BasicCommandCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetHeader = PacketHeaderT()
    self.command = int(0)  # ES_Command

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.command = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetHeader.pack()
    packet_elements = ()
    packet_elements += (self.command,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class BasicCommandRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [8]
    self.__formats = [('<I I ')]
    self.packetHeader = PacketHeaderT()
    self.command = int(0)  # ES_Command
    self.status = int(0)  # ES_ResultStatus

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.command = packet_elements[0]
    self.status = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetHeader.pack()
    packet_elements = ()
    packet_elements += (self.command,)
    packet_elements += (self.status,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class NivelResultT(object):
  def __init__(self):
    self.__packet_size = 44
    self.__sizes = [28]
    self.__formats = [('<I d d d ')]
    self.packetInfo = ReturnDataT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_NivelResult
    self.nivelStatus = int(0)  # ES_NivelStatus
    self.dXTilt = float(0)
    self.dYTilt = float(0)
    self.dNivelTemperature = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.nivelStatus = packet_elements[0]
    self.dXTilt = packet_elements[1]
    self.dYTilt = packet_elements[2]
    self.dNivelTemperature = packet_elements[3]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.nivelStatus,)
    packet_elements += (self.dXTilt,)
    packet_elements += (self.dYTilt,)
    packet_elements += (self.dNivelTemperature,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class ReflectorPosResultT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = [24]
    self.__formats = [('<d d d ')]
    self.packetInfo = ReturnDataT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_ReflectorPosResult
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SingleMeasResultT(object):
  def __init__(self):
    self.__packet_size = 160
    self.__sizes = [144]
    self.__formats = [('<I i d d d d d d d d d d d d d d d d d ')]
    self.packetInfo = ReturnDataT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_SingleMeasResult
    self.measMode = int(0)  # ES_MeasMode
    self.bIsTryMode = int(0)
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)
    self.dStd1 = float(0)
    self.dStd2 = float(0)
    self.dStd3 = float(0)
    self.dStdTotal = float(0)
    self.dPointingError1 = float(0)
    self.dPointingError2 = float(0)
    self.dPointingError3 = float(0)
    self.dAprioriStd1 = float(0)
    self.dAprioriStd2 = float(0)
    self.dAprioriStd3 = float(0)
    self.dAprioriStdTotal = float(0)
    self.dTemperature = float(0)
    self.dPressure = float(0)
    self.dHumidity = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.measMode = packet_elements[0]
    self.bIsTryMode = packet_elements[1]
    self.dVal1 = packet_elements[2]
    self.dVal2 = packet_elements[3]
    self.dVal3 = packet_elements[4]
    self.dStd1 = packet_elements[5]
    self.dStd2 = packet_elements[6]
    self.dStd3 = packet_elements[7]
    self.dStdTotal = packet_elements[8]
    self.dPointingError1 = packet_elements[9]
    self.dPointingError2 = packet_elements[10]
    self.dPointingError3 = packet_elements[11]
    self.dAprioriStd1 = packet_elements[12]
    self.dAprioriStd2 = packet_elements[13]
    self.dAprioriStd3 = packet_elements[14]
    self.dAprioriStdTotal = packet_elements[15]
    self.dTemperature = packet_elements[16]
    self.dPressure = packet_elements[17]
    self.dHumidity = packet_elements[18]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.measMode,)
    packet_elements += (self.bIsTryMode,)
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet_elements += (self.dStd1,)
    packet_elements += (self.dStd2,)
    packet_elements += (self.dStd3,)
    packet_elements += (self.dStdTotal,)
    packet_elements += (self.dPointingError1,)
    packet_elements += (self.dPointingError2,)
    packet_elements += (self.dPointingError3,)
    packet_elements += (self.dAprioriStd1,)
    packet_elements += (self.dAprioriStd2,)
    packet_elements += (self.dAprioriStd3,)
    packet_elements += (self.dAprioriStdTotal,)
    packet_elements += (self.dTemperature,)
    packet_elements += (self.dPressure,)
    packet_elements += (self.dHumidity,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SingleMeasResult2T(object):
  def __init__(self):
    self.__packet_size = 208
    self.__sizes = [192]
    self.__formats = [('<I i d d d d d d d d d d d d d d d d d d d d d d d ')]
    self.packetInfo = ReturnDataT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_SingleMeasResult2
    self.measMode = int(0)  # ES_MeasMode
    self.bIsTryMode = int(0)
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)
    self.dStd1 = float(0)
    self.dStd2 = float(0)
    self.dStd3 = float(0)
    self.dStdTotal = float(0)
    self.dCovar12 = float(0)
    self.dCovar13 = float(0)
    self.dCovar23 = float(0)
    self.dPointingErrorH = float(0)
    self.dPointingErrorV = float(0)
    self.dPointingErrorD = float(0)
    self.dAprioriStd1 = float(0)
    self.dAprioriStd2 = float(0)
    self.dAprioriStd3 = float(0)
    self.dAprioriStdTotal = float(0)
    self.dAprioriCovar12 = float(0)
    self.dAprioriCovar13 = float(0)
    self.dAprioriCovar23 = float(0)
    self.dTemperature = float(0)
    self.dPressure = float(0)
    self.dHumidity = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.measMode = packet_elements[0]
    self.bIsTryMode = packet_elements[1]
    self.dVal1 = packet_elements[2]
    self.dVal2 = packet_elements[3]
    self.dVal3 = packet_elements[4]
    self.dStd1 = packet_elements[5]
    self.dStd2 = packet_elements[6]
    self.dStd3 = packet_elements[7]
    self.dStdTotal = packet_elements[8]
    self.dCovar12 = packet_elements[9]
    self.dCovar13 = packet_elements[10]
    self.dCovar23 = packet_elements[11]
    self.dPointingErrorH = packet_elements[12]
    self.dPointingErrorV = packet_elements[13]
    self.dPointingErrorD = packet_elements[14]
    self.dAprioriStd1 = packet_elements[15]
    self.dAprioriStd2 = packet_elements[16]
    self.dAprioriStd3 = packet_elements[17]
    self.dAprioriStdTotal = packet_elements[18]
    self.dAprioriCovar12 = packet_elements[19]
    self.dAprioriCovar13 = packet_elements[20]
    self.dAprioriCovar23 = packet_elements[21]
    self.dTemperature = packet_elements[22]
    self.dPressure = packet_elements[23]
    self.dHumidity = packet_elements[24]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.measMode,)
    packet_elements += (self.bIsTryMode,)
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet_elements += (self.dStd1,)
    packet_elements += (self.dStd2,)
    packet_elements += (self.dStd3,)
    packet_elements += (self.dStdTotal,)
    packet_elements += (self.dCovar12,)
    packet_elements += (self.dCovar13,)
    packet_elements += (self.dCovar23,)
    packet_elements += (self.dPointingErrorH,)
    packet_elements += (self.dPointingErrorV,)
    packet_elements += (self.dPointingErrorD,)
    packet_elements += (self.dAprioriStd1,)
    packet_elements += (self.dAprioriStd2,)
    packet_elements += (self.dAprioriStd3,)
    packet_elements += (self.dAprioriStdTotal,)
    packet_elements += (self.dAprioriCovar12,)
    packet_elements += (self.dAprioriCovar13,)
    packet_elements += (self.dAprioriCovar23,)
    packet_elements += (self.dTemperature,)
    packet_elements += (self.dPressure,)
    packet_elements += (self.dHumidity,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SystemStatusChangeT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetHeader = PacketHeaderT()
    self.packetHeader.lPacketSize = self.__packet_size
    self.packetHeader.type = ES_DT_SystemStatusChange
    self.systemStatusChange = int(0)  # ES_SystemStatusChange

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemStatusChange = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetHeader.pack()
    packet_elements = ()
    packet_elements += (self.systemStatusChange,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class ErrorResponseT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [8]
    self.__formats = [('<I I ')]
    self.packetHeader = PacketHeaderT()
    self.packetHeader.lPacketSize = self.__packet_size
    self.packetHeader.type = ES_DT_Error
    self.command = int(0)  # ES_Command
    self.status = int(0)  # ES_ResultStatus

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.command = packet_elements[0]
    self.status = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetHeader.pack()
    packet_elements = ()
    packet_elements += (self.command,)
    packet_elements += (self.status,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class InitializeCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_Initialize

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class InitializeRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_Initialize

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ActivateCameraViewCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ActivateCameraView

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ActivateCameraViewRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ActivateCameraView

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ParkCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_Park

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ParkRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_Park

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoBirdBathCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoBirdBath

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoBirdBathRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoBirdBath

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoBirdBath2CT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoBirdBath2
    self.bClockWise = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.bClockWise = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.bClockWise,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoBirdBath2RT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoBirdBath2

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ChangeFaceCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ChangeFace

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ChangeFaceRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ChangeFace

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StartNivelMeasurementCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StartNivelMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StartNivelMeasurementRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StartNivelMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StartMeasurementCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StartMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StartMeasurementRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StartMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StopMeasurementCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StopMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class StopMeasurementRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_StopMeasurement

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ExitApplicationCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ExitApplication

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class ExitApplicationRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ExitApplication

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoLastMeasuredPointCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoLastMeasuredPoint

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoLastMeasuredPointRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoLastMeasuredPoint

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class FindReflectorCT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [8]
    self.__formats = [('<d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_FindReflector
    self.dAproxDistance = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dAproxDistance = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dAproxDistance,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class FindReflectorRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_FindReflector

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class SetCoordinateSystemTypeCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCoordinateSystemType
    self.coordSysType = int(0)  # ES_CoordinateSystemType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.coordSysType = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.coordSysType,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetCoordinateSystemTypeRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCoordinateSystemType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCoordinateSystemTypeCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCoordinateSystemType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCoordinateSystemTypeRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCoordinateSystemType
    self.coordSysType = int(0)  # ES_CoordinateSystemType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.coordSysType = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.coordSysType,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetMeasurementModeCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetMeasurementMode
    self.measMode = int(0)  # ES_MeasMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.measMode = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.measMode,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetMeasurementModeRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetMeasurementMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetMeasurementModeCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeasurementMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetMeasurementModeRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeasurementMode
    self.measMode = int(0)  # ES_MeasMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.measMode = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.measMode,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SearchParamsDataT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = [16]
    self.__formats = [('<d q ')]
    self.dSearchRadius = float(0)
    self.lTimeOut = int(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dSearchRadius = packet_elements[0]
    self.lTimeOut = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.dSearchRadius,)
    packet_elements += (self.lTimeOut,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetSearchParamsCT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetSearchParams
    self.searchParams = SearchParamsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.searchParams.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.searchParams.pack()
    return packet

class SetSearchParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetSearchParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSearchParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSearchParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSearchParamsRT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSearchParams
    self.searchParams = SearchParamsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.searchParams.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.searchParams.pack()
    return packet

class StationaryModeDataT(object):
  def __init__(self):
    self.__packet_size = 12
    self.__sizes = [12]
    self.__formats = [('<q i ')]
    self.lMeasTime = int(0)
    self.bUseADM = int(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.lMeasTime = packet_elements[0]
    self.bUseADM = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.lMeasTime,)
    packet_elements += (self.bUseADM,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetStationaryModeParamsCT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStationaryModeParams
    self.stationaryModeData = StationaryModeDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.stationaryModeData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.stationaryModeData.pack()
    return packet

class SetStationaryModeParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStationaryModeParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStationaryModeParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStationaryModeParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStationaryModeParamsRT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStationaryModeParams
    self.stationaryModeData = StationaryModeDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.stationaryModeData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.stationaryModeData.pack()
    return packet

class SystemSettingsDataT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = [36]
    self.__formats = [('<I i i i i i i i i ')]
    self.weatherMonitorStatus = int(0)  # ES_WeatherMonitorStatus
    self.bApplyTransformationParams = int(0)
    self.bApplyStationOrientationParams = int(0)
    self.bKeepLastPosition = int(0)
    self.bSendUnsolicitedMessages = int(0)
    self.bSendReflectorPositionData = int(0)
    self.bTryMeasurementMode = int(0)
    self.bHasNivel = int(0)
    self.bHasVideoCamera = int(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.weatherMonitorStatus = packet_elements[0]
    self.bApplyTransformationParams = packet_elements[1]
    self.bApplyStationOrientationParams = packet_elements[2]
    self.bKeepLastPosition = packet_elements[3]
    self.bSendUnsolicitedMessages = packet_elements[4]
    self.bSendReflectorPositionData = packet_elements[5]
    self.bTryMeasurementMode = packet_elements[6]
    self.bHasNivel = packet_elements[7]
    self.bHasVideoCamera = packet_elements[8]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.weatherMonitorStatus,)
    packet_elements += (self.bApplyTransformationParams,)
    packet_elements += (self.bApplyStationOrientationParams,)
    packet_elements += (self.bKeepLastPosition,)
    packet_elements += (self.bSendUnsolicitedMessages,)
    packet_elements += (self.bSendReflectorPositionData,)
    packet_elements += (self.bTryMeasurementMode,)
    packet_elements += (self.bHasNivel,)
    packet_elements += (self.bHasVideoCamera,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetSystemSettingsCT(object):
  def __init__(self):
    self.__packet_size = 52
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetSystemSettings
    self.systemSettings = SystemSettingsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.systemSettings.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.systemSettings.pack()
    return packet

class SetSystemSettingsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetSystemSettings

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSystemSettingsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemSettings

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSystemSettingsRT(object):
  def __init__(self):
    self.__packet_size = 56
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemSettings
    self.systemSettings = SystemSettingsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.systemSettings.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.systemSettings.pack()
    return packet

class SystemUnitsDataT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [20]
    self.__formats = [('<I I I I I ')]
    self.lenUnitType = int(0)  # ES_LengthUnit
    self.angUnitType = int(0)  # ES_AngleUnit
    self.tempUnitType = int(0)  # ES_TemperatureUnit
    self.pressUnitType = int(0)  # ES_PressureUnit
    self.humUnitType = int(0)  # ES_HumidityUnit

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.lenUnitType = packet_elements[0]
    self.angUnitType = packet_elements[1]
    self.tempUnitType = packet_elements[2]
    self.pressUnitType = packet_elements[3]
    self.humUnitType = packet_elements[4]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.lenUnitType,)
    packet_elements += (self.angUnitType,)
    packet_elements += (self.tempUnitType,)
    packet_elements += (self.pressUnitType,)
    packet_elements += (self.humUnitType,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetUnitsCT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetUnits
    self.unitsSettings = SystemUnitsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.unitsSettings.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.unitsSettings.pack()
    return packet

class SetUnitsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetUnits

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetUnitsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetUnits

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetUnitsRT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetUnits
    self.unitsSettings = SystemUnitsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.unitsSettings.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.unitsSettings.pack()
    return packet

class ESVersionNumberT(object):
  def __init__(self):
    self.__packet_size = 12
    self.__sizes = [12]
    self.__formats = [('<i i i ')]
    self.iMajorVersionNumber = int(0)
    self.iMinorVersionNumber = int(0)
    self.iBuildNumber = int(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iMajorVersionNumber = packet_elements[0]
    self.iMinorVersionNumber = packet_elements[1]
    self.iBuildNumber = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.iMajorVersionNumber,)
    packet_elements += (self.iMinorVersionNumber,)
    packet_elements += (self.iBuildNumber,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetSystemStatusCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemStatus

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSystemStatusRT(object):
  def __init__(self):
    self.__packet_size = 68
    self.__sizes = [16,20]
    self.__formats = [('<I I I I '),('<I q q ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemStatus
    self.lastResultStatus = int(0)  # ES_ResultStatus
    self.trackerProcessorStatus = int(0)  # ES_TrackerProcessorStatus
    self.laserStatus = int(0)  # ES_LaserProcessorStatus
    self.admStatus = int(0)  # ES_ADMStatus
    self.esVersionNumber = ESVersionNumberT()
    self.weatherMonitorStatus = int(0)  # ES_WeatherMonitorStatus
    self.lFlagsValue = int(0)
    self.lTrackerSerialNumber = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.lastResultStatus = packet_elements[0]
    self.trackerProcessorStatus = packet_elements[1]
    self.laserStatus = packet_elements[2]
    self.admStatus = packet_elements[3]
    packet = self.esVersionNumber.unpack(packet)
    packet_elements = struct.Struct(self.__formats[1]).unpack(packet[:self.__sizes[1]])
    self.weatherMonitorStatus = packet_elements[0]
    self.lFlagsValue = packet_elements[1]
    self.lTrackerSerialNumber = packet_elements[2]
    return packet[self.__sizes[1]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.lastResultStatus,)
    packet_elements += (self.trackerProcessorStatus,)
    packet_elements += (self.laserStatus,)
    packet_elements += (self.admStatus,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    packet += self.esVersionNumber.pack()
    packet_elements = ()
    packet_elements += (self.weatherMonitorStatus,)
    packet_elements += (self.lFlagsValue,)
    packet_elements += (self.lTrackerSerialNumber,)
    packet += struct.Struct(self.__formats[1]).pack(*packet_elements)
    return packet

class GetMeasurementStatusInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeasurementStatusInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetMeasurementStatusInfoRT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = [12]
    self.__formats = [('<I q ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeasurementStatusInfo
    self.lastResultStatus = int(0)  # ES_ResultStatus
    self.lMeasurementStatusInfo = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.lastResultStatus = packet_elements[0]
    self.lMeasurementStatusInfo = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.lastResultStatus,)
    packet_elements += (self.lMeasurementStatusInfo,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetTrackerStatusCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTrackerStatus

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetTrackerStatusRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTrackerStatus
    self.trackerStatus = int(0)  # ES_TrackerStatus

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.trackerStatus = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.trackerStatus,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetReflectorCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetReflector
    self.iInternalReflectorId = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iInternalReflectorId = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iInternalReflectorId,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetReflectorRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetReflector

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetReflectorsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetReflectors

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetReflectorsRT(object):
  def __init__(self):
    self.__packet_size = 72
    self.__sizes = [52]
    self.__formats = [('<i i I d 32s ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetReflectors
    self.iTotalReflectors = int(0)
    self.iInternalReflectorId = int(0)
    self.targetType = int(0)  # ES_TargetType
    self.dSurfaceOffset = float(0)
    self.cReflectorName = str()  # 32 bytes max

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iTotalReflectors = packet_elements[0]
    self.iInternalReflectorId = packet_elements[1]
    self.targetType = packet_elements[2]
    self.dSurfaceOffset = packet_elements[3]
    self.cReflectorName = packet_elements[4]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iTotalReflectors,)
    packet_elements += (self.iInternalReflectorId,)
    packet_elements += (self.targetType,)
    packet_elements += (self.dSurfaceOffset,)
    packet_elements += (self.cReflectorName,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetReflectorCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetReflector

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetReflectorRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetReflector
    self.iInternalReflectorId = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iInternalReflectorId = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iInternalReflectorId,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class EnvironmentDataT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [24]
    self.__formats = [('<d d d ')]
    self.dTemperature = float(0)
    self.dPressure = float(0)
    self.dHumidity = float(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dTemperature = packet_elements[0]
    self.dPressure = packet_elements[1]
    self.dHumidity = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.dTemperature,)
    packet_elements += (self.dPressure,)
    packet_elements += (self.dHumidity,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetEnvironmentParamsCT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetEnvironmentParams
    self.environmentData = EnvironmentDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.environmentData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.environmentData.pack()
    return packet

class SetEnvironmentParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetEnvironmentParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetEnvironmentParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetEnvironmentParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetEnvironmentParamsRT(object):
  def __init__(self):
    self.__packet_size = 44
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetEnvironmentParams
    self.environmentData = EnvironmentDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.environmentData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.environmentData.pack()
    return packet

class RefractionDataT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = [16]
    self.__formats = [('<d d ')]
    self.dIfmRefractionIndex = float(0)
    self.dAdmRefractionIndex = float(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dIfmRefractionIndex = packet_elements[0]
    self.dAdmRefractionIndex = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.dIfmRefractionIndex,)
    packet_elements += (self.dAdmRefractionIndex,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetRefractionParamsCT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetRefractionParams
    self.refractionData = RefractionDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.refractionData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.refractionData.pack()
    return packet

class SetRefractionParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetRefractionParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetRefractionParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetRefractionParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetRefractionParamsRT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetRefractionParams
    self.refractionData = RefractionDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.refractionData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.refractionData.pack()
    return packet

class StationOrientationDataT(object):
  def __init__(self):
    self.__packet_size = 48
    self.__sizes = [48]
    self.__formats = [('<d d d d d d ')]
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)
    self.dRot1 = float(0)
    self.dRot2 = float(0)
    self.dRot3 = float(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    self.dRot1 = packet_elements[3]
    self.dRot2 = packet_elements[4]
    self.dRot3 = packet_elements[5]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet_elements += (self.dRot1,)
    packet_elements += (self.dRot2,)
    packet_elements += (self.dRot3,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetStationOrientationParamsCT(object):
  def __init__(self):
    self.__packet_size = 64
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStationOrientationParams
    self.stationOrientation = StationOrientationDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.stationOrientation.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.stationOrientation.pack()
    return packet

class SetStationOrientationParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStationOrientationParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStationOrientationParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStationOrientationParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStationOrientationParamsRT(object):
  def __init__(self):
    self.__packet_size = 68
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStationOrientationParams
    self.stationOrientation = StationOrientationDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.stationOrientation.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.stationOrientation.pack()
    return packet

class TransformationDataT(object):
  def __init__(self):
    self.__packet_size = 56
    self.__sizes = [56]
    self.__formats = [('<d d d d d d d ')]
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)
    self.dRot1 = float(0)
    self.dRot2 = float(0)
    self.dRot3 = float(0)
    self.dScale = float(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    self.dRot1 = packet_elements[3]
    self.dRot2 = packet_elements[4]
    self.dRot3 = packet_elements[5]
    self.dScale = packet_elements[6]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet_elements += (self.dRot1,)
    packet_elements += (self.dRot2,)
    packet_elements += (self.dRot3,)
    packet_elements += (self.dScale,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetTransformationParamsCT(object):
  def __init__(self):
    self.__packet_size = 72
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetTransformationParams
    self.transformationData = TransformationDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.transformationData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.transformationData.pack()
    return packet

class SetTransformationParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetTransformationParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetTransformationParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTransformationParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetTransformationParamsRT(object):
  def __init__(self):
    self.__packet_size = 76
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTransformationParams
    self.transformationData = TransformationDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.transformationData.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.transformationData.pack()
    return packet

class GoPositionCT(object):
  def __init__(self):
    self.__packet_size = 44
    self.__sizes = [28]
    self.__formats = [('<d d d i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoPosition
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)
    self.bUseADM = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    self.bUseADM = packet_elements[3]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet_elements += (self.bUseADM,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoPositionRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoPosition

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetDirectionCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetDirection

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetDirectionRT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = [16]
    self.__formats = [('<d d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetDirection
    self.dHzAngle = float(0)
    self.dVtAngle = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dHzAngle = packet_elements[0]
    self.dVtAngle = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dHzAngle,)
    packet_elements += (self.dVtAngle,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoPositionHVDCT(object):
  def __init__(self):
    self.__packet_size = 44
    self.__sizes = [28]
    self.__formats = [('<d d d i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoPositionHVD
    self.dHzAngle = float(0)
    self.dVtAngle = float(0)
    self.dDistance = float(0)
    self.bUseADM = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dHzAngle = packet_elements[0]
    self.dVtAngle = packet_elements[1]
    self.dDistance = packet_elements[2]
    self.bUseADM = packet_elements[3]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dHzAngle,)
    packet_elements += (self.dVtAngle,)
    packet_elements += (self.dDistance,)
    packet_elements += (self.bUseADM,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoPositionHVDRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoPositionHVD

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class PointLaserCT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = [24]
    self.__formats = [('<d d d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PointLaser
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class PointLaserRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PointLaser

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class PositionRelativeHVCT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = [16]
    self.__formats = [('<d d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PositionRelativeHV
    self.dHzVal = float(0)
    self.dVtVal = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dHzVal = packet_elements[0]
    self.dVtVal = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dHzVal,)
    packet_elements += (self.dVtVal,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class PositionRelativeHVRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PositionRelativeHV

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class PointLaserHVDCT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = [24]
    self.__formats = [('<d d d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PointLaserHVD
    self.dHzAngle = float(0)
    self.dVtAngle = float(0)
    self.dDistance = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dHzAngle = packet_elements[0]
    self.dVtAngle = packet_elements[1]
    self.dDistance = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dHzAngle,)
    packet_elements += (self.dVtAngle,)
    packet_elements += (self.dDistance,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class PointLaserHVDRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_PointLaserHVD

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class MoveHVCT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [8]
    self.__formats = [('<i i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_MoveHV
    self.iHzSpeed = int(0)
    self.iVtSpeed = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iHzSpeed = packet_elements[0]
    self.iVtSpeed = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iHzSpeed,)
    packet_elements += (self.iVtSpeed,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class MoveHVRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_MoveHV

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoNivelPositionCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoNivelPosition
    self.nivelPosition = int(0)  # ES_NivelPosition

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.nivelPosition = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.nivelPosition,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoNivelPositionRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoNivelPosition

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class CallOrientToGravityCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_CallOrientToGravity

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class CallOrientToGravityRT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = [16]
    self.__formats = [('<d d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_CallOrientToGravity
    self.dOmega = float(0)
    self.dPhi = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dOmega = packet_elements[0]
    self.dPhi = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dOmega,)
    packet_elements += (self.dPhi,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetCompensationCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCompensation
    self.iInternalCompensationId = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iInternalCompensationId = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iInternalCompensationId,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetCompensationRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCompensation

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCompensationCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensation

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCompensationRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensation
    self.iInternalCompensationId = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iInternalCompensationId = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iInternalCompensationId,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetCompensationsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensations

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCompensationsRT(object):
  def __init__(self):
    self.__packet_size = 224
    self.__sizes = [204]
    self.__formats = [('<i i 32s 128s 32s i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensations
    self.iTotalCompensations = int(0)
    self.iInternalCompensationId = int(0)
    self.cTrackerCompensationName = str()  # 32 bytes max
    self.cTrackerCompensationComment = str()  # 128 bytes max
    self.cADMCompensationName = str()  # 32 bytes max
    self.bHasMeasurementCameraMounted = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iTotalCompensations = packet_elements[0]
    self.iInternalCompensationId = packet_elements[1]
    self.cTrackerCompensationName = packet_elements[2]
    self.cTrackerCompensationComment = packet_elements[3]
    self.cADMCompensationName = packet_elements[4]
    self.bHasMeasurementCameraMounted = packet_elements[5]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iTotalCompensations,)
    packet_elements += (self.iInternalCompensationId,)
    packet_elements += (self.cTrackerCompensationName,)
    packet_elements += (self.cTrackerCompensationComment,)
    packet_elements += (self.cADMCompensationName,)
    packet_elements += (self.bHasMeasurementCameraMounted,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetCompensations2CT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensations2

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCompensations2RT(object):
  def __init__(self):
    self.__packet_size = 356
    self.__sizes = [336]
    self.__formats = [('<i i 32s 128s 32s 128s i i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCompensations2
    self.iTotalCompensations = int(0)
    self.iInternalCompensationId = int(0)
    self.cTrackerCompensationName = str()  # 32 bytes max
    self.cTrackerCompensationComment = str()  # 128 bytes max
    self.cADMCompensationName = str()  # 32 bytes max
    self.cADMCompensationComment = str()  # 128 bytes max
    self.bHasMeasurementCameraMounted = int(0)
    self.bIsActive = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iTotalCompensations = packet_elements[0]
    self.iInternalCompensationId = packet_elements[1]
    self.cTrackerCompensationName = packet_elements[2]
    self.cTrackerCompensationComment = packet_elements[3]
    self.cADMCompensationName = packet_elements[4]
    self.cADMCompensationComment = packet_elements[5]
    self.bHasMeasurementCameraMounted = packet_elements[6]
    self.bIsActive = packet_elements[7]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iTotalCompensations,)
    packet_elements += (self.iInternalCompensationId,)
    packet_elements += (self.cTrackerCompensationName,)
    packet_elements += (self.cTrackerCompensationComment,)
    packet_elements += (self.cADMCompensationName,)
    packet_elements += (self.cADMCompensationComment,)
    packet_elements += (self.bHasMeasurementCameraMounted,)
    packet_elements += (self.bIsActive,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetStatisticModeCT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [8]
    self.__formats = [('<I I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStatisticMode
    self.stationaryMeasurements = int(0)  # ES_StatisticMode
    self.continuousMeasurements = int(0)  # ES_StatisticMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.stationaryMeasurements = packet_elements[0]
    self.continuousMeasurements = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.stationaryMeasurements,)
    packet_elements += (self.continuousMeasurements,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetStatisticModeRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetStatisticMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStatisticModeCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStatisticMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetStatisticModeRT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = [8]
    self.__formats = [('<I I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetStatisticMode
    self.stationaryMeasurements = int(0)  # ES_StatisticMode
    self.continuousMeasurements = int(0)  # ES_StatisticMode

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.stationaryMeasurements = packet_elements[0]
    self.continuousMeasurements = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.stationaryMeasurements,)
    packet_elements += (self.continuousMeasurements,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class CameraParamsDataT(object):
  def __init__(self):
    self.__packet_size = 12
    self.__sizes = [12]
    self.__formats = [('<i i i ')]
    self.iContrast = int(0)
    self.iBrightness = int(0)
    self.iSaturation = int(0)

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iContrast = packet_elements[0]
    self.iBrightness = packet_elements[1]
    self.iSaturation = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet_elements = ()
    packet_elements += (self.iContrast,)
    packet_elements += (self.iBrightness,)
    packet_elements += (self.iSaturation,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetCameraParamsCT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCameraParams
    self.cameraParams = CameraParamsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.cameraParams.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.cameraParams.pack()
    return packet

class SetCameraParamsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetCameraParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCameraParamsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCameraParams

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetCameraParamsRT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetCameraParams
    self.cameraParams = CameraParamsDataT()

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet = self.cameraParams.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet += self.cameraParams.pack()
    return packet

class GetADMInfo2CT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetADMInfo2

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetADMInfo2RT(object):
  def __init__(self):
    self.__packet_size = 100
    self.__sizes = [80]
    self.__formats = [('<I 32s q i i d d i d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetADMInfo2
    self.admType = int(0)  # ES_ADMType
    self.cADMName = str()  # 32 bytes max
    self.lSerialNumber = int(0)
    self.iFirmwareMajorVersionNumber = int(0)
    self.iFirmwareMinorVersionNumber = int(0)
    self.dMaxDistance = float(0)
    self.dMinDistance = float(0)
    self.iMaxDataRate = int(0)
    self.dAccuracyADMDistance = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.admType = packet_elements[0]
    self.cADMName = packet_elements[1]
    self.lSerialNumber = packet_elements[2]
    self.iFirmwareMajorVersionNumber = packet_elements[3]
    self.iFirmwareMinorVersionNumber = packet_elements[4]
    self.dMaxDistance = packet_elements[5]
    self.dMinDistance = packet_elements[6]
    self.iMaxDataRate = packet_elements[7]
    self.dAccuracyADMDistance = packet_elements[8]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.admType,)
    packet_elements += (self.cADMName,)
    packet_elements += (self.lSerialNumber,)
    packet_elements += (self.iFirmwareMajorVersionNumber,)
    packet_elements += (self.iFirmwareMinorVersionNumber,)
    packet_elements += (self.dMaxDistance,)
    packet_elements += (self.dMinDistance,)
    packet_elements += (self.iMaxDataRate,)
    packet_elements += (self.dAccuracyADMDistance,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetNivelInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetNivelInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetNivelInfoRT(object):
  def __init__(self):
    self.__packet_size = 36
    self.__sizes = [16]
    self.__formats = [('<i i q ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetNivelInfo
    self.iFirmwareMajorVersionNumber = int(0)
    self.iFirmwareMinorVersionNumber = int(0)
    self.lSerialNumber = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iFirmwareMajorVersionNumber = packet_elements[0]
    self.iFirmwareMinorVersionNumber = packet_elements[1]
    self.lSerialNumber = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iFirmwareMajorVersionNumber,)
    packet_elements += (self.iFirmwareMinorVersionNumber,)
    packet_elements += (self.lSerialNumber,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetNivelInfo2CT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetNivelInfo2

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetNivelInfo2RT(object):
  def __init__(self):
    self.__packet_size = 96
    self.__sizes = [76]
    self.__formats = [('<I 32s q i i d d d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetNivelInfo2
    self.nivelType = int(0)  # ES_NivelType
    self.cNivelName = str()  # 32 bytes max
    self.lSerialNumber = int(0)
    self.iFirmwareMajorVersionNumber = int(0)
    self.iFirmwareMinorVersionNumber = int(0)
    self.dMeasurementRange = float(0)
    self.dMeasurementAccuracyOffset = float(0)
    self.dMeasurementAccuracyFactor = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.nivelType = packet_elements[0]
    self.cNivelName = packet_elements[1]
    self.lSerialNumber = packet_elements[2]
    self.iFirmwareMajorVersionNumber = packet_elements[3]
    self.iFirmwareMinorVersionNumber = packet_elements[4]
    self.dMeasurementRange = packet_elements[5]
    self.dMeasurementAccuracyOffset = packet_elements[6]
    self.dMeasurementAccuracyFactor = packet_elements[7]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.nivelType,)
    packet_elements += (self.cNivelName,)
    packet_elements += (self.lSerialNumber,)
    packet_elements += (self.iFirmwareMajorVersionNumber,)
    packet_elements += (self.iFirmwareMinorVersionNumber,)
    packet_elements += (self.dMeasurementRange,)
    packet_elements += (self.dMeasurementAccuracyOffset,)
    packet_elements += (self.dMeasurementAccuracyFactor,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetTPInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTPInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetTPInfoRT(object):
  def __init__(self):
    self.__packet_size = 60
    self.__sizes = [40]
    self.__formats = [('<i i i i i i I I i I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTPInfo
    self.iTPBootMajorVersionNumber = int(0)
    self.iTPBootMinorVersionNumber = int(0)
    self.iTPFirmwareMajorVersionNumber = int(0)
    self.iTPFirmwareMinorVersionNumber = int(0)
    self.iLCPFirmwareMajorVersionNumber = int(0)
    self.iLCPFirmwareMinorVersionNumber = int(0)
    self.trackerprocessorType = int(0)  # ES_TrackerProcessorType
    self.microProcessorType = int(0)  # ES_TPMicroProcessorType
    self.iMicroProcessorClockSpeed = int(0)
    self.laserTrackerSensorType = int(0)  # ES_LTSensorType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iTPBootMajorVersionNumber = packet_elements[0]
    self.iTPBootMinorVersionNumber = packet_elements[1]
    self.iTPFirmwareMajorVersionNumber = packet_elements[2]
    self.iTPFirmwareMinorVersionNumber = packet_elements[3]
    self.iLCPFirmwareMajorVersionNumber = packet_elements[4]
    self.iLCPFirmwareMinorVersionNumber = packet_elements[5]
    self.trackerprocessorType = packet_elements[6]
    self.microProcessorType = packet_elements[7]
    self.iMicroProcessorClockSpeed = packet_elements[8]
    self.laserTrackerSensorType = packet_elements[9]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iTPBootMajorVersionNumber,)
    packet_elements += (self.iTPBootMinorVersionNumber,)
    packet_elements += (self.iTPFirmwareMajorVersionNumber,)
    packet_elements += (self.iTPFirmwareMinorVersionNumber,)
    packet_elements += (self.iLCPFirmwareMajorVersionNumber,)
    packet_elements += (self.iLCPFirmwareMinorVersionNumber,)
    packet_elements += (self.trackerprocessorType,)
    packet_elements += (self.microProcessorType,)
    packet_elements += (self.iMicroProcessorClockSpeed,)
    packet_elements += (self.laserTrackerSensorType,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetTrackerInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTrackerInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetTrackerInfoRT(object):
  def __init__(self):
    self.__packet_size = 144
    self.__sizes = [124]
    self.__formats = [('<I 32s q q i i i d d d i i d d I i i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetTrackerInfo
    self.trackerType = int(0)  # ES_LTSensorType
    self.cTrackerName = str()  # 32 bytes max
    self.lSerialNumber = int(0)
    self.lCompensationIdNumber = int(0)
    self.bHasADM = int(0)
    self.bHasOverviewCamera = int(0)
    self.bHasNivel = int(0)
    self.dNivelMountOffset = float(0)
    self.dMaxDistance = float(0)
    self.dMinDistance = float(0)
    self.iMaxDataRate = int(0)
    self.iNumberOfFaces = int(0)
    self.dHzAngleRange = float(0)
    self.dVtAngleRange = float(0)
    self.accuracyModel = int(0)  # ES_TrkAccuracyModel
    self.iMajLCPFirmwareVersion = int(0)
    self.iMinLCPFirmwareVersion = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.trackerType = packet_elements[0]
    self.cTrackerName = packet_elements[1]
    self.lSerialNumber = packet_elements[2]
    self.lCompensationIdNumber = packet_elements[3]
    self.bHasADM = packet_elements[4]
    self.bHasOverviewCamera = packet_elements[5]
    self.bHasNivel = packet_elements[6]
    self.dNivelMountOffset = packet_elements[7]
    self.dMaxDistance = packet_elements[8]
    self.dMinDistance = packet_elements[9]
    self.iMaxDataRate = packet_elements[10]
    self.iNumberOfFaces = packet_elements[11]
    self.dHzAngleRange = packet_elements[12]
    self.dVtAngleRange = packet_elements[13]
    self.accuracyModel = packet_elements[14]
    self.iMajLCPFirmwareVersion = packet_elements[15]
    self.iMinLCPFirmwareVersion = packet_elements[16]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.trackerType,)
    packet_elements += (self.cTrackerName,)
    packet_elements += (self.lSerialNumber,)
    packet_elements += (self.lCompensationIdNumber,)
    packet_elements += (self.bHasADM,)
    packet_elements += (self.bHasOverviewCamera,)
    packet_elements += (self.bHasNivel,)
    packet_elements += (self.dNivelMountOffset,)
    packet_elements += (self.dMaxDistance,)
    packet_elements += (self.dMinDistance,)
    packet_elements += (self.iMaxDataRate,)
    packet_elements += (self.iNumberOfFaces,)
    packet_elements += (self.dHzAngleRange,)
    packet_elements += (self.dVtAngleRange,)
    packet_elements += (self.accuracyModel,)
    packet_elements += (self.iMajLCPFirmwareVersion,)
    packet_elements += (self.iMinLCPFirmwareVersion,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetATRInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetATRInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetATRInfoRT(object):
  def __init__(self):
    self.__packet_size = 136
    self.__sizes = [116]
    self.__formats = [('<I 32s q q q q q q d d d d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetATRInfo
    self.atrType = int(0)  # ES_ATRType
    self.cATRName = str()  # 32 bytes max
    self.lMajFirmwareVersion = int(0)
    self.lMinFirmwareVersion = int(0)
    self.lBuildFirmwareVersion = int(0)
    self.lHardwareVersion = int(0)
    self.lErrorcode = int(0)
    self.lFPGAVersion = int(0)
    self.dMaxDistance = float(0)
    self.dMinDistance = float(0)
    self.dFieldOfView = float(0)
    self.dMaxTrackingSpeed = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.atrType = packet_elements[0]
    self.cATRName = packet_elements[1]
    self.lMajFirmwareVersion = packet_elements[2]
    self.lMinFirmwareVersion = packet_elements[3]
    self.lBuildFirmwareVersion = packet_elements[4]
    self.lHardwareVersion = packet_elements[5]
    self.lErrorcode = packet_elements[6]
    self.lFPGAVersion = packet_elements[7]
    self.dMaxDistance = packet_elements[8]
    self.dMinDistance = packet_elements[9]
    self.dFieldOfView = packet_elements[10]
    self.dMaxTrackingSpeed = packet_elements[11]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.atrType,)
    packet_elements += (self.cATRName,)
    packet_elements += (self.lMajFirmwareVersion,)
    packet_elements += (self.lMinFirmwareVersion,)
    packet_elements += (self.lBuildFirmwareVersion,)
    packet_elements += (self.lHardwareVersion,)
    packet_elements += (self.lErrorcode,)
    packet_elements += (self.lFPGAVersion,)
    packet_elements += (self.dMaxDistance,)
    packet_elements += (self.dMinDistance,)
    packet_elements += (self.dFieldOfView,)
    packet_elements += (self.dMaxTrackingSpeed,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetLaserOnTimerCT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [8]
    self.__formats = [('<i i ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetLaserOnTimer
    self.iLaserOnTimeOffsetHour = int(0)
    self.iLaserOnTimeOffsetMinute = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iLaserOnTimeOffsetHour = packet_elements[0]
    self.iLaserOnTimeOffsetMinute = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iLaserOnTimeOffsetHour,)
    packet_elements += (self.iLaserOnTimeOffsetMinute,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetLaserOnTimerRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetLaserOnTimer

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetLaserOnTimerCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetLaserOnTimer

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetLaserOnTimerRT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = [8]
    self.__formats = [('<i i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetLaserOnTimer
    self.iLaserOnTimeOffsetHour = int(0)
    self.iLaserOnTimeOffsetMinute = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.iLaserOnTimeOffsetHour = packet_elements[0]
    self.iLaserOnTimeOffsetMinute = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.iLaserOnTimeOffsetHour,)
    packet_elements += (self.iLaserOnTimeOffsetMinute,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetFaceCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetFace

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetFaceRT(object):
  def __init__(self):
    self.__packet_size = 24
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetFace
    self.trackerFace = int(0)  # ES_TrackerFace

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.trackerFace = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.trackerFace,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetLongSystemParamCT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = [12]
    self.__formats = [('<I q ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetLongSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter
    self.lParameter = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    self.lParameter = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet_elements += (self.lParameter,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetLongSystemParamRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetLongSystemParameter

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetLongSystemParamCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetLongSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetLongSystemParamRT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = [12]
    self.__formats = [('<I q ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetLongSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter
    self.lParameter = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    self.lParameter = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet_elements += (self.lParameter,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetObjectTemperatureCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetObjectTemperature

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetObjectTemperatureRT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = [8]
    self.__formats = [('<d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetObjectTemperature
    self.dObjectTemperature = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dObjectTemperature = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dObjectTemperature,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class ClearCommandQueueCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ClearCommandQueue
    self.clearQueueType = int(0)  # ES_ClearCommandQueueType

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.clearQueueType = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.clearQueueType,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class ClearCommandQueueRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_ClearCommandQueue

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetOverviewCameraInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetOverviewCameraInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetOverviewCameraInfoRT(object):
  def __init__(self):
    self.__packet_size = 92
    self.__sizes = [72]
    self.__formats = [('<I 32s i d d d i i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetOverviewCameraInfo
    self.cameraType = int(0)  # ES_OverviewCameraType
    self.cCameraName = str()  # 32 bytes max
    self.bIsColorCamera = int(0)
    self.dFocalLength = float(0)
    self.dHorizontalChipSize = float(0)
    self.dVerticalChipSize = float(0)
    self.bMirrorImageHz = int(0)
    self.bMirrorImageVt = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.cameraType = packet_elements[0]
    self.cCameraName = packet_elements[1]
    self.bIsColorCamera = packet_elements[2]
    self.dFocalLength = packet_elements[3]
    self.dHorizontalChipSize = packet_elements[4]
    self.dVerticalChipSize = packet_elements[5]
    self.bMirrorImageHz = packet_elements[6]
    self.bMirrorImageVt = packet_elements[7]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.cameraType,)
    packet_elements += (self.cCameraName,)
    packet_elements += (self.bIsColorCamera,)
    packet_elements += (self.dFocalLength,)
    packet_elements += (self.dHorizontalChipSize,)
    packet_elements += (self.dVerticalChipSize,)
    packet_elements += (self.bMirrorImageHz,)
    packet_elements += (self.bMirrorImageVt,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetDoubleSystemParamCT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = [4]
    self.__formats = [('<I ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetDoubleSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetDoubleSystemParamRT(object):
  def __init__(self):
    self.__packet_size = 32
    self.__sizes = [12]
    self.__formats = [('<I d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetDoubleSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter
    self.dParameter = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    self.dParameter = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet_elements += (self.dParameter,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetDoubleSystemParamCT(object):
  def __init__(self):
    self.__packet_size = 28
    self.__sizes = [12]
    self.__formats = [('<I d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetDoubleSystemParameter
    self.systemParam = int(0)  # ES_SystemParameter
    self.dParameter = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.systemParam = packet_elements[0]
    self.dParameter = packet_elements[1]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.systemParam,)
    packet_elements += (self.dParameter,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class SetDoubleSystemParamRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_SetDoubleSystemParameter

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class RestoreStartupConditionsCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_RestoreStartupConditions

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class RestoreStartupConditionsRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_RestoreStartupConditions

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GoAndMeasureCT(object):
  def __init__(self):
    self.__packet_size = 40
    self.__sizes = [24]
    self.__formats = [('<d d d ')]
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoAndMeasure
    self.dVal1 = float(0)
    self.dVal2 = float(0)
    self.dVal3 = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.dVal1 = packet_elements[0]
    self.dVal2 = packet_elements[1]
    self.dVal3 = packet_elements[2]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.dVal1,)
    packet_elements += (self.dVal2,)
    packet_elements += (self.dVal3,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GoAndMeasureRT(object):
  def __init__(self):
    self.__packet_size = 20
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GoAndMeasure

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetMeteoStationInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeteoStationInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetMeteoStationInfoRT(object):
  def __init__(self):
    self.__packet_size = 64
    self.__sizes = [44]
    self.__formats = [('<I 32s i i ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetMeteoStationInfo
    self.meteoStationType = int(0)  # ES_MeteoStationType
    self.cIdentifier = str()  # 32 bytes max
    self.iFirmwareMajorVersionNumber = int(0)
    self.iFirmwareMinorVersionNumber = int(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.meteoStationType = packet_elements[0]
    self.cIdentifier = packet_elements[1]
    self.iFirmwareMajorVersionNumber = packet_elements[2]
    self.iFirmwareMinorVersionNumber = packet_elements[3]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.meteoStationType,)
    packet_elements += (self.cIdentifier,)
    packet_elements += (self.iFirmwareMajorVersionNumber,)
    packet_elements += (self.iFirmwareMinorVersionNumber,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetAT4xxInfoCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetAT4xxInfo

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetAT4xxInfoRT(object):
  def __init__(self):
    self.__packet_size = 200
    self.__sizes = [180]
    self.__formats = [('<I 32s q q q q q q q q q q I I q d d d d d d ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetAT4xxInfo
    self.trackerType = int(0)  # ES_LTSensorType
    self.cTrackerName = str()  # 32 bytes max
    self.lSerialNumber = int(0)
    self.lMajorFirmwareVersion = int(0)
    self.lMinorFirmwareVersion = int(0)
    self.lProcessorBoardFWBuildNumber = int(0)
    self.lSensorBoardFWBuildNumber = int(0)
    self.lMajorOSVersion = int(0)
    self.lMinorOSVersion = int(0)
    self.lMajorServerSoftwareVersion = int(0)
    self.lMinorServerSoftwareVersion = int(0)
    self.lServerSoftwareBuildNumber = int(0)
    self.wlanType = int(0)  # ES_WLANType
    self.xscaleType = int(0)  # ES_TPMicroProcessorType
    self.lMinMeasureTime = int(0)
    self.dMinDistance = float(0)
    self.dMaxDistance = float(0)
    self.dStdDevDistOffsetADM = float(0)
    self.dStdDevAngleConst = float(0)
    self.dStdDevAngleOffset = float(0)
    self.dStdDevAngleFactor = float(0)

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.trackerType = packet_elements[0]
    self.cTrackerName = packet_elements[1]
    self.lSerialNumber = packet_elements[2]
    self.lMajorFirmwareVersion = packet_elements[3]
    self.lMinorFirmwareVersion = packet_elements[4]
    self.lProcessorBoardFWBuildNumber = packet_elements[5]
    self.lSensorBoardFWBuildNumber = packet_elements[6]
    self.lMajorOSVersion = packet_elements[7]
    self.lMinorOSVersion = packet_elements[8]
    self.lMajorServerSoftwareVersion = packet_elements[9]
    self.lMinorServerSoftwareVersion = packet_elements[10]
    self.lServerSoftwareBuildNumber = packet_elements[11]
    self.wlanType = packet_elements[12]
    self.xscaleType = packet_elements[13]
    self.lMinMeasureTime = packet_elements[14]
    self.dMinDistance = packet_elements[15]
    self.dMaxDistance = packet_elements[16]
    self.dStdDevDistOffsetADM = packet_elements[17]
    self.dStdDevAngleConst = packet_elements[18]
    self.dStdDevAngleOffset = packet_elements[19]
    self.dStdDevAngleFactor = packet_elements[20]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.trackerType,)
    packet_elements += (self.cTrackerName,)
    packet_elements += (self.lSerialNumber,)
    packet_elements += (self.lMajorFirmwareVersion,)
    packet_elements += (self.lMinorFirmwareVersion,)
    packet_elements += (self.lProcessorBoardFWBuildNumber,)
    packet_elements += (self.lSensorBoardFWBuildNumber,)
    packet_elements += (self.lMajorOSVersion,)
    packet_elements += (self.lMinorOSVersion,)
    packet_elements += (self.lMajorServerSoftwareVersion,)
    packet_elements += (self.lMinorServerSoftwareVersion,)
    packet_elements += (self.lServerSoftwareBuildNumber,)
    packet_elements += (self.wlanType,)
    packet_elements += (self.xscaleType,)
    packet_elements += (self.lMinMeasureTime,)
    packet_elements += (self.dMinDistance,)
    packet_elements += (self.dMaxDistance,)
    packet_elements += (self.dStdDevDistOffsetADM,)
    packet_elements += (self.dStdDevAngleConst,)
    packet_elements += (self.dStdDevAngleOffset,)
    packet_elements += (self.dStdDevAngleFactor,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class GetSystemSoftwareVersionCT(object):
  def __init__(self):
    self.__packet_size = 16
    self.__sizes = []
    self.__formats = []
    self.packetInfo = BasicCommandCT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemSoftwareVersion

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    return packet

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    return packet

class GetSystemSoftwareVersionRT(object):
  def __init__(self):
    self.__packet_size = 52
    self.__sizes = [32]
    self.__formats = [('<32s ')]
    self.packetInfo = BasicCommandRT()
    self.packetInfo.packetHeader.lPacketSize = self.__packet_size
    self.packetInfo.packetHeader.type = ES_DT_Command
    self.packetInfo.command = ES_C_GetSystemSoftwareVersion
    self.cSoftwareVersion = str()  # 32 bytes max

  def unpack(self, packet):
    packet = self.packetInfo.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self.__sizes[0]])
    self.cSoftwareVersion = packet_elements[0]
    return packet[self.__sizes[0]:]

  def pack(self):
    packet = b''
    packet += self.packetInfo.pack()
    packet_elements = ()
    packet_elements += (self.cSoftwareVersion,)
    packet += struct.Struct(self.__formats[0]).pack(*packet_elements)
    return packet

class LTPacketFactory(object):
  def packet(self, data):
    packet_header = PacketHeaderT()
    packet_header.unpack(data)
    packet_info = BasicCommandRT()
    packet = None
    if packet_header.type == ES_DT_Command:
      packet_info.unpack(data)
    if False:
      pass
    elif packet_header.type == ES_DT_NivelResult:
      packet = NivelResultT()
    elif packet_header.type == ES_DT_ReflectorPosResult:
      packet = ReflectorPosResultT()
    elif packet_header.type == ES_DT_SingleMeasResult:
      packet = SingleMeasResultT()
    elif packet_header.type == ES_DT_SingleMeasResult2:
      packet = SingleMeasResult2T()
    elif packet_header.type == ES_DT_SystemStatusChange:
      packet = SystemStatusChangeT()
    elif packet_header.type == ES_DT_Error:
      packet = ErrorResponseT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_Initialize:
      packet = InitializeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_ActivateCameraView:
      packet = ActivateCameraViewRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_Park:
      packet = ParkRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoBirdBath:
      packet = GoBirdBathRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoBirdBath2:
      packet = GoBirdBath2RT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_ChangeFace:
      packet = ChangeFaceRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_StartNivelMeasurement:
      packet = StartNivelMeasurementRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_StartMeasurement:
      packet = StartMeasurementRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_StopMeasurement:
      packet = StopMeasurementRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_ExitApplication:
      packet = ExitApplicationRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoLastMeasuredPoint:
      packet = GoLastMeasuredPointRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_FindReflector:
      packet = FindReflectorRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetCoordinateSystemType:
      packet = SetCoordinateSystemTypeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetCoordinateSystemType:
      packet = GetCoordinateSystemTypeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetMeasurementMode:
      packet = SetMeasurementModeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetMeasurementMode:
      packet = GetMeasurementModeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetSearchParams:
      packet = SetSearchParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetSearchParams:
      packet = GetSearchParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetStationaryModeParams:
      packet = SetStationaryModeParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetStationaryModeParams:
      packet = GetStationaryModeParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetSystemSettings:
      packet = SetSystemSettingsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetSystemSettings:
      packet = GetSystemSettingsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetUnits:
      packet = SetUnitsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetUnits:
      packet = GetUnitsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetSystemStatus:
      packet = GetSystemStatusRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetMeasurementStatusInfo:
      packet = GetMeasurementStatusInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetTrackerStatus:
      packet = GetTrackerStatusRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetReflector:
      packet = SetReflectorRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetReflectors:
      packet = GetReflectorsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetReflector:
      packet = GetReflectorRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetEnvironmentParams:
      packet = SetEnvironmentParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetEnvironmentParams:
      packet = GetEnvironmentParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetRefractionParams:
      packet = SetRefractionParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetRefractionParams:
      packet = GetRefractionParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetStationOrientationParams:
      packet = SetStationOrientationParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetStationOrientationParams:
      packet = GetStationOrientationParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetTransformationParams:
      packet = SetTransformationParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetTransformationParams:
      packet = GetTransformationParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoPosition:
      packet = GoPositionRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetDirection:
      packet = GetDirectionRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoPositionHVD:
      packet = GoPositionHVDRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_PointLaser:
      packet = PointLaserRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_PositionRelativeHV:
      packet = PositionRelativeHVRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_PointLaserHVD:
      packet = PointLaserHVDRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_MoveHV:
      packet = MoveHVRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoNivelPosition:
      packet = GoNivelPositionRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_CallOrientToGravity:
      packet = CallOrientToGravityRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetCompensation:
      packet = SetCompensationRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetCompensation:
      packet = GetCompensationRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetCompensations:
      packet = GetCompensationsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetCompensations2:
      packet = GetCompensations2RT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetStatisticMode:
      packet = SetStatisticModeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetStatisticMode:
      packet = GetStatisticModeRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetCameraParams:
      packet = SetCameraParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetCameraParams:
      packet = GetCameraParamsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetADMInfo2:
      packet = GetADMInfo2RT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetNivelInfo:
      packet = GetNivelInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetNivelInfo2:
      packet = GetNivelInfo2RT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetTPInfo:
      packet = GetTPInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetTrackerInfo:
      packet = GetTrackerInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetATRInfo:
      packet = GetATRInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetLaserOnTimer:
      packet = SetLaserOnTimerRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetLaserOnTimer:
      packet = GetLaserOnTimerRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetFace:
      packet = GetFaceRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetLongSystemParameter:
      packet = SetLongSystemParamRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetLongSystemParameter:
      packet = GetLongSystemParamRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetObjectTemperature:
      packet = GetObjectTemperatureRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_ClearCommandQueue:
      packet = ClearCommandQueueRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetOverviewCameraInfo:
      packet = GetOverviewCameraInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetDoubleSystemParameter:
      packet = GetDoubleSystemParamRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_SetDoubleSystemParameter:
      packet = SetDoubleSystemParamRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_RestoreStartupConditions:
      packet = RestoreStartupConditionsRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GoAndMeasure:
      packet = GoAndMeasureRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetMeteoStationInfo:
      packet = GetMeteoStationInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetAT4xxInfo:
      packet = GetAT4xxInfoRT()
    elif packet_header.type == ES_DT_Command and packet_info.command == ES_C_GetSystemSoftwareVersion:
      packet = GetSystemSoftwareVersionRT()
    return packet
