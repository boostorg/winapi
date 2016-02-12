//  creation_disposition.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_CREATION_DISPOSITION_HPP
#define BOOST_DETAIL_WINAPI_CREATION_DISPOSITION_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ CREATE_NEW_ = CREATE_NEW;
const DWORD_ CREATE_ALWAYS_ = CREATE_ALWAYS;
const DWORD_ OPEN_EXISTING_ = OPEN_EXISTING;
const DWORD_ OPEN_ALWAYS_ = OPEN_ALWAYS;
const DWORD_ TRUNCATE_EXISTING_ = TRUNCATE_EXISTING;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ CREATE_NEW_ = 1;
const DWORD_ CREATE_ALWAYS_ = 2;
const DWORD_ OPEN_EXISTING_ = 3;
const DWORD_ OPEN_ALWAYS_ = 4;
const DWORD_ TRUNCATE_EXISTING_ = 5;

#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_CREATION_DISPOSITION_HPP
