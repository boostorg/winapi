//  IsMingw.hxx  --------------------------------------------------------------//

//  Copyright 2015 Edward Diener

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_ISMINGW_HXX
#define BOOST_DETAIL_WINAPI_ISMINGW_HXX

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

/*

The macro BOOST_WINAPI_IS_MINGW expands to 1
if the compiler targets gcc/mingw on Windows,
else it expands to 0. For mingw-64 on Windows
it expands to 0. On Windows both gcc and clang
can target gcc/mingw.

The macro BOOST_WINAPI_IS_MINGW_64 expands to 1
if the compiler targets gcc/mingw-64 on Windows,
else it expands to 0. For mingw on Windows
it expands to 0. On Windows currently only gcc
can target gcc/mingw-64.

*/

#if defined __MINGW32__
#include <_mingw.h>
#if defined __MINGW64_VERSION_MAJOR
#define BOOST_WINAPI_IS_MINGW 0
#define BOOST_WINAPI_IS_MINGW_64 1
#else
#define BOOST_WINAPI_IS_MINGW 1
#define BOOST_WINAPI_IS_MINGW_64 0
#endif
#else
#define BOOST_WINAPI_IS_MINGW 0
#define BOOST_WINAPI_IS_MINGW_64 0
#endif

#endif //BOOST_DETAIL_WINAPI_ISMINGW_HXX
