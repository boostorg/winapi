//  basic_types.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_BASIC_TYPES_HPP
#define BOOST_DETAIL_WINAPI_BASIC_TYPES_HPP

#include <cstdarg>
#include <boost/cstdint.hpp>
#include <boost/detail/winapi/config.hpp>

#if defined( BOOST_USE_WINDOWS_H )
# include <windows.h>
#elif defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ ) ||  defined(__CYGWIN__)
# include <winerror.h>
# ifdef UNDER_CE
#  ifndef WINAPI
#   ifndef _WIN32_WCE_EMULATION
#    define WINAPI  __cdecl     // Note this doesn't match the desktop definition
#   else
#    define WINAPI  __stdcall
#   endif
#  endif
// Windows CE defines a few functions as inline functions in kfuncs.h
typedef int BOOL;
typedef unsigned long DWORD;
typedef void* HANDLE;
#  include <kfuncs.h>
# else
#  ifndef WINAPI
#   define WINAPI  __stdcall
#  endif
# endif
# ifndef NTAPI
#  define NTAPI __stdcall
# endif
#else
# error "Win32 functions not available"
#endif

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
struct _LARGE_INTEGER;
struct _SECURITY_ATTRIBUTES;
}
#endif

namespace boost {
namespace detail {
namespace winapi {
#if defined( BOOST_USE_WINDOWS_H )

typedef ::BOOL BOOL_;
typedef ::PBOOL PBOOL_;
typedef ::LPBOOL LPBOOL_;
typedef ::BOOLEAN BOOLEAN_;
typedef ::PBOOLEAN PBOOLEAN_;
typedef ::BYTE BYTE_;
typedef ::PBYTE PBYTE_;
typedef ::LPBYTE LPBYTE_;
typedef ::WORD WORD_;
typedef ::PWORD PWORD_;
typedef ::LPWORD LPWORD_;
typedef ::DWORD DWORD_;
typedef ::PDWORD PDWORD_;
typedef ::LPDWORD LPDWORD_;
typedef ::HANDLE HANDLE_;
typedef ::PHANDLE PHANDLE_;
typedef ::HMODULE HMODULE_;
typedef ::INT INT_;
typedef ::PINT PINT_;
typedef ::LPINT LPINT_;
typedef ::UINT UINT_;
typedef ::PUINT PUINT_;
typedef ::LONG LONG_;
typedef ::PLONG PLONG_;
typedef ::LPLONG LPLONG_;
typedef ::ULONG ULONG_;
typedef ::PULONG PULONG_;
typedef ::LONGLONG LONGLONG_;
typedef ::ULONGLONG ULONGLONG_;
typedef ::INT_PTR INT_PTR_;
typedef ::UINT_PTR UINT_PTR_;
typedef ::LONG_PTR LONG_PTR_;
typedef ::ULONG_PTR ULONG_PTR_;
typedef ::VOID VOID_;
typedef ::PVOID PVOID_;
typedef ::LPVOID LPVOID_;
typedef ::CHAR CHAR_;
typedef ::LPSTR LPSTR_;
typedef ::LPCSTR LPCSTR_;
typedef ::WCHAR WCHAR_;
typedef ::LPWSTR LPWSTR_;
typedef ::LPCWSTR LPCWSTR_;

#else

typedef int BOOL_;
typedef BOOL_* PBOOL_;
typedef BOOL_* LPBOOL_;
typedef unsigned char BYTE_;
typedef BYTE_* PBYTE_;
typedef BYTE_* LPBYTE_;
typedef BYTE_ BOOLEAN_;
typedef BOOLEAN_* PBOOLEAN_;
typedef unsigned short WORD_;
typedef WORD_* PWORD_;
typedef WORD_* LPWORD_;
typedef unsigned long DWORD_;
typedef DWORD_* PDWORD_;
typedef DWORD_* LPDWORD_;
typedef void* HANDLE_;
typedef void** PHANDLE_;
typedef void* HMODULE_;

typedef int INT_;
typedef INT_* PINT_;
typedef INT_* LPINT_;
typedef unsigned int UINT_;
typedef UINT_* PUINT_;
typedef long LONG_;
typedef LONG_* PLONG_;
typedef LONG_* LPLONG_;
typedef unsigned long ULONG_;
typedef ULONG_* PULONG_;

typedef boost::int64_t LONGLONG_;
typedef boost::uint64_t ULONGLONG_;

# ifdef _WIN64
#  if defined(__CYGWIN__)
typedef long INT_PTR_;
typedef unsigned long UINT_PTR_;
typedef long LONG_PTR_;
typedef unsigned long ULONG_PTR_;
#  else
typedef __int64 INT_PTR_;
typedef unsigned __int64 UINT_PTR_;
typedef __int64 LONG_PTR_;
typedef unsigned __int64 ULONG_PTR_;
#  endif
# else
typedef int INT_PTR_;
typedef unsigned int UINT_PTR_;
typedef long LONG_PTR_;
typedef unsigned long ULONG_PTR_;
# endif

typedef void VOID_;
typedef void *PVOID_;
typedef void *LPVOID_;
typedef const void *LPCVOID_;

typedef char CHAR_;
typedef CHAR_ *LPSTR_;
typedef const CHAR_ *LPCSTR_;

typedef wchar_t WCHAR_;
typedef WCHAR_ *LPWSTR_;
typedef const WCHAR_ *LPCWSTR_;

#endif

typedef struct _LARGE_INTEGER {
    LONGLONG_ QuadPart;
} LARGE_INTEGER_, *PLARGE_INTEGER_;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD_  nLength;
    LPVOID_ lpSecurityDescriptor;
    BOOL_   bInheritHandle;
} SECURITY_ATTRIBUTES_, *PSECURITY_ATTRIBUTES_, *LPSECURITY_ATTRIBUTES_;

}
}
}

#endif // BOOST_DETAIL_WINAPI_BASIC_TYPES_HPP
