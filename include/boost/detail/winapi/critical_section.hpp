//  critical_section.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_CRITICAL_SECTION_HPP
#define BOOST_DETAIL_WINAPI_CRITICAL_SECTION_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
struct _RTL_CRITICAL_SECTION;

BOOST_SYMBOL_IMPORT boost::detail::winapi::VOID_ WINAPI
InitializeCriticalSection(::_RTL_CRITICAL_SECTION* lpCriticalSection);

BOOST_SYMBOL_IMPORT boost::detail::winapi::VOID_ WINAPI
EnterCriticalSection(::_RTL_CRITICAL_SECTION* lpCriticalSection);

BOOST_SYMBOL_IMPORT boost::detail::winapi::VOID_ WINAPI
LeaveCriticalSection(::_RTL_CRITICAL_SECTION* lpCriticalSection);

#if BOOST_USE_WINAPI_VERSION >= 0x0403
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
InitializeCriticalSectionAndSpinCount(
    ::_RTL_CRITICAL_SECTION* lpCriticalSection,
    boost::detail::winapi::DWORD_ dwSpinCount);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
InitializeCriticalSectionEx(
    ::_RTL_CRITICAL_SECTION* lpCriticalSection,
    boost::detail::winapi::DWORD_ dwSpinCount,
    boost::detail::winapi::DWORD_ Flags);

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI
SetCriticalSectionSpinCount(
    ::_RTL_CRITICAL_SECTION* lpCriticalSection,
    boost::detail::winapi::DWORD_ dwSpinCount);
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
TryEnterCriticalSection(::_RTL_CRITICAL_SECTION* lpCriticalSection);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::VOID_ WINAPI
DeleteCriticalSection(::_RTL_CRITICAL_SECTION* lpCriticalSection);
}
#endif

namespace boost {
namespace detail {
namespace winapi {

struct _RTL_CRITICAL_SECTION_DEBUG;

#pragma pack(push, 8)

typedef struct _RTL_CRITICAL_SECTION {
    _RTL_CRITICAL_SECTION_DEBUG* DebugInfo;
    LONG_ LockCount;
    LONG_ RecursionCount;
    HANDLE_ OwningThread;
    HANDLE_ LockSemaphore;
    ULONG_PTR_ SpinCount;
} CRITICAL_SECTION_, *PCRITICAL_SECTION_;

#pragma pack(pop)

BOOST_FORCEINLINE VOID_ InitializeCriticalSection(CRITICAL_SECTION_* lpCriticalSection)
{
    ::InitializeCriticalSection(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection));
}

BOOST_FORCEINLINE VOID_ EnterCriticalSection(CRITICAL_SECTION_* lpCriticalSection)
{
    ::EnterCriticalSection(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection));
}

BOOST_FORCEINLINE VOID_ LeaveCriticalSection(CRITICAL_SECTION_* lpCriticalSection)
{
    ::LeaveCriticalSection(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection));
}

#if BOOST_USE_WINAPI_VERSION >= 0x0403
BOOST_FORCEINLINE BOOL_ InitializeCriticalSectionAndSpinCount(CRITICAL_SECTION_* lpCriticalSection, DWORD_ dwSpinCount)
{
    return ::InitializeCriticalSectionAndSpinCount(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection), dwSpinCount);
}

#if defined( BOOST_USE_WINDOWS_H )
const DWORD_ CRITICAL_SECTION_FLAG_NO_DEBUG_INFO_ = CRITICAL_SECTION_NO_DEBUG_INFO;
#else
const DWORD_ CRITICAL_SECTION_FLAG_NO_DEBUG_INFO_ = 0x01000000;
#endif
const DWORD_ CRITICAL_SECTION_FLAG_DYNAMIC_SPIN_ = 0x02000000; // undocumented
const DWORD_ CRITICAL_SECTION_FLAG_STATIC_INIT_ = 0x04000000; // undocumented

BOOST_FORCEINLINE BOOL_ InitializeCriticalSectionEx(CRITICAL_SECTION_* lpCriticalSection, DWORD_ dwSpinCount, DWORD_ Flags)
{
    return ::InitializeCriticalSectionEx(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection), dwSpinCount, Flags);
}

BOOST_FORCEINLINE DWORD_ SetCriticalSectionSpinCount(CRITICAL_SECTION_* lpCriticalSection, DWORD_ dwSpinCount)
{
    return ::SetCriticalSectionSpinCount(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection), dwSpinCount);
}
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
BOOST_FORCEINLINE BOOL_ TryEnterCriticalSection(CRITICAL_SECTION_* lpCriticalSection)
{
    return ::TryEnterCriticalSection(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection));
}
#endif

BOOST_FORCEINLINE VOID_ DeleteCriticalSection(CRITICAL_SECTION_* lpCriticalSection)
{
    ::DeleteCriticalSection(reinterpret_cast< ::_RTL_CRITICAL_SECTION* >(lpCriticalSection));
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_CRITICAL_SECTION_HPP
