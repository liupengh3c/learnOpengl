#!/bin/sh
rm -rf CM*
rm -rf cmake_install.cmake
rm Makefile
cp -r ../shader/src/* ./shader/src/
cmake ..
make clean
make
