#!/bin/bash
source environment

cd qhttp
mkdir -p BUILD_DIR
cd ./BUILD_DIR
qmake "OBJECTS_DIR=BUILD_DIR" "DESTDIR=${BINDIR}" "DLLDESTDIR=${BINDIR}" -spec ${QMAKESPEC} CONFIG+=release -r ../qhttp.pro
make ${MAKEOPTS}
make ${MAKEOPTS} install
cd ..
rm -rf BUILD_DIR
if [ ! -d ${HEADERDIR}/QHttp ]; then mkdir -p "${HEADERDIR}/QHttp"; fi
cd src
ls -la
cp ./*.hpp "${HEADERDIR}/QHttp"
rm Makefile	
