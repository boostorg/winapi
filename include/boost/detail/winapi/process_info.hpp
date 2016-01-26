//  process_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_
#define BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/config.hpp>
#include <boost/detail/winapi/handles.hpp>

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
extern "C" {

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


#if !defined(BOOST_NO_ANSI_APIS)
typedef STARTUPINFOA_ STARTUPINFO_;
#endif

#if defined( BOOST_USE_WINDOWS_H )
//typedef ::STARTUPINFOEX STARTUPINFOEX_;

#else

typedef struct PROC_THREAD_ATTRIBUTE_LIST_ *PPROC_THREAD_ATTRIBUTE_LIST_;

/*
struct STARTUPINFOEX_ {
  STARTUPINFO_                 StartupInfo;
  PPROC_THREAD_ATTRIBUTE_LIST_ lpAttributeList;
};*/

#endif
#endif
}
}}}

#endif /* BOOST_DETAIL_WINAPI_PROCESS_INFO_HPP_ */
