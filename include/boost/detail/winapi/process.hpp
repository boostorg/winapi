//  process_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt



#ifndef BOOST_DETAIL_PROCESS_HPP_
#define BOOST_DETAIL_PROCESS_HPP_

#include <boost/detail/winapi/config.hpp>
#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/security.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif


// Windows CE define GetCurrentProcessId as an inline function in kfuncs.h
#if !defined( BOOST_USE_WINDOWS_H ) && !defined( UNDER_CE )
extern "C" {
BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI GetCurrentProcessId(BOOST_DETAIL_WINAPI_VOID);
}
#endif

#if !defined( BOOST_USE_WINDOWS_H )

extern "C"
{
struct _PROCESS_INFORMATION;

#if !defined( BOOST_NO_ANSI_APIS )
struct _STARTUPINFOA;
#endif

struct _STARTUPINFOW;
}


extern "C" {

BOOST_SYMBOL_IMPORT BOOST_NORETURN void WINAPI
ExitProcess(
   boost::detail::winapi::UINT_ uExitCode);


BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI TerminateProcess(
    boost::detail::winapi::HANDLE_ hProcess,
    boost::detail::winapi::UINT_ uExitCode);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI GetExitCodeProcess(
    boost::detail::winapi::HANDLE_ hProcess,
    boost::detail::winapi::DWORD_* lpExitCode);


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI CreateProcessA(
    boost::detail::winapi::LPCSTR_ lpApplicationName,
    boost::detail::winapi::LPSTR_ lpCommandLine,
                         ::_SECURITY_ATTRIBUTES* lpProcessAttributes,
                         ::_SECURITY_ATTRIBUTES* lpThreadAttributes,
	boost::detail::winapi::INT_ bInheritHandles,
    boost::detail::winapi::DWORD_ dwCreationFlags,
    boost::detail::winapi::LPVOID_ lpEnvironment,
    boost::detail::winapi::LPCSTR_ lpCurrentDirectory,
                         ::_STARTUPINFOA* lpStartupInfo,
                         ::_PROCESS_INFORMATION* lpProcessInformation);


#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI CreateProcessW(
    boost::detail::winapi::LPCWSTR_ lpApplicationName,
    boost::detail::winapi::LPWSTR_ lpCommandLine,
                         ::_SECURITY_ATTRIBUTES* lpProcessAttributes,
                         ::_SECURITY_ATTRIBUTES* lpThreadAttributes,
    boost::detail::winapi::INT_ bInheritHandles,
    boost::detail::winapi::DWORD_ dwCreationFlags,
    boost::detail::winapi::LPVOID_ lpEnvironment,
    boost::detail::winapi::LPCWSTR_ lpCurrentDirectory,
                         ::_STARTUPINFOW* lpStartupInfo,
                         ::_PROCESS_INFORMATION* lpProcessInformation);

}
#endif //defined BOOST_WINDOWS_H



