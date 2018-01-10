
/******************************************************************************

Copyright (C) Leica Geosystems AG, 2001..2011

Filename: ES_MCPP_API_Def.h 

Description: Managed C++ wrapper for Leica Embedded Systems, for use 
             by C#- Applications.   

Notes: 
This file only comprises the interface for AT4xx 3D Tracker- types.            
It is an extract of the related full-featured include file (of same name)      
that is delivered with the emScon SDK). Applications addressing other tracker- 
types than AT4xx need to include the full-featured include file instead.       

******************************************************************************/

// Note: 
//
// The notation in this file still applies to .NET 1.0. It is still compatible with .NET 3.5
// applications, although the notation has changed for .NET 3.5. In order to leave this file
// compatible to .NET 1.0, these changes intentionally have not been applied yet. 
//
// Here are the main changes for .NET 3.5:
// 
// '__value struct'  becomes  'value struct'  (i.e. omit the leading double-underscores)
//
// 'public __value'  keywords in front of struct members are no longer necessary
//
// Example: the current notation...
//
// [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
// __value struct ContinuousTimeModeDataT
// {
//      public __value long lTimeSeparation;
//      public __value long lNumberOfPoints;    
//      public __value bool /*ES_BOOL*/ bUseRegion;
//      public __value ES_RegionType regionType;    
// };
//
// ...under .NET 3.5 becomes:
//
// [StructLayout(LayoutKind::Sequential, Pack=4)]
// value struct ContinuousTimeModeDataT
// {
//      long lTimeSeparation;
//      long lNumberOfPoints;    
//      bool /*ES_BOOL*/ bUseRegion;
//      ES_RegionType regionType;    
// };
//
// There is a new notation for array-type parameters (templates), Examples:
//
// virtual bool SendPacket(Byte packetAddress __gc [], int packetSize) = 0;
//
// becomes
//
// virtual bool SendPacket(array<Byte>^ packetAddress, int packetSize) abstract;
//
//
// bool DispatchData(void *data, int nSize)
// {
//     Byte pData __gc[] = new Byte __gc [nSize];
//     Byte __pin * pDest = &pData[0];
//     memcpy(pDest, data, nSize);
//     return SendPacket(pData, nSize);
// }
//
// becomes
//
// bool DispatchData(void *data, int nSize)
// {
//     array<Byte> ^ pData=gcnew array<Byte>(nSize);
//     pin_ptr<Byte> pDest = &pData[0];
//     memcpy(pDest, data, nSize);
//     return SendPacket(pData, nSize);
// }
//
//
// virtual void OnGetCamerasAnswer(int iCameraID, 
//                  int /*long*/ lSerialNumber, 
//                  ES_MeasurementCameraType cameraType,
//                  unsigned char cCameraName __gc [],
//                  unsigned char cComment __gc [], 
//                  int iCamerasTotal) {;}
//
// becomes
//
// virtual void OnGetCamerasAnswer(int iCameraID, 
//                  int /*long*/ lSerialNumber, 
//                  ES_MeasurementCameraType cameraType,
//                  array<unsigned char>^ cCameraName,
//                  array<unsigned char>^ cComment, 
//                  int iCamerasTotal) {;}
//
//
// Generally spoken, all keywords starting with double underscores
// (__gc, __value...) have become obsolete and Templates are 
// available for array-type parameters.
//
// Please note that above remarks are only hints - The definitive 
// syntax may still be slightly different or my change again with
// future versions. No tests have been performed with new .NET 3.5
// notation so far.
//
/////////////////////////////////////////////////////////////////////////////

// system include files
#include <memory.h> // used for memcpy()

// rather define TRUE locally instead of including <windef.h> 
#ifndef TRUE
#define TRUE  1
#endif

// CPP include files serve as base for the C# interface
#include "ES_CPP_API_Def.h"

#define ES_MCPP_API_MAJOR_VERSION 3  /* EmScon TPI/SDK V3.6 - Note: TPI/SDK Version..  */ 
#define ES_MCPP_API_MINOR_VERSION 6  /* not necessarily matches EmScon server version! */

#if ES_API_MAJOR_VERSION != ES_MCPP_API_MAJOR_VERSION
   #error Version conflict with EmScon API definition file (ES_C_API_Def.h) !
#endif
#if ES_API_MINOR_VERSION != ES_MCPP_API_MINOR_VERSION
   #error Version conflict with EmScon API definition file (ES_C_API_Def.h)!
#endif

// MC++/C# specific 'includes'
#using <mscorlib.dll>
using namespace System;
using namespace System::Runtime::InteropServices;

/////////////////////////////////////////////////////////////////////////////
// namespace EmScon

namespace EmScon
{
   // provide Enum types local to namespace EmScon

   #define  ES_MCPP_SUPPORT

   #undef ES_ENUM_H // force re-include
   #include "enum.h"

   #undef ES_C_API_DEF_H // force re-include
   #include "ES_C_API_Def.h"

   ///////////////////////////////////////////////////////////////////////////
   // class CESCSAPICommand

