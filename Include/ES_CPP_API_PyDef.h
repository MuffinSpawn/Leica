
/******************************************************************************

Copyright (C) Leica Geosystems AG, 2001..2011

Filename: ES_CPP_API_Def.h 

Description: C++ Application Programming Interface for Leica Embedded Systems

Notes: 
This file only comprises the interface for AT4xx 3D Tracker- types.            
It is an extract of the related full-featured include file (of same name)      
that is delivered with the emScon SDK). Applications addressing other tracker- 
types than AT4xx need to include the full-featured include file instead.       

******************************************************************************/ 

#ifndef ES_CPP_API_DEF_H
#define ES_CPP_API_DEF_H

#include <iostream>

// Including ES_C_API_Def.h into IDL file causes redefinition of enums/structs.
// By defining _C_API_INC_THROUGH_IDL prior to inclusion of es_cpp_api_def.h
// this can be prevented. Only an issue for COM objects using es_cpp_api_def.
//  
#ifndef _C_API_INC_THROUGH_IDL
   #include "ES_C_API_Def.h" /* Include prior to version definition */

   #define ES_CPP_API_MAJOR_VERSION 3  /* EmScon TPI/SDK V3.6 - Note: TPI/SDK Version..  */ 
   #define ES_CPP_API_MINOR_VERSION 6  /* not necessarily matches EmScon server version! */

   #if ES_API_MAJOR_VERSION != ES_CPP_API_MAJOR_VERSION
      // #error Version conflict with EmScon API definition file (ES_C_API_Def.h) !
   #endif
   #if ES_API_MINOR_VERSION != ES_CPP_API_MINOR_VERSION
      // #error Version conflict with EmScon API definition file (ES_C_API_Def.h)!
   #endif
#endif

// Ignore this macro in non- mfc environments
#ifndef TRACE
#define TRACE(s) 
#define TRACE2(s, x, y) 
#endif

// Ignore non- standard C++ extensions if not available (for non Microsoft/non MFC platforms) 
#ifndef _T
#define _T(s) s
#endif

// Ignore this macro in non- mfc environments
#ifndef ASSERT
#define ASSERT(a)
#endif


// define ES_USE_EMSCON_NAMESPACE if you wish to use the EmScon namespace
#ifdef ES_USE_EMSCON_NAMESPACE
namespace   EmScon
{
#endif

/////////////////////////////////////////////////////////////////////////////
class CInitialize
{
public:
   inline CInitialize()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(InitializeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_Initialize;
   };
   
   InitializeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CActivateCameraView
{
public:
   inline CActivateCameraView()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(ActivateCameraViewCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_ActivateCameraView;
   };
   
   ActivateCameraViewCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CPark
{
public:
   inline CPark()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(ParkCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_Park;
   };
   
   ParkCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetCoordinateSystemType
{
public:
   inline CSetCoordinateSystemType(ES_CoordinateSystemType coordSysType)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetCoordinateSystemTypeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetCoordinateSystemType;
      DataPacket.coordSysType = coordSysType;
   };
   
   SetCoordinateSystemTypeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetCoordinateSystemType
{
public:
   inline CGetCoordinateSystemType()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetCoordinateSystemTypeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetCoordinateSystemType;
   };
   
   GetCoordinateSystemTypeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetMeasurementMode
{
public:
   inline CSetMeasurementMode(ES_MeasMode Mode)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetMeasurementModeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetMeasurementMode;
      DataPacket.measMode = Mode;
   };
   
   SetMeasurementModeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetMeasurementMode
{
public:
   inline CGetMeasurementMode()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetMeasurementModeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetMeasurementMode;
   };
   
   GetMeasurementModeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetStationaryModeParams
{
public:
   inline CSetStationaryModeParams(StationaryModeDataT stationaryModeData)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetStationaryModeParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetStationaryModeParams;
      DataPacket.stationaryModeData = stationaryModeData;
   };
   
   inline CSetStationaryModeParams(long lMeasTime, 
                                   bool bUseADM)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetStationaryModeParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetStationaryModeParams;
      DataPacket.stationaryModeData.lMeasTime = lMeasTime;
      DataPacket.stationaryModeData.bUseADM = bUseADM;
   };
   
   SetStationaryModeParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetStationaryModeParams
{
public:
   inline CGetStationaryModeParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetStationaryModeParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetStationaryModeParams;
   };
   
   GetStationaryModeParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CFindReflector
{
public:
   inline CFindReflector(double dAproxDistance)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(FindReflectorCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_FindReflector;
      DataPacket.dAproxDistance = dAproxDistance;
   };
   
   FindReflectorCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetReflector
{
public:
   inline CSetReflector(int iInternalReflectorId)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetReflectorCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetReflector;
      DataPacket.iInternalReflectorId = iInternalReflectorId;
   };
   
   SetReflectorCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetReflectors
{
public:
   inline CGetReflectors()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetReflectorsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetReflectors;
   };
   
   GetReflectorsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetReflector
{
public:
   inline CGetReflector()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetReflectorCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetReflector;
   };
   
   GetReflectorCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetUnits
{
public:
   inline CSetUnits(SystemUnitsDataT unitsSettings)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetUnitsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetUnits;
      DataPacket.unitsSettings = unitsSettings;
   };
   
   inline CSetUnits(ES_LengthUnit      lenUnitType,
                    ES_AngleUnit       angUnitType,
                    ES_TemperatureUnit tempUnitType,
                    ES_PressureUnit    pressUnitType,
                    ES_HumidityUnit    humUnitType)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetUnitsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetUnits;
      DataPacket.unitsSettings.lenUnitType = lenUnitType;
      DataPacket.unitsSettings.angUnitType = angUnitType;
      DataPacket.unitsSettings.tempUnitType = tempUnitType;
      DataPacket.unitsSettings.pressUnitType = pressUnitType;
      DataPacket.unitsSettings.humUnitType = humUnitType;
   };
   
   SetUnitsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetUnits
{
public:
   inline CGetUnits()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetUnitsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetUnits;
   };
   
   GetUnitsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetSystemStatus
{
public:
   inline CGetSystemStatus()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetSystemStatusCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetSystemStatus;
   };
   
   GetSystemStatusCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetTrackerStatus
{
public:
   inline CGetTrackerStatus()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetTrackerStatusCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetTrackerStatus;
   };
   
   GetTrackerStatusCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetEnvironmentParams
{
public:
   inline CSetEnvironmentParams(EnvironmentDataT environmentData)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetEnvironmentParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetEnvironmentParams;
      DataPacket.environmentData = environmentData;
   };
   
   inline CSetEnvironmentParams(double dTemperature, 
                                double dPressure, 
                                double dHumidity)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetEnvironmentParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetEnvironmentParams;
      DataPacket.environmentData.dTemperature = dTemperature;
      DataPacket.environmentData.dPressure = dPressure;
      DataPacket.environmentData.dHumidity = dHumidity;
   };
   
   SetEnvironmentParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetEnvironmentParams
{
public:
   inline CGetEnvironmentParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetEnvironmentParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetEnvironmentParams;
   };
   
   GetEnvironmentParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetRefractionParams
{
public:
   inline CSetRefractionParams(RefractionDataT refractionData)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetRefractionParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetRefractionParams;
      DataPacket.refractionData.dIfmRefractionIndex = refractionData.dIfmRefractionIndex;
      DataPacket.refractionData.dAdmRefractionIndex = refractionData.dAdmRefractionIndex;
   };
   
   inline CSetRefractionParams(double dIfmRefractionIndex, 
                               double dAdmRefractionIndex)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetRefractionParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetRefractionParams;
      DataPacket.refractionData.dIfmRefractionIndex = dIfmRefractionIndex;
      DataPacket.refractionData.dAdmRefractionIndex = dAdmRefractionIndex;
   };
   
   SetRefractionParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetRefractionParams
{
public:
   inline CGetRefractionParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetRefractionParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetRefractionParams;
   };
   
   GetRefractionParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetSearchParams
{
public:
   inline CSetSearchParams(SearchParamsDataT searchParams)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetSearchParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetSearchParams;
      DataPacket.searchParams.dSearchRadius = searchParams.dSearchRadius;
      DataPacket.searchParams.lTimeOut = searchParams.lTimeOut;
   };
   
