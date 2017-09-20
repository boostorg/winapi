//  bcrypt.hpp  --------------------------------------------------------------//

//  Copyright 2017 James E. King, III

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_BCRYPT_HPP
#define BOOST_DETAIL_WINAPI_BCRYPT_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
#if defined(BOOST_WINAPI_IS_MINGW_W64) || (BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_VISTA)

#if defined(BOOST_USE_WINDOWS_H)
#include <bcrypt.h>
#else

namespace boost { namespace detail { namespace winapi {
    typedef PVOID_ BCRYPT_ALG_HANDLE_;
}}}

extern "C" {
boost::detail::winapi::NTSTATUS_ WINAPI
    BCryptCloseAlgorithmProvider(
        boost::detail::winapi::BCRYPT_ALG_HANDLE_ hAlgorithm,
        boost::detail::winapi::ULONG_             dwFlags
    );

boost::detail::winapi::NTSTATUS_ WINAPI
    BCryptGenRandom(
        boost::detail::winapi::BCRYPT_ALG_HANDLE_ hAlgorithm,
        boost::detail::winapi::PUCHAR_            pbBuffer,
        boost::detail::winapi::ULONG_             cbBuffer,
        boost::detail::winapi::ULONG_             dwFlags
    );

boost::detail::winapi::NTSTATUS_ WINAPI
    BCryptOpenAlgorithmProvider(
        boost::detail::winapi::BCRYPT_ALG_HANDLE_ *phAlgorithm,
        boost::detail::winapi::LPCWSTR_           pszAlgId,
        boost::detail::winapi::LPCWSTR_           pszImplementation,
        boost::detail::winapi::DWORD_             dwFlags
    );
} // extern "C"
#endif // !BOOST_USE_WINDOWS_H

namespace boost {
namespace detail {
namespace winapi {

#if defined(BOOST_USE_WINDOWS_H)
    typedef ::BCRYPT_ALG_HANDLE BCRYPT_ALG_HANDLE_;
    const LPCWSTR_ BCRYPT_RNG_ALGORITHM_ = BCRYPT_RNG_ALGORITHM;
#else
    const LPCWSTR_ BCRYPT_RNG_ALGORITHM_ = L"RNG";
#endif

using ::BCryptCloseAlgorithmProvider;
using ::BCryptGenRandom;
using ::BCryptOpenAlgorithmProvider;

} // winapi
} // detail
} // boost

#endif // defined(BOOST_WINAPI_IS_MINGW_W64) || (BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_VISTA)
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_DETAIL_WINAPI_BCRYPT_HPP
