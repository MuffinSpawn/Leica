#ifndef ES_CONSTANT_H
#define ES_CONSTANT_H

// Other than 'Enum.h', this file 'Constant.h' is not a mandatory include 
// for ES_C_API_Def.h. It can be included as needed into C++ projects.
// This file is more of informational nature since it should not be
// necessary to expliciltyly use these constants. There exist approriate
// conversion functions instead.

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Constants - use 1.0EXX, not 1EXX notation (for IDL include reasons)

// Transformation-Math related constants:
const double ES_FixedStdDev = 0.0;
const double ES_UnknownStdDev = 1.0E35;
const double ES_ApproxStdDev = 1.0E15;

// Unit-Conversion related constants:
const double ES_LengthFactorMeter = 1.0;
const double ES_LengthFactorMillimeter = 1000.0;
const double ES_LengthFactorMicron = 1000000.0;
const double ES_LengthFactorInch = 39.37007874;
const double ES_LengthFactorFoot = 3.280839895;
const double ES_LengthFactorYard = 1.093613298;
const double ES_AngleFactorRadian = 1.0;
const double ES_AngleFactorGon = 63.661977236758134307553505349006;
const double ES_AngleFactorDegree = 57.295779513082320876798154814105;
const double ES_PressureFactorMbar = 1.0;
const double ES_PressureFactorHPascal = 1.0;
const double ES_PressureFactorKPascal = 0.1;
const double ES_PressureFactorMmHg = 1.0/1.33322;
const double ES_PressureFactorPsi = 1.0/68.94757;
const double ES_PressureFactorInH2O = 1.0/2.49082;
const double ES_PressureFactorInHg = 1.0/33.86379;
const double ES_TemperatureFactorCelsius = 1.0;
const double ES_TemperatureOffsetCelsius = 0.0;
const double ES_TemperatureFactorFahrenheit = 1.8;
const double ES_TemperatureOffsetFahrenheit = 32.0;

#endif

