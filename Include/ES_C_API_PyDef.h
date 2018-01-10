
/******************************************************************************

Copyright (C) Leica Geosystems AG, 2001..2011

Filename: ES_C_API_Def.h 

Description: C- Application Programming Interface for Leica Embedded Systems

Notes: 
This file only comprises the interface for AT4xx 3D Tracker- types.            
It is an extract of the related full-featured include file (of same name)      
that is delivered with the emScon SDK). Applications addressing other tracker- 
types than AT4xx need to include the full-featured include file instead.       

******************************************************************************/ 

#ifndef ES_C_API_DEF_H
#define ES_C_API_DEF_H

// These symbols allow checking against correct include file versions.
// Note: TPI/SDK Version not necessarily matches EmScon server version!
//
// EmScon TPI/SDK Version V3.6
//
#define ES_API_MAJOR_VERSION  3
#define ES_API_MINOR_VERSION  6

// An application can define this symbol if interested in  
// version definitions only (mainly for Leica internal use)
#ifndef ES_API_VERSION_INC_ONLY

#include "Enum.h" /* include 'Enum.h' PAST version symbol definition */

// For managed CPP applications, enum definitions require 
// to be prefixed with a 'public __value' directive. 
// To achieve this, define preprocessor symbol 'ES_MCPP_SUPPORT'
// prior to inclusion of file 'es_c_api_def.h'.
// 
#undef ES_API
#ifdef ES_MCPP_SUPPORT
   #define ES_API public __value
#else
   #define ES_API
#endif

/////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
// new byte alignment == 4, save old value on stack
#pragma pack (push, 4)
#elif defined __linux__
#pragma pack (4)
#endif

// No boolean data type is available in C-language. By convention, 'int' is used
// in C for boolean variables. For convenience, the ES API defines an 'ES_BOOL'.
// In order to remain platform-independent, it must be of type 'int' (4 Bytes)'.
// Do not use 'BOOL' for not to conflict with Microsoft- specific type (2 Bytes!)!
//
typedef int ES_BOOL;

// New additional range for error numbers
#define ES_API_ERROR_OFFSET 10000

/////////////////////////////////////////////////////////////////////////////

// Enumeration Types:

/**
Identify the data used in the API calls over the TCP/IP communication
**/
ES_API enum ES_DataType
{
    ES_DT_Command = 0,
    ES_DT_Error = 1,
    ES_DT_SingleMeasResult = 2,
    ES_DT_NivelResult = 6,
    ES_DT_ReflectorPosResult = 7,
    ES_DT_SystemStatusChange = 8,
    ES_DT_SingleMeasResult2 = 9,
	ES_DT_Unknown = 99,  // shouldn't get this
};

