//  crypt.hpp  --------------------------------------------------------------//

//  Copyright 2014 Antony Polukhin
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_CRYPT_HPP
#define BOOST_DETAIL_WINAPI_CRYPT_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
namespace boost { namespace detail { namespace winapi {
typedef ULONG_PTR_ HCRYPTPROV_;
}}}

extern "C" {
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    CryptEnumProvidersA(
        boost::detail::winapi::DWORD_ dwIndex,
        boost::detail::winapi::DWORD_ *pdwReserved,
        boost::detail::winapi::DWORD_ dwFlags,
        boost::detail::winapi::DWORD_ *pdwProvType,
        boost::detail::winapi::LPSTR_ szProvName,
        boost::detail::winapi::DWORD_ *pcbProvName
);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    CryptAcquireContextA(
        boost::detail::winapi::HCRYPTPROV_ *phProv,
        boost::detail::winapi::LPCSTR_ pszContainer,
        boost::detail::winapi::LPCSTR_ pszProvider,
        boost::detail::winapi::DWORD_ dwProvType,
        boost::detail::winapi::DWORD_ dwFlags
);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    CryptGenRandom(
        boost::detail::winapi::HCRYPTPROV_ hProv,
        boost::detail::winapi::DWORD_ dwLen,
        boost::detail::winapi::BYTE_ *pbBuffer
);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    CryptReleaseContext(
        boost::detail::winapi::HCRYPTPROV_ hProv,
        boost::detail::winapi::DWORD_ dwFlags
);
}
#endif

namespace boost
{
namespace detail
{
namespace winapi
{
#if defined( BOOST_USE_WINDOWS_H )

typedef HCRYPTPROV HCRYPTPROV_;

using ::CryptEnumProvidersA;
using ::CryptAcquireContextA;
using ::CryptGenRandom;
using ::CryptReleaseContext;

const DWORD_ PROV_RSA_FULL_         = PROV_RSA_FULL;

const DWORD_ CRYPT_VERIFYCONTEXT_   = CRYPT_VERIFYCONTEXT;
const DWORD_ CRYPT_NEWKEYSET_       = CRYPT_NEWKEYSET;
const DWORD_ CRYPT_DELETEKEYSET_    = CRYPT_DELETEKEYSET;
const DWORD_ CRYPT_MACHINE_KEYSET_  = CRYPT_MACHINE_KEYSET;
const DWORD_ CRYPT_SILENT_          = CRYPT_SILENT;

#else

BOOST_FORCEINLINE BOOL_ CryptEnumProvidersA(
    DWORD_ dwIndex,
    DWORD_ *pdwReserved,
    DWORD_ dwFlags,
    DWORD_ *pdwProvType,
    LPSTR_ szProvName,
    DWORD_ *pcbProvName
)
{
    return ::CryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, szProvName, pcbProvName);
}

BOOST_FORCEINLINE BOOL_ CryptAcquireContextA(
    HCRYPTPROV_ *phProv,
    LPCSTR_ pszContainer,
    LPCSTR_ pszProvider,
    DWORD_ dwProvType,
    DWORD_ dwFlags
)
{
    return ::CryptAcquireContextA(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}

BOOST_FORCEINLINE BOOL_ CryptGenRandom(HCRYPTPROV_ hProv, DWORD_ dwLen, BYTE_ *pbBuffer)
{
    return ::CryptGenRandom(hProv, dwLen, pbBuffer);
}

BOOST_FORCEINLINE BOOL_ CryptReleaseContext(HCRYPTPROV_ hProv, DWORD_ dwFlags)
{
    return ::CryptReleaseContext(hProv, dwFlags);
}

const DWORD_ PROV_RSA_FULL_         = 1;

const DWORD_ CRYPT_VERIFYCONTEXT_   = 0xF0000000;
const DWORD_ CRYPT_NEWKEYSET_       = 8;
const DWORD_ CRYPT_DELETEKEYSET_    = 16;
const DWORD_ CRYPT_MACHINE_KEYSET_  = 32;
const DWORD_ CRYPT_SILENT_          = 64;

#endif
}
}
}

#endif // BOOST_DETAIL_WINAPI_CRYPT_HPP
