//  dbghelp.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_DBGHELP_HPP_
#define BOOST_DETAIL_WINAPI_DBGHELP_HPP_

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif


#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI UnDecorateSymbolName
        (const boost::detail::winapi::CHAR_ * DecoratedName,
               boost::detail::winapi::CHAR_ *UnDecoratedName,
               boost::detail::winapi::DWORD_ UndecoratedLength,
               boost::detail::winapi::DWORD_ Flags);

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI UnDecorateSymbolNameW
        (const boost::detail::winapi::WCHAR_ * DecoratedName,
               boost::detail::winapi::WCHAR_* UnDecoratedName,
               boost::detail::winapi::DWORD_ UndecoratedLength,
               boost::detail::winapi::DWORD_ Flags);

struct API_VERSION;
BOOST_SYMBOL_IMPORT API_VERSION* WINAPI ImagehlpApiVersion();
}
#else
#include <Dbghelp.h>
#endif


namespace boost
{
namespace detail
{
namespace winapi
{

using ::UnDecorateSymbolName;
using ::UnDecorateSymbolNameW;

inline DWORD_ undecorate_symbol_name(const char* decorated_name,
                              char*  undecorated_name,
                              DWORD_ undecorated_length,
                              DWORD_ flags)
{
    return ::UnDecorateSymbolName(decorated_name, undecorated_name, undecorated_length, flags);
}

inline DWORD_ undecorate_symbol_name(const wchar_t* decorated_name,
                              wchar_t*  undecorated_name,
                              DWORD_ undecorated_length,
                              DWORD_ flags)
{
    return ::UnDecorateSymbolNameW(decorated_name, undecorated_name, undecorated_length, flags);
}
struct API_VERSION {
  unsigned short MajorVersion;
  unsigned short MinorVersion;
  unsigned short Revision;
  unsigned short Reserved;
};

inline API_VERSION* ImagehlpApiVersion()
{
    return reinterpret_cast<API_VERSION*>(::ImagehlpApiVersion());
}

}}}




#endif /* INCLUDE_BOOST_DETAIL_WINAPI_DBGHELP_HPP_ */
