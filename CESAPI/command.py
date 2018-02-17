
import time
from CESAPI.packet import *
class CommandSync(object):
  def __init__(self, connection):
    self.__connection = connection
    print()
  def execute(self, packet):
    stream = self.__connection._Connection__stream
    stream.write(packet)
    print()
    in_packet = None
    return_packet = None
    done = False
    while (not done):
      unread_count = stream.unreadCount()
      if unread_count > 0:
        in_packet = stream.read()
        packet_type = packetType(in_packet)
        if packetType(in_packet) == ES_DT_Command and \
           in_packet.packetInfo.command == packet.packetInfo.command:
          return_packet = in_packet
          if in_packet.packetInfo.command != ES_C_StartMeasurement and \
             in_packet.packetInfo.command != ES_C_StartNivelMeasurement:
            done = True
        elif packetType(in_packet) == ES_DT_Error:
          raise Exception("Command {} failed with status {}".format(in_packet.command, in_packet.status))
        elif packet_type == ES_DT_SingleMeasResult or packet_type == ES_DT_SingleMeasResult2:
          return_packet = in_packet
          done = True
        elif packet_type == ES_DT_NivelResult:
          self.nivel_measurement = in_packet
          done = True
        elif packet_type == ES_DT_ReflectorPosResult:
          pass
        elif packet_type == ES_DT_SystemStatusChange:
          if packet.packetInfo.command == ES_C_SetCoordinateSystemType and \
             in_packet.systemStatusChange == ES_SSC_CoordinateSystemTypeChanged:
            done = True
        else:
          time.sleep(0.2)
    return return_packet

    
  def ActivateCameraView(self):
    packet = ActivateCameraViewCT()
    return self.execute(packet)

  def CallOrientToGravity(self):
    packet = CallOrientToGravityCT()
    return self.execute(packet)

  def ChangeFace(self):
    packet = ChangeFaceCT()
    return self.execute(packet)

  def ClearCommandQueue(self, clearQueueType):
    packet = ClearCommandQueueCT()
    packet.clearQueueType = clearQueueType
    return self.execute(packet)

  def ExitApplication(self):
    packet = ExitApplicationCT()
    return self.execute(packet)

  def FindReflector(self, dAproxDistance):
    packet = FindReflectorCT()
    packet.dAproxDistance = dAproxDistance
    return self.execute(packet)

  def GetADMInfo2(self):
    packet = GetADMInfo2CT()
    return self.execute(packet)

  def GetAT4xxInfo(self):
    packet = GetAT4xxInfoCT()
    return self.execute(packet)

  def GetATRInfo(self):
    packet = GetATRInfoCT()
    return self.execute(packet)

  def GetCameraParams(self):
    packet = GetCameraParamsCT()
    return self.execute(packet)

  def GetCompensation(self):
    packet = GetCompensationCT()
    return self.execute(packet)

  def GetCompensations2(self):
    packet = GetCompensations2CT()
    return self.execute(packet)

  def GetCompensations(self):
    packet = GetCompensationsCT()
    return self.execute(packet)

  def GetCoordinateSystemType(self):
    packet = GetCoordinateSystemTypeCT()
    return self.execute(packet)

  def GetDirection(self):
    packet = GetDirectionCT()
    return self.execute(packet)

  def GetDoubleSystemParam(self, systemParam):
    packet = GetDoubleSystemParamCT()
    packet.systemParam = systemParam
    return self.execute(packet)

  def GetEnvironmentParams(self):
    packet = GetEnvironmentParamsCT()
    return self.execute(packet)

  def GetFace(self):
    packet = GetFaceCT()
    return self.execute(packet)

  def GetLaserOnTimer(self):
    packet = GetLaserOnTimerCT()
    return self.execute(packet)

  def GetLongSystemParam(self, systemParam):
    packet = GetLongSystemParamCT()
    packet.systemParam = systemParam
    return self.execute(packet)

  def GetMeasurementMode(self):
    packet = GetMeasurementModeCT()
    return self.execute(packet)

  def GetMeasurementStatusInfo(self):
    packet = GetMeasurementStatusInfoCT()
    return self.execute(packet)

  def GetMeteoStationInfo(self):
    packet = GetMeteoStationInfoCT()
    return self.execute(packet)

  def GetNivelInfo2(self):
    packet = GetNivelInfo2CT()
    return self.execute(packet)

  def GetNivelInfo(self):
    packet = GetNivelInfoCT()
    return self.execute(packet)

  def GetObjectTemperature(self):
    packet = GetObjectTemperatureCT()
    return self.execute(packet)

  def GetOverviewCameraInfo(self):
    packet = GetOverviewCameraInfoCT()
    return self.execute(packet)

  def GetReflector(self):
    packet = GetReflectorCT()
    return self.execute(packet)

  def GetReflectors(self):
    packet = GetReflectorsCT()
    return self.execute(packet)

  def GetRefractionParams(self):
    packet = GetRefractionParamsCT()
    return self.execute(packet)

  def GetSearchParams(self):
    packet = GetSearchParamsCT()
    return self.execute(packet)

  def GetStationOrientationParams(self):
    packet = GetStationOrientationParamsCT()
    return self.execute(packet)

  def GetStationaryModeParams(self):
    packet = GetStationaryModeParamsCT()
    return self.execute(packet)

  def GetStatisticMode(self):
    packet = GetStatisticModeCT()
    return self.execute(packet)

  def GetSystemSettings(self):
    packet = GetSystemSettingsCT()
    return self.execute(packet)

  def GetSystemSoftwareVersion(self):
    packet = GetSystemSoftwareVersionCT()
    return self.execute(packet)

  def GetSystemStatus(self):
    packet = GetSystemStatusCT()
    return self.execute(packet)

  def GetTPInfo(self):
    packet = GetTPInfoCT()
    return self.execute(packet)

  def GetTrackerInfo(self):
    packet = GetTrackerInfoCT()
    return self.execute(packet)

  def GetTrackerStatus(self):
    packet = GetTrackerStatusCT()
    return self.execute(packet)

  def GetTransformationParams(self):
    packet = GetTransformationParamsCT()
    return self.execute(packet)

  def GetUnits(self):
    packet = GetUnitsCT()
    return self.execute(packet)

  def GoAndMeasure(self, dVal1, dVal2, dVal3):
    packet = GoAndMeasureCT()
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def GoBirdBath2(self, bClockWise):
    packet = GoBirdBath2CT()
    packet.bClockWise = bClockWise
    return self.execute(packet)

  def GoBirdBath(self):
    packet = GoBirdBathCT()
    return self.execute(packet)

  def GoLastMeasuredPoint(self):
    packet = GoLastMeasuredPointCT()
    return self.execute(packet)

  def GoNivelPosition(self, nivelPosition):
    packet = GoNivelPositionCT()
    packet.nivelPosition = nivelPosition
    return self.execute(packet)

  def GoPosition(self, bUseADM, dVal1, dVal2, dVal3):
    packet = GoPositionCT()
    packet.bUseADM = bUseADM
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def GoPositionHVD(self, bUseADM, dDistance, dHzAngle, dVtAngle):
    packet = GoPositionHVDCT()
    packet.bUseADM = bUseADM
    packet.dDistance = dDistance
    packet.dHzAngle = dHzAngle
    packet.dVtAngle = dVtAngle
    return self.execute(packet)

  def Initialize(self):
    packet = InitializeCT()
    return self.execute(packet)

  def MoveHV(self, iHzSpeed, iVtSpeed):
    packet = MoveHVCT()
    packet.iHzSpeed = iHzSpeed
    packet.iVtSpeed = iVtSpeed
    return self.execute(packet)

  def Park(self):
    packet = ParkCT()
    return self.execute(packet)

  def PointLaser(self, dVal1, dVal2, dVal3):
    packet = PointLaserCT()
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def PointLaserHVD(self, dDistance, dHzAngle, dVtAngle):
    packet = PointLaserHVDCT()
    packet.dDistance = dDistance
    packet.dHzAngle = dHzAngle
    packet.dVtAngle = dVtAngle
    return self.execute(packet)

  def PositionRelativeHV(self, dHzVal, dVtVal):
    packet = PositionRelativeHVCT()
    packet.dHzVal = dHzVal
    packet.dVtVal = dVtVal
    return self.execute(packet)

  def RestoreStartupConditions(self):
    packet = RestoreStartupConditionsCT()
    return self.execute(packet)

  def SetCameraParams(self, cameraParams):
    packet = SetCameraParamsCT()
    packet.cameraParams = cameraParams
    return self.execute(packet)

  def SetCompensation(self, iInternalCompensationId):
    packet = SetCompensationCT()
    packet.iInternalCompensationId = iInternalCompensationId
    return self.execute(packet)

  def SetCoordinateSystemType(self, coordSysType):
    packet = SetCoordinateSystemTypeCT()
    packet.coordSysType = coordSysType
    return self.execute(packet)

  def SetDoubleSystemParam(self, dParameter, systemParam):
    packet = SetDoubleSystemParamCT()
    packet.dParameter = dParameter
    packet.systemParam = systemParam
    return self.execute(packet)

  def SetEnvironmentParams(self, environmentData):
    packet = SetEnvironmentParamsCT()
    packet.environmentData = environmentData
    return self.execute(packet)

  def SetLaserOnTimer(self, iLaserOnTimeOffsetHour, iLaserOnTimeOffsetMinute):
    packet = SetLaserOnTimerCT()
    packet.iLaserOnTimeOffsetHour = iLaserOnTimeOffsetHour
    packet.iLaserOnTimeOffsetMinute = iLaserOnTimeOffsetMinute
    return self.execute(packet)

  def SetLongSystemParam(self, lParameter, systemParam):
    packet = SetLongSystemParamCT()
    packet.lParameter = lParameter
    packet.systemParam = systemParam
    return self.execute(packet)

  def SetMeasurementMode(self, measMode):
    packet = SetMeasurementModeCT()
    packet.measMode = measMode
    return self.execute(packet)

  def SetReflector(self, iInternalReflectorId):
    packet = SetReflectorCT()
    packet.iInternalReflectorId = iInternalReflectorId
    return self.execute(packet)

  def SetRefractionParams(self, refractionData):
    packet = SetRefractionParamsCT()
    packet.refractionData = refractionData
    return self.execute(packet)

  def SetSearchParams(self, searchParams):
    packet = SetSearchParamsCT()
    packet.searchParams = searchParams
    return self.execute(packet)

  def SetStationOrientationParams(self, stationOrientation):
    packet = SetStationOrientationParamsCT()
    packet.stationOrientation = stationOrientation
    return self.execute(packet)

  def SetStationaryModeParams(self, stationaryModeData):
    packet = SetStationaryModeParamsCT()
    packet.stationaryModeData = stationaryModeData
    return self.execute(packet)

  def SetStatisticMode(self, continuousMeasurements, stationaryMeasurements):
    packet = SetStatisticModeCT()
    packet.continuousMeasurements = continuousMeasurements
    packet.stationaryMeasurements = stationaryMeasurements
    return self.execute(packet)

  def SetSystemSettings(self, systemSettings):
    packet = SetSystemSettingsCT()
    packet.systemSettings = systemSettings
    return self.execute(packet)

  def SetTransformationParams(self, transformationData):
    packet = SetTransformationParamsCT()
    packet.transformationData = transformationData
    return self.execute(packet)

  def SetUnits(self, unitsSettings):
    packet = SetUnitsCT()
    packet.unitsSettings = unitsSettings
    return self.execute(packet)

  def StartMeasurement(self):
    packet = StartMeasurementCT()
    return self.execute(packet)

  def StartNivelMeasurement(self):
    packet = StartNivelMeasurementCT()
    return self.execute(packet)

