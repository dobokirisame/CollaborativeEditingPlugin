#!/bin/bash
source environment

cd qhttp
qmake "OBJECTS_DIR=BUILD_DIR" "DESTDIR=${DESTDIR}" "DLLDESTDIR=${BINDIR}" -spec ${QMAKESPEC} CONFIG+=release -r qhttp.pro
mkdir -p BUILD_DIR
make ${MAKEOPTS}
rm -rf BUILD_DIR
if [ ! -d ${HEADERDIR} ]; then mkdir "${HEADERDIR}"; fi
cp -r src/*.hpp "${HEADERDIR}"
rm Makefile	
