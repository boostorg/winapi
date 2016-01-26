//  process_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt



#ifndef BOOST_DETAIL_PROCESS_API_HPP_
#define BOOST_DETAIL_PROCESS_API_HPP_

#include <boost/detail/winapi/config.hpp>
#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/security.hpp>
#include <boost/detail/winapi/process_info.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

extern "C" {

#if !defined( BOOST_USE_WINDOWS_H )
BOOST_SYMBOL_IMPORT BOOST_NORETURN void WINAPI
ExitProcess(
   boost::detail::winapi::UINT_ uExitCode);


BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI TerminateProcess(
    boost::detail::winapi::HANDLE_ hProcess,
    boost::detail::winapi::UINT_ uExitCode);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI GetExitCodeProcess(
    boost::detail::winapi::HANDLE_ hProcess,
    boost::detail::winapi::DWORD_* lpExitCode);


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI CreateProcessA(
    boost::detail::winapi::LPCSTR_ lpApplicationName,
    boost::detail::winapi::LPSTR_ lpCommandLine,
                         ::_SECURITY_ATTRIBUTES* lpProcessAttributes,
                         ::_SECURITY_ATTRIBUTES* lpThreadAttributes,
	boost::detail::winapi::INT_ bInheritHandles,
    boost::detail::winapi::DWORD_ dwCreationFlags,
    boost::detail::winapi::LPVOID_ lpEnvironment,
    boost::detail::winapi::LPCSTR_ lpCurrentDirectory,
                         ::_STARTUPINFOA* lpStartupInfo,
                         ::_PROCESS_INFORMATION* lpProcessInformation);


#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ WINAPI CreateProcessW(
    boost::detail::winapi::LPCWSTR_ lpApplicationName,
    boost::detail::winapi::LPWSTR_ lpCommandLine,
                         ::_SECURITY_ATTRIBUTES* lpProcessAttributes,
                         ::_SECURITY_ATTRIBUTES* lpThreadAttributes,
    boost::detail::winapi::INT_ bInheritHandles,
    boost::detail::winapi::DWORD_ dwCreationFlags,
    boost::detail::winapi::LPVOID_ lpEnvironment,
    boost::detail::winapi::LPCWSTR_ lpCurrentDirectory,
                         ::_STARTUPINFOW* lpStartupInfo,
                         ::_PROCESS_INFORMATION* lpProcessInformation);

#endif //defined BOOST_WINDOWS_H
}


namespace boost
{
namespace detail
{
namespace winapi
{

//|| defined( CreateProcess )
using ::GetExitCodeProcess;
using ::ExitProcess;
using ::TerminateProcess;
using ::CreateProcessA;
using ::CreateProcessW;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE static INT_ create_process (
		LPCSTR_ lpApplicationName,
		LPSTR_ lpCommandLine,
		LPSECURITY_ATTRIBUTES_ lpProcessAttributes,
		LPSECURITY_ATTRIBUTES_ lpThreadAttributes,
		INT_ bInheritHandles, DWORD_ dwCreationFlags,
		LPVOID_ lpEnvironment,
		LPCSTR_ lpCurrentDirectory,
		STARTUPINFOA_* lpStartupInfo,
		PROCESS_INFORMATION_* lpProcessInformation)
{
	return CreateProcessA (lpApplicationName,
                           lpCommandLine,
                           reinterpret_cast<::_SECURITY_ATTRIBUTES*>(lpProcessAttributes),
                           reinterpret_cast<::_SECURITY_ATTRIBUTES*>(lpThreadAttributes),
                           bInheritHandles,
                           dwCreationFlags,
                           lpEnvironment,
                           lpCurrentDirectory,
						   reinterpret_cast<::_STARTUPINFOA*>(lpStartupInfo),
						   reinterpret_cast<::_PROCESS_INFORMATION*>(lpProcessInformation));
}
#endif

BOOST_FORCEINLINE static INT_ create_process (
		LPCWSTR_ lpApplicationName,
		LPWSTR_ lpCommandLine,
		LPSECURITY_ATTRIBUTES_ lpProcessAttributes,
		LPSECURITY_ATTRIBUTES_ lpThreadAttributes,
		INT_ bInheritHandles,
		DWORD_ dwCreationFlags,
		LPVOID_ lpEnvironment,
		LPCWSTR_ lpCurrentDirectory,
		STARTUPINFOW_* lpStartupInfo,
		PROCESS_INFORMATION_* lpProcessInformation)
{
	return CreateProcessW (lpApplicationName,
                           lpCommandLine,
                           reinterpret_cast<::_SECURITY_ATTRIBUTES*>(lpProcessAttributes),
                           reinterpret_cast<::_SECURITY_ATTRIBUTES*>(lpThreadAttributes),
                           bInheritHandles,
                           dwCreationFlags,
                           lpEnvironment,
                           lpCurrentDirectory,
						   reinterpret_cast<::_STARTUPINFOW*>(lpStartupInfo),
						   reinterpret_cast<::_PROCESS_INFORMATION*>(lpProcessInformation));
}


}
}
}



#endif /* BOOST_DETAIL_HANDLE_API_HPP_ */