/**
The embedded system supports these commands
**/
ES_API enum ES_Command
{
    ES_C_ExitApplication = 0,                      // stop (exit) the embedded system
    ES_C_GetSystemStatus = 1,                      // frequently used information
    ES_C_GetTrackerStatus = 2,                     // seldom used information
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
    ES_C_FindReflector = 63,                       // searches a reflector at the given position
    ES_C_Unknown = 64,                              
    
    // New commands added for release V1.1 / V1.2
    ES_C_GetDirection = 66,                        // get direction even without reflector locked on
    ES_C_CallOrientToGravity = 67,                 // starts the orient to gravity process
    ES_C_SetCompensation = 79,                     // set's the last calculated compensation as the active one
    ES_C_SetStatisticMode = 80,                    // set's the amount of statistical information returned by the system
    ES_C_GetStatisticMode = 81,                    // get's the statistical setting
    ES_C_SetCameraParams = 83,                     // adjust video camera parameters
    ES_C_GetCameraParams = 84,                     // read the current video camera parameters            
    
    // New commands added for release V1.3 / V1.4 
    ES_C_GetCompensation = 85,                     // read the currently active compensation ID
    ES_C_GetCompensations = 86,                    // read all compensations stored in the database
    ES_C_GetTPInfo = 90,
    ES_C_GetNivelInfo = 91,
    ES_C_SetLaserOnTimer = 92,                     // switch the laser on in ... time
    ES_C_GetLaserOnTimer = 93,                     // read the remining time until it is switched on
    ES_C_GoBirdBath2 = 95,                         // GoBirdBath with selection (clockwise / counter clockwise)
    ES_C_GetFace = 98,                             // returns the current face (Face1 / Face2)

    // New commands added for release V2.0 / V2.1
    ES_C_SetLongSystemParameter = 120,
    ES_C_GetLongSystemParameter = 121,
    ES_C_GetMeasurementStatusInfo = 122,
    ES_C_GetCompensations2 = 123,                  // enhanced read all compensations stored in the database
    
    // New commands added for release V2.3 / V2.4
    ES_C_SetDoubleSystemParameter = 125,
    ES_C_GetDoubleSystemParameter = 126,
    ES_C_GetObjectTemperature = 127,               // read the object temperature
    ES_C_GetOverviewCameraInfo = 129,                   
    ES_C_ClearCommandQueue = 130,                  // clear the command queue
    ES_C_GetADMInfo2 = 131, 
    ES_C_GetTrackerInfo = 132,
    ES_C_GetNivelInfo2 = 133,
    ES_C_RestoreStartupConditions = 134,
    ES_C_GoAndMeasure = 135,                       // AutoInspect type of operation

    // New commands added for release V3.5 
    ES_C_GetATRInfo = 138,
    ES_C_GetMeteoStationInfo = 139,    
    ES_C_GetAT4xxInfo = 140,
    
    // New commands added for release V3.6
    ES_C_GetSystemSoftwareVersion = 142,           
};

/**
The currently implemented measurement modes
**/
ES_API enum ES_MeasMode
{
    ES_MM_Stationary = 0,
};

/**
The known taraget types (prism types)
**/
ES_API enum ES_TargetType
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

/**
Ready status of laser tracker. This information is typically used to display the
status to the user (red green yellow) 
**/
ES_API enum ES_TrackerStatus
{
    ES_TS_NotReady = 0,
    ES_TS_Busy = 1,
    ES_TS_Ready = 2,
};

/**
Result status values. Generated as answer to function calls via API
**/
ES_API enum ES_ResultStatus
{
    ES_RS_AllOK = 0,
    ES_RS_ServerBusy = 1,                          // a pending command
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

    // New status values added for V1.1 / V1.2
    ES_RS_NoDistanceSet = 37,
    ES_RS_NoTrackerConnected = 38,
    ES_RS_TrackerNotInitialized = 39,              // sensor is not initialized
    ES_RS_ModuleNotStarted = 40,                   // an internal client (module) could not be started
    ES_RS_ModuleTimedOut = 41,                     // an internal client (module) did not finish in time
    ES_RS_NotInCameraPosition = 44,                // Camera can not be used in this position
    ES_RS_WrongParameter8 = 47,
    ES_RS_WrongParameter9 = 48,
    ES_RS_WrongParameter10 = 49,
    ES_RS_WrongParameter11 = 50,
    ES_RS_WrongParameter12 = 51,
    ES_RS_WrongParameter13 = 52,
    ES_RS_WrongParameter14 = 53,
    ES_RS_WrongParameter15 = 54,
    ES_RS_WrongParameter16 = 55,

    // New status values added for V1.3 / V1.4
    ES_RS_NoSuchCompensation = 56,                 // the selected compensation does not exist
    ES_RS_MeteoDataOutOfRange = 57,

    // New status values added for V2.0 / V2.1
    ES_RS_NoDataToImport = 90,
    ES_RS_NoTemperatureFromWM = 94,
    ES_RS_NoPressureFromWM = 95,
    ES_RS_NoHumidityFromWM = 96,

    // New status values added for V2.3 / V2.4
    ES_RS_InvalidInputData = 98,

    // New status values added for V3.0
    ES_RS_NoValidADMCompensation = ES_API_ERROR_OFFSET + 2,
    ES_RS_PressureSensorProblem = ES_API_ERROR_OFFSET + 3,
    ES_RS_MeasurementStatusNotReady = ES_API_ERROR_OFFSET + 4,
    ES_RS_ADMStartUpBusy = ES_API_ERROR_OFFSET + 5,    // for Sensors w/o Interferometer - alias to AIFMStartUpBusy (from V3.6 and up)

    // New status values added for V3.5
    ES_RS_NoAtr = ES_API_ERROR_OFFSET + 7,
    ES_RS_NoOVC = ES_API_ERROR_OFFSET + 8,
    ES_RS_NoStationaryResult = ES_API_ERROR_OFFSET + 9,
    ES_RS_SensorNotLeveled = ES_API_ERROR_OFFSET + 10,
    ES_RS_MultiConnectionsNotAllowed = ES_API_ERROR_OFFSET + 11,

    // New status values added for V3.6
    ES_RS_SensorNotStable = ES_API_ERROR_OFFSET + 13,
    ES_RS_SystemNotReadyForMeasurement = ES_API_ERROR_OFFSET + 14,
    ES_RS_CommunicationWithSensorFailed = ES_API_ERROR_OFFSET + 15,
    ES_RS_No_Sensor_Battery = ES_API_ERROR_OFFSET + 16,
    ES_RS_CompensatorNotAllowed = ES_API_ERROR_OFFSET + 17,
    ES_RS_WarmedUpStateReached = ES_API_ERROR_OFFSET + 18,
    ES_RS_NotLeveledForInitialization = ES_API_ERROR_OFFSET + 19,
    ES_RS_ADMHardwareProblem = ES_API_ERROR_OFFSET + 20,
    ES_RS_ATRHardwareProblem = ES_API_ERROR_OFFSET + 21,
};

