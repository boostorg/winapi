//  named_pipe_api.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_NAMED_PIPE_API_HPP_
#define BOOST_DETAIL_WINAPI_NAMED_PIPE_API_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/config.hpp>
#include <boost/detail/winapi/security.hpp>
#include <boost/detail/winapi/overlapped.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif


#if !defined( BOOST_USE_WINDOWS_H )
extern "C"
{

struct _SECURITY_ATTRIBUTES;

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI ImpersonateNamedPipeClient(
		boost::detail::winapi::HANDLE_ hNamedPipe);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI CreatePipe (
		boost::detail::winapi::HANDLE_* hReadPipe,
		boost::detail::winapi::HANDLE_* hWritePipe,
		_SECURITY_ATTRIBUTES* lpPipeAttributes,
		boost::detail::winapi::DWORD_ nSize);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI ConnectNamedPipe(
		boost::detail::winapi::HANDLE_ hNamedPipe,
		_OVERLAPPED* lpOverlapped);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI DisconnectNamedPipe (
		boost::detail::winapi::HANDLE_ hNamedPipe);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI SetNamedPipeHandleState (
		boost::detail::winapi::HANDLE_ hNamedPipe,
		boost::detail::winapi::DWORD_* lpMode,
		boost::detail::winapi::DWORD_* lpMaxCollectionCount,
		boost::detail::winapi::DWORD_* lpCollectDataTimeout);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI PeekNamedPipe(
		boost::detail::winapi::HANDLE_ hNamedPipe,
		boost::detail::winapi::LPVOID_ lpBuffer,
		boost::detail::winapi::DWORD_ nBufferSize,
		boost::detail::winapi::DWORD_* lpBytesRead,
		boost::detail::winapi::DWORD_* lpTotalBytesAvail,
		boost::detail::winapi::DWORD_* lpBytesLeftThisMessage);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_     WINAPI TransactNamedPipe(
		boost::detail::winapi::HANDLE_ hNamedPipe,
		boost::detail::winapi::LPVOID_ lpInBuffer,
		boost::detail::winapi::DWORD_ nInBufferSize,
		boost::detail::winapi::LPVOID_ lpOutBuffer,
		boost::detail::winapi::DWORD_ nOutBufferSize,
		boost::detail::winapi::DWORD_* lpBytesRead,
		_OVERLAPPED* lpOverlapped);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_  WINAPI CreateNamedPipeA(
		boost::detail::winapi::LPCSTR_ lpName,
		boost::detail::winapi::DWORD_ dwOpenMode,
		boost::detail::winapi::DWORD_ dwPipeMode,
		boost::detail::winapi::DWORD_ nMaxInstances,
		boost::detail::winapi::DWORD_ nOutBufferSize,
		boost::detail::winapi::DWORD_ nInBufferSize,
		boost::detail::winapi::DWORD_ nDefaultTimeOut,
		_SECURITY_ATTRIBUTES *lpSecurityAttributes);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ 	WINAPI WaitNamedPipeA(
		boost::detail::winapi::LPCSTR_ lpNamedPipeName,
		boost::detail::winapi::DWORD_ nTimeOut);

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_  WINAPI CreateNamedPipeW(
		boost::detail::winapi::LPCWSTR_ lpName,
		boost::detail::winapi::DWORD_ dwOpenMode,
		boost::detail::winapi::DWORD_ dwPipeMode,
		boost::detail::winapi::DWORD_ nMaxInstances,
		boost::detail::winapi::DWORD_ nOutBufferSize,
		boost::detail::winapi::DWORD_ nInBufferSize,
		boost::detail::winapi::DWORD_ nDefaultTimeOut,
		_SECURITY_ATTRIBUTES* lpSecurityAttributes);

BOOST_SYMBOL_IMPORT boost::detail::winapi::INT_ 	WINAPI WaitNamedPipeW(
		boost::detail::winapi::LPCWSTR_ lpNamedPipeName,
		boost::detail::winapi::DWORD_ nTimeOut);

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_  WINAPI GetNamedPipeClientComputerNameA(
		  boost::detail::winapi::HANDLE_ Pipe,
		  boost::detail::winapi::LPSTR_ ClientComputerName,
		  boost::detail::winapi::ULONG_ ClientComputerNameLength);
#endif // BOOST_NO_ANSI_APIS
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_  WINAPI GetNamedPipeClientComputerNameW(
		  boost::detail::winapi::HANDLE_ Pipe,
		  boost::detail::winapi::LPWSTR_ ClientComputerName,
		  boost::detail::winapi::ULONG_ ClientComputerNameLength);
#endif //BOOST_USE_WINAPI_VERSION
}
#endif //BOOST_USE_WINDOWS_H


