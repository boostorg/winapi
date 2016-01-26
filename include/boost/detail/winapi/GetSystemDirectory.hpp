//  GetSystemDirectory.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_
#define BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_

#include <boost/detail/winapi/basic_types.hpp>



#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::UINT_ WINAPI
GetSystemDirectoryA(
    boost::detail::winapi::LPSTR_ lpBuffer,
    boost::detail::winapi::UINT_   uSize);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::UINT_ WINAPI
GetSystemDirectoryW(
    boost::detail::winapi::LPWSTR_ lpBuffer,
    boost::detail::winapi::UINT_   uSize);

#endif

namespace boost
{
namespace detail
{
namespace winapi
{

#if !defined( BOOST_NO_ANSI_APIS )
using ::GetSystemDirectoryA;
#endif
using ::GetSystemDirectoryW;


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE UINT_ get_system_directory (LPSTR_ lpBuffer,  UINT_ uSize)
{
	return ::GetSystemDirectoryA(lpBuffer, uSize);
}
#endif

BOOST_FORCEINLINE UINT_ get_system_directory (LPWSTR_ lpBuffer,  UINT_ uSize)
{
	return ::GetSystemDirectoryW(lpBuffer, uSize);
}


}

}

}
}

#endif /* BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_ */