/**
Information about the laser tracker during startup. 

  The sequence of this enum is important. It shows the state of the laser tracker processor during 
  the startup of the embedded system.
  
    The tracker is only ready if it was initialized
    it is only initialized if it has a valid compensation
    it can only have a valid compensation if it was booted
    it can only be booted if there was a connection between 
    the embedded system and the laser tracker and this 
    connection is only possible if there is a laser tracker
**/
ES_API enum ES_TrackerProcessorStatus
{
    ES_TPS_NoTPFound = 0,
    ES_TPS_TPFound = 1,
    ES_TPS_Booted = 3,
    ES_TPS_CompensationSet = 4,
    ES_TPS_Initialized = 5,
};

/**
Additional information about the laser processor in the laser tracker
**/
ES_API enum ES_LaserProcessorStatus
{
    ES_LPS_LaserReady = 3,
};

/**
Additional information about the absolute distance meter in the laser tracker
**/
ES_API enum ES_ADMStatus
{
    ES_AS_ADMReady = 2,
};

/**
Additional information about the nivel sensor connected to the laser tracker
**/
ES_API enum ES_NivelStatus
{
    ES_NS_AllOK = 0,
    ES_NS_OutOfRangeOK = 1,
    ES_NS_OutOfRangeNOK = 2,
    ES_NS_NoNivel = 3,
};

/**
Additional information about the weather monitor connected to the embedded system
**/
ES_API enum ES_WeatherMonitorStatus
{
    ES_WMS_NotConnected = 0,
    ES_WMS_ReadOnly = 1,
    ES_WMS_ReadAndCalculateRefractions = 2,
};

/**
System changes originated by the embedded system
**/
ES_API enum ES_SystemStatusChange
{
    // New events added for releases V1.3 .. V2.3
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
    
    // New events added for release V3.6
    ES_SCC_InitializationStatusChanged = 151,      // Note the typing error: this should read ES_SSC instead of ES_SCC...
    ES_SCC_TiltSensorStatusChanged = 152,          // ...nevertheless, for compatibility reasons, leave this unchanged. 
    
    // New events added for release V2.3           // Note that items of this enum are ordered by theîr values, not by their release- time)
    ES_SSC_EmsysFilesImported = 820,     

    // New events added for release V3.5           // Note that items of this enum are ordered by theîr values, not by their release- time)
    ES_SSC_SensorDetected = 850,     
    ES_SSC_SensorDisconnected = 851,     

    // New events added for release V3.6
    ES_SSC_CompensatorStatusChanged = 852,         // compensator was switched ON / OFF
    ES_SSC_BatteryStatusChanged = 853,             // battery capacity has changed
    
    ES_SSC_TPConnectionClosing = 997,
    ES_SSC_ServerClosing = 998,
    ES_SSC_ServerStarted = 999,
};

