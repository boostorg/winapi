//  mutex.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_MUTEX_HPP
#define BOOST_DETAIL_WINAPI_MUTEX_HPP

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/security.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateMutexA(
    ::_SECURITY_ATTRIBUTES* lpMutexAttributes,
    boost::detail::winapi::BOOL_ bInitialOwner,
    boost::detail::winapi::LPCSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
OpenMutexA(
    boost::detail::winapi::DWORD_ dwDesiredAccess,
    boost::detail::winapi::BOOL_ bInheritHandle,
    boost::detail::winapi::LPCSTR_ lpName);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateMutexW(
    ::_SECURITY_ATTRIBUTES* lpMutexAttributes,
    boost::detail::winapi::BOOL_ bInitialOwner,
    boost::detail::winapi::LPCWSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
OpenMutexW(
    boost::detail::winapi::DWORD_ dwDesiredAccess,
    boost::detail::winapi::BOOL_ bInheritHandle,
    boost::detail::winapi::LPCWSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
ReleaseMutex(boost::detail::winapi::HANDLE_ hMutex);
}
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
using ::CreateMutexA;
#endif
using ::CreateMutexW;

#else // defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateMutexA(
    SECURITY_ATTRIBUTES_* lpMutexAttributes,
    BOOL_ bInitialOwner,
    LPCSTR_ lpName)
{
    return ::CreateMutexA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpMutexAttributes), bInitialOwner, lpName);
}
#endif

BOOST_FORCEINLINE HANDLE_ CreateMutexW(
    ::_SECURITY_ATTRIBUTES* lpMutexAttributes,
    BOOL_ bInitialOwner,
    LPCWSTR_ lpName)
{
    return ::CreateMutexW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpMutexAttributes), bInitialOwner, lpName);
}

#endif // defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
using ::OpenMutexA;
#endif
using ::OpenMutexW;
using ::ReleaseMutex;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_mutex(SECURITY_ATTRIBUTES_* lpAttributes, BOOL_ bInitialOwner, LPCSTR_ lpName)
{
    return ::CreateMutexA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpAttributes), bInitialOwner, lpName);
}

BOOST_FORCEINLINE HANDLE_ open_mutex(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCSTR_ lpName)
{
    return ::OpenMutexA(dwDesiredAccess, bInheritHandle, lpName);
}
#endif

BOOST_FORCEINLINE HANDLE_ create_mutex(SECURITY_ATTRIBUTES_* lpAttributes, BOOL_ bInitialOwner, LPCWSTR_ lpName)
{
    return ::CreateMutexW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpAttributes), bInitialOwner, lpName);
}

BOOST_FORCEINLINE HANDLE_ open_mutex(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCWSTR_ lpName)
{
    return ::OpenMutexW(dwDesiredAccess, bInheritHandle, lpName);
}

BOOST_FORCEINLINE HANDLE_ create_anonymous_mutex(SECURITY_ATTRIBUTES_* lpAttributes, BOOL_ bInitialOwner)
{
#ifdef BOOST_NO_ANSI_APIS
    return ::CreateMutexW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpAttributes), bInitialOwner, 0);
#else
    return ::CreateMutexA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpAttributes), bInitialOwner, 0);
#endif
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_MUTEX_HPP
