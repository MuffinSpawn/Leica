enum ES_LengthUnit
{
    ES_LU_Meter = 0, 
    ES_LU_Millimeter = 1, 
    ES_LU_Micron = 2, 
    ES_LU_Foot = 3, 
    ES_LU_Yard = 4, 
    ES_LU_Inch = 5
};

enum ES_AngleUnit
{
    ES_AU_Radian = 0, 
    ES_AU_Degree = 1, 
    ES_AU_Gon = 2
};

enum ES_TemperatureUnit
{
    ES_TU_Celsius = 0, 
    ES_TU_Fahrenheit = 1
};

enum ES_PressureUnit
{
   ES_PU_Mbar = 0,
   ES_PU_HPascal = 1,
   ES_PU_KPascal = 2, 
   ES_PU_MmHg = 3, 
   ES_PU_Psi = 4, 
   ES_PU_InH2O = 5, 
   ES_PU_InHg = 6, 
};

enum ES_HumidityUnit
{
    ES_HU_RH = 0, 
};

enum ES_CoordinateSystemType
{
    ES_CS_RHR = 0, 
    ES_CS_LHRX = 1, 
    ES_CS_LHRY = 2, 
    ES_CS_LHRZ = 3, 
    ES_CS_CCW = 4, 
    ES_CS_CCC = 5, 
    ES_CS_SCW = 6, 
    ES_CS_SCC = 7
};


enum ES_DataType
{
    ES_DT_Command = 0,
    ES_DT_Error = 1,
    ES_DT_SingleMeasResult = 2,
    ES_DT_NivelResult = 6,
    ES_DT_ReflectorPosResult = 7,
    ES_DT_SystemStatusChange = 8,
    ES_DT_SingleMeasResult2 = 9,
};

enum ES_Command
{
    ES_C_ExitApplication = 0,
    ES_C_GetSystemStatus = 1,
    ES_C_GetTrackerStatus = 2,
    ES_C_SetUnits = 5,
    ES_C_GetUnits = 6,
    ES_C_Initialize = 7,
    ES_C_ActivateCameraView = 9,
    ES_C_Park = 10,
    ES_C_SetStationOrientationParams = 12,
    ES_C_GetStationOrientationParams = 13,
    ES_C_SetTransformationParams = 14,
    ES_C_GetTransformationParams = 15,
    ES_C_SetEnvironmentParams = 20,
    ES_C_GetEnvironmentParams = 21,
    ES_C_SetRefractionParams = 22,
    ES_C_GetRefractionParams = 23,
    ES_C_SetMeasurementMode = 24,
    ES_C_GetMeasurementMode = 25,
    ES_C_SetCoordinateSystemType = 26,
    ES_C_GetCoordinateSystemType = 27,
    ES_C_SetStationaryModeParams = 28,
    ES_C_GetStationaryModeParams = 29,
    ES_C_SetReflector = 40,
    ES_C_GetReflector = 41,
    ES_C_GetReflectors = 42,
    ES_C_SetSearchParams = 43,
    ES_C_GetSearchParams = 44,
    ES_C_SetSystemSettings = 47,
    ES_C_GetSystemSettings = 48,
    ES_C_StartMeasurement = 49,
    ES_C_StartNivelMeasurement = 51,
    ES_C_StopMeasurement = 52,
    ES_C_ChangeFace = 53,
    ES_C_GoBirdBath = 54,
    ES_C_GoPosition = 55,
    ES_C_GoPositionHVD = 56,
    ES_C_PositionRelativeHV = 57,
    ES_C_PointLaser = 58,
    ES_C_PointLaserHVD = 59,
    ES_C_MoveHV = 60,
    ES_C_GoNivelPosition = 61,
    ES_C_GoLastMeasuredPoint = 62,
    ES_C_FindReflector = 63,
    ES_C_Unknown = 64,                              
    
    ES_C_GetDirection = 66,
    ES_C_CallOrientToGravity = 67,
    ES_C_SetCompensation = 79,
    ES_C_SetStatisticMode = 80,
    ES_C_GetStatisticMode = 81,
    ES_C_SetCameraParams = 83,
    ES_C_GetCameraParams = 84,
    

    ES_C_GetCompensation = 85,
    ES_C_GetCompensations = 86,
    ES_C_GetTPInfo = 90,
    ES_C_GetNivelInfo = 91,
    ES_C_SetLaserOnTimer = 92,
    ES_C_GetLaserOnTimer = 93,
    ES_C_GoBirdBath2 = 95,
    ES_C_GetFace = 98,


