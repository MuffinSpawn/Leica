/*
Copyright Leica Geosystems AG, 2005

Filename    :  enum.h 
  
Description :  Part of C++ interface for the Embedded System API
               (included intto ES_C_API_Def.h)
*/ 

#ifndef ES_ENUM_H
#define ES_ENUM_H

// This file 'Enum.h' is a mandatory include for ES_C_API_Def.h.
// Moreover, it may also be included to other non- EmScon projects.
// In the latter case, we cannot expect ES_API_MINOR_VERSION
// being defined. For these non- EmScon related cases, ENUM version 
// symbols are defined. For EmScon, a compliance check is performed.
//
// Attention: Programmers should not change any of these values in 
//            case of version conflict errors. Such errors indicate 
//            that include- files from different SDK versions have 
//            unintentionally been mixed up.
//
#ifdef ES_API_MINOR_VERSION
   #define ES_ENUM_MAJOR_VERSION 3  /* EmScon TPI/SDK V3.6 - Note: TPI/SDK Version.. */ 
   #define ES_ENUM_MINOR_VERSION 6  /* not necessarily matches EmScon server version! */

   #if ES_API_MAJOR_VERSION != ES_ENUM_MAJOR_VERSION
      #error Version conflict with EmScon API definition file (ES_C_API_Def.h) !
   #endif
   #if ES_API_MINOR_VERSION != ES_ENUM_MINOR_VERSION
      #error Version conflict with EmScon API definition file (ES_C_API_Def.h)!
   #endif
#endif

// For managed CPP applications, enum definitions require 
// to be prefixed with a 'public __value' directive. 
// To achieve this, define preprocessor symbol 'ES_MCPP_SUPPORT'
// prior to inclusion of file 'enum.h'.
// 
#undef ES_API
#ifdef ES_MCPP_SUPPORT
   #define ES_API public __value
#else
   #define ES_API
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////
// enums

/**
Length units supported 
**/
ES_API enum ES_LengthUnit
{
    ES_LU_Meter = 0, 
    ES_LU_Millimeter = 1, 
    ES_LU_Micron = 2, 
    ES_LU_Foot = 3, 
    ES_LU_Yard = 4, 
    ES_LU_Inch = 5
};

/**
Angle units supported 
**/
ES_API enum ES_AngleUnit
{
    ES_AU_Radian = 0, 
    ES_AU_Degree = 1, 
    ES_AU_Gon = 2
};

/**
Temperature units supported 
**/
ES_API enum ES_TemperatureUnit
{
    ES_TU_Celsius = 0, 
    ES_TU_Fahrenheit = 1
};

/**
Pressure units supported 
According to Thommen specification p. 17
**/
ES_API enum ES_PressureUnit
{
   ES_PU_Mbar = 0, //default
   ES_PU_HPascal = 1, //same as MBar
   ES_PU_KPascal = 2, 
   ES_PU_MmHg = 3, 
   ES_PU_Psi = 4, 
   ES_PU_InH2O = 5, 
   ES_PU_InHg = 6, 
};

/**
Humidity units supported 
**/
ES_API enum ES_HumidityUnit
{
    ES_HU_RH = 0, 
};

/**
Coordinate system types supported 
**/
ES_API enum ES_CoordinateSystemType
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

#endif

