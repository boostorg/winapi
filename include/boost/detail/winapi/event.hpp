//  event.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_EVENT_HPP
#define BOOST_DETAIL_WINAPI_EVENT_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateEventA(
    ::_SECURITY_ATTRIBUTES* lpEventAttributes,
    boost::detail::winapi::BOOL_ bManualReset,
    boost::detail::winapi::BOOL_ bInitialState,
    boost::detail::winapi::LPCSTR_ lpName);
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateEventExA(
    ::_SECURITY_ATTRIBUTES *lpEventAttributes,
    boost::detail::winapi::LPCSTR_ lpName,
    boost::detail::winapi::DWORD_ dwFlags,
    boost::detail::winapi::DWORD_ dwDesiredAccess);
#endif

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

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
CreateEventExW(
    ::_SECURITY_ATTRIBUTES *lpEventAttributes,
    boost::detail::winapi::LPCWSTR_ lpName,
    boost::detail::winapi::DWORD_ dwFlags,
    boost::detail::winapi::DWORD_ dwDesiredAccess);
#endif

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

#if !defined( BOOST_NO_ANSI_APIS )
using ::OpenEventA;
#endif
using ::OpenEventW;
using ::SetEvent;
using ::ResetEvent;

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ CREATE_EVENT_INITIAL_SET_ = CREATE_EVENT_INITIAL_SET;
const DWORD_ CREATE_EVENT_MANUAL_RESET_ = CREATE_EVENT_MANUAL_RESET;
const DWORD_ EVENT_ALL_ACCESS_ = EVENT_ALL_ACCESS;

#else // defined( BOOST_USE_WINDOWS_H )
    
const DWORD_ CREATE_EVENT_INITIAL_SET_ = 0x00000002;
const DWORD_ CREATE_EVENT_MANUAL_RESET_ = 0x00000001;
const DWORD_ EVENT_ALL_ACCESS_ = 0x1F0003;

#endif // defined( BOOST_USE_WINDOWS_H )

const DWORD_ create_event_initial_set = CREATE_EVENT_INITIAL_SET_;
const DWORD_ create_event_manual_reset = CREATE_EVENT_MANUAL_RESET_;
const DWORD_ event_all_access = EVENT_ALL_ACCESS_;


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateEventA(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCSTR_ lpName)
{
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
    return ::CreateEventA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
#else
    DWORD_ flags = (bManualReset ? create_event_manual_reset : 0)
                 | (bInitialState ? create_event_initial_set : 0)
                 ;
    return ::CreateEventExA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, flags, event_all_access); 
#endif
}

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_FORCEINLINE HANDLE_ CreateEventExA(SECURITY_ATTRIBUTES_* lpEventAttributes, LPCSTR_ lpName, DWORD_ dwFlags, DWORD_ dwDesiredAccess)
{
    return ::CreateEventExA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, dwFlags, dwDesiredAccess);
}
#endif
#endif

BOOST_FORCEINLINE HANDLE_ CreateEventW(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCWSTR_ lpName)
{
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
#else
    DWORD_ flags = (bManualReset ? create_event_manual_reset : 0)
                 | (bInitialState ? create_event_initial_set : 0)
                 ;
    return ::CreateEventExW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, flags, event_all_access); 
#endif
}

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_FORCEINLINE HANDLE_ CreateEventExW(SECURITY_ATTRIBUTES_* lpEventAttributes, LPCWSTR_ lpName, DWORD_ dwFlags, DWORD_ dwDesiredAccess)
{
    return ::CreateEventExW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, dwFlags, dwDesiredAccess);
}
#endif

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCSTR_ lpName)
{
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
    return ::CreateEventA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
#else
    DWORD_ flags = (bManualReset ? create_event_manual_reset : 0)
                 | (bInitialState ? create_event_initial_set : 0)
                 ;
    return ::CreateEventExA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, flags, event_all_access); 
#endif
}

BOOST_FORCEINLINE HANDLE_ open_event(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCSTR_ lpName)
{
    return ::OpenEventA(dwDesiredAccess, bInheritHandle, lpName);
}
#endif

BOOST_FORCEINLINE HANDLE_ create_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState, LPCWSTR_ lpName)
{
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, lpName);
#else
    DWORD_ flags = (bManualReset ? create_event_manual_reset : 0)
                 | (bInitialState ? create_event_initial_set : 0)
                 ;
    return ::CreateEventExW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), lpName, flags, event_all_access); 
#endif
}

BOOST_FORCEINLINE HANDLE_ open_event(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCWSTR_ lpName)
{
    return ::OpenEventW(dwDesiredAccess, bInheritHandle, lpName);
}

BOOST_FORCEINLINE HANDLE_ create_anonymous_event(SECURITY_ATTRIBUTES_* lpEventAttributes, BOOL_ bManualReset, BOOL_ bInitialState)
{
#if !defined( BOOST_PLAT_WINDOWS_RUNTIME_AVALIABLE )
    return ::CreateEventW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), bManualReset, bInitialState, 0);
#else
    DWORD_ flags = (bManualReset ? create_event_manual_reset : 0)
                 | (bInitialState ? create_event_initial_set : 0)
                 ;
    return ::CreateEventExW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpEventAttributes), 0, flags, event_all_access); 
#endif
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_EVENT_HPP
