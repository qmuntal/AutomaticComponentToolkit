/*++

Copyright (C) 2019 Calculator developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of Calculator library

Interface version: 1.0.0

*/

#ifndef __CALCULATOR_HEADER_CPP
#define __CALCULATOR_HEADER_CPP

#ifdef __CALCULATOR_EXPORTS
#ifdef _WIN32
#define CALCULATOR_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define CALCULATOR_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __CALCULATOR_EXPORTS
#define CALCULATOR_DECLSPEC
#endif // __CALCULATOR_EXPORTS

#include "calculator_types.hpp"


extern "C" {

/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class definition for Variable
**************************************************************************************************************************/

/**
* Returns the current value of this Variable
*
* @param[in] pVariable - Variable instance.
* @param[out] pValue - The current value of this Variable
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_variable_getvalue(Calculator_Variable pVariable, Calculator_double * pValue);

/**
* Set the numerical value of this Variable
*
* @param[in] pVariable - Variable instance.
* @param[in] dValue - The new value of this Variable
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_variable_setvalue(Calculator_Variable pVariable, Calculator_double dValue);

/*************************************************************************************************************************
 Class definition for Calculator
**************************************************************************************************************************/

/**
* Adds a Variable to the list of Variables this calculator works on
*
* @param[in] pCalculator - Calculator instance.
* @param[in] pVariable - The new variable in this calculator
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_calculator_enlistvariable(Calculator_Calculator pCalculator, Calculator_Variable pVariable);

/**
* Returns an instance of a enlisted variable
*
* @param[in] pCalculator - Calculator instance.
* @param[in] nIndex - The index of the variable to query
* @param[out] pVariable - The Index-th variable in this calculator
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_calculator_getenlistedvariable(Calculator_Calculator pCalculator, Calculator_uint32 nIndex, Calculator_Variable * pVariable);

/**
* Clears all variables in enlisted in this calculator
*
* @param[in] pCalculator - Calculator instance.
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_calculator_clearvariables(Calculator_Calculator pCalculator);

/**
* Multiplies all enlisted variables
*
* @param[in] pCalculator - Calculator instance.
* @param[out] pInstance - Variable that holds the product of all enlisted Variables
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_calculator_multiply(Calculator_Calculator pCalculator, Calculator_Variable * pInstance);

/**
* Sums all enlisted variables
*
* @param[in] pCalculator - Calculator instance.
* @param[out] pInstance - Variable that holds the sum of all enlisted Variables
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_calculator_add(Calculator_Calculator pCalculator, Calculator_Variable * pInstance);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_getversion(Calculator_uint32 * pMajor, Calculator_uint32 * pMinor, Calculator_uint32 * pMicro);

/**
* Returns the last error recorded on this object
*
* @param[in] pInstance - Instance Handle
* @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
* @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
* @param[out] pHasError - Is there a last error to query
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_getlasterror(Calculator_Base pInstance, const Calculator_uint32 nErrorMessageBufferSize, Calculator_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_releaseinstance(Calculator_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_acquireinstance(Calculator_Base pInstance);

/**
* Creates a new Variable instance
*
* @param[in] dInitialValue - Initial value of the new Variable
* @param[out] pInstance - New Variable instance
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_createvariable(Calculator_double dInitialValue, Calculator_Variable * pInstance);

/**
* Creates a new Calculator instance
*
* @param[out] pInstance - New Calculator instance
* @return error code or 0 (success)
*/
CALCULATOR_DECLSPEC CalculatorResult calculator_createcalculator(Calculator_Calculator * pInstance);

}

#endif // __CALCULATOR_HEADER_CPP