/**
Positions used to drive to during a orient to gravity procedure
**/
ES_API enum ES_NivelPosition
{
    ES_NP_Pos1 = 0,
    ES_NP_Pos2 = 1,
    ES_NP_Pos3 = 2,
    ES_NP_Pos4 = 3,
};

/**
The possible statistics mode selections
applicable to stationary and continuous mode measurements
**/
ES_API enum ES_StatisticMode
{
    ES_SM_Standard = 0,
    ES_SM_Extended = 1,
};

/**
The different tracker processor controller types
**/
ES_API enum ES_TrackerProcessorType
{
    ES_TT_Undefined = 0,
    ES_TT_ATC400 = 20,
};

/**
The possible tracker controller micro processor types
**/
ES_API enum ES_TPMicroProcessorType
{
    ES_TPM_Undefined = 0,
    ES_TPM_PXA250 = 20,
};

/**
The implemented sensor types
**/
ES_API enum ES_LTSensorType
{
    ES_LTS_Undefined = 0,
    ES_LTS_AT401 = 70,
    ES_LTS_NoSensor = 99,
};

/**
The GetFace command returns one of the following values
**/
ES_API enum ES_TrackerFace
{
    ES_TF_Unknown = 0,
    ES_TF_Face1 = 1,
    ES_TF_Face2 = 2,
};

ES_API enum ES_ProbeButtonEvent
{
    ES_PBE_DisableEvents = 0,                      // no button events are send
    ES_PBE_EnableEvents = 1,                       // server sends button events
};

ES_API enum ES_PowerLockMode
{
    ES_PLM_InDoor = 0,
    ES_PLM_OutDoor = 1,
    ES_PLM_OutDoor_LongRange = 2,
};

ES_API enum ES_SystemParameter
{
    ES_SP_KeepLastPositionFlag = 0,                // 0 = OFF; 1 = ON
    ES_SP_WeatherMonitorSetting = 1,               // see ES_WeatherMonitorStatus
    ES_SP_DisplayReflectorPosition = 10,           // 0 = OFF; 1 = ON
    ES_SP_ProbeConfig_ButtonEvent = 51,            // see enum ES_ProbeButtonEvent
    ES_SP_TcpCommandQueueSize = 200,               // 0 = OFF 1..10 queue size
    ES_SP_PowerLockFunctionAvailable = 410,        // 0 = NO ; 1 = YES, Power Lock functionality is available
    ES_SP_PowerLockFunctionActive = 411,           // 0 = NO ; 1 = YES Power Lock functionality is active
    ES_SP_PowerLockMode = 450,                     // see enum ES_PowerLockMode
    ES_SP_D_SystemLongest3DDistanceADM = 1101,     // Get only! Longest distance system can measure
    ES_SP_AT4xxControllerBatteryStatus = 5000,     // Get only; 0 .. 100%; 110% ==> external power; 120% ==> PoE (power over Ethernet)
    ES_SP_AT4xxSensorBatteryStatus = 5001,         // Get only; 0 .. 100%; 110% ==> external power
    ES_SP_AT4xxInclinationSensorState = 5002,      // valid states see ES_InclinationSensorState
};

ES_API enum ES_MeasurementStatusInfo
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

ES_API enum ES_ClearCommandQueueType
{
    ES_CCQ_ClearOwnOnly = 0,                       // clear only own commands from queue. all others are left
    ES_CCQ_ClearAll = 1,                           // clear all commands on queue
};

ES_API enum ES_OverviewCameraType
{
    ES_OCT_Unknown = 0,
    ES_OCT_Classic = 1,
    ES_OCT_AT4xx_Integrated = 20,                  
};

ES_API enum ES_ADMType
{
    ES_AMT_Unknown = 0,
    ES_AMT_LeicaADM2 = 3,                          // ADM of AT401 tracker series
};

