/*++

Copyright (C) 2018 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.5.0.

Abstract: This is an autogenerated C++ Header file in order to allow an easy use
 of Prime Numbers Library

Interface version: 1.2.0

*/


#ifndef __LIBPRIMES_CPPHEADER
#define __LIBPRIMES_CPPHEADER

#include "libprimes.h"
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace LibPrimes {

/*************************************************************************************************************************
 Forward Declaration of all classes 
**************************************************************************************************************************/

class CLibPrimesBase;
class CLibPrimesCalculator;
class CLibPrimesFactorizationCalculator;
class CLibPrimesSieveCalculator;

/*************************************************************************************************************************
 Declaration of shared pointer types 
**************************************************************************************************************************/

typedef std::shared_ptr<CLibPrimesBase> PLibPrimesBase;
typedef std::shared_ptr<CLibPrimesCalculator> PLibPrimesCalculator;
typedef std::shared_ptr<CLibPrimesFactorizationCalculator> PLibPrimesFactorizationCalculator;
typedef std::shared_ptr<CLibPrimesSieveCalculator> PLibPrimesSieveCalculator;
		 
/*************************************************************************************************************************
 Class ELibPrimesException 
**************************************************************************************************************************/
class ELibPrimesException : public std::exception {
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
		ELibPrimesException (LibPrimesResult errorCode, const std::string & sErrorMessage);

		/**
		* Returns error code
		*/
		LibPrimesResult getErrorCode () const noexcept;

		/**
		* Returns error message
		*/
		const char* what () const noexcept;

};

/*************************************************************************************************************************
 Class CLibPrimesInputVector
**************************************************************************************************************************/
template <typename T>
class CLibPrimesInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CLibPrimesInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CLibPrimesInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

		 
/*************************************************************************************************************************
 Class CLibPrimesBase 
**************************************************************************************************************************/
class CLibPrimesBase  {

	friend class CLibPrimesWrapper;
protected:
	/* Handle to Instance in library*/
	LibPrimesHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(LibPrimesResult nResult);

	/**
	* CLibPrimesBase::CLibPrimesBase - Constructor for Base class.
	*/
	CLibPrimesBase(LibPrimesHandle pHandle);

	/**
	* CLibPrimesBase::~CLibPrimesBase - Destructor for Base class.
	*/
	virtual ~CLibPrimesBase();

	/**
	* CLibPrimesBase::GetHandle - Returns handle to instance.
	*/
	LibPrimesHandle GetHandle();
	
};
		 
/*************************************************************************************************************************
 Class CLibPrimesCalculator 
**************************************************************************************************************************/
class CLibPrimesCalculator : public CLibPrimesBase  {
public:
	/**
	* CLibPrimesCalculator::CLibPrimesCalculator - Constructor for Calculator class.
	*/
	CLibPrimesCalculator (LibPrimesHandle pHandle);
public:
	

	/**
	* CLibPrimesCalculator::GetValue - Returns the current value of this Calculator
	* @return The current value of this Calculator
	*/
	LibPrimes_uint64 GetValue ();

	/**
	* CLibPrimesCalculator::SetValue - Sets the value to be factorized
	* @param[in] nValue - The value to be factorized
	*/
	void SetValue (const LibPrimes_uint64 nValue);

	/**
	* CLibPrimesCalculator::Calculate - Performs the specific calculation of this Calculator
	*/
	void Calculate ();

	/**
	* CLibPrimesCalculator::SetProgressCallback - Sets the progress callback function
	* @param[in] pProgressCallback - The progress callback
	*/
	void SetProgressCallback (const LibPrimesProgressCallback pProgressCallback);
};
		 
/*************************************************************************************************************************
 Class CLibPrimesFactorizationCalculator 
**************************************************************************************************************************/
class CLibPrimesFactorizationCalculator : public CLibPrimesCalculator  {
public:
	/**
	* CLibPrimesFactorizationCalculator::CLibPrimesFactorizationCalculator - Constructor for FactorizationCalculator class.
	*/
	CLibPrimesFactorizationCalculator (LibPrimesHandle pHandle);
public:
	

	/**
	* CLibPrimesFactorizationCalculator::GetPrimeFactors - Returns the prime factors of this number (without multiplicity)
	* @param[out] PrimeFactorsBuffer - The prime factors of this number
	*/
	void GetPrimeFactors (std::vector<sLibPrimesPrimeFactor> & PrimeFactorsBuffer);
};
		 
/*************************************************************************************************************************
 Class CLibPrimesSieveCalculator 
**************************************************************************************************************************/
class CLibPrimesSieveCalculator : public CLibPrimesCalculator  {
public:
	/**
	* CLibPrimesSieveCalculator::CLibPrimesSieveCalculator - Constructor for SieveCalculator class.
	*/
	CLibPrimesSieveCalculator (LibPrimesHandle pHandle);
public:
	

	/**
	* CLibPrimesSieveCalculator::GetPrimes - Returns all prime numbers lower or equal to the sieve's value
	* @param[out] PrimesBuffer - The primes lower or equal to the sieve's value
	*/
	void GetPrimes (std::vector<LibPrimes_uint64> & PrimesBuffer);
};
		 
/*************************************************************************************************************************
 Class CLibPrimesWrapper 
**************************************************************************************************************************/
class CLibPrimesWrapper {
	friend class CLibPrimesBase;
protected:
	static void CheckError(CLibPrimesBase * pBaseClass, LibPrimesResult nResult);
public:

	/**
	* CLibPrimesWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	static bool GetLastError (CLibPrimesBase * pInstance, std::string & sErrorMessage);

	/**
	* CLibPrimesWrapper::ReleaseInstance - Releases the memory of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void ReleaseInstance (CLibPrimesBase * pInstance);

	/**
	* CLibPrimesWrapper::GetLibraryVersion - retrieves the current version of the library.
	* @param[out] nMajor - returns the major version of the library
	* @param[out] nMinor - returns the minor version of the library
	* @param[out] nMicro - returns the micro version of the library
	*/
	static void GetLibraryVersion (LibPrimes_uint32 & nMajor, LibPrimes_uint32 & nMinor, LibPrimes_uint32 & nMicro);

	/**
	* CLibPrimesWrapper::CreateFactorizationCalculator - Creates a new FactorizationCalculator instance
	* @return New FactorizationCalculator instance
	*/
	static PLibPrimesFactorizationCalculator CreateFactorizationCalculator ();

	/**
	* CLibPrimesWrapper::CreateSieveCalculator - Creates a new SieveCalculator instance
	* @return New SieveCalculator instance
	*/
	static PLibPrimesSieveCalculator CreateSieveCalculator ();

	/**
	* CLibPrimesWrapper::SetJournal - Handles Library Journaling
	* @param[in] sFileName - Journal FileName
	*/
	static void SetJournal (const std::string & sFileName);
};

};

#endif // __LIBPRIMES_CPPHEADER

