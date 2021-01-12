# Use, modification, and distribution are
# subject to the Boost Software License, Version 1.0. (See accompanying
# file LICENSE.txt)
#
# Copyright Rene Rivera 2020.

# For Drone CI we use the Starlark scripting language to reduce duplication.
# As the yaml syntax for Drone CI is rather limited.
#
#
globalenv={'B2_VARIANT': 'variant=release,debug'}
linuxglobalimage="cppalliance/droneubuntu1404:1"
windowsglobalimage="cppalliance/dronevs2019"

def main(ctx):
  return [
  linux_cxx("COMMENT=c++03 gcc-4.8 TOOLSET=gcc COMPILER= Job 0", "g++", packages="", buildtype="boost", image=linuxglobalimage, environment={'COMMENT': 'c++03 gcc-4.8', 'TOOLSET': 'gcc', 'COMPILER': 'g++', 'CXXSTD': 'c++03', 'DRONE_JOB_UUID': 'b6589fc6ab'}, globalenv=globalenv),
  ]

# from https://github.com/boostorg/boost-ci
load("@boost_ci//ci/drone/:functions.star", "linux_cxx","windows_cxx","osx_cxx","freebsd_cxx")
