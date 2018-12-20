/*++

Copyright (C) 2018 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.3.2.

Abstract: This is an autogenerated C++ Header file with the basic internal
 exception type in order to allow an easy use of Prime Numbers Library

Interface version: 1.2.0

*/

#ifndef __LIBPRIMES_INTERFACEEXCEPTION_HEADER
#define __LIBPRIMES_INTERFACEEXCEPTION_HEADER

#include <exception>
#include <stdexcept>
#include "libprimes_types.h"

/*************************************************************************************************************************
 Class ELibPrimesInterfaceException
**************************************************************************************************************************/


class ELibPrimesInterfaceException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibPrimesResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibPrimesInterfaceException (LibPrimesResult errorCode);

	/**
	* Returns error code
	*/
	LibPrimesResult getErrorCode ();
	/**
	* Returns error message
	*/
	const char* what () const noexcept override;
};

#endif // __LIBPRIMES_INTERFACEEXCEPTION_HEADER
