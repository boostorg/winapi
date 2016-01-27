//  startf.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_STARTF_HPP_
#define BOOST_DETAIL_WINAPI_STARTF_HPP_

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/config.hpp>


namespace boost
{
namespace detail
{
namespace winapi
{

#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ STARTF_USESHOWWINDOW_ 		= STARTF_USESHOWWINDOW 	 ;
const DWORD_ STARTF_USESIZE_ 			= STARTF_USESIZE 		 ;
const DWORD_ STARTF_USEPOSITION_ 		= STARTF_USEPOSITION 	 ;
const DWORD_ STARTF_USECOUNTCHARS_ 		= STARTF_USECOUNTCHARS 	 ;
const DWORD_ STARTF_USEFILLATTRIBUTE_ 	= STARTF_USEFILLATTRIBUTE;
const DWORD_ STARTF_RUNFULLSCREEN_		= STARTF_RUNFULLSCREEN	 ;
const DWORD_ STARTF_FORCEONFEEDBACK_	= STARTF_FORCEONFEEDBACK ;
const DWORD_ STARTF_FORCEOFFFEEDBACK_ 	= STARTF_FORCEOFFFEEDBACK;
const DWORD_ STARTF_USESTDHANDLES_ 		= STARTF_USESTDHANDLES 	 ;
const DWORD_ STARTF_USEHOTKEY_ 			= STARTF_USEHOTKEY 		 ;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ STARTF_TITLEISLINKNAME_	= STARTF_TITLEISLINKNAME ;
const DWORD_ STARTF_TITLEISAPPID_ 		= STARTF_TITLEISAPPID 	 ;
const DWORD_ STARTF_PREVENTPINNING_		= STARTF_PREVENTPINNING	 ;
#endif

#else

const DWORD_ STARTF_USESHOWWINDOW_ 		= 0x00000001;
const DWORD_ STARTF_USESIZE_ 			= 0x00000002;
const DWORD_ STARTF_USEPOSITION_ 		= 0x00000004;
const DWORD_ STARTF_USECOUNTCHARS_ 		= 0x00000008;
const DWORD_ STARTF_USEFILLATTRIBUTE_ 	= 0x00000010;
const DWORD_ STARTF_RUNFULLSCREEN_		= 0x00000020;
const DWORD_ STARTF_FORCEONFEEDBACK_ 	= 0x00000040;
const DWORD_ STARTF_FORCEOFFFEEDBACK_ 	= 0x00000080;
const DWORD_ STARTF_USESTDHANDLES_ 		= 0x00000100;
const DWORD_ STARTF_USEHOTKEY_ 			= 0x00000200;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN7
const DWORD_ STARTF_TITLEISLINKNAME_ 	= 0x00000800;
const DWORD_ STARTF_TITLEISAPPID_ 		= 0x00001000;
const DWORD_ STARTF_PREVENTPINNING_		= 0x00002000;
#endif

#endif

}
}
}

//STARTF_USESTDHANDLES



#endif /* BOOST_DETAIL_WINAPI_STARTF_HPP_ */
