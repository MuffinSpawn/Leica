
#include <atomic>
#include <exception>
#include <string>
#include <list>
#include<winsock2.h>

#include "ES_C_API_Def.h"
#include "ES_CPP_API_Def.h"

#define DEFAULT_BUFLEN 512

namespace CESAPI {

  /*** Class Declarations ***/

  class
#ifdef _CPP_API_EXT_DLL
    AFX_EXT_CLASS
#endif
    ConnectionException;
  class
#ifdef _CPP_API_EXT_DLL
    AFX_EXT_CLASS
#endif
    Connection;
  class
#ifdef _CPP_API_EXT_DLL
    AFX_EXT_CLASS
#endif
    CommandAsync;
  class
#ifdef _CPP_API_EXT_DLL
    AFX_EXT_CLASS
#endif
    CommandSync;


  /*** ConnectionException Class Definition ***/

  class ConnectionException : public std::exception {
  private:
    std::string _what;

  public:
    ConnectionException() : _what("") {}
    ConnectionException(std::string what) : _what(what) {}
    const char * what() const throw () {
      return _what.c_str();
    }
  };


  /*** Connection Class Definition ***/

  class Connection {
    friend class CommandAsync;
  private:
    mutable SOCKET _socket;
    mutable char _receive_buffer[DEFAULT_BUFLEN];
    CommandAsync const * _commandAsync;
    CommandSync const * _commandSync;
    void SendPacket(void const * const packet) const;
    void const * ReceivePacket() const;

  public:
    Connection();
    Connection::~Connection();
    void Connect() const;  // uses default address and port
    void Connect(const std::string address, const uint16_t port) const;
    void Disconnect() const;
  };


  /*** CommandAsync Class Definition ***/

  class CommandAsync : public CESAPICommand {
    friend class Connection;
    friend class CommandSync;
  private:
    Connection const * _connection;
    std::list<CESAPIReceive *> _receivers;
    CommandAsync() {}  // not used

    /* functions invoked only by Connection */
    CommandAsync(Connection const * connection) : _connection(connection) {}
    void StartReceiving() const;
    void StopReceiving() const;

    /* functions invoked internally */
    bool SendPacket(void const * const PacketStart, const long PacketSize) const;
    void NotifyReceivers(void const * const packet, long packetSize);

  public:
    void RegisterReceiver(CESAPIReceive * receiver);
    void UnregisterReceiver(CESAPIReceive * receiver);
  };


  /*** CommandSync Class Definition ***/

  class MonitoringState {
  private:
    bool _enabled;
    ES_Command _command;
  public:
    MonitoringState() : _enabled(false), _command(ES_C_Unknown) {}
    ES_Command command() {
      return _command;
    }
    void enable(ES_Command command) {
      if (_enabled) {
        throw ConnectionException("busy monitoring command " + std::to_string(_command));
      }
      _enabled = true;
      _command = command;
    }
    void disable() {
      _enabled = false;
      _command = ES_C_Unknown;
    }
  };

  class CommandSync : public CESAPICommand, CESAPIReceive {
    friend class Connection;
    friend class CommandAsync;
  private:
    CommandAsync const * _commandAsync;
    void * _packet;
    mutable std::atomic<MonitoringState> _monitoring;

    CommandSync() {}
    CommandSync(CommandAsync const * commandAsync) : _commandAsync(commandAsync), _packet(NULL) {}
    bool SendPacket(void const * const PacketStart, const long PacketSize) const;
    // bool ProcessData(void *pDataArrived, long lBytes);
    void StopMonitoringIfTarget(const ES_DataType targetType);
    void StopMonitoringIfTargetCommand(const ES_DataType targetType, const ES_Command targetCommand);
    
