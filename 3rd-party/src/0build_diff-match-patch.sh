#!/bin/bash
source environment

mkdir -p ${HEADERDIR}/LCS
cd ./diff-match-patch-cpp-stl
cp ./diff_match_patch.h "${HEADERDIR}/LCS"
