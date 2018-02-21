# -*- coding: utf-8 -*-
"""
Created on Fri Feb 16 20:38:36 2018

@author: Peter G. Lane (petergwinlane@gmail.com)
"""

RI_MIN = 1.000150
RI_MAX = 1.000331

RI_ALG_Leica = 0
RI_ALG_CiddorAndHill = 1

class RefractionIndexAlgorithm(object):
    # Units: C, mbar, %RH
    def calculateRefractionIndex(self, temperature, pressure, humidity):
        pass

class CiddorAndHill(RefractionIndexAlgorithm):
    # Units: C, mbar, %RH
    def calculateRefractionIndex(self, temperature, pressure, humidity):
        # TODO: implement
        return 0.0


class AlgorithmFactory(object):
  def refractionIndexAlgorithm(self, algorithm):
      if algorithm == RI_ALG_CiddorAndHill:
          return CiddorAndHill()
      else:
          return None

def SetRefractionIndex(command, ri_algorithm=None):
    if ri_algorithm == None:
        return
    if ri_algorithm.__class__.__bases__[0] != RefractionIndexAlgorithm:
        raise Exception('Invalid RefractionIndexAlgorithm class {}. Use AlgorithmFactory.'.format(ri_algorithm.__class__.__bases__[0]))
    mid_refraction_index = (RI_MIN + RI_MAX)/2.0
    refraction_params = command.GetRefractionParams()
    if refraction_params.dIfmRefractionIndex <= mid_refraction_index:
        refraction_params.dIfmRefractionIndex = RI_MAX
    else:
        refraction_params.dIfmRefractionIndex = RI_MIN
    command.SetRefractionParams(refraction_params)

    env_params = command.GetEnvironmentParams()
    refraction_params.dIfmRefractionIndex = ri_algorithm(\
        env_params.dTemperature, env_params.dPressure, env_params.dHumidity)
    command.SetRefractionParams(refraction_params)