    ES_C_SetLongSystemParameter = 120,
    ES_C_GetLongSystemParameter = 121,
    ES_C_GetMeasurementStatusInfo = 122,
    ES_C_GetCompensations2 = 123,
    

    ES_C_SetDoubleSystemParameter = 125,
    ES_C_GetDoubleSystemParameter = 126,
    ES_C_GetObjectTemperature = 127,
    ES_C_GetOverviewCameraInfo = 129,                   
    ES_C_ClearCommandQueue = 130,
    ES_C_GetADMInfo2 = 131, 
    ES_C_GetTrackerInfo = 132,
    ES_C_GetNivelInfo2 = 133,
    ES_C_RestoreStartupConditions = 134,
    ES_C_GoAndMeasure = 135,


    ES_C_GetATRInfo = 138,
    ES_C_GetMeteoStationInfo = 139,    
    ES_C_GetAT4xxInfo = 140,
    

    ES_C_GetSystemSoftwareVersion = 142,           
};


enum ES_MeasMode
{
    ES_MM_Stationary = 0,
};


enum ES_TargetType
{
    ES_TT_Unknown = 0,
    ES_TT_CornerCube = 1,
    ES_TT_CatsEye = 2,
    ES_TT_GlassPrism = 3,
    ES_TT_RFIPrism = 4,
	ES_TT_RRR15 = 5,
	ES_TT_RRR05 = 6,
	ES_TT_BRR15 = 7,
	ES_TT_BRR05 = 8,
	ES_TT_TBR05 = 9,
};


enum ES_TrackerStatus
{
    ES_TS_NotReady = 0,
    ES_TS_Busy = 1,
    ES_TS_Ready = 2,
};


enum ES_ResultStatus
{
    ES_RS_AllOK = 0,
    ES_RS_ServerBusy = 1,
    ES_RS_NotImplemented = 2,
    ES_RS_WrongParameter = 3,
    ES_RS_WrongParameter1 = 4,
    ES_RS_WrongParameter2 = 5,
    ES_RS_WrongParameter3 = 6,
    ES_RS_WrongParameter4 = 7,
    ES_RS_WrongParameter5 = 8,
    ES_RS_WrongParameter6 = 9,
    ES_RS_WrongParameter7 = 10,
    ES_RS_Parameter1OutOfRangeOK = 11,
    ES_RS_Parameter1OutOfRangeNOK = 12,
    ES_RS_Parameter2OutOfRangeOK = 13,
    ES_RS_Parameter2OutOfRangeNOK = 14,
    ES_RS_Parameter3OutOfRangeOK = 15,
    ES_RS_Parameter3OutOfRangeNOK = 16,
    ES_RS_Parameter4OutOfRangeOK = 17,
    ES_RS_Parameter4OutOfRangeNOK = 18,
    ES_RS_Parameter5OutOfRangeOK = 19,
    ES_RS_Parameter5OutOfRangeNOK = 20,
    ES_RS_Parameter6OutOfRangeOK = 21,
    ES_RS_Parameter6OutOfRangeNOK = 22,
    ES_RS_WrongCurrentReflector = 23,
    ES_RS_NoTPFound = 26,
    ES_RS_NoWeathermonitorFound = 27,
    ES_RS_NoLastMeasuredPoint = 28,
    ES_RS_NoVideoCamera = 29,
    ES_RS_NoAdm = 30,
    ES_RS_NoNivel = 31,
    ES_RS_WrongTPFirmware = 32,
    ES_RS_UsageConflict = 35,
    ES_RS_Unknown = 36,


    ES_RS_NoDistanceSet = 37,
    ES_RS_NoTrackerConnected = 38,
    ES_RS_TrackerNotInitialized = 39,
    ES_RS_ModuleNotStarted = 40,
    ES_RS_ModuleTimedOut = 41,
    ES_RS_NotInCameraPosition = 44,
    ES_RS_WrongParameter8 = 47,
    ES_RS_WrongParameter9 = 48,
    ES_RS_WrongParameter10 = 49,
    ES_RS_WrongParameter11 = 50,
    ES_RS_WrongParameter12 = 51,
    ES_RS_WrongParameter13 = 52,
    ES_RS_WrongParameter14 = 53,
    ES_RS_WrongParameter15 = 54,
    ES_RS_WrongParameter16 = 55,


    ES_RS_NoSuchCompensation = 56,
    ES_RS_MeteoDataOutOfRange = 57,


