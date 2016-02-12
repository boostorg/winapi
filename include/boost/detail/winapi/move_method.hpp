//  move_method.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_MOVE_METHOD_HPP
#define BOOST_DETAIL_WINAPI_MOVE_METHOD_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_BEGIN_ = FILE_BEGIN;
const DWORD_ FILE_CURRENT_ = FILE_CURRENT;
const DWORD_ FILE_END_ = FILE_END;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_BEGIN_ = 0;
const DWORD_ FILE_CURRENT_ = 1;
const DWORD_ FILE_END_ = 2;

#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_MOVE_METHOD_HPP
