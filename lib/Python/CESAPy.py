import socket
import threading

# import CESAPI

class PacketHeaderT(object):
	def __init__(self, packet_header):
		self.lPacketSize = packet_header[0]
		self.type = packet_header[1]

class ReturnDataT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I').unpack(body_data)
		self.status = body[1]

class BasicCommandRT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]

class ErrorResponseT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]

class NivelResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I d d d').unpack(body_data)
		self.nivelStatus = body[0]
		self.dXTilt = body[1]
		self.dYTilt = body[2]
		self.dNivelTemperature = body[3]

class SingleMeasResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I d d d d d d d d d d d d d d d d d').unpack(body_data)
		self.measMode = body[0]
		self.bIsTryMode = body[1]
		self.dVal1 = body[2]
		self.dVal2 = body[3]
		self.dVal3 = body[4]
		self.dStd1 = body[5]
		self.dStd2 = body[6]
		self.dStd3 = body[7]
		self.dStdTotal = body[8]
		self.dPointingError1 = body[9]
		self.dPointingError2 = body[10]
		self.dPointingError3 = body[11]
		self.dAprioriStd1 = body[12]
		self.dAprioriStd2 = body[13]
		self.dAprioriStd3 = body[14]
		self.dAprioriStdTotal = body[15]
		self.dVal2 = dTemperature[16]
		self.dVal2 = dPressure[17]
		self.dVal2 = dHumidity[18]

class ReflectorPosResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('d d d').unpack(body_data)
		self.dVal1 = body[0]
		self.dVal2 = body[1]
		self.dVal3 = body[2]

class ReflectorPosResultT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I').unpack(body_data)
		self.systemStatusChange = body[0]