namespace boost
{
namespace detail
{
namespace winapi
{

/* ****************************** Process Information ********************/

#if defined( BOOST_USE_WINDOWS_H )
typedef ::PROCESS_INFORMATION PROCESS_INFORMATION_;
#if !defined( BOOST_NO_ANSI_APIS )
typedef ::STARTUPINFOA STARTUPINFOA_;
#endif
typedef ::STARTUPINFOW STARTUPINFOW_;
//typedef ::STARTUPINFOEX STARTUPINFOEX_;
#else

struct PROCESS_INFORMATION_
{
    HANDLE_ hProcess;
    HANDLE_ hThread;
    DWORD_ dwProcessId;
    DWORD_ dwThreadId;
};


struct STARTUPINFOA_ {
  DWORD_ cb;
  LPSTR_ lpReserved;
  LPSTR_ lpDesktop;
  LPSTR_ lpTitle;
  DWORD_ dwX;
  DWORD_ dwY;
  DWORD_ dwXSize;
  DWORD_ dwYSize;
  DWORD_ dwXCountChars;
  DWORD_ dwYCountChars;
  DWORD_ dwFillAttribute;
  DWORD_ dwFlags;
  WORD_ wShowWindow;
  WORD_ cbReserved2;
  BYTE_ *lpReserved2;
  HANDLE_ hStdInput;
  HANDLE_ hStdOutput;
  HANDLE_ hStdError;
};

struct STARTUPINFOW_ {
  DWORD_ cb;
  LPWSTR_ lpReserved;
  LPWSTR_ lpDesktop;
  LPWSTR_ lpTitle;
  DWORD_ dwX;
  DWORD_ dwY;
  DWORD_ dwXSize;
  DWORD_ dwYSize;
  DWORD_ dwXCountChars;
  DWORD_ dwYCountChars;
  DWORD_ dwFillAttribute;
  DWORD_ dwFlags;
  WORD_ wShowWindow;
  WORD_ cbReserved2;
  BYTE_ *lpReserved2;
  HANDLE_ hStdInput;
  HANDLE_ hStdOutput;
  HANDLE_ hStdError;
} ;

#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6


#if defined( BOOST_USE_WINDOWS_H )

#if !defined(BOOST_NO_ANSI_APIS)
typedef ::STARTUPINFOEXA STARTUPINFOEXA_;
#endif // BOOST_NO_ANSI_APIS

typedef ::STARTUPINFOEXW STARTUPINFOEXW_;


#else // BOOST_USE_WINDOWS_H

typedef struct PROC_THREAD_ATTRIBUTE_LIST_ *PPROC_THREAD_ATTRIBUTE_LIST_;

#if !defined(BOOST_NO_ANSI_APIS)

struct STARTUPINFOEXA_ {
  STARTUPINFOW_                StartupInfo;
  PPROC_THREAD_ATTRIBUTE_LIST_ lpAttributeList;
};
#endif //BOOST_NO_ANSI_APIS
struct STARTUPINFOEXW_ {
  STARTUPINFOW_                StartupInfo;
  PPROC_THREAD_ATTRIBUTE_LIST_ lpAttributeList;
};

#endif // BOOST_USE_WINDOWS_H
#endif // BOOST_USE_WINAPI_VERSION

/* **************************** STARTF *********************************/
#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ STARTF_USESHOWWINDOW_      = STARTF_USESHOWWINDOW   ;
const DWORD_ STARTF_USESIZE_            = STARTF_USESIZE         ;
const DWORD_ STARTF_USEPOSITION_        = STARTF_USEPOSITION     ;
const DWORD_ STARTF_USECOUNTCHARS_      = STARTF_USECOUNTCHARS   ;
const DWORD_ STARTF_USEFILLATTRIBUTE_   = STARTF_USEFILLATTRIBUTE;
const DWORD_ STARTF_RUNFULLSCREEN_      = STARTF_RUNFULLSCREEN   ;
const DWORD_ STARTF_FORCEONFEEDBACK_    = STARTF_FORCEONFEEDBACK ;
const DWORD_ STARTF_FORCEOFFFEEDBACK_   = STARTF_FORCEOFFFEEDBACK;
const DWORD_ STARTF_USESTDHANDLES_      = STARTF_USESTDHANDLES   ;
const DWORD_ STARTF_USEHOTKEY_          = STARTF_USEHOTKEY       ;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ STARTF_TITLEISLINKNAME_    = STARTF_TITLEISLINKNAME ;
const DWORD_ STARTF_TITLEISAPPID_       = STARTF_TITLEISAPPID    ;
const DWORD_ STARTF_PREVENTPINNING_     = STARTF_PREVENTPINNING  ;
#endif

#else

const DWORD_ STARTF_USESHOWWINDOW_      = 0x00000001;
const DWORD_ STARTF_USESIZE_            = 0x00000002;
const DWORD_ STARTF_USEPOSITION_        = 0x00000004;
const DWORD_ STARTF_USECOUNTCHARS_      = 0x00000008;
const DWORD_ STARTF_USEFILLATTRIBUTE_   = 0x00000010;
const DWORD_ STARTF_RUNFULLSCREEN_      = 0x00000020;
const DWORD_ STARTF_FORCEONFEEDBACK_    = 0x00000040;
const DWORD_ STARTF_FORCEOFFFEEDBACK_   = 0x00000080;
const DWORD_ STARTF_USESTDHANDLES_      = 0x00000100;
const DWORD_ STARTF_USEHOTKEY_          = 0x00000200;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ STARTF_TITLEISLINKNAME_    = 0x00000800;
const DWORD_ STARTF_TITLEISAPPID_       = 0x00001000;
const DWORD_ STARTF_PREVENTPINNING_     = 0x00002000;
#endif

#endif



using ::GetCurrentProcessId;


//|| defined( CreateProcess )
using ::GetExitCodeProcess;
using ::ExitProcess;
using ::TerminateProcess;
using ::CreateProcessA;
using ::CreateProcessW;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE INT_ create_process (
		LPCSTR_ lpApplicationName,
		LPSTR_ lpCommandLine,
		LPSECURITY_ATTRIBUTES_ lpProcessAttributes,
		LPSECURITY_ATTRIBUTES_ lpThreadAttributes,
		INT_ bInheritHandles, DWORD_ dwCreationFlags,
		LPVOID_ lpEnvironment,
		LPCSTR_ lpCurrentDirectory,
		STARTUPINFOA_* lpStartupInfo,
		PROCESS_INFORMATION_* lpProcessInformation)
{
	return CreateProcessA (lpApplicationName,
                           lpCommandLine,
                           reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpProcessAttributes),
                           reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpThreadAttributes),
                           bInheritHandles,
                           dwCreationFlags,
                           lpEnvironment,
                           lpCurrentDirectory,
						   reinterpret_cast< ::_STARTUPINFOA* >(lpStartupInfo),
						   reinterpret_cast< ::_PROCESS_INFORMATION* >(lpProcessInformation));
}
#endif

BOOST_FORCEINLINE INT_ create_process (
		LPCWSTR_ lpApplicationName,
		LPWSTR_ lpCommandLine,
		LPSECURITY_ATTRIBUTES_ lpProcessAttributes,
		LPSECURITY_ATTRIBUTES_ lpThreadAttributes,
		INT_ bInheritHandles,
		DWORD_ dwCreationFlags,
		LPVOID_ lpEnvironment,
		LPCWSTR_ lpCurrentDirectory,
		STARTUPINFOW_* lpStartupInfo,
		PROCESS_INFORMATION_* lpProcessInformation)
{
	return CreateProcessW (lpApplicationName,
                           lpCommandLine,
                           reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpProcessAttributes),
                           reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpThreadAttributes),
                           bInheritHandles,
                           dwCreationFlags,
                           lpEnvironment,
                           lpCurrentDirectory,
						   reinterpret_cast< ::_STARTUPINFOW* >(lpStartupInfo),
						   reinterpret_cast< ::_PROCESS_INFORMATION* >(lpProcessInformation));
}


}
}
}



#endif /* BOOST_DETAIL_HANDLE_API_HPP_ */
