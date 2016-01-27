//  environment.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_ENVIRONMENT_HPP_
#define BOOST_DETAIL_WINAPI_ENVIRONMENT_HPP_

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost
{
namespace detail
{
namespace winapi
{

#if defined(BOOST_USE_WINDOWS_H)

const DWORD_ DEBUG_PROCESS_                    = DEBUG_PROCESS                   ;
const DWORD_ DEBUG_ONLY_THIS_PROCESS_          = DEBUG_ONLY_THIS_PROCESS         ;
const DWORD_ CREATE_SUSPENDED_                 = CREATE_SUSPENDED                ;
const DWORD_ DETACHED_PROCESS_                 = DETACHED_PROCESS                ;
const DWORD_ CREATE_NEW_CONSOLE_               = CREATE_NEW_CONSOLE              ;
const DWORD_ NORMAL_PRIORITY_CLASS_            = NORMAL_PRIORITY_CLASS           ;
const DWORD_ IDLE_PRIORITY_CLASS_              = IDLE_PRIORITY_CLASS             ;
const DWORD_ HIGH_PRIORITY_CLASS_              = HIGH_PRIORITY_CLASS             ;
const DWORD_ REALTIME_PRIORITY_CLASS_          = REALTIME_PRIORITY_CLASS         ;
const DWORD_ CREATE_NEW_PROCESS_GROUP_         = CREATE_NEW_PROCESS_GROUP        ;
const DWORD_ CREATE_UNICODE_ENVIRONMENT_       = CREATE_UNICODE_ENVIRONMENT      ;
const DWORD_ CREATE_SEPARATE_WOW_VDM_          = CREATE_SEPARATE_WOW_VDM         ;
const DWORD_ CREATE_SHARED_WOW_VDM_            = CREATE_SHARED_WOW_VDM           ;
const DWORD_ CREATE_FORCEDOS_                  = CREATE_FORCEDOS                 ;
const DWORD_ BELOW_NORMAL_PRIORITY_CLASS_      = BELOW_NORMAL_PRIORITY_CLASS     ;
const DWORD_ ABOVE_NORMAL_PRIORITY_CLASS_      = ABOVE_NORMAL_PRIORITY_CLASS     ;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ INHERIT_PARENT_AFFINITY_          = INHERIT_PARENT_AFFINITY         ;// Since Win 7
const DWORD_ INHERIT_CALLER_PRIORITY_          = INHERIT_CALLER_PRIORITY         ;// Windows CE
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
const DWORD_ CREATE_PROTECTED_PROCESS_         = CREATE_PROTECTED_PROCESS        ;// Since Windows Vista
const DWORD_ EXTENDED_STARTUPINFO_PRESENT_     = EXTENDED_STARTUPINFO_PRESENT    ;// Since Windows Vista
const DWORD_ PROCESS_MODE_BACKGROUND_BEGIN_    = PROCESS_MODE_BACKGROUND_BEGIN   ;// Since Windows Vista
const DWORD_ PROCESS_MODE_BACKGROUND_END_      = PROCESS_MODE_BACKGROUND_END     ;// Since Windows Vista
#endif
const DWORD_ CREATE_BREAKAWAY_FROM_JOB_        = CREATE_BREAKAWAY_FROM_JOB       ;
const DWORD_ CREATE_PRESERVE_CODE_AUTHZ_LEVEL_ = CREATE_PRESERVE_CODE_AUTHZ_LEVEL;
const DWORD_ CREATE_DEFAULT_ERROR_MODE_        = CREATE_DEFAULT_ERROR_MODE       ;
const DWORD_ CREATE_NO_WINDOW_                 = CREATE_NO_WINDOW                ;
const DWORD_ PROFILE_USER_                     = PROFILE_USER                    ;
const DWORD_ PROFILE_KERNEL_                   = PROFILE_KERNEL                  ;
const DWORD_ PROFILE_SERVER_                   = PROFILE_SERVER                  ;
const DWORD_ CREATE_IGNORE_SYSTEM_DEFAULT_     = CREATE_IGNORE_SYSTEM_DEFAULT    ;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ DEBUG_PROCESS_                    = 0x1        ;
const DWORD_ DEBUG_ONLY_THIS_PROCESS_          = 0x2        ;
const DWORD_ CREATE_SUSPENDED_                 = 0x4        ;
const DWORD_ DETACHED_PROCESS_                 = 0x8        ;
const DWORD_ CREATE_NEW_CONSOLE_               = 0x10       ;
const DWORD_ NORMAL_PRIORITY_CLASS_            = 0x20       ;
const DWORD_ IDLE_PRIORITY_CLASS_              = 0x40       ;
const DWORD_ HIGH_PRIORITY_CLASS_              = 0x80       ;
const DWORD_ REALTIME_PRIORITY_CLASS_          = 0x100      ;
const DWORD_ CREATE_NEW_PROCESS_GROUP_         = 0x200      ;
const DWORD_ CREATE_UNICODE_ENVIRONMENT_       = 0x400      ;
const DWORD_ CREATE_SEPARATE_WOW_VDM_          = 0x800      ;
const DWORD_ CREATE_SHARED_WOW_VDM_            = 0x1000     ;
const DWORD_ CREATE_FORCEDOS_                  = 0x2000     ;
const DWORD_ BELOW_NORMAL_PRIORITY_CLASS_      = 0x4000     ;
const DWORD_ ABOVE_NORMAL_PRIORITY_CLASS_      = 0x8000     ;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ INHERIT_PARENT_AFFINITY_          = 0x10000    ;
const DWORD_ INHERIT_CALLER_PRIORITY_          = 0x20000    ;
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
const DWORD_ CREATE_PROTECTED_PROCESS_         = 0x40000    ;
const DWORD_ EXTENDED_STARTUPINFO_PRESENT_     = 0x80000    ;
const DWORD_ PROCESS_MODE_BACKGROUND_BEGIN_    = 0x100000   ;
const DWORD_ PROCESS_MODE_BACKGROUND_END_      = 0x200000   ;
#endif

const DWORD_ CREATE_BREAKAWAY_FROM_JOB_        = 0x1000000  ;
const DWORD_ CREATE_PRESERVE_CODE_AUTHZ_LEVEL_ = 0x2000000  ;
const DWORD_ CREATE_DEFAULT_ERROR_MODE_        = 0x4000000  ;
const DWORD_ CREATE_NO_WINDOW_                 = 0x8000000  ;
const DWORD_ PROFILE_USER_                     = 0x10000000 ;
const DWORD_ PROFILE_KERNEL_                   = 0x20000000 ;
const DWORD_ PROFILE_SERVER_                   = 0x40000000 ;
const DWORD_ CREATE_IGNORE_SYSTEM_DEFAULT_     = 0x80000000 ;


#endif // defined( BOOST_USE_WINDOWS_H )


}

}
}


#endif /* BOOST_DETAIL_WINAPI_ENVIRONMENT_HPP_ */