   inline CSetSearchParams(double dSearchRadius, 
                           long lTimeOut)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetSearchParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetSearchParams;
      DataPacket.searchParams.dSearchRadius = dSearchRadius;
      DataPacket.searchParams.lTimeOut = lTimeOut;
   };
   
   SetSearchParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetSearchParams
{
public:
   inline CGetSearchParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetSearchParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetSearchParams;
   };
   
   GetSearchParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetSystemSettings
{
public:
   inline CSetSystemSettings(SystemSettingsDataT systemSettings)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetSystemSettingsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetSystemSettings;
      DataPacket.systemSettings = systemSettings;
   };
   
   inline CSetSystemSettings(bool bApplyTransformationParams,
                             bool bApplyStationOrientationParams,
                             bool bKeepLastPosition,
                             bool bSendUnsolicitedMessages,
                             bool bSendReflectorPositionData,
                             bool bHasNivel,
                             bool bHasVideoCamera,
                             bool bTryMeasurementMode,
                             ES_WeatherMonitorStatus weatherMonitorStatus)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetSystemSettingsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetSystemSettings;
      DataPacket.systemSettings.bApplyTransformationParams = bApplyTransformationParams;
      DataPacket.systemSettings.bApplyStationOrientationParams = bApplyStationOrientationParams;
      DataPacket.systemSettings.bKeepLastPosition  = bKeepLastPosition;
      DataPacket.systemSettings.bSendUnsolicitedMessages = bSendUnsolicitedMessages;
      DataPacket.systemSettings.bSendReflectorPositionData = bSendReflectorPositionData;
      DataPacket.systemSettings.bTryMeasurementMode = bTryMeasurementMode;
      DataPacket.systemSettings.bHasNivel = bHasNivel;
      DataPacket.systemSettings.bHasVideoCamera = bHasVideoCamera;
      DataPacket.systemSettings.weatherMonitorStatus = weatherMonitorStatus;
   };
   
   SetSystemSettingsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetSystemSettings
{
public:
   inline CGetSystemSettings()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetSystemSettingsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetSystemSettings;
   };
   
   GetSystemSettingsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetStationOrientationParams
{
public:
   inline CSetStationOrientationParams(StationOrientationDataT stationOrientation)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetStationOrientationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetStationOrientationParams;
      DataPacket.stationOrientation = stationOrientation;
   };
   
   inline CSetStationOrientationParams(double dVal1, 
                                       double dVal2, 
                                       double dVal3, 
                                       double dRot1, 
                                       double dRot2, 
                                       double dRot3)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetStationOrientationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetStationOrientationParams;
      DataPacket.stationOrientation.dVal1 = dVal1;
      DataPacket.stationOrientation.dVal2 = dVal2;
      DataPacket.stationOrientation.dVal3 = dVal3;
      DataPacket.stationOrientation.dRot1 = dRot1;
      DataPacket.stationOrientation.dRot2 = dRot2;
      DataPacket.stationOrientation.dRot3 = dRot3;
   };
   
   SetStationOrientationParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetStationOrientationParams
{
public:
   inline CGetStationOrientationParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetStationOrientationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetStationOrientationParams;
   };
   
   GetStationOrientationParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetTransformationParams
{
public:
   inline CSetTransformationParams(double dVal1, 
                                   double dVal2, 
                                   double dVal3, 
                                   double dRot1, 
                                   double dRot2, 
                                   double dRot3, 
                                   double dScale)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetTransformationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetTransformationParams;
      DataPacket.transformationData.dVal1 = dVal1;
      DataPacket.transformationData.dVal2 = dVal2;
      DataPacket.transformationData.dVal3 = dVal3;
      DataPacket.transformationData.dRot1 = dRot1;
      DataPacket.transformationData.dRot2 = dRot2;
      DataPacket.transformationData.dRot3 = dRot3;
      DataPacket.transformationData.dScale = dScale;
   };
   
   inline CSetTransformationParams(TransformationDataT transformationData)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetTransformationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetTransformationParams;
      DataPacket.transformationData = transformationData;
   };
   
   SetTransformationParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetTransformationParams
{
public:
   inline CGetTransformationParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetTransformationParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetTransformationParams;
   };
   
   GetTransformationParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoLastMeasuredPoint
{
public:
   inline CGoLastMeasuredPoint()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoLastMeasuredPointCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoLastMeasuredPoint;
   };
   
   GoLastMeasuredPointCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CPositionRelativeHV
{
public:
   inline CPositionRelativeHV(double dHzVal, 
                              double dVtVal)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(PositionRelativeHVCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_PositionRelativeHV;
      DataPacket.dHzVal = dHzVal;
      DataPacket.dVtVal = dVtVal;
   };
   
   PositionRelativeHVCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoPosition
{
public:
   inline CGoPosition(double dVal1, 
                      double dVal2, 
                      double dVal3,
                      bool bUseADM)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoPositionCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoPosition;
      DataPacket.dVal1 = dVal1;
      DataPacket.dVal2 = dVal2;
      DataPacket.dVal3 = dVal3;
      DataPacket.bUseADM = bUseADM;
   };
   
   GoPositionCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetDirection
{
public:
   inline CGetDirection()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetDirectionCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetDirection;
   };
   
   GetDirectionCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoPositionHVD
{
public:
   inline CGoPositionHVD(double dHzAngle, 
                         double dVtAngle, 
                         double dDistance,
                         bool bUseADM)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoPositionHVDCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoPositionHVD;
      DataPacket.dHzAngle = dHzAngle;
      DataPacket.dVtAngle = dVtAngle;
      DataPacket.dDistance = dDistance;
      DataPacket.bUseADM = bUseADM;
   };
   
   GoPositionHVDCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CPointLaser
{
public:
   inline CPointLaser(double dVal1, 
                      double dVal2, 
                      double dVal3)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(PointLaserCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_PointLaser;
      DataPacket.dVal1 = dVal1;
      DataPacket.dVal2 = dVal2;
      DataPacket.dVal3 = dVal3;
   };
   
   PointLaserCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CPointLaserHVD
{
public:
   inline CPointLaserHVD(double dHzAngle, 
                         double dVtAngle, 
                         double dDistance)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(PointLaserHVDCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_PointLaserHVD;
      DataPacket.dHzAngle = dHzAngle;
      DataPacket.dVtAngle = dVtAngle;
      DataPacket.dDistance = dDistance;
   };
   
   PointLaserHVDCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CMoveHV
{
public:
   inline CMoveHV(int iHzSpeed, 
                  int iVtSpeed)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(MoveHVCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_MoveHV;
      DataPacket.iHzSpeed = iHzSpeed;
      DataPacket.iVtSpeed = iVtSpeed;
   };
   
   MoveHVCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoNivelPosition
{
public:
   inline CGoNivelPosition(ES_NivelPosition position)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoNivelPositionCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoNivelPosition;
      DataPacket.nivelPosition = position;
   };
   
   GoNivelPositionCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoBirdBath
{
public:
   inline CGoBirdBath()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoBirdBathCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoBirdBath;
   };
   
   GoBirdBathCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CChangeFace
{
public:
   inline CChangeFace()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(ChangeFaceCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_ChangeFace;
   };
   
   ChangeFaceCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CStartNivelMeasurement
{
public:
   inline CStartNivelMeasurement()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(StartNivelMeasurementCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_StartNivelMeasurement;
   };
   
   StartNivelMeasurementCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CStartMeasurement
{
public:
   inline CStartMeasurement()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(StartMeasurementCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_StartMeasurement;
   };
   
   StartMeasurementCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CStopMeasurement
{
public:
   inline CStopMeasurement()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(StopMeasurementCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_StopMeasurement;
   };
   
   StopMeasurementCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CExitApplication
{
public:
   inline CExitApplication()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(ExitApplicationCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_ExitApplication;
   };
   
   ExitApplicationCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CCallOrientToGravity
{
public:
   inline CCallOrientToGravity()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(CallOrientToGravityCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_CallOrientToGravity;
   };
   
   CallOrientToGravityCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetCompensation
{
public:
   inline CSetCompensation(int iInternalCompensationId)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetCompensationCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetCompensation;
      DataPacket.iInternalCompensationId = iInternalCompensationId;
   };
   
   SetCompensationCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetStatisticMode
{
public:
   inline CSetStatisticMode(ES_StatisticMode stationaryMeasurements,
                            ES_StatisticMode continuousMeasurements)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetStatisticModeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetStatisticMode;
      DataPacket.stationaryMeasurements = stationaryMeasurements;
      DataPacket.continuousMeasurements = continuousMeasurements;
   };
   
   SetStatisticModeCT   DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetStatisticMode
{
public:
   inline CGetStatisticMode()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetStatisticModeCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetStatisticMode;
   };
   
   GetStatisticModeCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetCameraParams
{
public:
   inline CSetCameraParams(CameraParamsDataT cameraParamsData)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetCameraParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetCameraParams;
      DataPacket.cameraParams = cameraParamsData;
   };

   inline CSetCameraParams(int iContrast, int iBrightness, int iSaturation)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetCameraParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetCameraParams;
      DataPacket.cameraParams.iContrast = iContrast;
      DataPacket.cameraParams.iBrightness = iBrightness;
      DataPacket.cameraParams.iSaturation = iSaturation;
   };
   
   SetCameraParamsCT   DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetCameraParams
{
public:
   inline CGetCameraParams()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetCameraParamsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetCameraParams;
   };
   
   GetCameraParamsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetCompensation
{
public:
   inline CGetCompensation()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetCompensationCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetCompensation;
   };
   
   GetCompensationCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetCompensations
{
public:
   inline CGetCompensations()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetCompensationsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetCompensations;
   };
   
   GetCompensationsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetCompensations2
{
public:
   inline CGetCompensations2()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetCompensations2CT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetCompensations2;
   };
   
   GetCompensations2CT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetTPInfo
{
public:
   inline CGetTPInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetTPInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetTPInfo;
   };
   
   GetTPInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetNivelInfo
{
public:
   inline CGetNivelInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetNivelInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetNivelInfo;
   };
   
   GetNivelInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetLaserOnTimer
{
public:
   inline CSetLaserOnTimer(int iTimeOffsetHour, int iTimeOffsetMinute)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetLaserOnTimerCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetLaserOnTimer;
      DataPacket.iLaserOnTimeOffsetHour = iTimeOffsetHour;
      DataPacket.iLaserOnTimeOffsetMinute = iTimeOffsetMinute;
   };
   
   SetLaserOnTimerCT   DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetLaserOnTimer
{
public:
   inline CGetLaserOnTimer()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetLaserOnTimerCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetLaserOnTimer;
   };
   
   GetLaserOnTimerCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoBirdBath2
{
public:
   inline CGoBirdBath2(bool bClockwise)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoBirdBath2CT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoBirdBath2;
      DataPacket.bClockWise = bClockwise;
   };
   
   GoBirdBath2CT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetFace
{
public:
   inline CGetFace()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetFaceCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetFace;
   };
   
   GetFaceCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetLongSystemParam
{
public:
   inline CSetLongSystemParam(ES_SystemParameter systemParam, long lParameter)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetLongSystemParamCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetLongSystemParameter;
      DataPacket.systemParam = systemParam;
      DataPacket.lParameter = lParameter;

   };
   
   SetLongSystemParamCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetLongSystemParam
{
public:
   inline CGetLongSystemParam(ES_SystemParameter systemParam)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetLongSystemParamCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetLongSystemParameter;
      DataPacket.systemParam = systemParam;
   };
   
   GetLongSystemParamCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetMeasurementStatusInfo
{
public:
   inline CGetMeasurementStatusInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetMeasurementStatusInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetMeasurementStatusInfo;
   };
   
   GetMeasurementStatusInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CSetDoubleSystemParam
{
public:
   inline CSetDoubleSystemParam(ES_SystemParameter systemParam, double dParameter)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(SetDoubleSystemParamCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_SetDoubleSystemParameter;
      DataPacket.systemParam = systemParam;
      DataPacket.dParameter = dParameter;
   };
   
   SetDoubleSystemParamCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetDoubleSystemParam
{
public:
   inline CGetDoubleSystemParam(ES_SystemParameter systemParam)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetDoubleSystemParamCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetDoubleSystemParameter;
      DataPacket.systemParam = systemParam;
   };
   
   GetDoubleSystemParamCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetObjectTemperature
{
public:
   inline CGetObjectTemperature()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetObjectTemperatureCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetObjectTemperature;
   };
   
   GetObjectTemperatureCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetOverviewCameraInfo
{
public:
   inline CGetOverviewCameraInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetOverviewCameraInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetOverviewCameraInfo;
   };
   
   GetOverviewCameraInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CClearCommandQueue
{
public:
   inline CClearCommandQueue(ES_ClearCommandQueueType ccqType)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(ClearCommandQueueCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_ClearCommandQueue;
      DataPacket.clearQueueType = ccqType;
   };
   
   ClearCommandQueueCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetADMInfo2
{
public:
   inline CGetADMInfo2()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetADMInfo2CT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetADMInfo2;
   };
   
   GetADMInfo2CT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetTrackerInfo
{
public:
   inline CGetTrackerInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetTrackerInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetTrackerInfo;
   };
   
   GetTrackerInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetNivelInfo2
{
public:
   inline CGetNivelInfo2()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetNivelInfo2CT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetNivelInfo2;
   };
   
   GetNivelInfo2CT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CRestoreStartupConditions
{
public:
   inline CRestoreStartupConditions()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(RestoreStartupConditionsCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_RestoreStartupConditions;
   };
   
   RestoreStartupConditionsCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGoAndMeasure
{
public:
   inline CGoAndMeasure(double dVal1, 
                        double dVal2, 
                        double dVal3)
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GoAndMeasureCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GoAndMeasure;
      DataPacket.dVal1 = dVal1;
      DataPacket.dVal2 = dVal2;
      DataPacket.dVal3 = dVal3;
   };
   
   GoAndMeasureCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetATRInfo
{
public:
   inline CGetATRInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetATRInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetATRInfo;
   };
   
   GetATRInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetMeteoStationInfo
{
public:
   inline CGetMeteoStationInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetMeteoStationInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetMeteoStationInfo;
   };
   
   GetMeteoStationInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetAT4xxInfo
{
public:
   inline CGetAT4xxInfo()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetAT4xxInfoCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetAT4xxInfo;
   };
   
   GetAT4xxInfoCT DataPacket;
};

/////////////////////////////////////////////////////////////////////////////
class CGetSystemSoftwareVersion
{
public:
   inline CGetSystemSoftwareVersion()
   {
      DataPacket.packetInfo.packetHeader.lPacketSize = sizeof(GetSystemSoftwareVersionCT);
      DataPacket.packetInfo.packetHeader.type = ES_DT_Command;
      DataPacket.packetInfo.command = ES_C_GetSystemSoftwareVersion;
   };
   
   GetSystemSoftwareVersionCT DataPacket;
};


/////////////////////////////////////////////////////////////////////////////
// Macro to compact duplicate code
#define ES_DATA_PACKET  &Data.DataPacket, sizeof(Data.DataPacket)

class 
#ifdef _CPP_API_EXT_DLL
AFX_EXT_CLASS 
#endif
CESAPICommand
{
public:
   inline CESAPICommand() {TRACE(_T("CESAPICommand()\n"));}

   // pure virtual function - MUST be overriden in derived class
   virtual bool SendPacket(void* PacketStart, long PacketSize) = 0;

public:
   // Send commands to embedded system
   bool inline Initialize() {CInitialize Data; return SendPacket(ES_DATA_PACKET);}
   bool inline ActivateCameraView() {CActivateCameraView Data; return SendPacket(ES_DATA_PACKET);}
   bool inline Park() {CPark Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GoLastMeasuredPoint() {CGoLastMeasuredPoint Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetSystemStatus() {CGetSystemStatus Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetTrackerStatus() {CGetTrackerStatus Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetCoordinateSystemType(ES_CoordinateSystemType sysType) {CSetCoordinateSystemType Data(sysType); return SendPacket(ES_DATA_PACKET);}
   bool inline GetCoordinateSystemType() {CGetCoordinateSystemType Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetMeasurementMode(ES_MeasMode mode) {CSetMeasurementMode Data(mode); return SendPacket(ES_DATA_PACKET);}
   bool inline GetMeasurementMode() {CGetMeasurementMode Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetStationaryModeParams(long lMeasTime, bool bUseADM) {CSetStationaryModeParams Data(lMeasTime, bUseADM); return SendPacket(ES_DATA_PACKET);}
   bool inline SetStationaryModeParams(StationaryModeDataT stationaryModeData) {CSetStationaryModeParams Data(stationaryModeData); return SendPacket(ES_DATA_PACKET);}
   bool inline GetStationaryModeParams() {CGetStationaryModeParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetReflectors() {CGetReflectors Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetReflector() {CGetReflector Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetReflector(int iInternalReflectorId) {CSetReflector Data(iInternalReflectorId); return SendPacket(ES_DATA_PACKET);}
   bool inline SetUnits(SystemUnitsDataT unitsSettings) {CSetUnits Data(unitsSettings); return SendPacket(ES_DATA_PACKET);}
   bool inline SetUnits(ES_LengthUnit lenUnitType, ES_AngleUnit angUnitType, ES_TemperatureUnit tempUnitType, ES_PressureUnit pressUnitType, ES_HumidityUnit humUnitType) {CSetUnits Data(lenUnitType, angUnitType, tempUnitType, pressUnitType, humUnitType); return SendPacket(ES_DATA_PACKET);}
   bool inline GetUnits() {CGetUnits Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetSystemSettings(SystemSettingsDataT settings) {CSetSystemSettings Data(settings); return SendPacket(ES_DATA_PACKET);}
   bool inline GetSystemSettings() {CGetSystemSettings Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetEnvironmentParams(double dTemperature, double dPressure, double dHumidity) {CSetEnvironmentParams Data(dTemperature, dPressure, dHumidity); return SendPacket(ES_DATA_PACKET);}
   bool inline SetEnvironmentParams(EnvironmentDataT environmentData) {CSetEnvironmentParams Data(environmentData); return SendPacket(ES_DATA_PACKET);}
   bool inline GetEnvironmentParams() {CGetEnvironmentParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetRefractionParams() {CGetRefractionParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetRefractionParams(double ifmIndex, double admIndex) {CSetRefractionParams Data(ifmIndex, admIndex); return SendPacket(ES_DATA_PACKET);}
   bool inline GetSearchParams() {CGetSearchParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetSearchParams(SearchParamsDataT searchParams) {CSetSearchParams Data(searchParams); return SendPacket(ES_DATA_PACKET);}
   bool inline SetStationOrientationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3) {CSetStationOrientationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3); return SendPacket(ES_DATA_PACKET);}
   bool inline SetStationOrientationParams(StationOrientationDataT stationOrientation) {CSetStationOrientationParams Data(stationOrientation); return SendPacket(ES_DATA_PACKET);}
   bool inline GetStationOrientationParams() {CGetStationOrientationParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetTransformationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3, double dScale) {CSetTransformationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3, dScale); return SendPacket(ES_DATA_PACKET);}
   bool inline SetTransformationParams(TransformationDataT transformationData) {CSetTransformationParams Data(transformationData); return SendPacket(ES_DATA_PACKET);}
   bool inline GetTransformationParams() {CGetTransformationParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GoPosition(double dVal1, double dVal2, double dVal3, bool bUseADM) {CGoPosition Data(dVal1, dVal2, dVal3, bUseADM); return SendPacket(ES_DATA_PACKET);}
   bool inline GoPositionHVD(double dHzAngle, double dVtAngle, double dDistance, bool bUseADM) {CGoPositionHVD Data(dHzAngle, dVtAngle, dDistance, bUseADM); return SendPacket(ES_DATA_PACKET);}
   bool inline PointLaser(double dVal1, double dVal2, double dVal3) {CPointLaser Data(dVal1, dVal2, dVal3); return SendPacket(ES_DATA_PACKET);}
   bool inline PointLaserHVD(double dHzAngle, double dVtAngle, double dDistance) {CPointLaserHVD Data(dHzAngle, dVtAngle, dDistance); return SendPacket(ES_DATA_PACKET);}
   bool inline GoNivelPosition(ES_NivelPosition position) {CGoNivelPosition Data(position); return SendPacket(ES_DATA_PACKET);}
   bool inline MoveHV(long lHzSpeed, long lVtSpeed) {CMoveHV Data(lHzSpeed, lVtSpeed); return SendPacket(ES_DATA_PACKET);}
   bool inline PositionRelativeHV(double dHz, double dVt) {CPositionRelativeHV Data(dHz, dVt); return SendPacket(ES_DATA_PACKET);}
   bool inline GoBirdBath() {CGoBirdBath Data; return SendPacket(ES_DATA_PACKET);}
   bool inline ChangeFace() {CChangeFace Data; return SendPacket(ES_DATA_PACKET);}
   bool inline FindReflector(double dAproxDistance) {CFindReflector Data(dAproxDistance); return SendPacket(ES_DATA_PACKET);}
   bool inline StartMeasurement() {CStartMeasurement Data; return SendPacket(ES_DATA_PACKET);}
   bool inline StartNivelMeasurement() {CStartNivelMeasurement Data; return SendPacket(ES_DATA_PACKET);}
   bool inline StopMeasurement() {CStopMeasurement Data; return SendPacket(ES_DATA_PACKET);}
   bool inline ExitApplication() {CExitApplication Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetDirection() {CGetDirection Data; return SendPacket(ES_DATA_PACKET);}
   bool inline CallOrientToGravity() {CCallOrientToGravity Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetCompensation(int iInternalCompensationId) {CSetCompensation Data(iInternalCompensationId); return SendPacket(ES_DATA_PACKET);}
   bool inline SetStatisticMode(ES_StatisticMode stationaryMeasurements, ES_StatisticMode continuousMeasurements) {CSetStatisticMode Data(stationaryMeasurements, continuousMeasurements); return SendPacket(ES_DATA_PACKET);}
   bool inline GetStatisticMode() {CGetStatisticMode Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetCameraParams() {CGetCameraParams Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetCameraParams(CameraParamsDataT cameraParams) {CSetCameraParams Data(cameraParams); return SendPacket(ES_DATA_PACKET);}
   bool inline SetCameraParams(int iContrast, int iBrightness, int iSaturation) {CSetCameraParams Data(iContrast, iBrightness, iSaturation); return SendPacket(ES_DATA_PACKET);}
   bool inline GetCompensation() {CGetCompensation Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetCompensations() {CGetCompensations Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetCompensations2() {CGetCompensations2 Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetTPInfo() {CGetTPInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetNivelInfo() {CGetNivelInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetLaserOnTimer() {CGetLaserOnTimer Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetLaserOnTimer(int iTimeOffsetHour, int iTimeOffsetMinute) {CSetLaserOnTimer Data(iTimeOffsetHour, iTimeOffsetMinute); return SendPacket(ES_DATA_PACKET);}
   bool inline GoBirdBath2(bool bClockwise) {CGoBirdBath2 Data(bClockwise); return SendPacket(ES_DATA_PACKET);}
   bool inline GetFace() {CGetFace Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetLongSystemParameter(ES_SystemParameter systemParam, long lParameter) {CSetLongSystemParam Data(systemParam, lParameter); return SendPacket(ES_DATA_PACKET);}
   bool inline GetLongSystemParameter(ES_SystemParameter systemParam) {CGetLongSystemParam Data(systemParam); return SendPacket(ES_DATA_PACKET);}
   bool inline GetMeasurementStatusInfo() {CGetMeasurementStatusInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline SetDoubleSystemParameter(ES_SystemParameter systemParam, double dParameter) {CSetDoubleSystemParam Data(systemParam, dParameter); return SendPacket(ES_DATA_PACKET);}
   bool inline GetDoubleSystemParameter(ES_SystemParameter systemParam) {CGetDoubleSystemParam Data(systemParam); return SendPacket(ES_DATA_PACKET);}
   bool inline GetObjectTemperature() {CGetObjectTemperature Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetOverviewCameraInfo() {CGetOverviewCameraInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline ClearCommandQueue(ES_ClearCommandQueueType ccqType) {CClearCommandQueue Data(ccqType); return SendPacket(ES_DATA_PACKET);}
   bool inline GetADMInfo2() {CGetADMInfo2 Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetTrackerInfo() {CGetTrackerInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetNivelInfo2() {CGetNivelInfo2 Data; return SendPacket(ES_DATA_PACKET);}
   bool inline RestoreStartupConditions() {CRestoreStartupConditions Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GoAndMeasure(double dval1, double dval2, double dval3) {CGoAndMeasure Data(dval1, dval2, dval3); return SendPacket(ES_DATA_PACKET);}
   bool inline GetATRInfo() {CGetATRInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetMeteoStationInfo() {CGetMeteoStationInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetAT4xxInfo() {CGetAT4xxInfo Data; return SendPacket(ES_DATA_PACKET);}
   bool inline GetSystemSoftwareVersion() {CGetSystemSoftwareVersion Data; return SendPacket(ES_DATA_PACKET);}
};

class
#ifdef _CPP_API_EXT_DLL
	AFX_EXT_CLASS
#endif
Encoder : public CESAPICommand
{
public:
	Encoder() : _packet(NULL), _packetSize(0) { }
	~Encoder()
	{
		if (_packet != NULL) {
			delete[] _packet;
		}
	}

private:
	char * _packet;
	long _packetSize;

	bool SendPacket(void* PacketStart, long PacketSize)
	{
		/*
		BasicCommandCT * command = static_cast<BasicCommandCT *>(PacketStart);
		std::cout << "Size: " << command->packetHeader.lPacketSize << std::endl
				  << "Type: " << command->packetHeader.type << std::endl
				  << "Command: " << command->command << std::endl;
		*/
		if (_packet != NULL)
		{
			delete[] _packet;
		}
		_packetSize = PacketSize;
		//std::cout << "Packet Size: " << PacketSize << std::endl;
		_packet = new char[_packetSize];
		memcpy(_packet, PacketStart, _packetSize);
		/*
		command = reinterpret_cast<BasicCommandCT *>(_packet);
		std::cout << "Size: " << command->packetHeader.lPacketSize << std::endl
			<< "Type: " << command->packetHeader.type << std::endl
			<< "Command: " << command->command << std::endl;
		*/
		return true;
	}

public:
	void getPacket(char ** const packet, int * const size)
	{
		*packet = _packet;
		*size = _packetSize;
	}
};

/////////////////////////////////////////////////////////////////////////////////////
// CESAPIReceive class

// This is an extension to the ES CPP-API for received data parsing. It mainly defines 
// a ProcessData() function with the typical 'switch'- table for parsing incoming
// command- and data- types (as used with the native C- interface). For each type
// of result (as far as defined), a virtual function call occurs.
// Hence the users just need to derive a class from CESAPIReceive and override only 
// those functions they are interested in.

// Note: this class only depends from the ES C-API

class 
#ifdef _CPP_API_EXT_DLL
AFX_EXT_CLASS 
#endif
CESAPIReceive
{
public:
   inline CESAPIReceive() {TRACE(_T("CESAPIReceive()\n"));}

//protected: // public from version 1.5

   // Packets passed to this method must be COMPLETE (in terms of an RT struct as
   // defined in the C-API). Packet fragments are not processed correclty. Hence
   // the application (which calls ReceiveData) must ensure to pass complete packets

   // Programmers of course may change this class or derive / implement their own 
   // receiver class is this behaviour is not suitable

   bool inline ReceiveData(void const * const packetStart, const long packetSize) 
   { 
      //TRACE(_T("ReceiveData()\n"));
       
      if (packetStart && packetSize > 0)
         return ProcessData(packetStart, packetSize); 
      else
         return false;
   } // ReceiveData()

protected:
   // virtual data handlers. In the derived class, override only these functions
   // to whose results your application is interested in. All other data arrival -
   // if any - would then be 'handled' by the virtual function below (inline).
   // That is, such data would be ignored - just a trace statement happens in debug mode
   // Note that OnCommandAnswer() is a most general handler which is called on every command.
   // For more distinguished command answers, other/additional handlers as shown in the 
   // section 'Particular command handlers' below need to be implemented.

   // General handlers
   virtual void OnCommandAnswer(const BasicCommandRT& cmd) {TRACE(_T("virtual OnCommandAnswer() call\n"));} // called on every command answer
   virtual void OnErrorAnswer(const ErrorResponseT& error) {TRACE(_T("virtual OnErrorAnswer() call\n"));}
   virtual void OnSystemStatusChange(const SystemStatusChangeT& status) {TRACE(_T("virtual OnSystemStatusChange() call\n"));}  
   virtual void OnUnknownAnswer() {TRACE(_T("virtual OnUnknownAnswer() call\n"));} // should never happen
   
   // Measurement and Reflectors data handlers
   virtual void OnSingleMeasurementAnswer(const SingleMeasResultT& singleMeas) {TRACE(_T("virtual OnSingleMeasurementAnswer() call\n"));}
   virtual void OnNivelMeasurementAnswer(const NivelResultT& nivelResult) {TRACE(_T("virtual OnNivelMeasurementAnswer() call\n"));}
   virtual void OnReflectorPosAnswer(const ReflectorPosResultT& reflPos) {TRACE(_T("virtual OnReflectorPosAnswer() call\n"));}  
   virtual void OnSingleMeasurement2Answer(const SingleMeasResult2T& singleMeas) {TRACE(_T("virtual OnSingleMeasurement2Answer() call\n"));}
   
   // Particular command handlers (called in addition to OnCommandAnswer)

   virtual void OnExitApplicationAnswer() {TRACE(_T("virtual OnExitApplicationAnswer() call\n"));}

   virtual void OnGetSystemStatusAnswer(const ES_ResultStatus           lastResultStatus,
                                        const ES_TrackerProcessorStatus trackerProcessorStatus,
                                        const ES_LaserProcessorStatus   laserStatus,
                                        const ES_ADMStatus              admStatus,
                                        const ESVersionNumberT          esVersionNumber,
                                        const ES_WeatherMonitorStatus   weatherMonitorStatus,
                                        const long lFlagsValue,
                                        const long lTrackerSerialNumber) {TRACE(_T("virtual OnGetSystemStatusAnswer() call\n"));}
   
   virtual void OnGetTrackerStatusAnswer(const ES_TrackerStatus trackerStatus) {TRACE(_T("virtual OnGetTrackerStatusAnswer() call\n"));}
   virtual void OnSetUnitsAnswer() {TRACE(_T("virtual OnSetUnitsAnswer() call\n"));}
   virtual void OnGetUnitsAnswer(const SystemUnitsDataT& unitsSettings) {TRACE(_T("virtual OnGetUnitsAnswer() call\n"));}
   virtual void OnInitializeAnswer() {TRACE(_T("virtual OnInitializeAnswer() call\n"));}
   virtual void OnActivateCameraViewAnswer() {TRACE(_T("virtual OnActivateCameraViewAnswer() call\n"));}
   virtual void OnParkAnswer() {TRACE(_T("virtual OnParkAnswer() call\n"));}
   virtual void OnSetStationOrientationParamsAnswer() {TRACE(_T("virtual OnSetStationOrientationParamsAnswer() call\n"));}
   virtual void OnGetStationOrientationParamsAnswer(const StationOrientationDataT& stationOrientation) {TRACE(_T("virtual OnGetStationOrientationParamsAnswer() call\n"));}
   virtual void OnSetTransformationParamsAnswer() {TRACE(_T("virtual OnSetTransformationParamsAnswer() call\n"));}
   virtual void OnGetTransformationParamsAnswer(const TransformationDataT& transformationData) {TRACE(_T("virtual OnGetTransformationParamsAnswer() call\n"));}
   virtual void OnSetEnvironmentParamsAnswer() {TRACE(_T("virtual OnSetEnvironmentParamsAnswer() call\n"));} 
   virtual void OnGetEnvironmentParamsAnswer(const EnvironmentDataT& environmentData) {TRACE(_T("virtual OnGetEnvironmentParamsAnswer() call\n"));}
   virtual void OnSetRefractionParamsAnswer() {TRACE(_T("virtual OnSetRefractionParamsAnswer() call\n"));}
   virtual void OnGetRefractionParamsAnswer(const RefractionDataT& refractionData) {TRACE(_T("virtual OnGetRefractionParamsAnswer() call\n"));}
   virtual void OnSetMeasurementModeAnswer() {TRACE(_T("virtual OnSetMeasurementModeAnswer() call\n"));}
   virtual void OnGetMeasurementModeAnswer(const ES_MeasMode measMode) {TRACE(_T("virtual OnGetMeasurementModeAnswer() call\n"));}
   virtual void OnSetCoordinateSystemTypeAnswer() {TRACE(_T("virtual OnSetCoordinateSystemTypeAnswer() call\n"));}
   virtual void OnGetCoordinateSystemTypeAnswer(const ES_CoordinateSystemType coordSysType) {TRACE(_T("virtual OnGetCoordinateSystemTypeAnswer() call\n"));}
   virtual void OnSetStationaryModeParamsAnswer() {TRACE(_T("virtual OnSetStationaryModeParamsAnswer() call\n"));}
   virtual void OnGetStationaryModeParamsAnswer(const StationaryModeDataT& stationaryModeData) {TRACE(_T("virtual OnGetStationaryModeParamsAnswer() call\n"));}
   virtual void OnSetReflectorAnswer() {TRACE(_T("virtual OnSetReflectorAnswer() call\n"));}
   virtual void OnGetReflectorAnswer(const int iInternalReflectorId) {TRACE(_T("virtual OnGetReflectorAnswer() call\n"));}

   virtual void OnGetReflectorsAnswer(const int            iTotalReflectors,
                                      const int            iInternalReflectorId,
                                      const ES_TargetType  targetType,
                                      const double         dSurfaceOffset,
                                      const unsigned short cReflectorName[32]) {TRACE(_T("virtual OnGetReflectorsAnswer() call\n"));}
   
   virtual void OnSetSearchParamsAnswer() {TRACE(_T("virtual OnSetSearchParamsAnswer() call\n"));}
   virtual void OnGetSearchParamsAnswer(const SearchParamsDataT& searchParams) {TRACE(_T("virtual OnGetSearchParamsAnswer() call\n"));}
   virtual void OnSetSystemSettingsAnswer() {TRACE(_T("virtual OnSetSystemSettingsAnswer() call\n"));}
   virtual void OnGetSystemSettingsAnswer(const SystemSettingsDataT& systemSettings) {TRACE(_T("virtual OnGetSystemSettingsAnswer() call\n"));}
   virtual void OnStartMeasurementAnswer() {TRACE(_T("virtual OnStartMeasurementAnswer() call\n"));}
   virtual void OnStartNivelMeasurementAnswer() {TRACE(_T("virtual OnStartNivelMeasurementAnswer() call\n"));}
   virtual void OnStopMeasurementAnswer() {TRACE(_T("virtual OnStopMeasurementAnswer() call\n"));}
   virtual void OnChangeFaceAnswer() {TRACE(_T("virtual OnChangeFaceAnswer() call\n"));}
   virtual void OnGoBirdBathAnswer() {TRACE(_T("virtual OnGoBirdBathAnswer() call\n"));}
   virtual void OnGoPositionAnswer() {TRACE(_T("virtual OnGoPositionAnswer() call\n"));}
   virtual void OnGoPositionHVDAnswer() {TRACE(_T("virtual OnGoPositionHVDAnswer() call\n"));}
   virtual void OnPositionRelativeHVAnswer() {TRACE(_T("virtual OnPositionRelativeHVAnswer() call\n"));}
   virtual void OnPointLaserAnswer() {TRACE(_T("virtual OnPointLaserAnswer() call\n"));}
   virtual void OnPointLaserHVDAnswer() {TRACE(_T("virtual OnPointLaserHVDAnswer() call\n"));}
   virtual void OnMoveHVAnswer() {TRACE(_T("virtual OnMoveHVAnswer() call\n"));}
   virtual void OnGoNivelPositionAnswer() {TRACE(_T("virtual OnGoNivelPositionAnswer() call\n"));}
   virtual void OnGoLastMeasuredPointAnswer() {TRACE(_T("virtual OnGoLastMeasuredPointAnswer() call\n"));}
   virtual void OnFindReflectorAnswer() {TRACE(_T("virtual OnFindReflectorAnswer() call\n"));}


   virtual void OnGetDirectionAnswer(const double dHzAngle,
                                     const double dVtAngle) {TRACE(_T("virtual OnGetDirectionAnswer() call\n"));}

   virtual void OnCallOrientToGravityAnswer(const double dOmega,
                                            const double dPhi) {TRACE(_T("virtual OnCallOrientToGravityAnswer() call\n"));}

   virtual void OnSetCompensationAnswer() {TRACE(_T("virtual OnSetCompensationAnswer() call\n"));}


   virtual void OnSetStatisticModeAnswer() {TRACE(_T("virtual OnSetStatisticModeAnswer() call\n"));}

   virtual void OnGetStatisticModeAnswer(const ES_StatisticMode stationaryMeasurements,
                                         const ES_StatisticMode continuousMeasurements) {TRACE(_T("virtual OnGetStatisticModeAnswer() call\n"));}
   
   virtual void OnSetCameraParamsAnswer() {TRACE(_T("virtual OnSetCameraParamsAnswer() call\n"));}
   virtual void OnGetCameraParamsAnswer(const CameraParamsDataT& cameraParamsData) {TRACE(_T("virtual OnGetCameraParamsAnswer() call\n"));}

   virtual void OnGetCompensationAnswer(const int iInternalCompensationId) {TRACE(_T("virtual OnGetCompensationAnswer() call\n"));}

   virtual void OnGetCompensationsAnswer(const int iTotalCompensations,
                                         const int iInternalCompensationId,
                                         const unsigned short cTrackerCompensationName[32],
                                         const unsigned short cTrackerCompensationComment[128],
                                         const unsigned short cADMCompensationName[32],
                                         const bool bHasMeasurementCameraMounted) {TRACE(_T("virtual OnGetCompensationsAnswer() call\n"));}

   virtual void OnGetCompensations2Answer(const int iTotalCompensations,
                                          const int iInternalCompensationId,
                                          const unsigned short cTrackerCompensationName[32],
                                          const unsigned short cTrackerCompensationComment[128],
                                          const unsigned short cADMCompensationName[32],
                                          const unsigned short cADMCompensationComment[128],
                                          const bool bHasMeasurementCameraMounted,
                                          const bool bIsActive) {TRACE(_T("virtual OnGetCompensations2Answer() call\n"));}

   virtual void OnGetTPInfoAnswer(const int  iTPBootMajorVersionNumber,
                                  const int  iTPBootMinorVersionNumber,
                                  const int  iTPFirmwareMajorVersionNumber,
                                  const int  iTPFirmwareMinorVersionNumber,
                                  const int  iLCPFirmwareMajorVersionNumber,
                                  const int  iLCPFirmwareMinorVersionNumber,
                                  const ES_TrackerProcessorType trackerprocessorType,
                                  const ES_TPMicroProcessorType microProcessorType,
                                  const int  iMicroProcessorClockSpeed,
                                  const ES_LTSensorType laserTrackerSensorType) {TRACE(_T("virtual OnGetTPInfoAnswer() call\n"));}
   
   virtual void OnGetNivelInfoAnswer(const int iFirmwareMajorVersionNumber,
                                     const int iFirmwareMinorVersionNumber,
                                     const long lSerialNumber) {TRACE(_T("virtual OnGetNivelInfoAnswer() call\n"));}

   virtual void OnSetLaserOnTimerAnswer() {TRACE(_T("virtual OnSetLaserOnTimerAnswer() call\n"));}
   
   virtual void OnGetLaserOnTimerAnswer(const int iLaserOnTimeOffsetHour,
                                        const int iLaserOnTimeOffsetMinute) {TRACE(_T("virtual OnGetLaserOnTimerAnswer() call\n"));}

   virtual void OnGoBirdBath2Answer() {TRACE(_T("virtual OnGoBirdBath2Answer() call\n"));}

   virtual void OnGetFaceAnswer(const ES_TrackerFace trackerFace) {TRACE(_T("virtual OnGetFaceAnswer() call\n"));}

   virtual void OnSetLongSystemParamAnswer() {TRACE(_T("virtual OnSetLongSystemParamAnswer() call\n"));}
   virtual void OnGetLongSystemParamAnswer(const long lParameter) {TRACE(_T("virtual OnGetLongSystemParamAnswer() call\n"));}
   virtual void OnGetMeasurementStatusInfoAnswer(const long measurementStatusInfo) {TRACE(_T("virtual OnGetMeasurementStatusInfoAnswer() call\n"));}

   virtual void OnSetDoubleSystemParamAnswer() {TRACE(_T("virtual OnSetDoubleSystemParamAnswer() call\n"));}
   virtual void OnGetDoubleSystemParamAnswer(const double dParameter) {TRACE(_T("virtual OnGetDoubleSystemParamAnswer() call\n"));}
   
   virtual void OnGetObjectTemperatureAnswer(const double dObjectTemperature) {TRACE(_T("virtual OnGetObjectTemperatureAnswer() call\n"));}

   virtual void OnGetOverviewCameraInfoAnswer(const ES_OverviewCameraType cameraType,
                                              const unsigned short cCameraName[32],
                                              const bool bIsColorCamera,
                                              const double dFocalLength,
                                              const double dHorizontalChipSize,
                                              const double dVerticalChipSize,
                                              const bool bMirrorImageHz,
                                              const bool bMirrorImageVt) {TRACE(_T("virtual OnGetOverviewCameraInfoAnswer() call\n"));}
  
   virtual void OnClearCommandQueueAnswer() {TRACE(_T("virtual OnClearCommandQueueAnswer() call\n"));}

   virtual void OnGetADMInfo2Answer(const ES_ADMType admType,
                                    const unsigned short cADMName[32],
                                    const long lSerialNumber,
                                    const int iFirmwareMajorVersionNumber,
                                    const int iFirmwareMinorVersionNumber,
                                    const double dMaxDistance,
                                    const double dMinDistance,
                                    const int iMaxDataRate,
                                    const double dAccuracyADMDistance) {TRACE(_T("virtual OnGetADMInfo2Answer() call\n"));}
   
   virtual void OnGetTrackerInfoAnswer(const ES_LTSensorType trackerType,
                                       const unsigned short cTrackerName[32],
                                       const long lSerialNumber,
                                       const int iCompensationIdNumber, 
                                       const bool bHasADM,
                                       const bool bHasOverviewCamera,
                                       const bool bHasNivel,
                                       const double dNivelMountOffset,
                                       const double dMaxDistance,
                                       const double dMinDistance,
                                       const int iMaxDataRate,
                                       const int iNumberOfFaces,
                                       const double dHzAngleRange,
                                       const double dVtAngleRange,
                                       const ES_TrkAccuracyModel accuracyModel,
                                       const int iMajLCPFirmwareVersion,
                                       const int iMinLCPFirmwareVersion) {TRACE(_T("virtual OnGetTrackerInfoAnswer() call\n"));}
   
   virtual void OnGetNivelInfo2Answer(const ES_NivelType nivelType,
                                      const unsigned short cNivelName[32],
                                      const long lSerialNumber,
                                      const int iFirmwareMajorVersionNumber,
                                      const int iFirmwareMinorVersionNumber,
                                      const double dMeasurementRange,
                                      const double dMeasurementAccuracyOffset,
                                      const double dMeasurementAccuracyFactor) {TRACE(_T("virtual OnGetNivelInfo2() call\n"));}

   virtual void OnRestoreStartupConditionsAnswer() {TRACE(_T("virtual OnRestoreStartupConditionsAnswer() call\n"));}

   virtual void OnGetATRInfoAnswer(const ES_ATRType atrType,
                                   const unsigned short cATRName[32],
                                   const long lMajFirmwareVersion,
                                   const long lMinFirmwareVersion, 
                                   const long lBuildFirmwareVersion,
                                   const long lHardwareVersion,
                                   const long lErrorcode,
                                   const long lFPGAVersion,
                                   const double dMaxDistance,
                                   const double dMinDistance,
                                   const double dFieldOfView,
                                   const double dMaxTrackingSpeed) {TRACE(_T("virtual OnGetATRInfoAnswer() call\n"));}

   virtual void OnGetMeteoStationInfoAnswer(const ES_MeteoStationType meteoStationType,
                                            const unsigned short cIdentifier[32],
                                            const long iFirmwareMajorVersionNumber,
                                            const long iFirmwareMinorVersionNumber) {TRACE(_T("virtual OnGetMeteoStationInfoAnswer() call\n"));}

   virtual void OnGetAT4xxInfoAnswer(const ES_LTSensorType trackerType,
                                     const unsigned short cTrackerName[32],
                                     const long lSerialNumber,
                                     const long lMajorFirmwareVersion,
                                     const long lMinorFirmwareVersion,
                                     const long lProcessorBoardFWBuildNumber,
                                     const long lSensorBoardFWBuildNumber,
                                     const long lMajorOSVersion,
                                     const long lMinorOSVersion,
                                     const long lMajorServerSoftwareVersion,
                                     const long lMinorServerSoftwareVersion,
                                     const long lServerSoftwareBuildNumber,
                                     const ES_WLANType wlanType,
                                     const ES_TPMicroProcessorType xscaleType,
                                     const long lMinMeasureTime,
                                     const double dMinDistance,
                                     const double dMaxDistance,
                                     const double dStdDevDistOffsetADM,
                                     const double dStdDevAngleConst,
                                     const double dStdDevAngleOffset,
                                     const double dStdDevAngleFactor) {TRACE(_T("virtual OnGetAT4xxInfoAnswer() call\n"));}

   virtual void OnGetSystemSoftwareVersionAnswer(const unsigned short cSoftwareVersion[32]) {TRACE(_T("virtual OnGetSystemSoftwareVersionAnswer() call\n"));}

   // You may add more handlers here. There are no more answer types, but you may want to define overloads
   // with different formal parameter lists (for example return x, y, z instead of structs comprising these values)
   // However, if you define your own virtual functions here, make sure they are eing called in ProcessData() below.
   // As an alternative, you may define your own handlers only in your derived class where you override ProcessData()
   // in order to call your own overrides. It's a good idea only to call your own overides but calling ProcessData()
   // of the base class within your own ProcessData() function.

protected:
   // It is supposed that one and only one and COMPLETE data  
   // packet is being passed to this function.
   // Parameter 'lBytes' just passed for diagnostics purpose
   //
   virtual bool ProcessData(void const * const pDataArrived, long const lBytes)
   {
      // ProcessData() is a parser for the incoming data. When ProcessData()
      // is being called, we can assume that 'm_vtData.parray->pvData' points
      // to a valid and complete 'answer block' (just an array of bytes).
      // Next we must mask this data block with NoParamRT in order to figure 
      // out type. Once the type (for example ES_DT_SingleMeasResult) is known,
      // we can mask it with the appropriate structure (e.g. 'SingleMeasResultT').

      // Parameter 'long lBytes' just needed for diagnostics

      // mask arrived data with RT structure in order to figure out type/status
      PacketHeaderT *pData = (PacketHeaderT*)pDataArrived;

      // Diagnostics and overflow prevention.
      if (pData->lPacketSize != lBytes)
      {
         // Means a 'traffic jam' on the network. Not a single packet has arrived,
         // but at least two are 'aggregated'. Would need some extra handling to 
         // interpret this correctly. Note: Release version may be able to process
         // higher data rate due to nothing written out to display
      
         // Beep(300, 50); // info tracing in debug mode only!
         TRACE2("PacketSize (%ld) differs from TotalBytes (%ld) !\n", pData->lPacketSize, lBytes);

         return false; // causes to signal a data receive error
      } // if

      switch (pData->type)
      {
         case ES_DT_Command: // A 'command- type' answer has arrived
         {
            // decode type of command
            BasicCommandRT *pData2 = (BasicCommandRT *)pDataArrived;

            // call general virtual function for commands
            //
            // Currently just used for error handling in case of command status not ok,
            // since all commands have a dedicated specific answer function in case of success.
            //
            OnCommandAnswer(*pData2);  // uses reference parameter. see comment in header file

            // handle error
            if (pData2->status != ES_RS_AllOK)
               return true; // Exit here, but make sure pData2->status gets forwared somehow.
                            // This is done on using the general OnCommandAnswer() function above.
                            // Do not return false, since data was correctly received.

            // decode which type of command
            switch (pData2->command)
            {
               case ES_C_ExitApplication:
                  OnExitApplicationAnswer();
                  break;
 
               case ES_C_GetSystemStatus:
                  OnGetSystemStatusAnswer(((GetSystemStatusRT*)pDataArrived)->lastResultStatus,
                                          ((GetSystemStatusRT*)pDataArrived)->trackerProcessorStatus,
                                          ((GetSystemStatusRT*)pDataArrived)->laserStatus,
                                          ((GetSystemStatusRT*)pDataArrived)->admStatus,
                                          ((GetSystemStatusRT*)pDataArrived)->esVersionNumber,
                                          ((GetSystemStatusRT*)pDataArrived)->weatherMonitorStatus,
                                          ((GetSystemStatusRT*)pDataArrived)->lFlagsValue,
                                          ((GetSystemStatusRT*)pDataArrived)->lTrackerSerialNumber);
                  break;
 
               case ES_C_GetTrackerStatus:
                  OnGetTrackerStatusAnswer(((GetTrackerStatusRT*)pDataArrived)->trackerStatus);
                  break;

               case ES_C_SetUnits:
                  OnSetUnitsAnswer();
                  break;
 
               case ES_C_GetUnits:
                  OnGetUnitsAnswer(((GetUnitsRT*)pDataArrived)->unitsSettings);
                  break;
 
               case ES_C_Initialize:
                  OnInitializeAnswer();
                  break;

               case ES_C_ActivateCameraView:
                  OnActivateCameraViewAnswer();
                  break;
 
               case ES_C_Park:
                  OnParkAnswer();
                  break;

               case ES_C_SetStationOrientationParams:
                  OnSetStationOrientationParamsAnswer();
                  break;
 
               case ES_C_GetStationOrientationParams:
                  OnGetStationOrientationParamsAnswer(((GetStationOrientationParamsRT*)pDataArrived)->stationOrientation);
                  break;
 
               case ES_C_SetTransformationParams:
                  OnSetTransformationParamsAnswer();
                  break;
 
               case ES_C_GetTransformationParams:
                  OnGetTransformationParamsAnswer(((GetTransformationParamsRT*)pDataArrived)->transformationData);
                  break;

               case ES_C_SetEnvironmentParams:
                  OnSetEnvironmentParamsAnswer();
                  break;
 
               case ES_C_GetEnvironmentParams:
                  OnGetEnvironmentParamsAnswer(((GetEnvironmentParamsRT*)pDataArrived)->environmentData);
                  break;
 
               case ES_C_SetRefractionParams:
                  OnSetRefractionParamsAnswer();
                  break;
 
               case ES_C_GetRefractionParams:
                  OnGetRefractionParamsAnswer(((GetRefractionParamsRT*)pDataArrived)->refractionData);
                  break;
 
               case ES_C_SetMeasurementMode:
                  OnSetMeasurementModeAnswer();
                  break;
 
               case ES_C_GetMeasurementMode:
                  OnGetMeasurementModeAnswer(((GetMeasurementModeRT*)pDataArrived)->measMode);
                  break;
 
               case ES_C_SetCoordinateSystemType:
                  OnSetCoordinateSystemTypeAnswer();
                  break;
 
               case ES_C_GetCoordinateSystemType:
                  OnGetCoordinateSystemTypeAnswer(((GetCoordinateSystemTypeRT*)pDataArrived)->coordSysType);
                  break;
 
               case ES_C_SetStationaryModeParams:
                  OnSetStationaryModeParamsAnswer();
                  break;
 
               case ES_C_GetStationaryModeParams:
                  OnGetStationaryModeParamsAnswer(((GetStationaryModeParamsRT*)pDataArrived)->stationaryModeData);
                  break;

               case ES_C_SetReflector:
                  OnSetReflectorAnswer();
                  break;
 
               case ES_C_GetReflector:
                  OnGetReflectorAnswer(((GetReflectorRT*)pDataArrived)->iInternalReflectorId);
                  break;
 
               case ES_C_GetReflectors:
                  OnGetReflectorsAnswer(((GetReflectorsRT*)pDataArrived)->iTotalReflectors,
                                        ((GetReflectorsRT*)pDataArrived)->iInternalReflectorId,
                                        ((GetReflectorsRT*)pDataArrived)->targetType,
                                        ((GetReflectorsRT*)pDataArrived)->dSurfaceOffset,
                                        ((GetReflectorsRT*)pDataArrived)->cReflectorName);
                  break;
 
               case ES_C_SetSearchParams:
                  OnSetSearchParamsAnswer();
                  break;
 
               case ES_C_GetSearchParams:
                  OnGetSearchParamsAnswer(((GetSearchParamsRT*)pDataArrived)->searchParams);
                  break;

               case ES_C_SetSystemSettings:
                  OnSetSystemSettingsAnswer();
                  break;
 
               case ES_C_GetSystemSettings:
                  OnGetSystemSettingsAnswer(((GetSystemSettingsRT*)pDataArrived)->systemSettings);
                  break;
 
               case ES_C_StartMeasurement:
                  OnStartMeasurementAnswer(); // Called only in Continuous Mode
                  break;
 
               case ES_C_StartNivelMeasurement:
                  OnStartNivelMeasurementAnswer();
                  break;
 
               case ES_C_StopMeasurement:
                  OnStopMeasurementAnswer();
                  break;

               case ES_C_ChangeFace:
                  OnChangeFaceAnswer();
                  break;
 
               case ES_C_GoBirdBath:
                  OnGoBirdBathAnswer();
                  break;

               case ES_C_GoPosition:
                  OnGoPositionAnswer();
                  break;
 
               case ES_C_GoPositionHVD:
                  OnGoPositionHVDAnswer();
                  break;
 
               case ES_C_PositionRelativeHV:
                  OnPositionRelativeHVAnswer();
                  break;
 
               case ES_C_PointLaser:
                  OnPointLaserAnswer();
                  break;
 
               case ES_C_PointLaserHVD:
                  OnPointLaserHVDAnswer();
                  break;
 
               case ES_C_MoveHV:
                  OnMoveHVAnswer();
                  break;
 
               case ES_C_GoNivelPosition:
                  OnGoNivelPositionAnswer();
                  break;

               case ES_C_GoLastMeasuredPoint:
                  OnGoLastMeasuredPointAnswer();
                  break;
 
               case ES_C_FindReflector:
                  OnFindReflectorAnswer();
                  break;
 
               case ES_C_Unknown:
                  OnUnknownAnswer();
                  break;

               case ES_C_GetDirection:
                  OnGetDirectionAnswer(((GetDirectionRT*)pDataArrived)->dHzAngle,
                                       ((GetDirectionRT*)pDataArrived)->dVtAngle);
                  break;

               case ES_C_CallOrientToGravity:
                  OnCallOrientToGravityAnswer(((CallOrientToGravityRT*)pDataArrived)->dOmega,
                                              ((CallOrientToGravityRT*)pDataArrived)->dPhi);
                  break;

               case ES_C_SetCompensation:
                  OnSetCompensationAnswer();
                  break;

               case ES_C_SetStatisticMode:
                  OnSetStatisticModeAnswer();
                  break;

               case ES_C_GetStatisticMode:
                  OnGetStatisticModeAnswer(((GetStatisticModeRT*)pDataArrived)->stationaryMeasurements,
                                           ((GetStatisticModeRT*)pDataArrived)->continuousMeasurements);
                  break;

               case ES_C_SetCameraParams:
                  OnSetCameraParamsAnswer();
                  break;

               case ES_C_GetCameraParams:
                  OnGetCameraParamsAnswer(((GetCameraParamsRT*)pDataArrived)->cameraParams);
                  break;

               case ES_C_GetCompensation:
                  OnGetCompensationAnswer(((GetCompensationRT*)pDataArrived)->iInternalCompensationId);
                  break;
 
               case ES_C_GetCompensations:
                  OnGetCompensationsAnswer(((GetCompensationsRT*)pDataArrived)->iTotalCompensations,
                                           ((GetCompensationsRT*)pDataArrived)->iInternalCompensationId,
                                           ((GetCompensationsRT*)pDataArrived)->cTrackerCompensationName,
                                           ((GetCompensationsRT*)pDataArrived)->cTrackerCompensationComment,
                                           ((GetCompensationsRT*)pDataArrived)->cADMCompensationName,
                                           ((GetCompensationsRT*)pDataArrived)->bHasMeasurementCameraMounted != 0);
                  break;

               case ES_C_GetCompensations2:
                  OnGetCompensations2Answer(((GetCompensations2RT*)pDataArrived)->iTotalCompensations,
                                            ((GetCompensations2RT*)pDataArrived)->iInternalCompensationId,
                                            ((GetCompensations2RT*)pDataArrived)->cTrackerCompensationName,
                                            ((GetCompensations2RT*)pDataArrived)->cTrackerCompensationComment,
                                            ((GetCompensations2RT*)pDataArrived)->cADMCompensationName,
                                            ((GetCompensations2RT*)pDataArrived)->cADMCompensationComment,
                                            ((GetCompensations2RT*)pDataArrived)->bHasMeasurementCameraMounted != 0,
                                            ((GetCompensations2RT*)pDataArrived)->bIsActive != 0);
                  break;

                case ES_C_GetTPInfo:
                  OnGetTPInfoAnswer(((GetTPInfoRT*)pDataArrived)->iTPBootMajorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->iTPBootMinorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMajorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMinorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMajorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMinorVersionNumber,
                                    ((GetTPInfoRT*)pDataArrived)->trackerprocessorType,
                                    ((GetTPInfoRT*)pDataArrived)->microProcessorType,
                                    ((GetTPInfoRT*)pDataArrived)->iMicroProcessorClockSpeed,
                                    ((GetTPInfoRT*)pDataArrived)->laserTrackerSensorType);
                  break;

               case ES_C_GetNivelInfo:
                  OnGetNivelInfoAnswer(((GetNivelInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                       ((GetNivelInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                       ((GetNivelInfoRT*)pDataArrived)->lSerialNumber);
                  break;

               case ES_C_SetLaserOnTimer:
                  OnSetLaserOnTimerAnswer();
                  break;

               case ES_C_GetLaserOnTimer:
                  OnGetLaserOnTimerAnswer(((GetLaserOnTimerRT*)pDataArrived)->iLaserOnTimeOffsetHour,
                                          ((GetLaserOnTimerRT*)pDataArrived)->iLaserOnTimeOffsetMinute);
                  break;

               case ES_C_GoBirdBath2:
                  OnGoBirdBath2Answer();
                  break;

               case ES_C_GetFace:
                  OnGetFaceAnswer(((GetFaceRT*)pDataArrived)->trackerFace);
                  break;

               case ES_C_SetLongSystemParameter:
                  OnSetLongSystemParamAnswer();
                  break;

               case ES_C_GetLongSystemParameter:
                  OnGetLongSystemParamAnswer(((GetLongSystemParamRT*)pDataArrived)->lParameter);
                  break;

               case ES_C_GetMeasurementStatusInfo:
                  OnGetMeasurementStatusInfoAnswer(((GetMeasurementStatusInfoRT*)pDataArrived)->lMeasurementStatusInfo);
                  break;
               case ES_C_SetDoubleSystemParameter:
                  OnSetDoubleSystemParamAnswer();
                  break;

               case ES_C_GetDoubleSystemParameter:
                  OnGetDoubleSystemParamAnswer(((GetDoubleSystemParamRT*)pDataArrived)->dParameter);
                  break;

               case ES_C_GetObjectTemperature:
                  OnGetObjectTemperatureAnswer(((GetObjectTemperatureRT*)pDataArrived)->dObjectTemperature);
                  break;

               case ES_C_GetOverviewCameraInfo:
                  OnGetOverviewCameraInfoAnswer(((GetOverviewCameraInfoRT*)pDataArrived)->cameraType,    
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->cCameraName, 
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->bIsColorCamera != 0,
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->dFocalLength,
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->dHorizontalChipSize,
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->dVerticalChipSize,
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageHz != 0,
                                                ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageVt != 0);
                  break;

               case ES_C_ClearCommandQueue:
                  OnClearCommandQueueAnswer();
                  break;

               case ES_C_GetADMInfo2:
                  OnGetADMInfo2Answer(((GetADMInfo2RT*)pDataArrived)->admType,
                                      ((GetADMInfo2RT*)pDataArrived)->cADMName,
                                      ((GetADMInfo2RT*)pDataArrived)->lSerialNumber,
                                      ((GetADMInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                      ((GetADMInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                      ((GetADMInfo2RT*)pDataArrived)->dMaxDistance,
                                      ((GetADMInfo2RT*)pDataArrived)->dMinDistance,
                                      ((GetADMInfo2RT*)pDataArrived)->iMaxDataRate,
                                      ((GetADMInfo2RT*)pDataArrived)->dAccuracyADMDistance);
                  break;

               case ES_C_GetTrackerInfo:
                  OnGetTrackerInfoAnswer(((GetTrackerInfoRT*)pDataArrived)->trackerType,
                                         ((GetTrackerInfoRT*)pDataArrived)->cTrackerName,
                                         ((GetTrackerInfoRT*)pDataArrived)->lSerialNumber,
                                         ((GetTrackerInfoRT*)pDataArrived)->lCompensationIdNumber, 
                                         ((GetTrackerInfoRT*)pDataArrived)->bHasADM != 0,
                                         ((GetTrackerInfoRT*)pDataArrived)->bHasOverviewCamera != 0,
                                         ((GetTrackerInfoRT*)pDataArrived)->bHasNivel != 0,
                                         ((GetTrackerInfoRT*)pDataArrived)->dNivelMountOffset,
                                         ((GetTrackerInfoRT*)pDataArrived)->dMaxDistance,
                                         ((GetTrackerInfoRT*)pDataArrived)->dMinDistance,
                                         ((GetTrackerInfoRT*)pDataArrived)->iMaxDataRate,
                                         ((GetTrackerInfoRT*)pDataArrived)->iNumberOfFaces,
                                         ((GetTrackerInfoRT*)pDataArrived)->dHzAngleRange,
                                         ((GetTrackerInfoRT*)pDataArrived)->dVtAngleRange,
                                         ((GetTrackerInfoRT*)pDataArrived)->accuracyModel,
                                         ((GetTrackerInfoRT*)pDataArrived)->iMajLCPFirmwareVersion,
                                         ((GetTrackerInfoRT*)pDataArrived)->iMinLCPFirmwareVersion);
                  break;

               case ES_C_GetNivelInfo2:
                  OnGetNivelInfo2Answer(((GetNivelInfo2RT*)pDataArrived)->nivelType,
                                        ((GetNivelInfo2RT*)pDataArrived)->cNivelName,
                                        ((GetNivelInfo2RT*)pDataArrived)->lSerialNumber,
                                        ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                        ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                        ((GetNivelInfo2RT*)pDataArrived)->dMeasurementRange,
                                        ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyOffset,
                                        ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyFactor);
                  break;

               case ES_C_RestoreStartupConditions:
                  OnRestoreStartupConditionsAnswer();
                  break;

               case ES_C_GetATRInfo:
                  OnGetATRInfoAnswer(((GetATRInfoRT*)pDataArrived)->atrType,
                                     ((GetATRInfoRT*)pDataArrived)->cATRName,
                                     ((GetATRInfoRT*)pDataArrived)->lMajFirmwareVersion,
                                     ((GetATRInfoRT*)pDataArrived)->lMinFirmwareVersion, 
                                     ((GetATRInfoRT*)pDataArrived)->lBuildFirmwareVersion,
                                     ((GetATRInfoRT*)pDataArrived)->lHardwareVersion,
                                     ((GetATRInfoRT*)pDataArrived)->lErrorcode,
                                     ((GetATRInfoRT*)pDataArrived)->lFPGAVersion,
                                     ((GetATRInfoRT*)pDataArrived)->dMaxDistance,
                                     ((GetATRInfoRT*)pDataArrived)->dMinDistance,
                                     ((GetATRInfoRT*)pDataArrived)->dFieldOfView,
                                     ((GetATRInfoRT*)pDataArrived)->dMaxTrackingSpeed);
                  break;

               case ES_C_GetMeteoStationInfo:
                  OnGetMeteoStationInfoAnswer(((GetMeteoStationInfoRT*)pDataArrived)->meteoStationType,
                                     ((GetMeteoStationInfoRT*)pDataArrived)->cIdentifier,
                                     ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                     ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber);
                  break;

               case ES_C_GetAT4xxInfo:
                  OnGetAT4xxInfoAnswer(((GetAT4xxInfoRT*)pDataArrived)->trackerType,
                                       ((GetAT4xxInfoRT*)pDataArrived)->cTrackerName,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lSerialNumber,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMajorFirmwareVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMinorFirmwareVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lProcessorBoardFWBuildNumber,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lSensorBoardFWBuildNumber,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMajorOSVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMinorOSVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMajorServerSoftwareVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMinorServerSoftwareVersion,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lServerSoftwareBuildNumber,
                                       ((GetAT4xxInfoRT*)pDataArrived)->wlanType,
                                       ((GetAT4xxInfoRT*)pDataArrived)->xscaleType,
                                       ((GetAT4xxInfoRT*)pDataArrived)->lMinMeasureTime,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dMinDistance,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dMaxDistance,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dStdDevDistOffsetADM,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleConst,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleOffset,
                                       ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleFactor);
                  break;

               case ES_C_GetSystemSoftwareVersion:
                  OnGetSystemSoftwareVersionAnswer(((GetSystemSoftwareVersionRT*)pDataArrived)->cSoftwareVersion);
                  break;

               default:
                  ASSERT(false); // uexpected answer
                  return false;  // treat as data receive error
                  break;
            } // switch

            break;
         } // ES_DT_Command

         case ES_DT_Error: 
            OnErrorAnswer(*(ErrorResponseT *)pDataArrived);
            break;

         case ES_DT_SingleMeasResult:  // A 'meas-result- type' answer has arrived
            OnSingleMeasurementAnswer(*(SingleMeasResultT *)pDataArrived);
            break;

         case ES_DT_NivelResult: 
            OnNivelMeasurementAnswer(*(NivelResultT *)pDataArrived);
            break;

         case ES_DT_ReflectorPosResult: 
            OnReflectorPosAnswer(*(ReflectorPosResultT *)pDataArrived);
            break;

         case ES_DT_SystemStatusChange: 
            OnSystemStatusChange(*(SystemStatusChangeT *)pDataArrived);
            break;

         case ES_DT_SingleMeasResult2:
            OnSingleMeasurement2Answer(*(SingleMeasResult2T *)pDataArrived);
            break;

         default:
            // Do not treat unknown packets as error - just ignore them
            TRACE(_T("Unexpected data received (ignored)\n"));
            break;
      } // switch

      return true;
   } // ProcessData()
};

class
#ifdef _CPP_API_EXT_DLL
	AFX_EXT_CLASS
#endif
Message
{
public:
	Message(char const * const packet, const long size) : _packet(packet), _size(size) { }

private:
	Message() : _packet(NULL), _size(0) { }
	char const * _packet;
	long _size;

public:
	/*** Basic Packet Inspection Functions ***/

	enum ES_DataType getType()
	{
		if (_packet == NULL)
		{
			return ES_DT_Unknown;
		}
		PacketHeaderT const * header = reinterpret_cast<PacketHeaderT const *>(_packet);
		return header->type;
	}

	/*** Packet Specialization Functions ***/

	BasicCommandRT const * getCommand()
	{
		if (_packet == NULL || getType() != ES_DT_Command)
		{
			return NULL;
		}
		return reinterpret_cast<BasicCommandRT const *>(_packet);
	}

	ErrorResponseT const * getError()
	{
		if (_packet == NULL || getType() != ES_DT_Error)
		{
			return NULL;
		}
		return reinterpret_cast<ErrorResponseT const *>(_packet);
	}

	SingleMeasResultT const * getSingleMeasurement()
	{
		if (_packet == NULL || getType() != ES_DT_SingleMeasResult)
		{
			return NULL;
		}
		return reinterpret_cast<SingleMeasResultT const *>(_packet);
	}

	NivelResultT const * getNivelMeasurement()
	{
		if (_packet == NULL || getType() != ES_DT_NivelResult)
		{
			return NULL;
		}
		return reinterpret_cast<NivelResultT const *>(_packet);
	}

	ReflectorPosResultT const * getReflectorPosition()
	{
		if (_packet == NULL || getType() != ES_DT_ReflectorPosResult)
		{
			return NULL;
		}
		return reinterpret_cast<ReflectorPosResultT const *>(_packet);
	}

	SystemStatusChangeT const * getSystemStatusChange()
	{
		if (_packet == NULL || getType() != ES_DT_SystemStatusChange)
		{
			return NULL;
		}
		return reinterpret_cast<SystemStatusChangeT const *>(_packet);
	}
//		InitializeRT

	InitializeRT const * getInitialize()
	{
		BasicCommandRT const * command = getCommand();
		if (command == NULL || command->command != ES_C_Initialize)
		{
			return NULL;
		}
		return reinterpret_cast<InitializeRT const *>(_packet);
	}
};

class
#ifdef _CPP_API_EXT_DLL
	AFX_EXT_CLASS
#endif
Decoder: public CESAPIReceive
{
public:
	Decoder() { }

	long getSize(char const * const packetPart)
	{
		if (packetPart == NULL)
		{
			return 0;
		}
		PacketHeaderT const * header = reinterpret_cast<PacketHeaderT const *>(packetPart);
		return header->lPacketSize;
	}

	Message decode(char const * const packet)
	{
		return Message(packet, getSize(packet));
	}
};

#ifdef ES_USE_EMSCON_NAMESPACE
};
#endif

#endif //ES_CPP_API_DEF_H