    ES_RS_NoDataToImport = 90,
    ES_RS_NoTemperatureFromWM = 94,
    ES_RS_NoPressureFromWM = 95,
    ES_RS_NoHumidityFromWM = 96,


    ES_RS_InvalidInputData = 98,


    ES_RS_NoValidADMCompensation = 10002,
    ES_RS_PressureSensorProblem = 10003,
    ES_RS_MeasurementStatusNotReady = 10004,
    ES_RS_ADMStartUpBusy = 10005,


    ES_RS_NoAtr = 10007,
    ES_RS_NoOVC = 10008,
    ES_RS_NoStationaryResult = 10009,
    ES_RS_SensorNotLeveled = 10010,
    ES_RS_MultiConnectionsNotAllowed = 10011,


    ES_RS_SensorNotStable = 10013,
    ES_RS_SystemNotReadyForMeasurement = 10014,
    ES_RS_CommunicationWithSensorFailed = 10015,
    ES_RS_No_Sensor_Battery = 10016,
    ES_RS_CompensatorNotAllowed = 10017,
    ES_RS_WarmedUpStateReached = 10018,
    ES_RS_NotLeveledForInitialization = 10019,
    ES_RS_ADMHardwareProblem = 10020,
    ES_RS_ATRHardwareProblem = 10021,
};


enum ES_TrackerProcessorStatus
{
    ES_TPS_NoTPFound = 0,
    ES_TPS_TPFound = 1,
    ES_TPS_Booted = 3,
    ES_TPS_CompensationSet = 4,
    ES_TPS_Initialized = 5,
};


enum ES_LaserProcessorStatus
{
    ES_LPS_LaserReady = 3,
};


enum ES_ADMStatus
{
    ES_AS_ADMReady = 2,
};


enum ES_NivelStatus
{
    ES_NS_AllOK = 0,
    ES_NS_OutOfRangeOK = 1,
    ES_NS_OutOfRangeNOK = 2,
    ES_NS_NoNivel = 3,
};


enum ES_WeatherMonitorStatus
{
    ES_WMS_NotConnected = 0,
    ES_WMS_ReadOnly = 1,
    ES_WMS_ReadAndCalculateRefractions = 2,
};


enum ES_SystemStatusChange
{

    ES_SSC_EnvironmentParamsChanged = 2,
    ES_SSC_RefractionParamsChanged = 3,
    ES_SSC_SearchParamsChanged = 4,
    ES_SSC_AdmParamsChanged = 5,
    ES_SSC_UnitsChanged = 6,
    ES_SSC_ReflectorChanged = 7,
    ES_SSC_SystemSettingsChanged = 8,
    ES_SSC_TemperatureRangeChanged = 9,
    ES_SSC_CameraParamsChanged = 10,
    ES_SSC_CompensationChanged = 11,
    ES_SSC_CoordinateSystemTypeChanged = 12,
    ES_SSC_StationOrientationParamsChanged = 15,
    ES_SSC_TransformationParamsChanged = 16,
    ES_SSC_MeasurementModeChanged = 17,
    ES_SSC_StationaryModeParamsChanged = 18,
    ES_SSC_StatisticModeChanged = 24,
    ES_SSC_MeasStatus_NotReady = 25,
    ES_SSC_MeasStatus_Busy = 26,
    ES_SSC_MeasStatus_Ready = 27,
    ES_SSC_IsFace1 = 30,
    ES_SSC_IsFace2 = 31,
    ES_SSC_ObjectTemperatureChanged = 105,               
    ES_SSC_ProbeButton1Down = 110,
    ES_SSC_ProbeButton1Up = 111,
    ES_SSC_ProbeButton2Down = 120,
    ES_SSC_ProbeButton2Up = 121,
    ES_SSC_ProbeButton3Down = 130,
    ES_SSC_ProbeButton3Up = 131,
    ES_SSC_ProbeButton4Down = 140,
    ES_SSC_ProbeButton4Up = 141,
    

    ES_SCC_InitializationStatusChanged = 151,
    ES_SCC_TiltSensorStatusChanged = 152,
    

    ES_SSC_EmsysFilesImported = 820,     


    ES_SSC_SensorDetected = 850,     
    ES_SSC_SensorDisconnected = 851,     


    ES_SSC_CompensatorStatusChanged = 852,
    ES_SSC_BatteryStatusChanged = 853,
    
    ES_SSC_TPConnectionClosing = 997,
    ES_SSC_ServerClosing = 998,
    ES_SSC_ServerStarted = 999,
};


