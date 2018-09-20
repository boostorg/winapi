# Copyright 2018 Mike Dev
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5)
project(BoostWinapi LANGUAGES CXX)

add_library(boost_winapi INTERFACE)
add_library(Boost::winapi ALIAS boost_winapi)

target_include_directories(boost_winapi INTERFACE include)

target_link_libraries(boost_winapi
    INTERFACE
        Boost::config
        Boost::predef
)
