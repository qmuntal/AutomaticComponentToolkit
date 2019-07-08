/*++

Copyright (C) 2019 Calculation developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0-RC1.

Abstract: This is an autogenerated C++ header file in order to allow easy
development of Calculation library. The implementer of Calculation library needs to
derive concrete classes from the abstract classes in this header.

Interface version: 1.0.0

*/


#ifndef __CALCULATION_CPPINTERFACES
#define __CALCULATION_CPPINTERFACES

#include <string>
#include <memory>

#include "calculation_types.hpp"


#include "numbers_dynamic.hpp"

namespace Calculation {
namespace Impl {

/**
 Forward declarations of class interfaces
*/
class IBase;
class ICalculator;



/*************************************************************************************************************************
 Class interface for Base 
**************************************************************************************************************************/

class IBase {
public:
	/**
	* IBase::~IBase - virtual destructor of IBase
	*/
	virtual ~IBase() {};

	/**
	* IBase::ReleaseBaseClassInterface - Releases ownership of a base class interface. Deletes the reference, if necessary.
	* @param[in] pIBase - The base class instance to release
	*/
	static void ReleaseBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->DecRefCount();
		}
	};

	/**
	* IBase::AcquireBaseClassInterface - Acquires shared ownership of a base class interface.
	* @param[in] pIBase - The base class instance to acquire
	*/
	static void AcquireBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->IncRefCount();
		}
	};


	/**
	* IBase::GetLastErrorMessage - Returns the last error registered of this class instance
	* @param[out] sErrorMessage - Message of the last error registered
	* @return Has an error been registered already
	*/
	virtual bool GetLastErrorMessage(std::string & sErrorMessage) = 0;

	/**
	* IBase::ClearErrorMessages - Clears all registered messages of this class instance
	*/
	virtual void ClearErrorMessages() = 0;

	/**
	* IBase::RegisterErrorMessage - Registers an error message with this class instance
	* @param[in] sErrorMessage - Error message to register
	*/
	virtual void RegisterErrorMessage(const std::string & sErrorMessage) = 0;

	/**
	* IBase::IncRefCount - Increases the reference count of a class instance
	*/
	virtual void IncRefCount() = 0;

	/**
	* IBase::DecRefCount - Decreases the reference count of a class instance and free releases it, if the last reference has been removed
	* @return Has the object been released
	*/
	virtual bool DecRefCount() = 0;
};


/**
 Definition of a shared pointer class for IBase
*/
template<class T>
class IBaseSharedPtr : public std::shared_ptr<T>
{
public:
	explicit IBaseSharedPtr(T* t = nullptr)
		: std::shared_ptr<T>(t, IBase::ReleaseBaseClassInterface)
	{
		t->IncRefCount();
	}

	// Reset function, as it also needs to properly set the deleter.
	void reset(T* t = nullptr)
	{
		std::shared_ptr<T>::reset(t, IBase::ReleaseBaseClassInterface);
	}

	// Get-function that increases the Base class's reference count
	T* getCoOwningPtr()
	{
		T* t = this->get();
		t->IncRefCount();
		return t;
	}
};


typedef IBaseSharedPtr<IBase> PIBase;


/*************************************************************************************************************************
 Class interface for Calculator 
**************************************************************************************************************************/

class ICalculator : public virtual IBase {
public:
	/**
	* ICalculator::EnlistVariable - Adds a Variable to the list of Variables this calculator works on
	* @param[in] pVariable - The new variable in this calculator
	*/
	virtual void EnlistVariable(Numbers::PVariable pVariable) = 0;

	/**
	* ICalculator::GetEnlistedVariable - Returns an instance of a enlisted variable
	* @param[in] nIndex - The index of the variable to query
	* @return The Index-th variable in this calculator
	*/
	virtual Numbers::PVariable GetEnlistedVariable(const Calculation_uint32 nIndex) = 0;

	/**
	* ICalculator::ClearVariables - Clears all variables in enlisted in this calculator
	*/
	virtual void ClearVariables() = 0;

	/**
	* ICalculator::Multiply - Multiplies all enlisted variables
	* @return Variable that holds the product of all enlisted Variables
	*/
	virtual Numbers::PVariable Multiply() = 0;

	/**
	* ICalculator::Add - Sums all enlisted variables
	* @return Variable that holds the sum of all enlisted Variables
	*/
	virtual Numbers::PVariable Add() = 0;

};

typedef IBaseSharedPtr<ICalculator> PICalculator;


/*************************************************************************************************************************
 Global functions declarations
**************************************************************************************************************************/
class CWrapper {
public:
	// Injected Components
	static Numbers::PWrapper sPNumbersWrapper;

	/**
	* Icalculation::CreateCalculator - Creates a new Calculator instance
	* @return New Calculator instance
	*/
	static ICalculator * CreateCalculator();

	/**
	* Icalculation::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	static void GetVersion(Calculation_uint32 & nMajor, Calculation_uint32 & nMinor, Calculation_uint32 & nMicro);

	/**
	* Icalculation::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	static bool GetLastError(IBase* pInstance, std::string & sErrorMessage);

	/**
	* Icalculation::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void ReleaseInstance(IBase* pInstance);

	/**
	* Icalculation::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void AcquireInstance(IBase* pInstance);

};

} // namespace Impl
} // namespace Calculation

#endif // __CALCULATION_CPPINTERFACES
