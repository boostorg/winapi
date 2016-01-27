//  shell_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_SHELL_API_HPP_
#define BOOST_DETAIL_WINAPI_SHELL_API_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if !defined( BOOST_NO_ANSI_APIS )
struct _SHFILEINFOA;
#endif // BOOST_NO_ANSI_APIS
struct _SHFILEINFOW;

#if !defined( BOOST_NO_ANSI_APIS )

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_PTR_ WINAPI SHGetFileInfoA(
        boost::detail::winapi::LPCSTR_ pszPath,
        boost::detail::winapi::DWORD_ dwFileAttributes,
        ::_SHFILEINFOA *psfinsigned,
        boost::detail::winapi::UINT_ cbFileInfons,
        boost::detail::winapi::UINT_ uFlags);

#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_PTR_ WINAPI SHGetFileInfoW(
        boost::detail::winapi::LPCWSTR_ pszPath,
        boost::detail::winapi::DWORD_ dwFileAttributes,
        ::_SHFILEINFOW *psfinsigned,
        boost::detail::winapi::UINT_ cbFileInfons,
        boost::detail::winapi::UINT_ uFlags);

BOOST_DETAIL_WINAPI_DECLARE_HANDLE(HICON)
;

}
#endif // BOOST_USE_WINDOWS_H

namespace boost {
namespace detail {
namespace winapi {

typedef ::HICON HICON_;

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ SHGFI_ICON_              = SHGFI_ICON;
const DWORD_ SHGFI_DISPLAYNAME_       = SHGFI_DISPLAYNAME;
const DWORD_ SHGFI_TYPENAME_          = SHGFI_TYPENAME;
const DWORD_ SHGFI_ATTRIBUTES_        = SHGFI_ATTRIBUTES;
const DWORD_ SHGFI_ICONLOCATION_      = SHGFI_ICONLOCATION;
const DWORD_ SHGFI_EXETYPE_           = SHGFI_EXETYPE;
const DWORD_ SHGFI_SYSICONINDEX_      = SHGFI_SYSICONINDEX;
const DWORD_ SHGFI_LINKOVERLAY_       = SHGFI_LINKOVERLAY;
const DWORD_ SHGFI_SELECTED_          = SHGFI_SELECTED;
const DWORD_ SHGFI_ATTR_SPECIFIED_    = SHGFI_ATTR_SPECIFIED;
const DWORD_ SHGFI_LARGEICON_         = SHGFI_LARGEICON;
const DWORD_ SHGFI_SMALLICON_         = SHGFI_SMALLICON;
const DWORD_ SHGFI_OPENICON_          = SHGFI_OPENICON;
const DWORD_ SHGFI_SHELLICONSIZE_     = SHGFI_SHELLICONSIZE;
const DWORD_ SHGFI_PIDL_              = SHGFI_PIDL;
const DWORD_ SHGFI_USEFILEATTRIBUTES_ = SHGFI_USEFILEATTRIBUTES;
const DWORD_ SHGFI_ADDOVERLAYS_       = SHGFI_ADDOVERLAYS;
const DWORD_ SHGFI_OVERLAYINDEX_      = SHGFI_OVERLAYINDEX;
const DWORD_ MAX_PATH_                = MAX_PATH;

using ::SHGetFileInfoA;
using ::SHGetFileInfoW;

typedef ::SHFILEINFOA SHFILEINFOA_;
typedef ::SHFILEINFOW SHFILEINFOW_;
#else

const DWORD_ max_path = 260;

const DWORD_ SHGFI_ICON_              = 0x000000100;
const DWORD_ SHGFI_DISPLAYNAME_       = 0x000000200;
const DWORD_ SHGFI_TYPENAME_          = 0x000000400;
const DWORD_ SHGFI_ATTRIBUTES_        = 0x000000800;
const DWORD_ SHGFI_ICONLOCATION_      = 0x000001000;
const DWORD_ SHGFI_EXETYPE_           = 0x000002000;
const DWORD_ SHGFI_SYSICONINDEX_      = 0x000004000;
const DWORD_ SHGFI_LINKOVERLAY_       = 0x000008000;
const DWORD_ SHGFI_SELECTED_          = 0x000010000;
const DWORD_ SHGFI_ATTR_SPECIFIED_    = 0x000020000;
const DWORD_ SHGFI_LARGEICON_         = 0x000000000;
const DWORD_ SHGFI_SMALLICON_         = 0x000000001;
const DWORD_ SHGFI_OPENICON_          = 0x000000002;
const DWORD_ SHGFI_SHELLICONSIZE_     = 0x000000004;
const DWORD_ SHGFI_PIDL_              = 0x000000008;
const DWORD_ SHGFI_USEFILEATTRIBUTES_ = 0x000000010;
const DWORD_ SHGFI_ADDOVERLAYS_       = 0x000000020;
const DWORD_ SHGFI_OVERLAYINDEX_      = 0x000000040;
const DWORD_ MAX_PATH_                = 260;

struct SHFILEINFOA_ {
    HICON_ hIcon;
    int iIcon;
    DWORD_ dwAttributes;
    CHAR_ szDisplayName[MAX_PATH_];
    CHAR_ szTypeName[80];
};

struct SHFILEINFOW_ {
    HICON_ hIcon;
    int iIcon;
    DWORD_ dwAttributes;
    WCHAR_ szDisplayName[MAX_PATH_];
    WCHAR_ szTypeName[80];
};

#endif

#if !defined( BOOST_NO_ANSI_APIS )

typedef SHFILEINFOA_ SHFILEINFO_;
inline DWORD_PTR_ sh_get_file_info(
        LPCSTR_ pszPath,
        DWORD_ dwFileAttributes,
        SHFILEINFOA_ *psfinsigned,
        UINT_ cbFileInfons,
        UINT_ uFlags) {
    return ::SHGetFileInfoA(
            pszPath,
            dwFileAttributes,
            reinterpret_cast< ::_SHFILEINFOA* >(psfinsigned),
            cbFileInfons,
            uFlags);
}
#endif // BOOST_NO_ANSI_APIS

inline DWORD_PTR_ sh_get_file_info(
        LPCWSTR_ pszPath,
        DWORD_ dwFileAttributes,
        SHFILEINFOW_ *psfinsigned,
        UINT_ cbFileInfons,
        UINT_ uFlags) {
    return ::SHGetFileInfoW(
            pszPath,
            dwFileAttributes,
            reinterpret_cast< ::_SHFILEINFOW* >(psfinsigned),
            cbFileInfons,
            uFlags);
}

}
}
}

#endif /* BOOST_DETAIL_WINAPI_SHELL_API_HPP_ */
