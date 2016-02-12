//  file_errors.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_FILE_ERRORS_HPP
#define BOOST_DETAIL_WINAPI_FILE_ERRORS_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ INVALID_FILE_SIZE_ = INVALID_FILE_SIZE;
const DWORD_ INVALID_SET_FILE_POINTER_ = INVALID_SET_FILE_POINTER;
const DWORD_ INVALID_FILE_ATTRIBUTES_ = INVALID_FILE_ATTRIBUTES;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ INVALID_FILE_SIZE_ = ((DWORD_)0xFFFFFFFF);
const DWORD_ INVALID_SET_FILE_POINTER_ = ((DWORD_)-1);
const DWORD_ INVALID_FILE_ATTRIBUTES_ = ((DWORD_)-1);
        
#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_FILE_ERRORS_HPP
