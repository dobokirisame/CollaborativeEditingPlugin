#!/bin/bash
source environment

mkdir -p ${PREFIX}
cd ./googletest
mkdir -p BUILD_DIR
cd BUILD_DIR

if [[ $PLATFORM == 'linux' || $PLATFORM == 'macx' || $PLATFORM == 'arm-linux-androideabi' ]]; then
	GENERATOR='Unix Makefiles'
elif [[ $PLATFORM == 'mingw' ]]; then
	GENERATOR='MSYS Makefiles'
fi

cmake -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
      -G "$GENERATOR" \
      -DBUILD_GTEST=ON \
      -DBUILD_SHARED_LIBS=ON \
      -Dgtest_build_tests=ON \
      -Dgmock_build_tests=ON  ..
      #\ -Dgtest_disable_pthreads=ON

make ${MAKEOPTS}
make install
cd ..
rm -fr BUILD_DIR
  