enum ES_NivelPosition
{
    ES_NP_Pos1 = 0,
    ES_NP_Pos2 = 1,
    ES_NP_Pos3 = 2,
    ES_NP_Pos4 = 3,
};


enum ES_StatisticMode
{
    ES_SM_Standard = 0,
    ES_SM_Extended = 1,
};


enum ES_TrackerProcessorType
{
    ES_TT_Undefined = 0,
    ES_TT_ATC400 = 20,
};


enum ES_TPMicroProcessorType
{
    ES_TPM_Undefined = 0,
    ES_TPM_PXA250 = 20,
};


enum ES_LTSensorType
{
    ES_LTS_Undefined = 0,
    ES_LTS_AT401 = 70,
    ES_LTS_NoSensor = 99,
};


enum ES_TrackerFace
{
    ES_TF_Unknown = 0,
    ES_TF_Face1 = 1,
    ES_TF_Face2 = 2,
};

enum ES_ProbeButtonEvent
{
    ES_PBE_DisableEvents = 0,
    ES_PBE_EnableEvents = 1,
};

enum ES_PowerLockMode
{
    ES_PLM_InDoor = 0,
    ES_PLM_OutDoor = 1,
    ES_PLM_OutDoor_LongRange = 2,
};

enum ES_SystemParameter
{
    ES_SP_KeepLastPositionFlag = 0,
    ES_SP_WeatherMonitorSetting = 1,
    ES_SP_DisplayReflectorPosition = 10,
    ES_SP_ProbeConfig_ButtonEvent = 51,
    ES_SP_TcpCommandQueueSize = 200,
    ES_SP_PowerLockFunctionAvailable = 410,
    ES_SP_PowerLockFunctionActive = 411,
    ES_SP_PowerLockMode = 450,
    ES_SP_D_SystemLongest3DDistanceADM = 1101,
    ES_SP_AT4xxControllerBatteryStatus = 5000,
    ES_SP_AT4xxSensorBatteryStatus = 5001,
    ES_SP_AT4xxInclinationSensorState = 5002,
};

enum ES_MeasurementStatusInfo
{
    ES_MSI_Unknown = 0,
    ES_MSI_TrackerFound = 1,
    ES_MSI_TrackerCompensationFound = 2,
    ES_MSI_ADMFound = 4,
    ES_MSI_ADMCompensationFound = 8,
    ES_MSI_ReflectorFound = 2048,
    ES_MSI_InFace1 = 4096,
    ES_MSI_SensorBatteryMounted = 16384,
    ES_MSI_NivelInWorkingRange = 32768,
    ES_MSI_Initialized = 65536,
};

enum ES_ClearCommandQueueType
{
    ES_CCQ_ClearOwnOnly = 0,
    ES_CCQ_ClearAll = 1,
};

enum ES_OverviewCameraType
{
    ES_OCT_Unknown = 0,
    ES_OCT_Classic = 1,
    ES_OCT_AT4xx_Integrated = 20,                  
};

enum ES_ADMType
{
    ES_AMT_Unknown = 0,
    ES_AMT_LeicaADM2 = 3,
};

enum ES_ATRType
{
    ES_ATR_None = 0,
    ES_ATR_4 = 1,
    ES_ATR_5i = 2,
};

enum ES_TrkAccuracyModel
{
    ES_TAM_Unknown = 0,
    ES_TAM_2005 = 1,
};

enum ES_NivelType
{
    ES_NT_Unknown = 0,
    ES_NT_NivelAT4xx = 3,
};

enum ES_MeteoStationType
{
    ES_MST_None = 0,
    ES_MST_Thommen = 1,
    ES_MST_AT = 2,
};

enum ES_WLANType
{
    ES_WLAN_None = 0,
    ES_WLAN_OWL211 = 1,
    ES_WLAN_OWL221 = 2,
};

enum ES_InclinationSensorState
{
    ES_ISS_Off = 0,
    ES_ISS_ApplyCorrections = 2,
};


struct PacketHeaderT
{
    long             lPacketSize;
    enum ES_DataType type;
};


struct ReturnDataT
{
    struct PacketHeaderT packetHeader;
    enum ES_ResultStatus status;   
};


struct BasicCommandCT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
};

struct BasicCommandRT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
    enum ES_ResultStatus status;
};



struct NivelResultT
{
    struct ReturnDataT  packetInfo;
    enum ES_NivelStatus nivelStatus;
    double              dXTilt;
    double              dYTilt;
    double              dNivelTemperature;
};

