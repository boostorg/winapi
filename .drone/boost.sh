#!/bin/bash

set -ex
export TRAVIS_BUILD_DIR=$(pwd)
export DRONE_BUILD_DIR=$(pwd)
export TRAVIS_BRANCH=$DRONE_BRANCH
export VCS_COMMIT_ID=$DRONE_COMMIT
export GIT_COMMIT=$DRONE_COMMIT
export REPO_NAME=$DRONE_REPO
export PATH=~/.local/bin:/usr/local/bin:$PATH

echo '==================================> BEFORE_INSTALL'

. .drone/before-install.sh

echo '==================================> INSTALL'

GIT_FETCH_JOBS=8
export SELF=`basename $TRAVIS_BUILD_DIR`
cd ..
git clone -b $TRAVIS_BRANCH --depth 1 https://github.com/boostorg/boost.git boost-root
cd boost-root
git submodule init tools/boostdep
git submodule init tools/build
git submodule init tools/boost_install
git submodule init libs/headers
git submodule init libs/config
git submodule update --jobs $GIT_FETCH_JOBS
cp -r $TRAVIS_BUILD_DIR/* libs/$SELF
export BOOST_ROOT="`pwd`"
export PATH="`pwd`":$PATH
python tools/boostdep/depinst/depinst.py --git_args "--jobs $GIT_FETCH_JOBS" $SELF
./bootstrap.sh
./b2 headers

echo '==================================> BEFORE_SCRIPT'

. $DRONE_BUILD_DIR/.drone/before-script.sh

echo '==================================> SCRIPT'

export COMPILER_VERSION=`$COMPILER --version`
BUILD_JOBS=`(nproc || sysctl -n hw.ncpu) 2> /dev/null`
echo "using $TOOLSET : : $COMPILER : <cxxflags>-std=$CXXSTD ;" > ~/user-config.jam
echo "[**] COMPILER: $COMPILER_VERSION [**]"
echo "./b2 -j $BUILD_JOBS libs/$SELF/test toolset=$TOOLSET $B2_ADDRESS_MODEL $B2_LINK $B2_THREADING $B2_VARIANT"
./b2 -j $BUILD_JOBS libs/$SELF/test toolset=$TOOLSET $B2_ADDRESS_MODEL $B2_LINK $B2_THREADING $B2_VARIANT

echo '==================================> AFTER_SUCCESS'

. $DRONE_BUILD_DIR/.drone/after-success.sh