ES_API enum ES_ATRType
{
    ES_ATR_None = 0,
    ES_ATR_4 = 1,
    ES_ATR_5i = 2,                                 // ATR of AT401 tracker series
};

ES_API enum ES_TrkAccuracyModel
{
    ES_TAM_Unknown = 0,
    ES_TAM_2005 = 1,
};

ES_API enum ES_NivelType
{
    ES_NT_Unknown = 0,
    ES_NT_NivelAT4xx = 3,
};

ES_API enum ES_MeteoStationType
{
    ES_MST_None = 0,
    ES_MST_Thommen = 1,
    ES_MST_AT = 2,
};

ES_API enum ES_WLANType
{
    ES_WLAN_None = 0,
    ES_WLAN_OWL211 = 1,
    ES_WLAN_OWL221 = 2,
};

ES_API enum ES_InclinationSensorState
{
    ES_ISS_Off = 0,
    ES_ISS_ApplyCorrections = 2,
};

/////////////////////////////////////////////////////////////////////////////

// Data- types used as sub- and helper- structs for some command- structs:

// C- structures defined here are not suitable for managed C++ 
#ifndef ES_MCPP_SUPPORT

/**
Basic structure that is base of all data transmitted on the network
**/
struct PacketHeaderT
{
    long             lPacketSize;
    enum ES_DataType type;
};

/**
General data type used with all data packets on the network
**/
struct ReturnDataT
{
    struct PacketHeaderT packetHeader;
    enum ES_ResultStatus status;   
};

/**
General data type used with all commands that do not contain parameters
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Result packet sent after a Nivel measurement was carried out
**/
struct NivelResultT
{
    struct ReturnDataT  packetInfo;
    enum ES_NivelStatus nivelStatus;
    double              dXTilt;
    double              dYTilt;
    double              dNivelTemperature;
};

/**
Result packet sent whenever the tracker is locked onto a reflector
this "measurements" can be switched on/off
**/
struct ReflectorPosResultT
{
    struct ReturnDataT packetInfo;
    double             dVal1;
    double             dVal2;
    double             dVal3;
};

/**
Result packet sent after a Single Point measurement was carried out
**/
struct SingleMeasResultT
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    ES_BOOL            bIsTryMode;
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

/**
Result packet sent after a Single Point measurement was carried out
in addition to SingleMeasResultT it contains additional statiscical information
**/
struct SingleMeasResult2T
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    ES_BOOL            bIsTryMode;
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

/**
Packet sent after a system status change
**/
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

/////////////////////////////////////////////////////////////////////////////

// Command data- types (structs):

struct InitializeCT
{
    struct BasicCommandCT packetInfo;
};

struct InitializeRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct ActivateCameraViewCT
{
    struct BasicCommandCT packetInfo;
};

struct ActivateCameraViewRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct ParkCT
{
    struct BasicCommandCT packetInfo;
};

struct ParkRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct GoBirdBathCT
{
    struct BasicCommandCT packetInfo;
};

struct GoBirdBathRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Drive to BirdBath clock- or counter clock wise
**/
struct GoBirdBath2CT
{
    struct BasicCommandCT packetInfo;
    ES_BOOL               bClockWise;
};

struct GoBirdBath2RT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct ChangeFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct ChangeFaceRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct StartNivelMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartNivelMeasurementRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct StartMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartMeasurementRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct StopMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StopMeasurementRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
struct ExitApplicationCT
{
    struct BasicCommandCT packetInfo;
};

struct ExitApplicationRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Return to the last measured (single point mode) point
**/
struct GoLastMeasuredPointCT
{
    struct BasicCommandCT packetInfo;
};

struct GoLastMeasuredPointRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Call the FindReflector command
**/
struct FindReflectorCT
{
    struct BasicCommandCT packetInfo;
    double                dAproxDistance;
};

struct FindReflectorRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the active coordinate system type
**/
struct SetCoordinateSystemTypeCT
{
    struct BasicCommandCT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};

struct SetCoordinateSystemTypeRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the active coordinate system type
**/
struct GetCoordinateSystemTypeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCoordinateSystemTypeRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the active measurement mode
**/
struct SetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
    enum ES_MeasMode      measMode;
};