namespace boost
{
namespace detail
{
namespace winapi
{

#if defined( BOOST_USE_WINDOWS_H )
using ::ImpersonateNamedPipeClient;
using ::CreatePipe;
using ::ConnectNamedPipe;
using ::DisconnectNamedPipe;
using ::SetNamedPipeHandleState;
using ::PeekNamedPipe;
using ::TransactNamedPipe;
using ::CreateNamedPipeW;
using ::WaitNamedPipeW;

#if !defined( BOOST_NO_ANSI_APIS )
using ::CreateNamedPipeA;
using ::WaitNamedPipeA;
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
#if !defined( BOOST_NO_ANSI_APIS )
using ::GetNamedPipeClientComputerNameA;
#endif
using ::GetNamedPipeClientComputerNameW;
#endif


#endif // BOOST_USE_WINDOWS_H


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_named_pipe(
		LPCSTR_ lpName,
		DWORD_ dwOpenMode,
		DWORD_ dwPipeMode,
		DWORD_ nMaxInstances,
		DWORD_ nOutBufferSize,
		DWORD_ nInBufferSize,
		DWORD_ nDefaultTimeOut,
		LPSECURITY_ATTRIBUTES_ lpSecurityAttributes)
{
	return CreateNamedPipeA(
			lpName,
			dwOpenMode,
			dwPipeMode,
			nMaxInstances,
			nOutBufferSize,
			nInBufferSize,
			nDefaultTimeOut,
			reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes));
}
#endif //BOOST_NO_ANSI_APIS

BOOST_FORCEINLINE HANDLE_ create_named_pipe(
		LPCWSTR_ lpName,
		DWORD_ dwOpenMode,
		DWORD_ dwPipeMode,
		DWORD_ nMaxInstances,
		DWORD_ nOutBufferSize,
		DWORD_ nInBufferSize,
		DWORD_ nDefaultTimeOut,
		LPSECURITY_ATTRIBUTES_ lpSecurityAttributes)
{
	return CreateNamedPipeW(
			lpName,
			dwOpenMode,
			dwPipeMode,
			nMaxInstances,
			nOutBufferSize,
			nInBufferSize,
			nDefaultTimeOut,
			reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes));
}

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE INT_ wait_named_pipe(LPCSTR_ lpNamedPipeName, DWORD_ nTimeOut)
{
	return WaitNamedPipeA(lpNamedPipeName, nTimeOut);
}
#endif //BOOST_NO_ANSI_APIS

BOOST_FORCEINLINE INT_ wait_named_pipe(LPCWSTR_ lpNamedPipeName, DWORD_ nTimeOut)
{
	return WaitNamedPipeW(lpNamedPipeName, nTimeOut);
}

#if (BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6) && !defined(GetNamedPipeClientComputerName)

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE INT_ get_named_pipe_client_computer_name(
		HANDLE_ Pipe,
		LPSTR_ ClientComputerName,
		ULONG_ ClientComputerNameLength)
{
	return GetNamedPipeClientComputerNameA(Pipe, ClientComputerName, ClientComputerNameLength);
}
#endif //BOOST_NO_ANSI_APIS

BOOST_FORCEINLINE INT_ get_named_pipe_client_computer_name(
		HANDLE_ Pipe,
		LPWSTR_ ClientComputerName,
		ULONG_ ClientComputerNameLength)
{
	return GetNamedPipeClientComputerNameW(Pipe, ClientComputerName, ClientComputerNameLength);
}
#endif //BOOST_USE_WINAPI_VERSION


BOOST_FORCEINLINE INT_     WINAPI connect_named_pipe(
        HANDLE_ hNamedPipe,
        OVERLAPPED_* lpOverlapped)
{
    return ::ConnectNamedPipe(hNamedPipe, reinterpret_cast<::_OVERLAPPED*>(lpOverlapped));
}


BOOST_FORCEINLINE INT_     WINAPI transact_named_pipe(
       HANDLE_  hNamedPipe,
       LPVOID_  lpInBuffer,
       DWORD_   nInBufferSize,
       LPVOID_  lpOutBuffer,
       DWORD_   nOutBufferSize,
       DWORD_*  lpBytesRead,
       OVERLAPPED_* lpOverlapped)
{
    return ::TransactNamedPipe(
        hNamedPipe,
        lpInBuffer,
        nInBufferSize,
        lpOutBuffer,
        nOutBufferSize,
        lpBytesRead,
        reinterpret_cast<::_OVERLAPPED*>(lpOverlapped));
}

}
}
}


#endif /* BOOST_DETAIL_WINAPI_NAMED_PIPE_API_HPP_ */
