//  process_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_
#define BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

extern "C"
{
struct _PROCESS_INFORMATION;

#if !defined( BOOST_NO_ANSI_APIS )
struct _STARTUPINFOA;
#endif

struct _STARTUPINFOW;
}

namespace boost
{
namespace detail
{
namespace winapi
{

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

}}}

#endif /* BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_ */