    /*
    // Message type handlers
    void OnErrorAnswer(const ErrorResponseT& error);
    void OnSystemStatusChange(const SystemStatusChangeT& status);
    void OnUnknownAnswer(); // should never happen
    void OnSingleMeasurementAnswer(const SingleMeasResultT& singleMeas);
    void OnNivelMeasurementAnswer(const NivelResultT& nivelResult);
    void OnReflectorPosAnswer(const ReflectorPosResultT& reflPos);
    void OnSingleMeasurement2Answer(const SingleMeasResult2T& singleMeas);

    // Command message type handlers
    void OnExitApplicationAnswer();
    void OnGetSystemStatusAnswer(const ES_ResultStatus           lastResultStatus,
      const ES_TrackerProcessorStatus trackerProcessorStatus,
      const ES_LaserProcessorStatus   laserStatus,
      const ES_ADMStatus              admStatus,
      const ESVersionNumberT          esVersionNumber,
      const ES_WeatherMonitorStatus   weatherMonitorStatus,
      const long lFlagsValue,
      const long lTrackerSerialNumber);
    void OnGetTrackerStatusAnswer(const ES_TrackerStatus trackerStatus);
    void OnSetUnitsAnswer();
    void OnGetUnitsAnswer(const SystemUnitsDataT& unitsSettings);
    */
    void OnInitializeAnswer();
    /*
    void OnActivateCameraViewAnswer();
    void OnParkAnswer();
    void OnSetStationOrientationParamsAnswer();
    void OnGetStationOrientationParamsAnswer(const StationOrientationDataT& stationOrientation);
    void OnSetTransformationParamsAnswer();
    void OnGetTransformationParamsAnswer(const TransformationDataT& transformationData);
    void OnSetEnvironmentParamsAnswer();
    void OnGetEnvironmentParamsAnswer(const EnvironmentDataT& environmentData);
    void OnSetRefractionParamsAnswer();
    void OnGetRefractionParamsAnswer(const RefractionDataT& refractionData);
    void OnSetMeasurementModeAnswer();
    void OnGetMeasurementModeAnswer(const ES_MeasMode measMode);
    void OnSetCoordinateSystemTypeAnswer();
    void OnGetCoordinateSystemTypeAnswer(const ES_CoordinateSystemType coordSysType);
    void OnSetStationaryModeParamsAnswer();
    void OnGetStationaryModeParamsAnswer(const StationaryModeDataT& stationaryModeData);
    void OnSetReflectorAnswer();
    void OnGetReflectorAnswer(const int iInternalReflectorId);
    void OnGetReflectorsAnswer(const int            iTotalReflectors,
      const int            iInternalReflectorId,
      const ES_TargetType  targetType,
      const double         dSurfaceOffset,
      const unsigned short cReflectorName[32]);
    void OnSetSearchParamsAnswer();
    void OnGetSearchParamsAnswer(const SearchParamsDataT& searchParams);
    void OnSetSystemSettingsAnswer();
    void OnGetSystemSettingsAnswer(const SystemSettingsDataT& systemSettings);
    void OnStartMeasurementAnswer();
    void OnStartNivelMeasurementAnswer();
    void OnStopMeasurementAnswer();
    void OnChangeFaceAnswer();
    void OnGoBirdBathAnswer();
    void OnGoPositionAnswer();
    void OnGoPositionHVDAnswer();
    void OnPositionRelativeHVAnswer();
    void OnPointLaserAnswer();
    void OnPointLaserHVDAnswer();
    void OnMoveHVAnswer();
    void OnGoNivelPositionAnswer();
    void OnGoLastMeasuredPointAnswer();
    void OnFindReflectorAnswer();
    void OnGetDirectionAnswer(const double dHzAngle, const double dVtAngle);
    void OnCallOrientToGravityAnswer(const double dOmega, const double dPhi);
    void OnSetCompensationAnswer();
    void OnSetStatisticModeAnswer();
    void OnGetStatisticModeAnswer(const ES_StatisticMode stationaryMeasurements,
      const ES_StatisticMode continuousMeasurements);
    void OnSetCameraParamsAnswer();
    void OnGetCameraParamsAnswer(const CameraParamsDataT& cameraParamsData);
    void OnGetCompensationAnswer(const int iInternalCompensationId);
    void OnGetCompensationsAnswer(const int iTotalCompensations,
      const int iInternalCompensationId,
      const unsigned short cTrackerCompensationName[32],
      const unsigned short cTrackerCompensationComment[128],
      const unsigned short cADMCompensationName[32],
      const bool bHasMeasurementCameraMounted);
    void OnGetCompensations2Answer(const int iTotalCompensations,
      const int iInternalCompensationId,
      const unsigned short cTrackerCompensationName[32],
      const unsigned short cTrackerCompensationComment[128],
      const unsigned short cADMCompensationName[32],
      const unsigned short cADMCompensationComment[128],
      const bool bHasMeasurementCameraMounted,
      const bool bIsActive);
    void OnGetTPInfoAnswer(const int  iTPBootMajorVersionNumber,
      const int  iTPBootMinorVersionNumber,
      const int  iTPFirmwareMajorVersionNumber,
      const int  iTPFirmwareMinorVersionNumber,
      const int  iLCPFirmwareMajorVersionNumber,
      const int  iLCPFirmwareMinorVersionNumber,
      const ES_TrackerProcessorType trackerprocessorType,
      const ES_TPMicroProcessorType microProcessorType,
      const int  iMicroProcessorClockSpeed,
      const ES_LTSensorType laserTrackerSensorType);
    void OnGetNivelInfoAnswer(const int iFirmwareMajorVersionNumber,
      const int iFirmwareMinorVersionNumber,
      const long lSerialNumber);
    void OnSetLaserOnTimerAnswer();
    void OnGetLaserOnTimerAnswer(const int iLaserOnTimeOffsetHour,
      const int iLaserOnTimeOffsetMinute);
    void OnGoBirdBath2Answer();
    void OnGetFaceAnswer(const ES_TrackerFace trackerFace);
    void OnSetLongSystemParamAnswer();
    void OnGetLongSystemParamAnswer(const long lParameter);
    void OnGetMeasurementStatusInfoAnswer(const long measurementStatusInfo);
    void OnSetDoubleSystemParamAnswer();
    void OnGetDoubleSystemParamAnswer(const double dParameter);
    void OnGetObjectTemperatureAnswer(const double dObjectTemperature);
    void OnGetOverviewCameraInfoAnswer(const ES_OverviewCameraType cameraType,
      const unsigned short cCameraName[32],
      const bool bIsColorCamera,
      const double dFocalLength,
      const double dHorizontalChipSize,
      const double dVerticalChipSize,
      const bool bMirrorImageHz,
      const bool bMirrorImageVt);
    void OnClearCommandQueueAnswer();
    void OnGetADMInfo2Answer(const ES_ADMType admType,
      const unsigned short cADMName[32],
      const long lSerialNumber,
      const int iFirmwareMajorVersionNumber,
      const int iFirmwareMinorVersionNumber,
      const double dMaxDistance,
      const double dMinDistance,
      const int iMaxDataRate,
      const double dAccuracyADMDistance);
    void OnGetTrackerInfoAnswer(const ES_LTSensorType trackerType,
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
      const int iMinLCPFirmwareVersion);
    void OnGetNivelInfo2Answer(const ES_NivelType nivelType,
      const unsigned short cNivelName[32],
      const long lSerialNumber,
      const int iFirmwareMajorVersionNumber,
      const int iFirmwareMinorVersionNumber,
      const double dMeasurementRange,
      const double dMeasurementAccuracyOffset,
      const double dMeasurementAccuracyFactor);
    void OnRestoreStartupConditionsAnswer();
    void OnGetATRInfoAnswer(const ES_ATRType atrType,
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
      const double dMaxTrackingSpeed);
    void OnGetMeteoStationInfoAnswer(const ES_MeteoStationType meteoStationType,
      const unsigned short cIdentifier[32],
      const long iFirmwareMajorVersionNumber,
      const long iFirmwareMinorVersionNumber);
    void OnGetAT4xxInfoAnswer(const ES_LTSensorType trackerType,
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
      const double dStdDevAngleFactor);
    void OnGetSystemSoftwareVersionAnswer(const unsigned short cSoftwareVersion[32]);
    */
    void StartMonitoring(const ES_DataType targetType, const ES_Command targetCommand);
    void WaitWhileMonitoring();