struct ReflectorPosResultT
{
    struct ReturnDataT packetInfo;
    double             dVal1;
    double             dVal2;
    double             dVal3;
};


struct SingleMeasResultT
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dVal1;
    double             dVal2;
    double             dVal3;
    double             dStd1;
    double             dStd2;
    double             dStd3;
    double             dStdTotal;
    double             dPointingError1;
    double             dPointingError2;
    double             dPointingError3;
    double             dAprioriStd1;
    double             dAprioriStd2;
    double             dAprioriStd3;
    double             dAprioriStdTotal;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
};


struct SingleMeasResult2T
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dVal1;
    double             dVal2;
    double             dVal3;
    double             dStd1;
    double             dStd2;
    double             dStd3;
    double             dStdTotal;
    double             dCovar12;
    double             dCovar13;
    double             dCovar23;
    double             dPointingErrorH;
    double             dPointingErrorV;
    double             dPointingErrorD;
    double             dAprioriStd1;
    double             dAprioriStd2;
    double             dAprioriStd3;
    double             dAprioriStdTotal;
    double             dAprioriCovar12;
    double             dAprioriCovar13;
    double             dAprioriCovar23;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
};


struct SystemStatusChangeT
{
    struct PacketHeaderT       packetHeader;
    enum ES_SystemStatusChange systemStatusChange;
};

struct ErrorResponseT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
    enum ES_ResultStatus status;
};





struct InitializeCT
{
    struct BasicCommandCT packetInfo;
};

struct InitializeRT
{
    struct BasicCommandRT packetInfo;
};


struct ActivateCameraViewCT
{
    struct BasicCommandCT packetInfo;
};

struct ActivateCameraViewRT
{
    struct BasicCommandRT packetInfo;
};


struct ParkCT
{
    struct BasicCommandCT packetInfo;
};

struct ParkRT
{
    struct BasicCommandRT packetInfo;
};


struct GoBirdBathCT
{
    struct BasicCommandCT packetInfo;
};

struct GoBirdBathRT
{
    struct BasicCommandRT packetInfo;
};



struct GoBirdBath2CT
{
    struct BasicCommandCT packetInfo;
    int               bClockWise;
};

struct GoBirdBath2RT
{
    struct BasicCommandRT packetInfo;
};


struct ChangeFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct ChangeFaceRT
{
    struct BasicCommandRT packetInfo;
};


struct StartNivelMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartNivelMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct StartMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct StopMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StopMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct ExitApplicationCT
{
    struct BasicCommandCT packetInfo;
};

struct ExitApplicationRT
{
    struct BasicCommandRT packetInfo;
};



struct GoLastMeasuredPointCT
{
    struct BasicCommandCT packetInfo;
};

struct GoLastMeasuredPointRT
{
    struct BasicCommandRT packetInfo;
};



struct FindReflectorCT
{
    struct BasicCommandCT packetInfo;
    double                dAproxDistance;
};

struct FindReflectorRT
{
    struct BasicCommandRT packetInfo;
};



struct SetCoordinateSystemTypeCT
{
    struct BasicCommandCT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};

struct SetCoordinateSystemTypeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCoordinateSystemTypeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCoordinateSystemTypeRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};



struct SetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
    enum ES_MeasMode      measMode;
};

struct SetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
    enum ES_MeasMode      measMode;
};



struct SearchParamsDataT
{
    double dSearchRadius;
    long   lTimeOut;
};

struct SetSearchParamsCT
{
    struct BasicCommandCT    packetInfo;
    struct SearchParamsDataT searchParams;
};

struct SetSearchParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSearchParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSearchParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct SearchParamsDataT searchParams;
};



struct StationaryModeDataT
{
    long    lMeasTime;
    int bUseADM;
};

struct SetStationaryModeParamsCT
{
    struct BasicCommandCT      packetInfo;
    struct StationaryModeDataT stationaryModeData;
};

struct SetStationaryModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStationaryModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationaryModeParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct StationaryModeDataT stationaryModeData;
};



struct SystemSettingsDataT
{
    enum ES_WeatherMonitorStatus weatherMonitorStatus;
    int                      bApplyTransformationParams;
    int                      bApplyStationOrientationParams;
    int                      bKeepLastPosition;
    int                      bSendUnsolicitedMessages;
    int                      bSendReflectorPositionData;
    int                      bTryMeasurementMode;
    int                      bHasNivel;
    int                      bHasVideoCamera;
};                                  

struct SetSystemSettingsCT
{
    struct BasicCommandCT      packetInfo;
    struct SystemSettingsDataT systemSettings;
};

