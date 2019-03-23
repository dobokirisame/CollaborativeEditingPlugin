#!/bin/bash
source environment

mkdir -p ${PREFIX}
cd ./googletest
mkdir -p BUILD_DIR
cd BUILD_DIR

if [[ $PLATFORM == 'linux' || $PLATFORM == 'macx' || $PLATFORM == 'arm-linux-androideabi' ]]; then
	GENERATOR='Unix Makefiles'
elif [[ $PLATFORM == 'mingw' ]]; then
	#GENERATOR='MinGW Makefiles'
	GENERATOR='MSYS Makefiles'
fi
echo "Platform is ${PLATFORM}. Will use generator ${GENERATOR}"

# Beacuase i could not fix gtest build failure i'll use this workaround
if [[ $PLATFORM == 'mingw' ]]; then
	rm -fr BUILD_DIR
	if [ ! -d ${DESTDIR} ]; then mkdir -p "${DESTDIR}"; fi
	if [ ! -d ${HEADERDIR} ]; then mkdir -p "${HEADERDIR}"; fi
	cd ../googletest/make
	make
	cp ./*.a ${DESTDIR}
	cp -r ../include/gtest ${HEADERDIR}
	make clean
	cd ../../googlemock/make
	make
	cp ./*.a ${DESTDIR}
	cp -r ../include/gmock ${HEADERDIR}
	make clean
	exit 0
fi

cmake .. -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
      -G "$GENERATOR" \
      -DBUILD_GTEST=ON \
      -DCMAKE_CXX_STANDARD=11 \
      -DBUILD_SHARED_LIBS=ON \
#      -Dgtest_build_tests=ON \
#      -Dgmock_build_tests=ON  \
#      -Dgtest_disable_pthreads=ON


make ${MAKEOPTS}
make install
cd ..
rm -fr BUILD_DIR
  