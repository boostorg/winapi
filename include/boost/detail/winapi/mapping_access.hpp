//  mapping_access.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_MAPPING_ACCESS_HPP
#define BOOST_DETAIL_WINAPI_MAPPING_ACCESS_HPP

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/access_rights.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_MAP_COPY_ = FILE_MAP_COPY;
const DWORD_ FILE_MAP_WRITE_ = FILE_MAP_WRITE;
const DWORD_ FILE_MAP_READ_ = FILE_MAP_READ;
const DWORD_ FILE_MAP_ALL_ACCESS_ = FILE_MAP_ALL_ACCESS;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ FILE_MAP_COPY_ = 0x0001;
const DWORD_ FILE_MAP_WRITE_ = 0x0002;
const DWORD_ FILE_MAP_READ_ = 0x0004;
const DWORD_ FILE_MAP_ALL_ACCESS_ = STANDARD_RIGHTS_REQUIRED_ | 0x1F;

#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_MAPPING_ACCESS_HPP
