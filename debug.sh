#!/bin/sh

rm -rf build
mkdir build
cp dot_header.txt build/dot_header.txt
cp dot_footer.txt build/dot_footer.txt
cd build

g++ ../main.cpp
./a.out

dot -Tpng sample.dot > sample.png
open sample.png

cd ..
