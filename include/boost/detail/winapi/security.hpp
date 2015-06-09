//  security.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_SECURITY_HPP
#define BOOST_DETAIL_WINAPI_SECURITY_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" { 
struct _ACL;
struct _SECURITY_ATTRIBUTES;
struct _SECURITY_DESCRIPTOR;

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
InitializeSecurityDescriptor(
    ::_SECURITY_DESCRIPTOR* pSecurityDescriptor,
    boost::detail::winapi::DWORD_ dwRevision);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
SetSecurityDescriptorDacl(
    ::_SECURITY_DESCRIPTOR* pSecurityDescriptor,
    boost::detail::winapi::BOOL_ bDaclPresent,
    ::_ACL* pDacl,
    boost::detail::winapi::BOOL_ bDaclDefaulted);
}
#endif

namespace boost {
namespace detail {
namespace winapi {
#if defined( BOOST_USE_WINDOWS_H )
typedef ::SECURITY_ATTRIBUTES SECURITY_ATTRIBUTES_;
typedef ::PSECURITY_ATTRIBUTES PSECURITY_ATTRIBUTES_;
typedef ::LPSECURITY_ATTRIBUTES LPSECURITY_ATTRIBUTES_;
#else
struct SECURITY_DESCRIPTOR_;
typedef SECURITY_DESCRIPTOR_* PSECURITY_DESCRIPTOR_;
typedef struct _ACL {
    BYTE_ AclRevision;
    BYTE_ Sbz1;
    WORD_ AclSize;
    WORD_ AceCount;
    WORD_ Sbz2;
} ACL_, *PACL_;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD_  nLength;
    LPVOID_ lpSecurityDescriptor;
    BOOL_   bInheritHandle;
} SECURITY_ATTRIBUTES_, *PSECURITY_ATTRIBUTES_, *LPSECURITY_ATTRIBUTES_;

BOOST_FORCEINLINE BOOL_ InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR_ pSecurityDescriptor, DWORD_ dwRevision)
{
    return ::InitializeSecurityDescriptor(reinterpret_cast< ::_SECURITY_DESCRIPTOR* >(pSecurityDescriptor), dwRevision);
}

BOOST_FORCEINLINE BOOL_ SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR_ pSecurityDescriptor, BOOL_ bDaclPresent, PACL_ pDacl, BOOL_ bDaclDefaulted)
{
    return ::SetSecurityDescriptorDacl(reinterpret_cast< ::_SECURITY_DESCRIPTOR* >(pSecurityDescriptor), bDaclPresent, reinterpret_cast< ::_ACL* >(pDacl), bDaclDefaulted);
}
#endif
}
}
}

#endif // BOOST_DETAIL_WINAPI_SECURITY_HPP