struct SetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the active measurement mode
**/
struct GetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
    enum ES_MeasMode      measMode;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the parameters for the search functionality
**/
struct SearchParamsDataT
{
    double dSearchRadius;
    long   lTimeOut;                               // in milliseconds
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the parameters for the search functionality
**/
struct GetSearchParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSearchParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct SearchParamsDataT searchParams;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the parameters for the stationary measurement mode
**/
struct StationaryModeDataT
{
    long    lMeasTime;
    ES_BOOL bUseADM;                               // Caution: has no effect in 6D mode and for AT4xx trackers !
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the parameters for the stationary measurement mode
**/
struct GetStationaryModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationaryModeParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct StationaryModeDataT stationaryModeData;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set system specific settings

bApplyTransformationParams: 
if this flag TRUE, the embedded system tranforms the measurements into
a user specified coordinate system. If FALSE, the specified system is ignored.

bApplyStationOrientationParams:
if this flag TRUE, the embedded system uses the given orientation parameters. If  FALSE 
the station orientation will be 0.0, 0.0, 0.0, 0.0, 0.0, 0.0.

bKeepLastPosition:
If this flag is TRUE, the laser does not leave the current position after the laser
beam is broken. If the flag is FALSE, the laser moves to a save position or if a video camera
is installed, the sensor drives into the video position.

bSendUnsolicitedMessages:
If this flag is TRUE, the system sends error messages at all times (when they occur). 

bSendReflectorPositionData:
If this flag is TRUE, the system sends (at a rate of up to 10 measurements per second) the
current reflector position. This only happens, if a reflector is locked on by the tracker.

weatherMonitorStatus:
This parameter represents the possible modes for the weather monitor. 

bTryMeasurementMode:
With this flag set to TRUE, the system delivers all results in the try mode.

bHasNivel:
This flag tells the system that a nivel sensor is mounted. Measurements with this sensor are
now possible.

bHasVideoCamera:
This flag tells the system that a video camera is mounted.
**/
struct SystemSettingsDataT
{
    enum ES_WeatherMonitorStatus weatherMonitorStatus;
    ES_BOOL                      bApplyTransformationParams;
    ES_BOOL                      bApplyStationOrientationParams;
    ES_BOOL                      bKeepLastPosition;
    ES_BOOL                      bSendUnsolicitedMessages;
    ES_BOOL                      bSendReflectorPositionData;
    ES_BOOL                      bTryMeasurementMode;
    ES_BOOL                      bHasNivel;
    ES_BOOL                      bHasVideoCamera;
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current system settings
**/
struct GetSystemSettingsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSettingsRT
{
    struct BasicCommandRT      packetInfo;
    struct SystemSettingsDataT systemSettings;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the current system units
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current system units
**/
struct GetUnitsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetUnitsRT
{
    struct BasicCommandRT   packetInfo;
    struct SystemUnitsDataT unitsSettings;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current system status
**/
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
    long                           lFlagsValue;                     // Always 0 (zero) in AT401 use GetMeasurementStatusInfo
    long                           lTrackerSerialNumber;
};                                

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current circle status
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current laser tracker status
**/
struct GetTrackerStatusCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerStatusRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerStatus trackerStatus;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the current reflector
**/
struct SetReflectorCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalReflectorId;
};

struct SetReflectorRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current reflector
**/
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
    unsigned short        cReflectorName[32];      // reflector name as UNICODE string
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current reflector
**/
struct GetReflectorCT
{
    struct BasicCommandCT packetInfo;
};

struct GetReflectorRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalReflectorId;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the current temperature, pressure and humidity
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current temperature, pressure and humidity.
If the weather monitor is active, the internal values are updated at a regular interval.
**/
struct GetEnvironmentParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetEnvironmentParamsRT
{
    struct BasicCommandRT   packetInfo;
    struct EnvironmentDataT environmentData;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the current refraction data
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current refraction values.
**/
struct GetRefractionParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetRefractionParamsRT
{
    struct BasicCommandRT  packetInfo;
    struct RefractionDataT refractionData;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the current station orientation parameters
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current station orientation parameters
**/
struct GetStationOrientationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationOrientationParamsRT
{
    struct BasicCommandRT          packetInfo;
    struct StationOrientationDataT stationOrientation;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the transformation parameters
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the transformation parameters
**/
struct GetTransformationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTransformationParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct TransformationDataT transformationData;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GoPosition command
The input parameter are according to the selected coordinate system type
**/
struct GoPositionCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
    ES_BOOL               bUseADM;
};

struct GoPositionRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetDirectionCT command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GoPosition command
The input parameter are always in a spherical coordinate system type
**/
struct GoPositionHVDCT
{
    struct BasicCommandCT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
    double                dDistance;
    ES_BOOL               bUseADM;
};

struct GoPositionHVDRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the Laser Pointer command
The input parameter are according to the selected coordinate system type
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the PositionRelative command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the LaserPointer command
The input parameter are alwasy in a spherical coordinate system type
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the MoveHV command
The input parameter are a vertical or horizontal speed value between
1% and 100% ot the total speed of the tracker.
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the NivelMove command
The input parameter are the defined nivel positions (1 to 4). The laser tracker moves at a much 
slower speed. This is to avoid disturbing the nivel sensor.

