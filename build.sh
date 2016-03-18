#!/bin/bash
#Build environment
echo "Building Sources"
cd src
make clean
make
cd ..
echo "Building App"
cd test
make clean
make
cd ..