  public:
    InitializeRT const * Initialize();
    ActivateCameraViewRT const * ActivateCameraView();
    ParkRT const * Park();
    GoLastMeasuredPointRT const * GoLastMeasuredPoint();
    GetSystemStatusRT const * GetSystemStatus();
    GetTrackerStatusRT const * GetTrackerStatus();
    SetCoordinateSystemTypeRT const * SetCoordinateSystemType(ES_CoordinateSystemType sysType);
    GetCoordinateSystemTypeRT const * GetCoordinateSystemType();
    SetMeasurementModeRT const * SetMeasurementMode(ES_MeasMode mode);
    GetMeasurementModeRT const * GetMeasurementMode();
    SetStationaryModeParamsRT const * SetStationaryModeParams(long lMeasTime, bool bUseADM);
    SetStationaryModeParamsRT const * SetStationaryModeParams(StationaryModeDataT stationaryModeData);
    GetStationaryModeParamsRT const * GetStationaryModeParams();
    GetReflectorsRT const * GetReflectors();
    GetReflectorRT const * GetReflector();
    SetReflectorRT const * SetReflector(int iInternalReflectorId);
    SetUnitsRT const * SetUnits(SystemUnitsDataT unitsSettings);
    SetUnitsRT const * SetUnits(ES_LengthUnit lenUnitType, ES_AngleUnit angUnitType, ES_TemperatureUnit tempUnitType, ES_PressureUnit pressUnitType, ES_HumidityUnit humUnitType);
    GetUnitsRT const * GetUnits();
    SetSystemSettingsRT const * SetSystemSettings(SystemSettingsDataT settings);
    GetSystemSettingsRT const * GetSystemSettings();
    SetEnvironmentParamsRT const * SetEnvironmentParams(double dTemperature, double dPressure, double dHumidity);
    SetEnvironmentParamsRT const * SetEnvironmentParams(EnvironmentDataT environmentData);
    GetEnvironmentParamsRT const * GetEnvironmentParams();
    GetRefractionParamsRT const * GetRefractionParams();
    SetRefractionParamsRT const * SetRefractionParams(double ifmIndex, double admIndex);
    GetSearchParamsRT const * GetSearchParams();
    SetSearchParamsRT const * SetSearchParams(SearchParamsDataT searchParams);
    SetStationOrientationParamsRT const * SetStationOrientationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3);
    SetStationOrientationParamsRT const * SetStationOrientationParams(StationOrientationDataT stationOrientation);
    GetStationOrientationParamsRT const * GetStationOrientationParams();
    SetTransformationParamsRT const * SetTransformationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3, double dScale);
    SetTransformationParamsRT const * SetTransformationParams(TransformationDataT transformationData);
    GetTransformationParamsRT const * GetTransformationParams();
    GoPositionRT const * GoPosition(double dVal1, double dVal2, double dVal3, bool bUseADM);
    GoPositionHVDRT const * GoPositionHVD(double dHzAngle, double dVtAngle, double dDistance, bool bUseADM);
    PointLaserRT const * PointLaser(double dVal1, double dVal2, double dVal3);
    PointLaserHVDRT const * PointLaserHVD(double dHzAngle, double dVtAngle, double dDistance);
    GoNivelPositionRT const * GoNivelPosition(ES_NivelPosition position);
    MoveHVRT const * MoveHV(long lHzSpeed, long lVtSpeed);
    PositionRelativeHVRT const * PositionRelativeHV(double dHz, double dVt);
    GoBirdBathRT const * GoBirdBath();
    ChangeFaceRT const * ChangeFace();
    FindReflectorRT const * FindReflector(double dAproxDistance);
    StartMeasurementRT const * StartMeasurement();
    StartNivelMeasurementRT const * StartNivelMeasurement();
    StopMeasurementRT const * StopMeasurement();
    ExitApplicationRT const * ExitApplication();
    GetDirectionRT const * GetDirection();
    CallOrientToGravityRT const * CallOrientToGravity();
    SetCompensationRT const * SetCompensation(int iInternalCompensationId);
    SetStatisticModeRT const * SetStatisticMode(ES_StatisticMode stationaryMeasurements, ES_StatisticMode continuousMeasurements);
    GetStatisticModeRT const * GetStatisticMode();
    GetCameraParamsRT const * GetCameraParams();
    SetCameraParamsRT const * SetCameraParams(CameraParamsDataT cameraParams);
    SetCameraParamsRT const * SetCameraParams(int iContrast, int iBrightness, int iSaturation);
    GetCompensationRT const * GetCompensation();
    GetCompensationsRT const * GetCompensations();
    GetCompensations2RT const * GetCompensations2();
    GetTPInfoRT const * GetTPInfo();
    GetNivelInfoRT const * GetNivelInfo();
    GetLaserOnTimerRT const * GetLaserOnTimer();
    SetLaserOnTimerRT const * SetLaserOnTimer(int iTimeOffsetHour, int iTimeOffsetMinute);
    GoBirdBath2RT const * GoBirdBath2(bool bClockwise);
    GetFaceRT const * GetFace();
    SetLongSystemParamRT const * SetLongSystemParameter(ES_SystemParameter systemParam, long lParameter);
    GetLongSystemParamRT const * GetLongSystemParameter(ES_SystemParameter systemParam);
    GetMeasurementStatusInfoRT const * GetMeasurementStatusInfo();
    SetDoubleSystemParamRT const * SetDoubleSystemParameter(ES_SystemParameter systemParam, double dParameter);
    GetDoubleSystemParamRT const * GetDoubleSystemParameter(ES_SystemParameter systemParam);
    GetObjectTemperatureRT const * GetObjectTemperature();
    GetOverviewCameraInfoRT const * GetOverviewCameraInfo();
    ClearCommandQueueRT const * ClearCommandQueue(ES_ClearCommandQueueType ccqType);
    GetADMInfo2RT const * GetADMInfo2();
    GetTrackerInfoRT const * GetTrackerInfo();
    GetNivelInfo2RT const * GetNivelInfo2();
    RestoreStartupConditionsRT const * RestoreStartupConditions();
    GoAndMeasureRT const * GoAndMeasure(double dval1, double dval2, double dval3);
    GetATRInfoRT const * GetATRInfo();
    GetMeteoStationInfoRT const * GetMeteoStationInfo();
    GetAT4xxInfoRT const * GetAT4xxInfo();
    GetSystemSoftwareVersionRT const * GetSystemSoftwareVersion();
  };

  /*
  Connection -> CommandAsync
             -> CommandSync

  - Connection: Sets up a socket connection to the LT
  - CommandAsync: 1. Sends command packets to the LT
          2. Packet dispatcher loop in seperate thread
    - Callbacks: CommandCompleted, Error, SingleMeasurement, NivelMeasurement, ReflectorPosition,
           SystemStatusChange
    - getters for all of the command result types
  - CommandSync: Uses CommandAsync to provide blocking LT command functions
  */

}  // namespace CESAPI