#!/bin/bash

if [ "$DRONE_JOB_UUID" = "b6589fc6ab" ] ; then
    if [[ "$COVERALL" -ne "1" ]]; then exit 0; fi
    wget https://github.com/linux-test-project/lcov/archive/v1.13.zip
    unzip v1.13.zip
    LCOV="`pwd`/lcov-1.13/bin/lcov --gcov-tool gcov-6"
    mkdir -p $TRAVIS_BUILD_DIR/coverals
    $LCOV --directory bin.v2/libs/$SELF --base-directory libs/$SELF --capture --output-file $TRAVIS_BUILD_DIR/coverals/coverage.info --no-external
    $LCOV --remove $TRAVIS_BUILD_DIR/coverals/coverage.info "*/$SELF/test/*" --output-file $TRAVIS_BUILD_DIR/coverals/coverage-filtered.info
    cd $TRAVIS_BUILD_DIR
    gem install coveralls-lcov || echo "ERROR. Failed to install coveralls-lcov"
    coveralls-lcov coverals/coverage-filtered.info
fi