struct SetSystemSettingsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSystemSettingsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSettingsRT
{
    struct BasicCommandRT      packetInfo;
    struct SystemSettingsDataT systemSettings;
};



struct SystemUnitsDataT
{
    enum ES_LengthUnit      lenUnitType;
    enum ES_AngleUnit       angUnitType;
    enum ES_TemperatureUnit tempUnitType;
    enum ES_PressureUnit    pressUnitType;
    enum ES_HumidityUnit    humUnitType;
};

struct SetUnitsCT
{
    struct BasicCommandCT   packetInfo;
    struct SystemUnitsDataT unitsSettings;
};

struct SetUnitsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetUnitsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetUnitsRT
{
    struct BasicCommandRT   packetInfo;
    struct SystemUnitsDataT unitsSettings;
};



struct ESVersionNumberT
{
    int iMajorVersionNumber;
    int iMinorVersionNumber;
    int iBuildNumber;
    
};

struct GetSystemStatusCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemStatusRT
{
    struct BasicCommandRT          packetInfo;
    enum ES_ResultStatus           lastResultStatus;
    enum ES_TrackerProcessorStatus trackerProcessorStatus;
    enum ES_LaserProcessorStatus   laserStatus;
    enum ES_ADMStatus              admStatus;
    struct ESVersionNumberT        esVersionNumber;
    enum ES_WeatherMonitorStatus   weatherMonitorStatus;
    long                           lFlagsValue;
    long                           lTrackerSerialNumber;
};                                



struct GetMeasurementStatusInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementStatusInfoRT
{
    struct BasicCommandRT packetInfo;
    enum ES_ResultStatus  lastResultStatus;
    long                  lMeasurementStatusInfo;
};                                



struct GetTrackerStatusCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerStatusRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerStatus trackerStatus;
};



struct SetReflectorCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalReflectorId;
};

struct SetReflectorRT
{
    struct BasicCommandRT packetInfo;
};



struct GetReflectorsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetReflectorsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalReflectors;
    int                   iInternalReflectorId;
    enum ES_TargetType    targetType;
    double                dSurfaceOffset;
    unsigned short        cReflectorName[32];
};



struct GetReflectorCT
{
    struct BasicCommandCT packetInfo;
};

struct GetReflectorRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalReflectorId;
};



struct EnvironmentDataT
{
    double dTemperature;
    double dPressure;
    double dHumidity;
};

struct SetEnvironmentParamsCT
{
    struct BasicCommandCT   packetInfo;
    struct EnvironmentDataT environmentData;
};

struct SetEnvironmentParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetEnvironmentParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetEnvironmentParamsRT
{
    struct BasicCommandRT   packetInfo;
    struct EnvironmentDataT environmentData;
};



struct RefractionDataT
{
    double dIfmRefractionIndex;
    double dAdmRefractionIndex;
};

struct SetRefractionParamsCT
{
    struct BasicCommandCT  packetInfo;
    struct RefractionDataT refractionData;
};

struct SetRefractionParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetRefractionParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetRefractionParamsRT
{
    struct BasicCommandRT  packetInfo;
    struct RefractionDataT refractionData;
};



struct StationOrientationDataT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dRot1;
    double dRot2;
    double dRot3;
};

struct SetStationOrientationParamsCT
{
    struct BasicCommandCT          packetInfo;
    struct StationOrientationDataT stationOrientation;
};

struct SetStationOrientationParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStationOrientationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationOrientationParamsRT
{
    struct BasicCommandRT          packetInfo;
    struct StationOrientationDataT stationOrientation;
};



struct TransformationDataT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dRot1;
    double dRot2;
    double dRot3;
    double dScale;
};

struct SetTransformationParamsCT
{
    struct BasicCommandCT      packetInfo;
    struct TransformationDataT transformationData;
};

struct SetTransformationParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTransformationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTransformationParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct TransformationDataT transformationData;
};



struct GoPositionCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
    int               bUseADM;
};

struct GoPositionRT
{
    struct BasicCommandRT packetInfo;
};



struct GetDirectionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetDirectionRT
{
    struct BasicCommandRT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
};



struct GoPositionHVDCT
{
    struct BasicCommandCT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
    double                dDistance;
    int               bUseADM;
};

struct GoPositionHVDRT
{
    struct BasicCommandRT packetInfo;
};



struct PointLaserCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};

struct PointLaserRT
{
    struct BasicCommandRT packetInfo;
};



