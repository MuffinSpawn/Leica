/* File : CESAPI.i */
%module CESAPI
%include "cstring.i"

%begin %{
#define SWIG_PYTHON_STRICT_BYTE_CHAR
%}

%cstring_output_allocate_size(char **const packet, int *const size, );

%{
#include "Include/ES_C_API_PyDef.h"
#include "Include/ES_CPP_API_PyDef.h"
%}

%include "Include/ES_C_API_PyDef.h"
%include "Include/ES_CPP_API_PyDef.h"