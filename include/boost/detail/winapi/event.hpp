//  event.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_EVENT_HPP
#define BOOST_DETAIL_WINAPI_EVENT_HPP

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/security.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateEventA(
    ::_SECURITY_ATTRIBUTES* lpEventAttributes,
    boost::detail::winapi::BOOL_ bManualReset,
    boost::detail::winapi::BOOL_ bInitialState,
    boost::detail::winapi::LPCSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
OpenEventA(
    boost::detail::winapi::DWORD_ dwDesiredAccess,
    boost::detail::winapi::BOOL_ bInheritHandle,
    boost::detail::winapi::LPCSTR_ lpName);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateEventW(
    ::_SECURITY_ATTRIBUTES* lpEventAttributes,
    boost::detail::winapi::BOOL_ bManualReset,
    boost::detail::winapi::BOOL_ bInitialState,
    boost::detail::winapi::LPCWSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
OpenEventW(
    boost::detail::winapi::DWORD_ dwDesiredAccess,
    boost::detail::winapi::BOOL_ bInheritHandle,
    boost::detail::winapi::LPCWSTR_ lpName);

// Windows CE define SetEvent/ResetEvent as inline functions in kfuncs.h
#if !defined( UNDER_CE )
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
SetEvent(boost::detail::winapi::HANDLE_ hEvent);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
ResetEvent(boost::detail::winapi::HANDLE_ hEvent);
#endif
}
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
using ::CreateEventA;
#endif
using ::CreateEventW;

#else // defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateEventA(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCSTR_ lpName)
{
    return ::CreateEventA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
}
#endif

BOOST_FORCEINLINE HANDLE_ CreateEventW(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCWSTR_ lpName)
{
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
}

#endif // defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
using ::OpenEventA;
#endif
using ::OpenEventW;
using ::SetEvent;
using ::ResetEvent;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCSTR_ lpName)
{
    return ::CreateEventA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
}

BOOST_FORCEINLINE HANDLE_ open_event(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCSTR_ lpName)
{
    return ::OpenEventA(dwDesiredAccess, bInheritHandle, lpName);
}
#endif

BOOST_FORCEINLINE HANDLE_ create_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCWSTR_ lpName)
{
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
}

BOOST_FORCEINLINE HANDLE_ open_event(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCWSTR_ lpName)
{
    return ::OpenEventW(dwDesiredAccess, bInheritHandle, lpName);
}

BOOST_FORCEINLINE HANDLE_ create_anonymous_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState)
{
#ifdef BOOST_NO_ANSI_APIS
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, 0);
#else
    return ::CreateEventA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, 0);
#endif
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_EVENT_HPP
