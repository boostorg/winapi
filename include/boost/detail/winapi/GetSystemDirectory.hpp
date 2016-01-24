/*
 * GetSystemDirectory.hpp
 *
 *  Created on: 11.10.2015
 *      Author: Klemens
 */

#ifndef BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_
#define BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/tchar.hpp>

namespace boost
{
namespace detail
{
namespace winapi
{
extern "C" {

#if defined( BOOST_USE_WINDOWS_H )

using ::GetSystemDirectoryA;
using ::GetSystemDirectoryW;
#else

__declspec(dllimport) unsigned int WINAPI GetSystemDirectoryA (LPSTR_ lpBuffer,  unsigned int uSize);
__declspec(dllimport) unsigned int WINAPI GetSystemDirectoryW (LPWSTR_ lpBuffer, unsigned int uSize);


#if defined(UNICODE) && !defined(GetSystemDirectory)
inline unsigned int GetSystemDirectory (LPWSTR_ lpBuffer,  unsigned int uSize)
{
	return GetSystemDirectoryW(lpBuffer, uSize);
}


#elif !defined(GetSystemDirectory)
inline unsigned int GetSystemDirectory (LPSTR_ lpBuffer,  unsigned int uSize)
{
	return GetSystemDirectoryA(lpBuffer, uSize);
}

#endif
#endif
}

}

}
}





#endif /* BOOST_DETAIL_WINAPI_GETSYSTEMDIRECTORY_HPP_ */