class SingleMeasResult2T(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I d d d d d d d d d d d d d d d d d d d d d d d').unpack(body_data)
		self.measMode = body[0]
		self.bIsTryMode = body[1]
		self.dVal1 = body[2]
		self.dVal2 = body[3]
		self.dVal3 = body[4]
		self.dStd1 = body[5]
		self.dStd2 = body[6]
		self.dStd3 = body[7]
		self.dStdTotal = body[8]
		self.dCovar12 = body[9]
		self.dCovar13 = body[10]
		self.dCovar23 = body[11]
		self.dPointingErrorH = body[12]
		self.dPointingErrorV = body[13]
		self.dPointingErrorD = body[14]
		self.dAprioriStd1 = body[15]
		self.dAprioriStd2 = body[16]
		self.dAprioriStd3 = body[17]
		self.dAprioriStdTotal = body[18]
		self.dAprioriCovar12 = body[19]
		self.dAprioriCovar13 = body[20]
		self.dAprioriCovar23 = body[21]
		self.dVal2 = dTemperature[22]
		self.dVal2 = dPressure[23]
		self.dVal2 = dHumidity[24]

class SimpleCommandRT(object):
	def __init__(self, packet_info):
		self.packetInfo = packet_info

class ExitApplicationRT(SimpleCommandRT): pass
class SetUnitsRT(SimpleCommandRT): pass
class InitializeRT(SimpleCommandRT): pass
class ActivateCameraViewRT(SimpleCommandRT): pass
class ParkRT(SimpleCommandRT): pass
class SetStationOrientationParamsRT(SimpleCommandRT): pass
class SetTransformationParamsRT(SimpleCommandRT): pass
class SetTransformationParamsRT(SimpleCommandRT): pass
class SetEnvironmentParamsRT(SimpleCommandRT): pass
class SetRefractionParamsRT(SimpleCommandRT): pass
class SetMeasurementModeRT(SimpleCommandRT): pass
class SetCoordinateSystemTypeRT(SimpleCommandRT): pass
class SetStationaryModeParamsRT(SimpleCommandRT): pass
class SetReflectorRT(SimpleCommandRT): pass
class SetSearchParamsRT(SimpleCommandRT): pass
class SetSystemSettingsRT(SimpleCommandRT): pass
class StartMeasurementRT(SimpleCommandRT): pass
class StartNivelMeasurementRT(SimpleCommandRT): pass
class StopMeasurementRT(SimpleCommandRT): pass
class ChangeFaceRT(SimpleCommandRT): pass
class GoBirdBathRT(SimpleCommandRT): pass
class GoPositionRT(SimpleCommandRT): pass
class GoPositionHVDRT(SimpleCommandRT): pass
class PositionRelativeHVRT(SimpleCommandRT): pass
class PointLaserRT(SimpleCommandRT): pass
class PointLaserHVDRT(SimpleCommandRT): pass
class MoveHVRT(SimpleCommandRT): pass
class GoNivelPositionRT(SimpleCommandRT): pass
class GoLastMeasuredPointRT(SimpleCommandRT): pass
class FindReflectorRT(SimpleCommandRT): pass
class CallOrientToGravityRT(SimpleCommandRT): pass
class SetCompensationRT(SimpleCommandRT): pass
class SetStatisticModeRT(SimpleCommandRT): pass
class SetCameraParamsRT(SimpleCommandRT): pass
class SetLaserOnTimerRT(SimpleCommandRT): pass
class GoBirdBath2RT(SimpleCommandRT): pass
class SetLongSystemParameterRT(SimpleCommandRT): pass
class ClearCommandQueueRT(SimpleCommandRT): pass
class RestoreStartupConditionsRT(SimpleCommandRT): pass
class GoAndMeasureRT(SimpleCommandRT): pass

class ESVersionNumberT(object):
	def __init__(self, body_data):
		body = struct.Struct('i i i').unpack(body_data)
		self.iMajorVersionNumber = body[0]
		self.iMinorVersionNumber = body[1]
		self.iBuildNumber = body[1]

class GetSystemStatusRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I I I').unpack(body_data[:16])
		self.lastResultStatus = body[0]
		self.trackerProcessorStatus = body[1]
		self.laserStatus = body[2]
		self.admStatus = body[3]
		self.weatherMonitorStatus = ESVersionNumberT(body_data[16:28])
		body = struct.Struct('L L').unpack(body_data[28:])
		self.lFlagsValue = body[0]
		self.lTrackerSerialNumber = body[1]

class GetTrackerStatusRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I').unpack(body_data)
		self.trackerStatus = body[0]

class SystemUnitsDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('I I I I I').unpack(body_data)
		self.lenUnitType = body[0]
		self.angUnitType = body[1]
		self.tempUnitType = body[2]
		self.pressUnitType = body[3]
		self.humUnitType = body[4]

class GetUnitsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.unitsSettings = SystemUnitsDataT(body_data)

class StationOrientationDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('d d d d d d').unpack(body_data)
		self.dVal1 = body[0]
		self.dVal2 = body[1]
		self.dVal3 = body[2]
		self.dRot1 = body[3]
		self.dRot2 = body[4]
		self.dRot3 = body[5]

class GetStationOrientationParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.stationOrientation = StationOrientationDataT(body_data)

class TransformationDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('d d d d d d').unpack(body_data)
		self.dVal1 = body[0]
		self.dVal2 = body[1]
		self.dVal3 = body[2]
		self.dRot1 = body[3]
		self.dRot2 = body[4]
		self.dRot3 = body[5]

class GetTransformationParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

class EnvironmentDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('d d d').unpack(body_data)
		self.dTemperature = body[0]
		self.dPressure = body[1]
		self.dHumidity = body[2]

class GetEnvironmentParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.environmentData = TransformationDataT(body_data)

class EnvironmentDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('d d').unpack(body_data)
		self.dIfmRefractionIndex = body[0]
		self.dAdmRefractionIndex = body[1]

class GetRefractionParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.refractionData = TransformationDataT(body_data)

class GetMeasurementModeRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I').unpack(body_data)
		self.measMode = body[0]

class GetCoordinateSystemTypeRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I').unpack(body_data)
		self.coordSysType = body[0]

class StationaryModeDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('L i').unpack(body_data)
		self.lMeasTime = body[0]
		self.bUseADM = bool(body[1])

class GetStationaryModeParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.stationaryModeData = StationaryModeDataT(body_data)

class GetReflectorRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i').unpack(body_data)
		self.iInternalReflectorId = body[0]

class GetReflectorsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i I d').unpack(body_data[:20])
		self.iTotalReflectors = body[0]
		self.iInternalReflectorId = body[1]
		self.targetType = body[2]
		self.dSurfaceOffset = body[3]
		self.cReflectorName = body_data[20:]

class SearchParamsDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('d L').unpack(body_data)
		self.dSearchRadius = body[0]
		self.lTimeOut = body[1]

class GetSearchParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.searchParams = SearchParamsDataT(body_data)

class SystemSettingsDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('i i i i i i i i').unpack(body_data)
		self.bApplyTransformationParams = bool(body[0])
		self.bApplyStationOrientationParams = bool(body[1])
		self.bKeepLastPosition = bool(body[2])
		self.bSendUnsolicitedMessages = bool(body[3])
		self.bSendReflectorPositionData = bool(body[4])
		self.bTryMeasurementMode = bool(body[5])
		self.bHasNivel = bool(body[6])
		self.bHasVideoCamera = bool(body[7])

class GetSystemSettingsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.systemSettings = SystemSettingsDataT(body_data)

class GetDirectionRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('d d').unpack(body_data)
		self.dHzAngle = body[0]
		self.dVtAngle = body[1]

class GetStatisticModeRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I').unpack(body_data)
		self.stationaryMeasurements = body[0]
		self.continuousMeasurements = body[1]

class CameraParamsDataT(object):
	def __init__(self, body_data):
		body = struct.Struct('i i i').unpack(body_data)
		self.iContrast = body[0]
		self.iBrightness = body[0]
		self.iSaturation = body[0]

class GetCameraParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.cameraParams = CameraParamsDataT(body_data)

class GetCompensationRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i').unpack(body_data)
		self.iInternalCompensationId = body[0]

class GetCompensationsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i').unpack(body_data[:8])
		self.iTotalCompensations = body[0]
		self.iInternalCompensationId = body[1]
		self.cTrackerCompensationName = body_data[8:40]
		self.cTrackerCompensationComment = body_data[40:168]
		self.cADMCompensationName = body_data[168:200]
		body = struct.Struct('i').unpack(body_data[200:])
		self.bHasMeasurementCameraMounted = bool(body[0])

class GetTPInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i i i i i I I i I').unpack(body_data)
		self.iTPBootMajorVersionNumber = body[0]
		self.iTPBootMinorVersionNumber = body[1]
		self.iTPFirmwareMajorVersionNumber = body[2]
		self.iTPFirmwareMinorVersionNumber = body[3]
		self.iLCPFirmwareMajorVersionNumber = body[4]
		self.iLCPFirmwareMinorVersionNumber = body[5]
		self.iTotalCompentrackerprocessorTypesations = body[6]
		self.microProcessorType = body[7]
		self.iMicroProcessorClockSpeed = body[8]
		self.laserTrackerSensorType = body[9]

class GetNivelInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i L').unpack(body_data)
		self.iFirmwareMajorVersionNumber = body[0]
		self.iFirmwareMinorVersionNumber = body[1]
		self.lSerialNumber = body[2]

class GetLaserOnTimerRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i').unpack(body_data)
		self.iLaserOnTimeOffsetHour = body[0]
		self.iLaserOnTimeOffsetMinute = body[1]

class GetFaceRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I').unpack(body_data)
		self.trackerFace = body[0]

class GetLongSystemParamRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I L').unpack(body_data)
		self.systemParam = body[0]
		self.lParameter = body[1]

class GetMeasurementStatusInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I L').unpack(body_data)
		self.lastResultStatus = body[0]
		self.lMeasurementStatusInfo = body[1]

class GetCompensations2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('i i').unpack(body_data[:8])
		self.iTotalCompensations = body[0]
		self.iInternalCompensationId = body[1]
		self.cTrackerCompensationName = body_data[8:40]
		self.cTrackerCompensationComment = body_data[40:168]
		self.cADMCompensationName = body_data[168:200]
		self.cADMCompensationComment = body_data[200:328]
		body = struct.Struct('i i').unpack(body_data[328:])
		self.bHasMeasurementCameraMounted = bool(body[0])
		self.bIsActive = bool(body[1])

class GetDoubleSystemParamRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I d').unpack(body_data)
		self.systemParam = body[0]
		self.dParameter = body[1]

class GetObjectTemperatureRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('d').unpack(body_data)
		self.dObjectTemperature = body[0]

class GetOverviewCameraInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I').unpack(body_data[:4])
		self.cameraType = body[0]
		self.cCameraName = body_data[4:36]
		body = struct.Struct('i d d d i i').unpack(body_data[36:])
		self.bIsColorCamera = body[0]
		self.dFocalLength = body[1]
		self.dHorizontalChipSize = body[2]
		self.dVerticalChipSize = body[3]
		self.bMirrorImageHz = body[4]
		self.bMirrorImageVt = body[5]

    ES_C_GetADMInfo2 = 131, 
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

class GetADMInfo2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetTrackerInfo = 132,
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

class GetTrackerInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetNivelInfo2 = 133,
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

class GetNivelInfo2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetATRInfo = 138,
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

class GetATRInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetMeteoStationInfo = 139,    
struct GetMeteoStationInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_MeteoStationType meteoStationType;
    unsigned short           cIdentifier[32];      // UNICODE string
    int                      iFirmwareMajorVersionNumber;
    int                      iFirmwareMinorVersionNumber;
};

class GetMeteoStationInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetAT4xxInfo = 140,
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

class GetAT4xxInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetSystemSoftwareVersion = 142,           
struct GetSystemSoftwareVersionRT
{
    struct BasicCommandRT packetInfo;
    unsigned short        cSoftwareVersion[32]; // UNICODE string
};

class GetSystemSoftwareVersionRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

class LTPacketFactory(object):
	def __init__(self):
		self.PACKET_HEADER_SIZE = 12
		self.RETURN_DATA_SIZE = 16
		self.RETURN_DATA_BODY_SIZE = self.RETURN_DATA_SIZE-self.PACKET_HEADER_SIZE
		self.BASIC_COMMAND_SIZE = 20
		self.BASIC_COMMAND_BODY_SIZE = self.BASIC_COMMAND_SIZE-self.PACKET_HEADER_SIZE

	def packet(self, packet_header, body_data):
		packet_type = packet_header[1]
		if packet_header.type == ES_DT_Command:
			packet_info = BasicCommandRT(packet_header, body_data[:self.BASIC_COMMAND_BODY_SIZE])
			# instantiate specific command type
			command = packet_info.command
			if command == ES_C_Initialize:
				packet = InitializeRT(packet_info)
		elif packet_header.type == ES_DT_Error:
			packet = ErrorResponseT(packet_header, body_data)
		elif packet_header.type == ES_DT_SingleMeasResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = SingleMeasResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_NivelResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = NivelResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_ReflectorPosResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = ReflectorPosResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_SystemStatusChange:
			packet = ReflectorPosResultT(packet)_header, body_data)
		elif packet_header.type == ES_DT_SingleMeasResult2:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = SingleMeasResult2T(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		else:
			packet = PacketHeaderT(packet_header)
		return packet

class LTPacketStream(Thread):
	def __init__(self, sock):
		self.__sock = sock
		self.__running = False
		self.PACKET_HEADER_SIZE = 12  # lPacketSize, type
		self.PACKET_BUFFER_SIZE = 1000
		self.__packet_buffer = []
		self.__head_index = 0
		self.__tail_index = 0

	def start(self):
		self.__running = True

	def stop(self):
		self.__running = False

	def run(self):
		packet_factory = CESAPI.LTPacketFactory()

		while __running:
			header_data = __sock.recv(self.PACKET_HEADER_SIZE)
			packet_header = struct.Struct('L I').unpack(header_data)
			packet_size = packet_header[0]

			body_data = __sock.recv(packet_size-self.PACKET_HEADER_SIZE)
			packet = packet_factory.packet(packet_header, body_data)
			self.__packet_buffer[self.__tail_index] = packet
			self.__tail_index += 1
			if self.__tail_index == self.PACKET_BUFFER_SIZE:
				self.__tail_index = 0
			if self.__tail_index == self.__head_index:
				self.__head_index += 1
			if self.__head_index == self.PACKET_BUFFER_SIZE:
				self.__head_index = 0

	def read(self):
		if self.__tail_index == self.__head_index:
			return None
		packet = self.__packet_buffer[self.__head_index]
		self.__head_index += 1
		if self.__head_index == self.PACKET_BUFFER_SIZE:
			self.__head_index = 0
		return packet

class LTConnection(object):
	def __init__(self):
		self.__sock = None
		self.__stream = None

	def connect(self, host, port):
		if __sock != None:
			raise Exception("Repeat connection. Only one connection to the laser tracker is allowed at one time.")

		# Create a TCP/IP socket
		self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

		# Connect the socket to the port where the server is listening
		self.__sock.connect((host, port))

		self.__stream = LTPacketStream(__sock)
		self.__stream.start()
		return __stream

	def disconnect(self):
		self.__stream.stop()
		self.__sock.close()
		self.__sock = None