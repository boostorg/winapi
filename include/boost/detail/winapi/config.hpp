//  config.hpp  --------------------------------------------------------------//

//  Copyright 2013 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_
#define BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_

#if defined __MINGW32__
#include <_mingw.h>
#endif

// BOOST_WINAPI_IS_MINGW indicates that the target Windows SDK is provided by MinGW (http://mingw.org/).
// BOOST_WINAPI_IS_MINGW_W64 indicates that the target Windows SDK is provided by MinGW-w64 (http://mingw-w64.org).
#if defined __MINGW32__
#if defined __MINGW64_VERSION_MAJOR
#define BOOST_WINAPI_IS_MINGW_W64
#else
#define BOOST_WINAPI_IS_MINGW
#endif
#endif

// These constants reflect _WIN32_WINNT_* macros from sdkddkver.h and will not change over time
// See also: http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745%28v=vs.85%29.aspx#setting_winver_or__win32_winnt
#define BOOST_WINAPI_VERSION_NT4 0x0400
#define BOOST_WINAPI_VERSION_WIN2K 0x0500
#define BOOST_WINAPI_VERSION_WINXP 0x0501
#define BOOST_WINAPI_VERSION_WS03 0x0502
#define BOOST_WINAPI_VERSION_WIN6 0x0600
#define BOOST_WINAPI_VERSION_VISTA 0x0600
#define BOOST_WINAPI_VERSION_WS08 0x0600
#define BOOST_WINAPI_VERSION_LONGHORN 0x0600
#define BOOST_WINAPI_VERSION_WIN7 0x0601
#define BOOST_WINAPI_VERSION_WIN8 0x0602
#define BOOST_WINAPI_VERSION_WINBLUE 0x0603
#define BOOST_WINAPI_VERSION_WINTHRESHOLD 0x0A00
#define BOOST_WINAPI_VERSION_WIN10 0x0A00

#if defined(BOOST_USE_WINDOWS_H) && !defined(BOOST_WINAPI_IS_MINGW)
// Defines VER_PRODUCTBUILD in case one needs a compile time
// branch based on the Platform SDK / Windows Kit, available
// back to at least kit 7.0 that shipped with Visual Studio 2010.
#include <ntverp.h>
#define BOOST_WINAPI_WINDOWS_SDK            VER_PRODUCTBUILD
#else
#define BOOST_WINAPI_WINDOWS_SDK            0
#endif

// These constants reflect the kit being used by VER_PRODUCTBUILD
#define BOOST_WINAPI_WINDOWS_SDK_MINGW_W64  3790    /* https://github.com/Alexpux/mingw-w64/blame/master/mingw-w64-headers/include/ntverp.h */
#define BOOST_WINAPI_WINDOWS_SDK_7          7600    /* covers 7.0, 7.1A */
#define BOOST_WINAPI_WINDOWS_SDK_8          9200
#define BOOST_WINAPI_WINDOWS_SDK_8_1        9600
#define BOOST_WINAPI_WINDOWS_SDK_10         10011   /* covers all 10.0.<buildnum> */

#if !defined(BOOST_USE_WINAPI_VERSION)
#if defined(_WIN32_WINNT)
#define BOOST_USE_WINAPI_VERSION _WIN32_WINNT
#elif defined(WINVER)
#define BOOST_USE_WINAPI_VERSION WINVER
#else
// By default use Windows Vista API on compilers that support it and XP on the others
#if (defined(_MSC_VER) && _MSC_VER < 1500) || defined(BOOST_WINAPI_IS_MINGW)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WINXP
#else
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN6
#endif
#endif
#endif


#if defined(BOOST_WINAPI_IS_MINGW_W64) || (BOOST_WINAPI_WINDOWS_SDK >= BOOST_WINAPI_WINDOWS_SDK_8)
//
// Windows family partitions - part of support for Windows Store, Windows Phone,
// Windows Server, Windows Desktop differentiation in the API set.  They are only
// meaningful if the Windows SDK has support for the concept.  The headers provided
// are simple and do not pull in much, and they are quite different on certain SDKs.
//
// This is necessary to get UWP support.
//

#include <winapifamily.h>

#if !defined(BOOST_USE_WINAPI_FAMILY)
#if defined(WINAPI_FAMILY)
#define BOOST_USE_WINAPI_FAMILY WINAPI_FAMILY
#else
// If none is specified, default to a desktop application which is the most
// backwards compatible to previos ways of doing things.
#define BOOST_USE_WINAPI_FMAILY WINAPI_FAMILY_DESKTOP_APP
#endif
#endif
// Note that BOOST_USE_WINAPI_FAMILY may not have a definition, 
// for example with SDK 7, and we account for this below.
#endif

#define BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION2(x) x##0000
#define BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION(x) BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION2(x)

#if defined(BOOST_USE_WINDOWS_H) || defined(BOOST_WINAPI_DEFINE_VERSION_MACROS)
// We have to define the version macros so that windows.h provides the necessary symbols
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT BOOST_USE_WINAPI_VERSION
#endif
#if !defined(WINVER)
#define WINVER BOOST_USE_WINAPI_VERSION
#endif
#if !defined(NTDDI_VERSION)
// Default to respective Windows version with the latest Service Pack
#if BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN2K
#define NTDDI_VERSION 0x05000400
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WINXP
#define NTDDI_VERSION 0x05010300
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WS03
#define NTDDI_VERSION 0x05020200
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN6
#define NTDDI_VERSION 0x06000200
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN7
#define NTDDI_VERSION 0x06010100
#else
#define NTDDI_VERSION BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION(BOOST_USE_WINAPI_VERSION)
#endif
#if !defined(WINAPI_FAMILY) && defined(BOOST_USE_WINAPI_FAMILY)
#define WINAPI_FAMILY BOOST_USE_WINAPI_FAMILY
#endif
#endif
#endif

#include <boost/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#endif // BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_
