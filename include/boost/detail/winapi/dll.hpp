//  dll.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_DLL_HPP
#define BOOST_DETAIL_WINAPI_DLL_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

namespace boost { namespace detail { namespace winapi {
#ifdef _WIN64
typedef INT_PTR_ (WINAPI *FARPROC_)();
typedef INT_PTR_ (WINAPI *NEARPROC_)();
typedef INT_PTR_ (WINAPI *PROC_)();
#else
typedef int (WINAPI *FARPROC_)();
typedef int (WINAPI *NEARPROC_)();
typedef int (WINAPI *PROC_)();
#endif // _WIN64
}}}

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::HMODULE_ WINAPI
    LoadLibraryA(boost::detail::winapi::LPCSTR_ lpFileName);
BOOST_SYMBOL_IMPORT boost::detail::winapi::HMODULE_ WINAPI
    GetModuleHandleA(boost::detail::winapi::LPCSTR_ lpFileName);
#endif
BOOST_SYMBOL_IMPORT boost::detail::winapi::HMODULE_ WINAPI
    LoadLibraryW(boost::detail::winapi::LPCWSTR_ lpFileName);
BOOST_SYMBOL_IMPORT boost::detail::winapi::HMODULE_ WINAPI
    GetModuleHandleW(boost::detail::winapi::LPCWSTR_ lpFileName);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    FreeLibrary(boost::detail::winapi::HMODULE_ hModule);
BOOST_SYMBOL_IMPORT boost::detail::winapi::FARPROC_ WINAPI
    GetProcAddress(boost::detail::winapi::HMODULE_ hModule, boost::detail::winapi::LPCSTR_ lpProcName);
}
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )
typedef ::FARPROC FARPROC_;
typedef ::NEARPROC NEARPROC_;
typedef ::PROC PROC_;
#endif

#if !defined( BOOST_NO_ANSI_APIS )
using ::LoadLibraryA;
using ::GetModuleHandleA;
#endif
using ::LoadLibraryW;
using ::GetModuleHandleW;
using ::FreeLibrary;
using ::GetProcAddress;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HMODULE_ load_library(LPCSTR_ lpFileName)
{
    return ::LoadLibraryA(lpFileName);
}

BOOST_FORCEINLINE HMODULE_ get_module_handle(LPCSTR_ lpFileName)
{
    return ::GetModuleHandleA(lpFileName);
}
#endif

BOOST_FORCEINLINE HMODULE_ load_library(LPCWSTR_ lpFileName)
{
    return ::LoadLibraryW(lpFileName);
}

BOOST_FORCEINLINE HMODULE_ get_module_handle(LPCWSTR_ lpFileName)
{
    return ::GetModuleHandleW(lpFileName);
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_DLL_HPP
