/*++

Copyright (C) 2019 ACT Developers


This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0-RC1.

Abstract: This is an autogenerated C++ Header file with the basic internal
 exception type in order to allow an easy use of Optional Class Library

Interface version: 1.0.0

*/

#ifndef __OPTCLASS_INTERFACEEXCEPTION_HEADER
#define __OPTCLASS_INTERFACEEXCEPTION_HEADER

#include <exception>
#include <stdexcept>
#include "optclass_types.hpp"

/*************************************************************************************************************************
 Class EOptClassInterfaceException
**************************************************************************************************************************/


class EOptClassInterfaceException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	OptClassResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	EOptClassInterfaceException(OptClassResult errorCode);

	/**
	* Custom Exception Constructor.
	*/
	EOptClassInterfaceException(OptClassResult errorCode, std::string errorMessage);

	/**
	* Returns error code
	*/
	OptClassResult getErrorCode();
	/**
	* Returns error message
	*/
	const char* what() const noexcept override;
};

#endif // __OPTCLASS_INTERFACEEXCEPTION_HEADER