struct PositionRelativeHVCT
{
    struct BasicCommandCT packetInfo;
    double                dHzVal;
    double                dVtVal;
};

struct PositionRelativeHVRT
{
    struct BasicCommandRT packetInfo;
};



struct PointLaserHVDCT
{
    struct BasicCommandCT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
    double                dDistance;
};

struct PointLaserHVDRT
{
    struct BasicCommandRT packetInfo;
};



struct MoveHVCT
{
    struct BasicCommandCT packetInfo;
    int                   iHzSpeed;
    int                   iVtSpeed;
};

struct MoveHVRT
{
    struct BasicCommandRT packetInfo;
};



struct GoNivelPositionCT
{
    struct BasicCommandCT packetInfo;
    enum ES_NivelPosition nivelPosition;
};

struct GoNivelPositionRT
{
    struct BasicCommandRT packetInfo;
};



struct CallOrientToGravityCT
{
    struct BasicCommandCT packetInfo;
};

struct CallOrientToGravityRT
{
    struct BasicCommandRT packetInfo;
    double                dOmega;
    double                dPhi;
};



struct SetCompensationCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalCompensationId;
};

struct SetCompensationRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalCompensationId;
};



struct GetCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];
    unsigned short        cTrackerCompensationComment[128];
    unsigned short        cADMCompensationName[32];
    int               bHasMeasurementCameraMounted;
};



struct GetCompensations2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensations2RT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];
    unsigned short        cTrackerCompensationComment[128];
    unsigned short        cADMCompensationName[32];
    unsigned short        cADMCompensationComment[128];
    int               bHasMeasurementCameraMounted;
    int               bIsActive;
};


struct SetStatisticModeCT
{
    struct BasicCommandCT   packetInfo;
    enum   ES_StatisticMode stationaryMeasurements;
    enum   ES_StatisticMode continuousMeasurements;
};

struct SetStatisticModeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStatisticModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStatisticModeRT
{
    struct BasicCommandRT   packetInfo;
    enum   ES_StatisticMode stationaryMeasurements;
    enum   ES_StatisticMode continuousMeasurements;
};



struct CameraParamsDataT
{
    int iContrast;
    int iBrightness;
    int iSaturation;
};

struct SetCameraParamsCT
{
    struct BasicCommandCT    packetInfo;
    struct CameraParamsDataT cameraParams;
};

struct SetCameraParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCameraParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCameraParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct CameraParamsDataT cameraParams;
};



struct GetADMInfo2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetADMInfo2RT
{
    struct BasicCommandRT packetInfo;
    enum ES_ADMType       admType;
    unsigned short        cADMName[32];
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMaxDistance;
    double                dMinDistance;
    int                   iMaxDataRate;
    double                dAccuracyADMDistance;
};



struct GetNivelInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetNivelInfoRT
{
    struct BasicCommandRT packetInfo;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    long                  lSerialNumber;
};

struct GetNivelInfo2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetNivelInfo2RT
{
    struct BasicCommandRT packetInfo;
    enum ES_NivelType     nivelType;
    unsigned short        cNivelName[32];
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMeasurementRange;
    double                dMeasurementAccuracyOffset;
    double                dMeasurementAccuracyFactor;                
};



struct GetTPInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTPInfoRT
{
    struct BasicCommandRT        packetInfo;
    int                          iTPBootMajorVersionNumber;
    int                          iTPBootMinorVersionNumber;
    int                          iTPFirmwareMajorVersionNumber;
    int                          iTPFirmwareMinorVersionNumber;
    int                          iLCPFirmwareMajorVersionNumber;
    int                          iLCPFirmwareMinorVersionNumber;
    enum ES_TrackerProcessorType trackerprocessorType;
    enum ES_TPMicroProcessorType microProcessorType;
    int                          iMicroProcessorClockSpeed;
    enum ES_LTSensorType         laserTrackerSensorType;
};



struct GetTrackerInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_LTSensorType     trackerType;
    unsigned short           cTrackerName[32];
    long                     lSerialNumber;
    long                     lCompensationIdNumber;
    int                  bHasADM;
    int                  bHasOverviewCamera;
    int                  bHasNivel;
    double                   dNivelMountOffset;
    double                   dMaxDistance;
    double                   dMinDistance;
    int                      iMaxDataRate;
    int                      iNumberOfFaces;
    double                   dHzAngleRange;
    double                   dVtAngleRange;
    enum ES_TrkAccuracyModel accuracyModel;
    int                      iMajLCPFirmwareVersion;
    int                      iMinLCPFirmwareVersion;
};



