//  share_mode.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_SHARE_MODE_HPP
#define BOOST_DETAIL_WINAPI_SHARE_MODE_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_SHARE_READ_ = FILE_SHARE_READ;
const DWORD_ FILE_SHARE_WRITE_ = FILE_SHARE_WRITE;
const DWORD_ FILE_SHARE_DELETE_ = FILE_SHARE_DELETE;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_SHARE_READ_ = 0x00000001;
const DWORD_ FILE_SHARE_WRITE_ = 0x00000002;
const DWORD_ FILE_SHARE_DELETE_ = 0x00000004;

#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_SHARE_MODE_HPP