  This command is used for the orient to gravity procedure.
**/
struct GoNivelPositionCT
{
    struct BasicCommandCT packetInfo;
    enum ES_NivelPosition nivelPosition;
};

struct GoNivelPositionRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the OrientToGravity process
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the SetCompensation command
this command clears the drive point list used for the intermediate compensation
**/
struct SetCompensationCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalCompensationId;
};

struct SetCompensationRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the currently active compensation ID
**/
struct GetCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalCompensationId;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read all the compensations currently 
stored in the systems database
**/
struct GetCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];      // tracker compensation name as UNICODE string
    unsigned short        cTrackerCompensationComment[128];  // comment in UNICODE
    unsigned short        cADMCompensationName[32];          // ADM compensation name as UNICODE string
    ES_BOOL               bHasMeasurementCameraMounted;      // Used for 6D systems
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read all the compensations currently 
stored in the systems database
**/
struct GetCompensations2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensations2RT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];      // tracker compensation name as UNICODE string
    unsigned short        cTrackerCompensationComment[128];  // comment in UNICODE
    unsigned short        cADMCompensationName[32];          // ADM compensation name as UNICODE string
    unsigned short        cADMCompensationComment[128];      // comment in UNICODE
    ES_BOOL               bHasMeasurementCameraMounted;      // Used for 6D systems
    ES_BOOL               bIsActive;                         // Will be used in this configuration
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the SetStatisticMode command
This command selects the amount of statistical information returned by the 
system for stationary and/or continuous measurement modes
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetStatisticMode command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the parameters for the video camera
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the parameters for the video camera
**/
struct GetCameraParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCameraParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct CameraParamsDataT cameraParams;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get additional ADM diagnostic data
Only works with the device connected and selected
**/
struct GetADMInfo2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetADMInfo2RT
{
    struct BasicCommandRT packetInfo;
    enum ES_ADMType       admType;
    unsigned short        cADMName[32];                  // UNICODE string
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMaxDistance;                  // maximal ADM distance
    double                dMinDistance;                  // minimal ADM distance
    int                   iMaxDataRate;                  // measurements per second
    double                dAccuracyADMDistance;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get additional Nivel diagnostic data
Only works with the device connected and selected
**/
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
    unsigned short        cNivelName[32];                // UNICODE string
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMeasurementRange;             // +- in radians
    double                dMeasurementAccuracyOffset;    // Accuracy = Offset + (Facor * Reading)
    double                dMeasurementAccuracyFactor;                
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get additional TP diagnostic data
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get Tracker features data
**/
struct GetTrackerInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_LTSensorType     trackerType;
    unsigned short           cTrackerName[32];           // UNICODE string
    long                     lSerialNumber;
    long                     lCompensationIdNumber;      // identifies the compensation
    ES_BOOL                  bHasADM;
    ES_BOOL                  bHasOverviewCamera;
    ES_BOOL                  bHasNivel;
    double                   dNivelMountOffset;
    double                   dMaxDistance;               // maximal distance for laser
    double                   dMinDistance;               // minimal distance for laser
    int                      iMaxDataRate;               // measurements per second
    int                      iNumberOfFaces;
    double                   dHzAngleRange;              // e.g.: +/- 240
    double                   dVtAngleRange;
    enum ES_TrkAccuracyModel accuracyModel;
    int                      iMajLCPFirmwareVersion;
    int                      iMinLCPFirmwareVersion;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get ATR diagnostic data
**/
struct GetATRInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetATRInfoRT
{
    struct BasicCommandRT packetInfo;
    enum ES_ATRType       atrType;
    unsigned short        cATRName[32];                  // UNICODE string
    long                  lMajFirmwareVersion;
    long                  lMinFirmwareVersion;
    long                  lBuildFirmwareVersion;
    long                  lHardwareVersion;
    long                  lErrorcode;                    // 0 ==> All OK
    long                  lFPGAVersion;
    double                dMaxDistance;
    double                dMinDistance;
    double                dFieldOfView;
    double                dMaxTrackingSpeed;             // 0.0 ==> stationary only
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set the time (hour, minute) when the laser will
be switched on by the system (must be running). 
The input is rounded to the nearest 15 minutes
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the time (hour, minute) until the laser will
be switched on. This value is ZERO after a system restart.
The value is rounded to the nearest 15 minutes
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read the current laser tracker face information
**/
struct GetFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct GetFaceRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerFace   trackerFace;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to set an individual system parameter
See ES_SystemParameter for possible parameters
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to read an individual system parameter
See ES_SystemParameter for possible parameters
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetObjTemperature command
**/
struct GetObjectTemperatureCT
{
    struct BasicCommandCT packetInfo;
};

struct GetObjectTemperatureRT
{
    struct BasicCommandRT packetInfo;
    double                dObjectTemperature;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the ClearCommandQueue command
**/
struct ClearCommandQueueCT
{
    struct BasicCommandCT         packetInfo;
    enum ES_ClearCommandQueueType clearQueueType;
};

struct ClearCommandQueueRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetOverviewCameraInfo command
**/
struct GetOverviewCameraInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetOverviewCameraInfoRT
{
    struct BasicCommandRT      packetInfo;
    enum ES_OverviewCameraType cameraType;
    unsigned short             cCameraName[32];    // UNICODE strings
    ES_BOOL                    bIsColorCamera;
    double                     dFocalLength;
    double                     dHorizontalChipSize;
    double                     dVerticalChipSize;
    ES_BOOL                    bMirrorImageHz;
    ES_BOOL                    bMirrorImageVt;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetDoubleSystemParameter command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the SetDoubleSystemParameter command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the RestoreStartupConditions command
**/
struct RestoreStartupConditionsCT
{
    struct BasicCommandCT packetInfo;
};

struct RestoreStartupConditionsRT
{
    struct BasicCommandRT packetInfo;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GoAndMeasure command
**/
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get additional meteo station data
Only works with the device connected and switched on
**/
struct GetMeteoStationInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeteoStationInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_MeteoStationType meteoStationType;
    unsigned short           cIdentifier[32];      // UNICODE string
    int                      iFirmwareMajorVersionNumber;
    int                      iFirmwareMinorVersionNumber;
};

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to get AT4xx sensor information
Only works with the device connected and switched on
**/
struct GetAT4xxInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetAT4xxInfoRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_LTSensorType         trackerType;
    unsigned short               cTrackerName[32]; // UNICODE string
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

/////////////////////////////////////////////////////////////////////////////
/**
Use this data type to call the GetSystemSoftwareVersion command
**/
struct GetSystemSoftwareVersionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSoftwareVersionRT
{
    struct BasicCommandRT packetInfo;
    unsigned short        cSoftwareVersion[32]; // UNICODE string
};

#endif /* ES_MCPP_SUPPORT */

/////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
// restore old byte alignment from stack
#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////

#endif /* ES_API_VERSION_INC_ONLY */

#endif /* ES_C_API_DEF_H */