struct GetATRInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetATRInfoRT
{
    struct BasicCommandRT packetInfo;
    enum ES_ATRType       atrType;
    unsigned short        cATRName[32];
    long                  lMajFirmwareVersion;
    long                  lMinFirmwareVersion;
    long                  lBuildFirmwareVersion;
    long                  lHardwareVersion;
    long                  lErrorcode;
    long                  lFPGAVersion;
    double                dMaxDistance;
    double                dMinDistance;
    double                dFieldOfView;
    double                dMaxTrackingSpeed;
};



struct SetLaserOnTimerCT
{
    struct BasicCommandCT packetInfo;
    int                   iLaserOnTimeOffsetHour;
    int                   iLaserOnTimeOffsetMinute;
};

struct SetLaserOnTimerRT
{
    struct BasicCommandRT packetInfo;
};



struct GetLaserOnTimerCT
{
    struct BasicCommandCT packetInfo;
};

struct GetLaserOnTimerRT
{
    struct BasicCommandRT packetInfo;
    int                   iLaserOnTimeOffsetHour;
    int                   iLaserOnTimeOffsetMinute;
};



struct GetFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct GetFaceRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerFace   trackerFace;
};



struct SetLongSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
    long                    lParameter;
};

struct SetLongSystemParamRT
{
    struct BasicCommandRT packetInfo;
};



struct GetLongSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
};

struct GetLongSystemParamRT
{
    struct BasicCommandRT   packetInfo;
    enum ES_SystemParameter systemParam;
    long                    lParameter;
};



struct GetObjectTemperatureCT
{
    struct BasicCommandCT packetInfo;
};

struct GetObjectTemperatureRT
{
    struct BasicCommandRT packetInfo;
    double                dObjectTemperature;
};



struct ClearCommandQueueCT
{
    struct BasicCommandCT         packetInfo;
    enum ES_ClearCommandQueueType clearQueueType;
};

struct ClearCommandQueueRT
{
    struct BasicCommandRT packetInfo;
};



struct GetOverviewCameraInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetOverviewCameraInfoRT
{
    struct BasicCommandRT      packetInfo;
    enum ES_OverviewCameraType cameraType;
    unsigned short             cCameraName[32];
    int                    bIsColorCamera;
    double                     dFocalLength;
    double                     dHorizontalChipSize;
    double                     dVerticalChipSize;
    int                    bMirrorImageHz;
    int                    bMirrorImageVt;
};



struct GetDoubleSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
};

struct GetDoubleSystemParamRT
{
    struct BasicCommandRT   packetInfo;
    enum ES_SystemParameter systemParam;
    double                  dParameter;
};



struct SetDoubleSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
    double                  dParameter;
};

struct SetDoubleSystemParamRT
{
    struct BasicCommandRT packetInfo;
};



struct RestoreStartupConditionsCT
{
    struct BasicCommandCT packetInfo;
};

struct RestoreStartupConditionsRT
{
    struct BasicCommandRT packetInfo;
};



struct GoAndMeasureCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};

struct GoAndMeasureRT
{
    struct BasicCommandRT packetInfo;
};



struct GetMeteoStationInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeteoStationInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_MeteoStationType meteoStationType;
    unsigned short           cIdentifier[32];
    int                      iFirmwareMajorVersionNumber;
    int                      iFirmwareMinorVersionNumber;
};



struct GetAT4xxInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetAT4xxInfoRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_LTSensorType         trackerType;
    unsigned short               cTrackerName[32];
    long                         lSerialNumber;
    long                         lMajorFirmwareVersion;
    long                         lMinorFirmwareVersion;
    long                         lProcessorBoardFWBuildNumber;
    long                         lSensorBoardFWBuildNumber;
    long                         lMajorOSVersion;
    long                         lMinorOSVersion;
    long                         lMajorServerSoftwareVersion;
    long                         lMinorServerSoftwareVersion;
    long                         lServerSoftwareBuildNumber;
    enum ES_WLANType             wlanType;
    enum ES_TPMicroProcessorType xscaleType;
    long                         lMinMeasureTime;
    double                       dMinDistance;
    double                       dMaxDistance;
    double                       dStdDevDistOffsetADM;
    double                       dStdDevAngleConst;
    double                       dStdDevAngleOffset;
    double                       dStdDevAngleFactor;
};



struct GetSystemSoftwareVersionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSoftwareVersionRT
{
    struct BasicCommandRT packetInfo;
    unsigned short        cSoftwareVersion[32];
};
