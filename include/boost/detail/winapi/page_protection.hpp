//  page_protection.hpp  --------------------------------------------------------------//

//  Copyright 2016 Jorge Lodos

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_PAGE_PROTECTION_HPP
#define BOOST_DETAIL_WINAPI_PAGE_PROTECTION_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ PAGE_NOACCESS_ = PAGE_NOACCESS;
const DWORD_ PAGE_READONLY_ = PAGE_READONLY;
const DWORD_ PAGE_READWRITE_ = PAGE_READWRITE;
const DWORD_ PAGE_WRITECOPY_ = PAGE_WRITECOPY;

const DWORD_ SEC_FILE_ = SEC_FILE;
const DWORD_ SEC_IMAGE_ = SEC_IMAGE;
const DWORD_ SEC_PROTECTED_IMAGE_ = SEC_PROTECTED_IMAGE;
const DWORD_ SEC_RESERVE_ = SEC_RESERVE;
const DWORD_ SEC_COMMIT_ = SEC_COMMIT;
const DWORD_ SEC_NOCACHE_ = SEC_NOCACHE;
const DWORD_ SEC_WRITECOMBINE_ = SEC_WRITECOMBINE;
const DWORD_ SEC_LARGE_PAGES_ = SEC_LARGE_PAGES;
const DWORD_ SEC_IMAGE_NO_EXECUTE_ = SEC_IMAGE_NO_EXECUTE;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ PAGE_NOACCESS_ = 0x01;
const DWORD_ PAGE_READONLY_ = 0x02;
const DWORD_ PAGE_READWRITE_ = 0x04;
const DWORD_ PAGE_WRITECOPY_ = 0x08;

const DWORD_ SEC_FILE_ = 0x800000;
const DWORD_ SEC_IMAGE_ = 0x1000000;
const DWORD_ SEC_PROTECTED_IMAGE_ = 0x2000000;
const DWORD_ SEC_RESERVE_ = 0x4000000;
const DWORD_ SEC_COMMIT_ = 0x8000000;
const DWORD_ SEC_NOCACHE_ = 0x10000000;
const DWORD_ SEC_WRITECOMBINE_ = 0x40000000;
const DWORD_ SEC_LARGE_PAGES_ = 0x80000000;
const DWORD_ SEC_IMAGE_NO_EXECUTE_ = (SEC_IMAGE_ | SEC_NOCACHE_);

#endif // defined( BOOST_USE_WINDOWS_H )

}
}
}

#endif // BOOST_DETAIL_WINAPI_PAGE_PROTECTION_HPP
