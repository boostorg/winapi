cmake_minimum_required(VERSION 3.5)

include(cmake/BoostVersion.cmake)
set(BOOST_PROJECT_NAME winapi)

project(boost_${BOOST_PROJECT_NAME} VERSION ${BOOST_VERSION} LANGUAGES CXX)

include(cmake/default.cmake)
