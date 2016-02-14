//  dbghelp.hpp  --------------------------------------------------------------//

//  Copyright 2015 Klemens Morgenstern
//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_DBGHELP_HPP
#define BOOST_DETAIL_WINAPI_DBGHELP_HPP

// dbghelp is supported in MinGW-w64 but not MinGW
#if !defined( BOOST_WINAPI_IS_MINGW )

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI
UnDecorateSymbolName(
    boost::detail::winapi::LPCSTR_ DecoratedName,
    boost::detail::winapi::LPSTR_ UnDecoratedName,
    boost::detail::winapi::DWORD_ UndecoratedLength,
    boost::detail::winapi::DWORD_ Flags);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI
UnDecorateSymbolNameW(
    boost::detail::winapi::LPCWSTR_ DecoratedName,
    boost::detail::winapi::LPWSTR_ UnDecoratedName,
    boost::detail::winapi::DWORD_ UndecoratedLength,
    boost::detail::winapi::DWORD_ Flags);

struct API_VERSION;
typedef API_VERSION* LPAPI_VERSION;
BOOST_SYMBOL_IMPORT LPAPI_VERSION WINAPI
ImagehlpApiVersion();

}
#endif

namespace boost {
namespace detail {
namespace winapi {

#if !defined( BOOST_NO_ANSI_APIS )
using ::UnDecorateSymbolName;
#endif

using ::UnDecorateSymbolNameW;

typedef struct BOOST_DETAIL_WINAPI_MAY_ALIAS API_VERSION {
    USHORT_  MajorVersion;
    USHORT_  MinorVersion;
    USHORT_  Revision;
    USHORT_  Reserved;
} API_VERSION_, *LPAPI_VERSION_;

BOOST_FORCEINLINE LPAPI_VERSION_ ImagehlpApiVersion()
{
    return reinterpret_cast<LPAPI_VERSION_>(::ImagehlpApiVersion());
}

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE DWORD_ undecorate_symbol_name(
    LPCSTR_ DecoratedName,
    LPSTR_ UnDecoratedName,
    DWORD_ UndecoratedLength,
    DWORD_ Flags)
{
    return ::UnDecorateSymbolName(
        DecoratedName,
        UnDecoratedName,
        UndecoratedLength,
        Flags);
}
#endif

BOOST_FORCEINLINE DWORD_ undecorate_symbol_name(
    LPCWSTR_ DecoratedName,
    LPWSTR_ UnDecoratedName,
    DWORD_ UndecoratedLength,
    DWORD_ Flags)
{
    return ::UnDecorateSymbolNameW(
        DecoratedName,
        UnDecoratedName,
        UndecoratedLength,
        Flags);
}

}
}
}

#endif // BOOST_WINAPI_IS_MINGW

#endif // BOOST_DETAIL_WINAPI_DBGHELP_HPP
