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
		body = struct.Struct('l l').unpack(body_data[28:])
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

    ES_C_GetCoordinateSystemType = 27,
coordSysType
class GetCoordinateSystemTypeRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetStationaryModeParams = 29,

class GetStationaryModeParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetReflector = 41,

class GetReflectorRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetReflectors = 42,

class GetReflectorsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetSearchParams = 44,

class GetSearchParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetSystemSettings = 48,

class GetSystemSettingsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetDirection = 66,                        // get direction even without reflector locked on

class GetDirectionRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetStatisticMode = 81,                    // get's the statistical setting

class GetStatisticModeRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetCameraParams = 84,                     // read the current video camera parameters            

class GetCameraParamsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetCompensation = 85,                     // read the currently active compensation ID

class GetCompensationRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetCompensations = 86,                    // read all compensations stored in the database

class GetCompensationsRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetTPInfo = 90,

class GetTPInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetNivelInfo = 91,

class GetNivelInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_SetLaserOnTimer = 92,                     // switch the laser on in ... time

class SetLaserOnTimerRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetLaserOnTimer = 93,                     // read the remining time until it is switched on

class GetLaserOnTimerRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetFace = 98,                             // returns the current face (Face1 / Face2)

class GetFaceRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetLongSystemParameter = 121,

class GetLongSystemParameterRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetMeasurementStatusInfo = 122,

class GetMeasurementStatusInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetCompensations2 = 123,                  // enhanced read all compensations stored in the database

class GetCompensations2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetDoubleSystemParameter = 126,

class GetDoubleSystemParameterRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetObjectTemperature = 127,               // read the object temperature

class GetObjectTemperatureT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetOverviewCameraInfo = 129,                   

class GetOverviewCameraInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetADMInfo2 = 131, 

class GetADMInfo2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetTrackerInfo = 132,

class GetTrackerInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetNivelInfo2 = 133,

class GetNivelInfo2RT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetATRInfo = 138,

class GetATRInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetMeteoStationInfo = 139,    

class GetMeteoStationInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetAT4xxInfo = 140,

class GetAT4xxInfoRT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		self.transformationData = TransformationDataT(body_data)

    ES_C_GetSystemSoftwareVersion = 142,           

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