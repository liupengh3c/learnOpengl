#!/bin/sh
rm -rf CM*
rm -rf cmake_install.cmake
rm Makefile
cp -r ../shader/* ./shader/
cmake ..
make clean
make
