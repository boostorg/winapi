//  error_codes.hpp  --------------------------------------------------------------//

//  Copyright 2016 Klemens D. Morgenstern

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DETAIL_WINAPI_ERROR_CODES_HPP_
#define BOOST_DETAIL_WINAPI_ERROR_CODES_HPP_

#include <boost/detail/winapi/basic_types.hpp>

namespace boost {
namespace detail {
namespace winapi {


#if defined( BOOST_USE_WINDOWS_H )

const DWORD_ ERROR_SUCCESS_                           = ERROR_SUCCESS             ;
const DWORD_ ERROR_INVALID_FUNCTION_                  = ERROR_INVALID_FUNCTION    ;
const DWORD_ ERROR_FILE_NOT_FOUND_                    = ERROR_FILE_NOT_FOUND      ;
const DWORD_ ERROR_PATH_NOT_FOUND_                    = ERROR_PATH_NOT_FOUND      ;
const DWORD_ ERROR_TOO_MANY_OPEN_FILES_               = ERROR_TOO_MANY_OPEN_FILES ;
const DWORD_ ERROR_ACCESS_DENIED_                     = ERROR_ACCESS_DENIED       ;
const DWORD_ ERROR_INVALID_HANDLE_                    = ERROR_INVALID_HANDLE      ;
const DWORD_ ERROR_ARENA_TRASHED_                     = ERROR_ARENA_TRASHED       ;
const DWORD_ ERROR_NOT_ENOUGH_MEMORY_                 = ERROR_NOT_ENOUGH_MEMORY   ;
const DWORD_ ERROR_INVALID_BLOCK_                     = ERROR_INVALID_BLOCK       ;
const DWORD_ ERROR_BAD_ENVIRONMENT_                   = ERROR_BAD_ENVIRONMENT     ;
const DWORD_ ERROR_BAD_FORMAT_                        = ERROR_BAD_FORMAT          ;
const DWORD_ ERROR_INVALID_ACCESS_                    = ERROR_INVALID_ACCESS      ;
const DWORD_ ERROR_INVALID_DATA_                      = ERROR_INVALID_DATA        ;
const DWORD_ ERROR_OUTOFMEMORY_                       = ERROR_OUTOFMEMORY         ;

const DWORD_ ERROR_BROKEN_PIPE_                       = ERROR_BROKEN_PIPE         ;

const DWORD_ ERROR_ENVVAR_NOT_FOUND_                  = ERROR_ENVVAR_NOT_FOUND    ;

#else

const DWORD_ ERROR_SUCCESS_                           = 0x0;
const DWORD_ ERROR_INVALID_FUNCTION_                  = 0x1;
const DWORD_ ERROR_FILE_NOT_FOUND_                    = 0x2;
const DWORD_ ERROR_PATH_NOT_FOUND_                    = 0x3;
const DWORD_ ERROR_TOO_MANY_OPEN_FILES_               = 0x4;
const DWORD_ ERROR_ACCESS_DENIED_                     = 0x5;
const DWORD_ ERROR_INVALID_HANDLE_                    = 0x6;
const DWORD_ ERROR_ARENA_TRASHED_                     = 0x7;
const DWORD_ ERROR_NOT_ENOUGH_MEMORY_                 = 0x8;
const DWORD_ ERROR_INVALID_BLOCK_                     = 0x9;
const DWORD_ ERROR_BAD_ENVIRONMENT_                   = 0xA;
const DWORD_ ERROR_BAD_FORMAT_                        = 0xB;
const DWORD_ ERROR_INVALID_ACCESS_                    = 0xC;
const DWORD_ ERROR_INVALID_DATA_                      = 0xD;
const DWORD_ ERROR_OUTOFMEMORY_                       = 0xE;

const DWORD_ ERROR_BROKEN_PIPE_                       = 0x6D;

const DWORD_ ERROR_ENVVAR_NOT_FOUND_                  = 0xCB;

#endif

}
}
}



#endif /* BOOST_DETAIL_WINAPI_ERROR_CODES_HPP_ */