   public __gc __abstract class CESCSAPICommand
   {
   public:
      // structures related to class CESCSAPICommand

      // Remark: These (input parameter) structs are duplicated ones from ES_C_API_Def.h 
      // file. Make sure these always match those in ES_C_API_Def.h.

      // Important: ES_BOOL is defined as int. However, C# applications do not
      // allow casting int to bool. Since boolean variables in C# applications
      // should accept true/false as values rather than 0/1, all boolean 
      // variables defined as ES_BOOL in the C/C++ API have been replaced by 
      // 'bool' for the duplicated MCPP structures.
      // Comments /*ES_BOOL*/ have been left for documentation.

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationaryModeDataT
      {
         public __value long lMeasTime;
         public __value bool /*ES_BOOL*/ bUseADM;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemUnitsDataT
      {
         public __value ES_LengthUnit      lenUnitType;
         public __value ES_AngleUnit       angUnitType;
         public __value ES_TemperatureUnit tempUnitType;
         public __value ES_PressureUnit    pressUnitType;
         public __value ES_HumidityUnit    humUnitType;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemSettingsDataT
      {
         public __value ES_WeatherMonitorStatus weatherMonitorStatus;
         public __value bool /*ES_BOOL*/ bApplyTransformationParams;
         public __value bool /*ES_BOOL*/ bApplyStationOrientationParams;
         public __value bool /*ES_BOOL*/ bKeepLastPosition;
         public __value bool /*ES_BOOL*/ bSendUnsolicitedMessages;
         public __value bool /*ES_BOOL*/ bSendReflectorPositionData;
         public __value bool /*ES_BOOL*/ bTryMeasurementMode;
         public __value bool /*ES_BOOL*/ bHasNivel;
         public __value bool /*ES_BOOL*/ bHasVideoCamera;
      };  

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct EnvironmentDataT
      {
         public __value double dTemperature;
         public __value double dPressure;
         public __value double dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SearchParamsDataT
      {
         public __value double dSearchRadius;
         public __value long   lTimeOut;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationOrientationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
         public __value double dScale;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CameraParamsDataT
      {
         public __value int iContrast;
         public __value int iBrightness;
         public __value int iSaturation;
      };

   public:
      // SendPacket is a pure virtual function - MUST be overridden in derived class in C# client
      virtual bool SendPacket(Byte packetAddress __gc [], int packetSize) = 0;

   public:
      // Wrapped MC++ emScon API command methods that can be called from C# client
      bool Initialize() {CInitialize Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ActivateCameraView() {CActivateCameraView Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool Park() {CPark Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoLastMeasuredPoint() {CGoLastMeasuredPoint Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetSystemStatus() {CGetSystemStatus Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTrackerStatus() {CGetTrackerStatus Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetCoordinateSystemType(ES_CoordinateSystemType sysType) {CSetCoordinateSystemType Data((::ES_CoordinateSystemType)sysType); return DispatchData(&Data, sizeof(Data.DataPacket));}  
      bool GetCoordinateSystemType() {CGetCoordinateSystemType  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetMeasurementMode(ES_MeasMode mode) {CSetMeasurementMode Data((::ES_MeasMode)mode); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementMode() {CGetMeasurementMode Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetStationaryModeParams(long lMeasTime, bool bUseADM) {CSetStationaryModeParams Data(lMeasTime, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationaryModeParams(StationaryModeDataT stationaryModeData) {::StationaryModeDataT smd; 
         smd.lMeasTime = stationaryModeData.lMeasTime; 
         smd.bUseADM = stationaryModeData.bUseADM;
         CSetStationaryModeParams Data(smd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetStationaryModeParams() {CGetStationaryModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetReflectors() {CGetReflectors Data;return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetReflector() {CGetReflector Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetReflector(int reflID) {CSetReflector Data(reflID);return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetUnits(SystemUnitsDataT unitsSettings) {::SystemUnitsDataT su;
         su.lenUnitType = (::ES_LengthUnit)unitsSettings.lenUnitType;
         su.angUnitType = (::ES_AngleUnit)unitsSettings.angUnitType;
         su.tempUnitType = (::ES_TemperatureUnit)unitsSettings.tempUnitType;
         su.pressUnitType = (::ES_PressureUnit)unitsSettings.pressUnitType;
         su.humUnitType = (::ES_HumidityUnit)unitsSettings.humUnitType;
         CSetUnits Data(su); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetUnits(ES_LengthUnit lenUnitType, ES_AngleUnit angUnitType, ES_TemperatureUnit tempUnitType, ES_PressureUnit pressUnitType, ES_HumidityUnit humUnitType) {CSetUnits Data((::ES_LengthUnit)lenUnitType, (::ES_AngleUnit)angUnitType, (::ES_TemperatureUnit)tempUnitType, (::ES_PressureUnit)pressUnitType, (::ES_HumidityUnit)humUnitType); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetUnits() {CGetUnits Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSystemSettings(SystemSettingsDataT settings) {::SystemSettingsDataT ssd;
         ssd.weatherMonitorStatus = (::ES_WeatherMonitorStatus)settings.weatherMonitorStatus;
         ssd.bApplyStationOrientationParams = settings.bApplyStationOrientationParams;
         ssd.bApplyTransformationParams = settings.bApplyTransformationParams;
         ssd.bHasNivel = settings.bHasNivel;
         ssd.bHasVideoCamera = settings.bHasVideoCamera;
         ssd.bKeepLastPosition = settings.bKeepLastPosition;
         ssd.bSendReflectorPositionData = settings.bSendReflectorPositionData;
         ssd.bSendUnsolicitedMessages = settings.bSendUnsolicitedMessages;
         ssd.bTryMeasurementMode = settings.bTryMeasurementMode;
         CSetSystemSettings Data(ssd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSystemSettings() {CGetSystemSettings Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetEnvironmentParams(double dTemperature, double dPressure, double dHumidity) {CSetEnvironmentParams Data(dTemperature, dPressure, dHumidity); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetEnvironmentParams(EnvironmentDataT environmentData) {::EnvironmentDataT ed;
         ed.dTemperature = environmentData.dTemperature;
         ed.dPressure = environmentData.dPressure;
         ed.dHumidity = environmentData.dHumidity;
         CSetEnvironmentParams Data(ed); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetEnvironmentParams() {CGetEnvironmentParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetRefractionParams() {CGetRefractionParams  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetRefractionParams(double  ifmIndex, double admIndex) {CSetRefractionParams Data(ifmIndex, admIndex); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSearchParams() {CGetSearchParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSearchParams(SearchParamsDataT searchParams) {::SearchParamsDataT sp;
         sp.dSearchRadius = searchParams.dSearchRadius;
         sp.lTimeOut = searchParams.lTimeOut;
         CSetSearchParams Data(sp); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationOrientationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3) {CSetStationOrientationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationOrientationParams(StationOrientationDataT stationOrientation) {::StationOrientationDataT sod;
         sod.dVal1 = stationOrientation.dVal1;
         sod.dVal2 = stationOrientation.dVal2;
         sod.dVal3 = stationOrientation.dVal3;
         sod.dRot1 = stationOrientation.dRot1;
         sod.dRot2 = stationOrientation.dRot2;
         sod.dRot3 = stationOrientation.dRot3;
         CSetStationOrientationParams Data(sod); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetStationOrientationParams() {CGetStationOrientationParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTransformationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3, double dScale) {CSetTransformationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3, dScale); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetTransformationParams(TransformationDataT transformationData) {::TransformationDataT td;
         td.dVal1 = transformationData.dVal1;
         td.dVal2 = transformationData.dVal2;
         td.dVal3 = transformationData.dVal3;
         td.dRot1 = transformationData.dRot1;
         td.dRot2 = transformationData.dRot2;
         td.dRot3 = transformationData.dRot3;
         td.dScale = transformationData.dScale;
         CSetTransformationParams Data(td); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetTransformationParams() {CGetTransformationParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoPosition(double dVal1, double dVal2, double dVal3, bool bUseADM) {CGoPosition Data(dVal1, dVal2, dVal3, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoPositionHVD(double dHzAngle, double dVtAngle, double dDistance, bool bUseADM) {CGoPositionHVD Data(dHzAngle, dVtAngle, dDistance, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PointLaser(double dVal1, double dVal2, double dVal3) {CPointLaser Data(dVal1, dVal2, dVal3); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PointLaserHVD(double dHzAngle, double dVtAngle, double dDistance) {CPointLaserHVD Data(dHzAngle, dVtAngle, dDistance); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoNivelPosition(ES_NivelPosition position) {CGoNivelPosition Data((::ES_NivelPosition)position); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool MoveHV(long lHzSpeed, long lVtSpeed) {CMoveHV Data(lHzSpeed, lVtSpeed); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PositionRelativeHV(double dHz, double dVt) {CPositionRelativeHV Data(dHz, dVt); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoBirdBath() {CGoBirdBath Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ChangeFace() {CChangeFace Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool FindReflector(double dAproxDistance) {CFindReflector Data(dAproxDistance); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StartMeasurement() {CStartMeasurement Data;return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StartNivelMeasurement() {CStartNivelMeasurement Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StopMeasurement() {CStopMeasurement Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ExitApplication() {CExitApplication Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetDirection() {CGetDirection Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool CallOrientToGravity() {CCallOrientToGravity Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetCompensation(int iInternalCompensationId) {CSetCompensation  Data(iInternalCompensationId); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetStatisticMode(ES_StatisticMode stationaryMeasurements, ES_StatisticMode continuousMeasurements) {CSetStatisticMode Data((::ES_StatisticMode)stationaryMeasurements, (::ES_StatisticMode)continuousMeasurements); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetStatisticMode() {CGetStatisticMode  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCameraParams() {CGetCameraParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetCameraParams(CameraParamsDataT cameraParams) {::CameraParamsDataT cpd;
         cpd.iContrast = cameraParams.iContrast;
         cpd.iBrightness = cameraParams.iBrightness;
         cpd.iSaturation = cameraParams.iSaturation;
         CSetCameraParams Data(cpd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetCameraParams(int iContrast, int iBrightness, int iSaturation) {CSetCameraParams Data(iContrast, iBrightness, iSaturation); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCompensation() {CGetCompensation  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCompensations() {CGetCompensations Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCompensations2() {CGetCompensations2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTPInfo() {CGetTPInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetNivelInfo() {CGetNivelInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetLaserOnTimer() {CGetLaserOnTimer Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetLaserOnTimer(int iTimeOffsetHour, int iTimeOffsetMinute) {CSetLaserOnTimer Data(iTimeOffsetHour, iTimeOffsetMinute); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoBirdBath2(bool bClockwise) {CGoBirdBath2 Data(bClockwise); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetFace() {CGetFace Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetLongSystemParameter(ES_SystemParameter systemParam, long lParameter) {CSetLongSystemParam Data((::ES_SystemParameter)systemParam, lParameter); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetLongSystemParameter(ES_SystemParameter systemParam) {CGetLongSystemParam Data((::ES_SystemParameter)systemParam); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementStatusInfo() {CGetMeasurementStatusInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetDoubleSystemParameter(ES_SystemParameter systemParam, double dParameter) {CSetDoubleSystemParam Data((::ES_SystemParameter)systemParam, dParameter); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetDoubleSystemParameter(ES_SystemParameter systemParam) {CGetDoubleSystemParam Data((::ES_SystemParameter)systemParam); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetObjectTemperature() {CGetObjectTemperature Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetOverviewCameraInfo() {CGetOverviewCameraInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ClearCommandQueue(ES_ClearCommandQueueType ccqType) {CClearCommandQueue Data((::ES_ClearCommandQueueType)ccqType); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetADMInfo2() {CGetADMInfo2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTrackerInfo() {CGetTrackerInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetNivelInfo2() {CGetNivelInfo2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool RestoreStartupConditions() {CRestoreStartupConditions Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoAndMeasure(double dval1, double dval2, double dval3) {CGoAndMeasure Data(dval1, dval2, dval3); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetATRInfo() {CGetATRInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeteoStationInfo() {CGetMeteoStationInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetAT4xxInfo() {CGetAT4xxInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetSystemSoftwareVersion() {CGetSystemSoftwareVersion Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

   private:
      bool DispatchData(void *data, int nSize)
      {
         Byte pData __gc[] = new Byte __gc [nSize];  // Managed destination array
         Byte __pin * pDest = &pData[0];             // Pin the destination array
         memcpy(pDest, data, nSize);                 // Copy source to destination
         return SendPacket(pData, nSize);            // Send managed data to socket
      } // DispatchData()
   };  // class CESCSAPICommand


   ///////////////////////////////////////////////////////////////////////////
   // class CESCSAPIReceive

   public __gc __abstract class CESCSAPIReceive
   {
   public:
      // structures related to class CESCSAPICommand

      // Remark: These structs (for output paramters of virtual data  
      // receive handlers) are duplicated ones from ES_C_API_Def.h file.
      // Make sure these always match those in ES_C_API_Def.h.

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct PacketHeaderT
      {
         public __value long        lPacketSize;
         public __value ES_DataType type;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct BasicCommandRT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_Command      command;
         public __value ES_ResultStatus status;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ReturnDataT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_ResultStatus status;   
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ErrorResponseT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_Command      command;
         public __value ES_ResultStatus status;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemStatusChangeT
      {
         public __value PacketHeaderT         packetHeader;
         public __value ES_SystemStatusChange systemStatusChange;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemUnitsDataT
      {
         public __value ES_LengthUnit      lenUnitType;
         public __value ES_AngleUnit       angUnitType;
         public __value ES_TemperatureUnit tempUnitType;
         public __value ES_PressureUnit    pressUnitType;
         public __value ES_HumidityUnit    humUnitType;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationOrientationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
         public __value double dScale;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct EnvironmentDataT
      {
         public __value double dTemperature;
         public __value double dPressure;
         public __value double dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct RefractionDataT
      {
         public __value double dIfmRefractionIndex;
         public __value double dAdmRefractionIndex;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationaryModeDataT
      {
         public __value long    lMeasTime;
         public __value ES_BOOL bUseADM;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SearchParamsDataT
      {
         public __value double dSearchRadius;
         public __value long   lTimeOut;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemSettingsDataT
      {
         public __value ES_WeatherMonitorStatus weatherMonitorStatus;
         public __value ES_BOOL                 bApplyTransformationParams;
         public __value ES_BOOL                 bApplyStationOrientationParams;
         public __value ES_BOOL                 bKeepLastPosition;
         public __value ES_BOOL                 bSendUnsolicitedMessages;
         public __value ES_BOOL                 bSendReflectorPositionData;
         public __value ES_BOOL                 bTryMeasurementMode;
         public __value ES_BOOL                 bHasNivel;
         public __value ES_BOOL                 bHasVideoCamera;
      };  

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CameraParamsDataT
      {
         public __value int iContrast;
         public __value int iBrightness;
         public __value int iSaturation;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetUnitsRT
      {
         public __value BasicCommandRT   packetInfo;
         public __value SystemUnitsDataT unitsSettings;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetStationOrientationParamsRT
      {
         public __value  BasicCommandRT          packetInfo;
         public __value  StationOrientationDataT stationOrientation;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetTransformationParamsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  TransformationDataT transformationData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetEnvironmentParamsRT
      {
         public __value  BasicCommandRT   packetInfo;
         public __value  EnvironmentDataT environmentData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetRefractionParamsRT
      {
         public __value  BasicCommandRT  packetInfo;
         public __value  RefractionDataT refractionData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetStationaryModeParamsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  StationaryModeDataT stationaryModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSearchParamsRT
      {
         public __value  BasicCommandRT    packetInfo;
         public __value  SearchParamsDataT searchParams;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSystemSettingsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  SystemSettingsDataT systemSettings;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetCameraParamsRT
      {
         public __value  BasicCommandRT    packetInfo;
         public __value  CameraParamsDataT cameraParams;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ESVersionNumberT
      {
         public __value int iMajorVersionNumber;
         public __value int iMinorVersionNumber;
         public __value int iBuildNumber;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SingleMeasResultT
      {
         public __value ReturnDataT packetInfo;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dVal1;
         public __value double      dVal2;
         public __value double      dVal3;
         public __value double      dStd1;
         public __value double      dStd2;
         public __value double      dStd3;
         public __value double      dStdTotal;
         public __value double      dPointingError1;
         public __value double      dPointingError2;
         public __value double      dPointingError3;
         public __value double      dAprioriStd1;
         public __value double      dAprioriStd2;
         public __value double      dAprioriStd3;
         public __value double      dAprioriStdTotal;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SingleMeasResult2T
      {
         public __value ReturnDataT packetInfo;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dVal1;
         public __value double      dVal2;
         public __value double      dVal3;
         public __value double      dStd1;
         public __value double      dStd2;
         public __value double      dStd3;
         public __value double      dStdTotal;
         public __value double      dCovar12;
         public __value double      dCovar13;
         public __value double      dCovar23;
         public __value double      dPointingErrorH;
         public __value double      dPointingErrorV;
         public __value double      dPointingErrorD;
         public __value double      dAprioriStd1;
         public __value double      dAprioriStd2;
         public __value double      dAprioriStd3;
         public __value double      dAprioriStdTotal;
         public __value double      dAprioriCovar12;
         public __value double      dAprioriCovar13;
         public __value double      dAprioriCovar23;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MeasValueT
      {
         public __value ES_MeasurementStatus status;
         public __value long                 lTime1;
         public __value long                 lTime2;
         public __value double               dVal1;
         public __value double               dVal2;
         public __value double               dVal3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MeasValue2T
      {
         public __value ES_MeasurementStatus status;
         public __value long                 lTime1;
         public __value long                 lTime2;
         public __value double               dVal1;
         public __value double               dVal2;
         public __value double               dVal3;
         public __value double               dAprioriStd1;
         public __value double               dAprioriStd2;
         public __value double               dAprioriStd3;
         public __value double               dAprioriStdTotal;
         public __value double               dAprioriCovar12;
         public __value double               dAprioriCovar13;
         public __value double               dAprioriCovar23;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct NivelResultT
      {
         public __value ReturnDataT    packetInfo;
         public __value ES_NivelStatus nivelStatus;
         public __value double         dXTilt;
         public __value double         dYTilt;
         public __value double         dNivelTemperature;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ReflectorPosResultT
      {
         public __value ReturnDataT packetInfo;
         public __value double       dVal1;
         public __value double       dVal2;
         public __value double       dVal3;
      };

   public:
      CESCSAPIReceive() {m_pDataArrived = 0;} // constructor
      

      // ReceiveData to be called by client upon data arrival on socket.
      // Packets are assumed to be complete and single.
      //
      bool ReceiveData(Byte packetAddress __gc [], int packetSize) 
      { 
         if (packetAddress && packetSize > 0)
         {
            void __pin* pDat = &packetAddress[0];
            return ProcessData(pDat, packetSize);
         }
         else
            return false;
      } // ReceiveData


      // GetPacketHeader() allows extracting packet header info 
      // from byte streams (as received from socket in C# clients)
      //
      void GetPacketHeader(Byte packetAddress __gc [], [System::Runtime::InteropServices::Out] PacketHeaderT __gc *header)
      {
         PacketHeaderT dest;
         Byte __pin* pSrc = &packetAddress[0];

         memcpy(&dest, pSrc, sizeof(PacketHeaderT));
         *header = dest;
      } // ByteArrayToHeader()


   protected:
      // Virtual answer handlers - to be overridden by derived class  
      // as far as answers are of interest for client

      // Important: The 'long' data type in C/C++ is 4 bytes (the same as 'int'), 
      // but 8 bytes in C#. Indeed, 'long' data coming from emscon server is 
      // always 4 bytes. Virtual functions defined in MCPP class with 'long' 
      // parameters in fact must use 'int' parameters in derived C# classes.
      // To avoid confusion, all 'long' paramters have been changed to 'int'.
      // Comments /*long*/ have been left for documentation.

      // General handlers
      virtual void OnCommandAnswer(BasicCommandRT) {;}
      virtual void OnErrorAnswer(ErrorResponseT) {;}
      virtual void OnSystemStatusChange(SystemStatusChangeT) {;}
      virtual void OnUnknownAnswer() {;}

      // Measurement and Reflectors data handlers
      virtual void OnSingleMeasurementAnswer(SingleMeasResultT) {;}
      virtual void OnNivelMeasurementAnswer(NivelResultT) {;}
      virtual void OnReflectorPosAnswer(ReflectorPosResultT) {;}
      virtual void OnSingleMeasurement2Answer(SingleMeasResult2T) {;}

      // Particular command handlers (called in addition to OnCommandAnswer)

      virtual void OnExitApplicationAnswer() {;}

      virtual void OnGetSystemStatusAnswer(ES_ResultStatus           lastResultStatus,
                                           ES_TrackerProcessorStatus trackerProcessorStatus,
                                           ES_LaserProcessorStatus   laserStatus,
                                           ES_ADMStatus              admStatus,
                                           ESVersionNumberT          esVersionNumber,
                                           ES_WeatherMonitorStatus   weatherMonitorStatus,
                                           int /*long*/              lFlagsValue, // 'long' in C++ is 'int' in C# ! 
                                           int /*long*/              lTrackerSerialNumber) {;}

      virtual void OnGetTrackerStatusAnswer(ES_TrackerStatus) {;}
      virtual void OnSetUnitsAnswer() {;}
      virtual void OnGetUnitsAnswer(SystemUnitsDataT) {;}
      virtual void OnInitializeAnswer() {;}
      virtual void OnActivateCameraViewAnswer() {;}
      virtual void OnParkAnswer() {;}
      virtual void OnSetStationOrientationParamsAnswer() {;}
      virtual void OnGetStationOrientationParamsAnswer(StationOrientationDataT) {;}
      virtual void OnSetTransformationParamsAnswer() {;}
      virtual void OnGetTransformationParamsAnswer(TransformationDataT) {;}
      virtual void OnSetEnvironmentParamsAnswer() {;} 
      virtual void OnGetEnvironmentParamsAnswer(EnvironmentDataT) {;}
      virtual void OnSetRefractionParamsAnswer() {;}
      virtual void OnGetRefractionParamsAnswer(RefractionDataT) {;}
      virtual void OnSetMeasurementModeAnswer() {;}
      virtual void OnGetMeasurementModeAnswer(ES_MeasMode) {;}
      virtual void OnSetCoordinateSystemTypeAnswer() {;}
      virtual void OnGetCoordinateSystemTypeAnswer(ES_CoordinateSystemType) {;}
      virtual void OnSetStationaryModeParamsAnswer() {;}
      virtual void OnGetStationaryModeParamsAnswer(StationaryModeDataT) {;}
      virtual void OnSetReflectorAnswer() {;}
      virtual void OnGetReflectorAnswer(int iInternalReflectorId) {;}

      virtual void OnGetReflectorsAnswer(int           iTotalReflectors,
                                         int           iInternalReflectorId,
                                         ES_TargetType targetType,
                                         double        dSurfaceOffset,
                                         unsigned char cReflectorName __gc []) {;}

      virtual void OnSetSearchParamsAnswer() {;}
      virtual void OnGetSearchParamsAnswer(SearchParamsDataT) {;}
      virtual void OnSetSystemSettingsAnswer() {;}
      virtual void OnGetSystemSettingsAnswer(SystemSettingsDataT) {;}
      virtual void OnStartMeasurementAnswer() {;}
      virtual void OnStartNivelMeasurementAnswer() {;}
      virtual void OnStopMeasurementAnswer() {;}
      virtual void OnChangeFaceAnswer() {;}
      virtual void OnGoBirdBathAnswer() {;}
      virtual void OnGoPositionAnswer() {;}
      virtual void OnGoPositionHVDAnswer() {;}
      virtual void OnPositionRelativeHVAnswer() {;}
      virtual void OnPointLaserAnswer() {;}
      virtual void OnPointLaserHVDAnswer() {;}
      virtual void OnMoveHVAnswer() {;}
      virtual void OnGoNivelPositionAnswer() {;}
      virtual void OnGoLastMeasuredPointAnswer() {;}
      virtual void OnFindReflectorAnswer() {;}


      virtual void OnGetDirectionAnswer(double dHzAngle,
                                        double dVtAngle) {;}

      virtual void OnCallOrientToGravityAnswer(double dOmega,
                                               double dPhi) {;}

      virtual void OnSetCompensationAnswer() {;}

      virtual void OnSetStatisticModeAnswer() {;}

      virtual void OnGetStatisticModeAnswer(ES_StatisticMode stationaryMeasurements,
                                            ES_StatisticMode continuousMeasurements) {;}

      virtual void OnSetCameraParamsAnswer() {;}
      virtual void OnGetCameraParamsAnswer(CameraParamsDataT) {;}

      virtual void OnGetCompensationAnswer(int iInternalCompensationId) {;}

      virtual void OnGetCompensationsAnswer(int iTotalCompensations,
                                            int iInternalCompensationId,
                                            unsigned char cTrackerCompensationName __gc [],
                                            unsigned char cTrackerCompensationComment __gc [],
                                            unsigned char cADMCompensationName __gc [],
                                            bool bHasMeasurementCameraMounted) {;}

      virtual void OnGetCompensations2Answer(int iTotalCompensations,
                                             int iInternalCompensationId,
                                             unsigned char cTrackerCompensationName __gc [],
                                             unsigned char cTrackerCompensationComment __gc [],
                                             unsigned char cADMCompensationName __gc [],
                                             unsigned char cADMCompensationComment __gc [],
                                             bool bHasMeasurementCameraMounted,
                                             bool bIsActive) {;}

      virtual void OnGetTPInfoAnswer(int iTPBootMajorVersionNumber,
                                     int iTPBootMinorVersionNumber,
                                     int iTPFirmwareMajorVersionNumber,
                                     int iTPFirmwareMinorVersionNumber,
                                     int iLCPFirmwareMajorVersionNumber,
                                     int iLCPFirmwareMinorVersionNumber,
                                     ES_TrackerProcessorType trackerprocessorType,
                                     ES_TPMicroProcessorType microProcessorType,
                                     int iMicroProcessorClockSpeed,
                                     ES_LTSensorType laserTrackerSensorType) {;}

      virtual void OnGetNivelInfoAnswer(int iFirmwareMajorVersionNumber,
                                        int iFirmwareMinorVersionNumber,
                                        int /*long*/ lSerialNumber) {;}

      virtual void OnSetLaserOnTimerAnswer() {;}

      virtual void OnGetLaserOnTimerAnswer(int iLaserOnTimeOffsetHour,
                                           int iLaserOnTimeOffsetMinute) {;}

      virtual void OnGoBirdBath2Answer() {;}

      virtual void OnGetFaceAnswer(ES_TrackerFace) {;}

      virtual void OnSetLongSystemParamAnswer() {;}
      virtual void OnGetLongSystemParamAnswer(int /*long*/ lParameter) {;}
      virtual void OnGetMeasurementStatusInfoAnswer(int /*long*/ measurementStatusInfo) {;}

      virtual void OnSetDoubleSystemParamAnswer() {;}
      virtual void OnGetDoubleSystemParamAnswer(double dParameter) {;}
   
      virtual void OnGetObjectTemperatureAnswer(double dObjectTemperature) {;}

      virtual void OnGetOverviewCameraInfoAnswer(const ES_OverviewCameraType cameraType,
                                                 unsigned char cCameraName __gc[],
                                                 bool bIsColorCamera,
                                                 double dFocalLength,
                                                 double dHorizontalChipSize,
                                                 double dVerticalChipSize,
                                                 bool bMirrorImageHz,
                                                 bool bMirrorImageVt) {;}
  
      virtual void OnClearCommandQueueAnswer() {;}

      virtual void OnGetADMInfo2Answer(ES_ADMType admType,
                                       unsigned char cADMName __gc[],
                                       int /*long*/ lSerialNumber,
                                       int iFirmwareMajorVersionNumber,
                                       int iFirmwareMinorVersionNumber,
                                       double dMaxDistance,
                                       double dMinDistance,
                                       int iMaxDataRate,
                                       double dAccuracyADMDistance) {;}
   
      virtual void OnGetTrackerInfoAnswer(ES_LTSensorType trackerType,
                                          unsigned char cTrackerName __gc[],
                                          int /*long*/ lSerialNumber,
                                          int /*long*/ lCompensationIdNumber, 
                                          bool bHasADM,
                                          bool bHasOverviewCamera,
                                          bool bHasNivel,
                                          double dNivelMountOffset,
                                          double dMaxDistance,
                                          double dMinDistance,
                                          int iMaxDataRate,
                                          int iNumberOfFaces,
                                          double dHzAngleRange,
                                          double dVtAngleRange,
                                          ES_TrkAccuracyModel accuracyModel,
                                          int iMajLCPFirmwareVersion,
                                          int iMinLCPFirmwareVersion) {;}
   
      virtual void OnGetNivelInfo2Answer(ES_NivelType nivelType,
                                         unsigned char cNivelName __gc[],
                                         int /*long*/ lSerialNumber,
                                         int iFirmwareMajorVersionNumber,
                                         int iFirmwareMinorVersionNumber,
                                         double dMeasurementRange,
                                         double dMeasurementAccuracyOffset,
                                         double dMeasurementAccuracyFactor) {;}

      virtual void OnRestoreStartupConditionsAnswer() {;}

      virtual void OnGetATRInfoAnswer(ES_ATRType atrType,
                                      unsigned char cATRName __gc[],
                                      int /*long*/ lMajFirmwareVersion,
                                      int /*long*/ lMinFirmwareVersion,
                                      int /*long*/ lBuildFirmwareVersion, 
                                      int /*long*/ lHardwareVersion, 
                                      int /*long*/ lErrorcode, 
                                      int /*long*/ lFPGAVersion,
                                      double dMaxDistance,
                                      double dMinDistance,
                                      double dFieldOfView,
                                      double dMaxTrackingSpeed) {;}

      virtual void OnGetMeteoStationInfoAnswer(ES_MeteoStationType meteoStationType,
                                               unsigned char cMeteoStationIdentifier __gc[],
                                               int /*long*/ lMajFirmwareVersion,
                                               int /*long*/ lMinFirmwareVersion) {;}
      
      virtual void OnGetAT4xxInfoAnswer(ES_LTSensorType trackerType,
                                        unsigned char cTrackerName __gc[],
                                        int /*long*/ lSerialNumber,
                                        int /*long*/ lMajorFirmwareVersion,
                                        int /*long*/ lMinorFirmwareVersion,
                                        int /*long*/ lProcessorBoardFWBuildNumber,
                                        int /*long*/ lSensorBoardFWBuildNumber,
                                        int /*long*/ lMajorOSVersion,
                                        int /*long*/ lMinorOSVersion,
                                        int /*long*/ lMajorServerSoftwareVersion,
                                        int /*long*/ lMinorServerSoftwareVersion,
                                        int /*long*/ lServerSoftwareBuildNumber,
                                        ES_WLANType wlanType,
                                        ES_TPMicroProcessorType xscaleType,
                                        int /*long*/ lMinMeasureTime,
                                        double dMinDistance,
                                        double dMaxDistance,
                                        double dStdDevDistOffsetADM,
                                        double dStdDevAngleConst,
                                        double dStdDevAngleOffset,
                                        double dStdDevAngleFactor) {;}

      virtual void OnGetSystemSoftwareVersionAnswer(unsigned char cSoftwareVersion __gc[]) {;}

   protected:
      virtual bool ProcessData(void* pDataArrived, long lBytes)
      {
         // See ProcessData() equivalent in ES_CPP_API_Def.h file for further explanation.

         // mask arrived data with RT structure in order to figure out type/status
         PacketHeaderT *pData = (PacketHeaderT*)pDataArrived;

         // Diagnostics and overflow prevention.
         if (pData->lPacketSize != lBytes)
         {
            // Beep(300, 50); // info tracing in debug mode only!
            //TRACE2("PacketSize (%ld) differs from TotalBytes (%ld) !\n", pData->lPacketSize, lBytes);

            return false; // causes to signal a data receive error
         } // if

         switch (pData->type)
         {
            case ES_DT_Command: // A 'command- type' answer has arrived
            {
               // decode type of command
               BasicCommandRT *pData2 = (BasicCommandRT *)pDataArrived;

               // call general virtual function for commands
               OnCommandAnswer(*pData2);

               // handle error
               if (pData2->status != ES_RS_AllOK)
                  return true; // Exit here, but make sure pData2->status gets forwared.
                            // Do not return false, since data was correctly received.

               // decode type of command
               switch (pData2->command)
               {
                  case ES_C_ExitApplication:
                     OnExitApplicationAnswer();
                     break;

                  case ES_C_GetSystemStatus:
                     {
                     ESVersionNumberT versionNumber;

                     // Compiler does not directly accept '((GetSystemStatusRT*)pDataArrived)->esVersionNumber' as parameter.
                     versionNumber.iBuildNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iBuildNumber;
                     versionNumber.iMajorVersionNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iMajorVersionNumber;
                     versionNumber.iMinorVersionNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iMinorVersionNumber;

                     OnGetSystemStatusAnswer((ES_ResultStatus)((GetSystemStatusRT*)pDataArrived)->lastResultStatus,
                                             (ES_TrackerProcessorStatus)((GetSystemStatusRT*)pDataArrived)->trackerProcessorStatus,
                                             (ES_LaserProcessorStatus)((GetSystemStatusRT*)pDataArrived)->laserStatus,
                                             (ES_ADMStatus)((GetSystemStatusRT*)pDataArrived)->admStatus,
                                             versionNumber, // workaround for problem mentioned above
                                             (ES_WeatherMonitorStatus)((GetSystemStatusRT*)pDataArrived)->weatherMonitorStatus,
                                             ((GetSystemStatusRT*)pDataArrived)->lFlagsValue,
                                             ((GetSystemStatusRT*)pDataArrived)->lTrackerSerialNumber);
                     }
                     break;
    
                  case ES_C_GetTrackerStatus:
                     OnGetTrackerStatusAnswer((ES_TrackerStatus)((GetTrackerStatusRT*)pDataArrived)->trackerStatus);
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
                     OnGetMeasurementModeAnswer((ES_MeasMode)((GetMeasurementModeRT*)pDataArrived)->measMode);
                     break;

                  case ES_C_SetCoordinateSystemType:
                     OnSetCoordinateSystemTypeAnswer();
                     break;

                  case ES_C_GetCoordinateSystemType:
                     OnGetCoordinateSystemTypeAnswer((ES_CoordinateSystemType)((GetCoordinateSystemTypeRT*)pDataArrived)->coordSysType);
                     break;

                  case ES_C_SetStationaryModeParams:
                     OnSetStationaryModeParamsAnswer();
                     break;

                  case ES_C_GetStationaryModeParams:
                     OnGetStationaryModeParamsAnswer(((GetStationaryModeParamsRT*)pDataArrived)->stationaryModeData);
                     break;

                  case ES_C_GetReflector:
                     OnGetReflectorAnswer(((GetReflectorRT*)pDataArrived)->iInternalReflectorId);
                     break;

                  case ES_C_SetReflector:
                     OnSetReflectorAnswer();
                     break;

                  case ES_C_GetReflectors:
                     {
                        Byte pName __gc[] = StringToByteArray(sizeof(((GetReflectorsRT*)pDataArrived)->cReflectorName),
                                                              &((GetReflectorsRT*)pDataArrived)->cReflectorName[0]);

                        OnGetReflectorsAnswer(((GetReflectorsRT*)pDataArrived)->iTotalReflectors,
                                              ((GetReflectorsRT*)pDataArrived)->iInternalReflectorId,
                                              (ES_TargetType)((GetReflectorsRT*)pDataArrived)->targetType,
                                              ((GetReflectorsRT*)pDataArrived)->dSurfaceOffset,
                                               pName);
                     }
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
                     OnStartMeasurementAnswer();
                     break;

                  case ES_C_StartNivelMeasurement:
                     OnStartNivelMeasurementAnswer(); // Never called - leave for completeness
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
                     OnGetStatisticModeAnswer((ES_StatisticMode)((GetStatisticModeRT*)pDataArrived)->stationaryMeasurements,
                                              (ES_StatisticMode)((GetStatisticModeRT*)pDataArrived)->continuousMeasurements);
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
                     {
                        Byte pTrkCompName __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cTrackerCompensationName),
                                                                     &((GetCompensationsRT*)pDataArrived)->cTrackerCompensationName[0]);

                        Byte pTrkCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cTrackerCompensationComment),
                                                                    &((GetCompensationsRT*)pDataArrived)->cTrackerCompensationComment[0]);

                        Byte pAdmCompName __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cADMCompensationName),
                                                                     &((GetCompensationsRT*)pDataArrived)->cADMCompensationName[0]);

                        OnGetCompensationsAnswer(((GetCompensationsRT*)pDataArrived)->iTotalCompensations,
                                                 ((GetCompensationsRT*)pDataArrived)->iInternalCompensationId,
                                                  pTrkCompName,
                                                  pTrkCompCmt,
                                                  pAdmCompName,
                                                  ((GetCompensationsRT*)pDataArrived)->bHasMeasurementCameraMounted != 0);
                     }
                     break;

                     case ES_C_GetCompensations2:
                     {
                        Byte pTrkCompName __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cTrackerCompensationName),
                                                                     &((GetCompensations2RT*)pDataArrived)->cTrackerCompensationName[0]);

                        Byte pTrkCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cTrackerCompensationComment),
                                                                    &((GetCompensations2RT*)pDataArrived)->cTrackerCompensationComment[0]);

                        Byte pAdmCompName __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cADMCompensationName),
                                                                     &((GetCompensations2RT*)pDataArrived)->cADMCompensationName[0]);

                        Byte pAdmCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cADMCompensationComment),
                                                                    &((GetCompensations2RT*)pDataArrived)->cADMCompensationComment[0]);

                        OnGetCompensations2Answer(((GetCompensations2RT*)pDataArrived)->iTotalCompensations,
                                                  ((GetCompensations2RT*)pDataArrived)->iInternalCompensationId,
                                                  pTrkCompName,
                                                  pTrkCompCmt,
                                                  pAdmCompName,
                                                  pAdmCompCmt,
                                                  ((GetCompensations2RT*)pDataArrived)->bHasMeasurementCameraMounted != 0,
                                                  ((GetCompensations2RT*)pDataArrived)->bIsActive != 0);
                     }
                     break;

                  case ES_C_GetTPInfo:
                     OnGetTPInfoAnswer(((GetTPInfoRT*)pDataArrived)->iTPBootMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPBootMinorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMinorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMinorVersionNumber,
                                       (ES_TrackerProcessorType)((GetTPInfoRT*)pDataArrived)->trackerprocessorType,
                                       (ES_TPMicroProcessorType)((GetTPInfoRT*)pDataArrived)->microProcessorType,
                                       ((GetTPInfoRT*)pDataArrived)->iMicroProcessorClockSpeed,
                                       (ES_LTSensorType)((GetTPInfoRT*)pDataArrived)->laserTrackerSensorType);
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
                     OnGetFaceAnswer((ES_TrackerFace)((GetFaceRT*)pDataArrived)->trackerFace);
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
                     {
                        Byte pCameraName __gc[] = StringToByteArray(sizeof(((GetOverviewCameraInfoRT*)pDataArrived)->cCameraName),
                                    &((GetOverviewCameraInfoRT*)pDataArrived)->cCameraName[0]);

                        OnGetOverviewCameraInfoAnswer((ES_OverviewCameraType)((GetOverviewCameraInfoRT*)pDataArrived)->cameraType,    
                                                      pCameraName, 
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bIsColorCamera != 0,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dFocalLength,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dHorizontalChipSize,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dVerticalChipSize,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageHz != 0,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageVt != 0);
                     }
                     break;

                  case ES_C_ClearCommandQueue:
                     OnClearCommandQueueAnswer();
                     break;

                  case ES_C_GetADMInfo2:
                     {
                        Byte pADMName __gc[] = StringToByteArray(sizeof(((GetADMInfo2RT*)pDataArrived)->cADMName),
                                    &((GetADMInfo2RT*)pDataArrived)->cADMName[0]);

                        OnGetADMInfo2Answer(((ES_ADMType)((GetADMInfo2RT*)pDataArrived)->admType),
                                            pADMName,
                                            ((GetADMInfo2RT*)pDataArrived)->lSerialNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->dMaxDistance,
                                            ((GetADMInfo2RT*)pDataArrived)->dMinDistance,
                                            ((GetADMInfo2RT*)pDataArrived)->iMaxDataRate,
                                            ((GetADMInfo2RT*)pDataArrived)->dAccuracyADMDistance);
                     }
                     break;

                  case ES_C_GetTrackerInfo:
                     {
                        Byte pTrackerName __gc[] = StringToByteArray(sizeof(((GetTrackerInfoRT*)pDataArrived)->cTrackerName),
                                    &((GetTrackerInfoRT*)pDataArrived)->cTrackerName[0]);

                        OnGetTrackerInfoAnswer((ES_LTSensorType)((GetTrackerInfoRT*)pDataArrived)->trackerType,
                                               pTrackerName,
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
                                               ((ES_TrkAccuracyModel)((GetTrackerInfoRT*)pDataArrived)->accuracyModel),
                                               ((GetTrackerInfoRT*)pDataArrived)->iMajLCPFirmwareVersion,
                                               ((GetTrackerInfoRT*)pDataArrived)->iMinLCPFirmwareVersion);
                     }
                     break;

                  case ES_C_GetNivelInfo2:
                     {
                        Byte pNivelName __gc[] = StringToByteArray(sizeof(((GetNivelInfo2RT*)pDataArrived)->cNivelName),
                                    &((GetNivelInfo2RT*)pDataArrived)->cNivelName[0]);

                        OnGetNivelInfo2Answer(((ES_NivelType)((GetNivelInfo2RT*)pDataArrived)->nivelType),
                                              pNivelName,
                                              ((GetNivelInfo2RT*)pDataArrived)->lSerialNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementRange,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyOffset,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyFactor);
                     }
                     break;

                  case ES_C_RestoreStartupConditions:
                     OnRestoreStartupConditionsAnswer();
                     break;

                  case ES_C_GetATRInfo:
                     {
                        Byte pATRName __gc[] = StringToByteArray(sizeof(((GetATRInfoRT*)pDataArrived)->cATRName),
                                    &((GetATRInfoRT*)pDataArrived)->cATRName[0]);

                        OnGetATRInfoAnswer((ES_ATRType)((GetATRInfoRT*)pDataArrived)->atrType,
                                           pATRName,
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
                     }
                     break;

                  case ES_C_GetMeteoStationInfo:
                     {
                        Byte pMeteoStatIdent __gc[] = StringToByteArray(sizeof(((GetMeteoStationInfoRT*)pDataArrived)->cIdentifier),
                                    &((GetMeteoStationInfoRT*)pDataArrived)->cIdentifier[0]);

                        OnGetMeteoStationInfoAnswer((ES_MeteoStationType)((GetMeteoStationInfoRT*)pDataArrived)->meteoStationType,
                                                    pMeteoStatIdent,
                                                    ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                                    ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber);
                     }
                     break;

                   case ES_C_GetAT4xxInfo:
                     {
                        Byte pAT4xxIdent __gc[] = StringToByteArray(sizeof(((GetAT4xxInfoRT*)pDataArrived)->cTrackerName),
                                    &((GetAT4xxInfoRT*)pDataArrived)->cTrackerName[0]);

                        OnGetAT4xxInfoAnswer((ES_LTSensorType)((GetAT4xxInfoRT*)pDataArrived)->trackerType,
                                             pAT4xxIdent,
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
                                             (ES_WLANType)((GetAT4xxInfoRT*)pDataArrived)->wlanType,
                                             (ES_TPMicroProcessorType)((GetAT4xxInfoRT*)pDataArrived)->xscaleType,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMinMeasureTime,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dMinDistance,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dMaxDistance,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevDistOffsetADM,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleConst,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleOffset,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleFactor);
                     }
                     break;

                  case ES_C_GetSystemSoftwareVersion:
                     {
                        Byte pSoftwareVersion __gc[] = StringToByteArray(sizeof(((GetSystemSoftwareVersionRT*)pDataArrived)->cSoftwareVersion),
                                    &((GetSystemSoftwareVersionRT*)pDataArrived)->cSoftwareVersion[0]);

                        OnGetSystemSoftwareVersionAnswer(pSoftwareVersion);
                     }
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

            case ES_DT_SingleMeasResult: 
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
               //TRACE(_T("Unexpected data received (ignored)\n"));
               break;
         } // switch

         return true;
      } // ProcessData()

   private:
      Byte StringToByteArray(int nSize, unsigned short* str)[]
      {
         Byte pData __gc[] = new Byte __gc [2*nSize];
         Byte __pin* pDest = &pData[0];
         memcpy(pDest, str, nSize);
         return pData; // caller must free this string!
      } // StringToByteArray()

   private:
      void *m_pDataArrived;

   }; // class CESCSAPIReceive
}; // namespace EmScon

