#!/usr/bin/env sh
rm -rf build
mkdir build
cmake -H. -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_CXX_INCLUDE_WHAT_YOU_USE=iwyu -DCMAKE_CXX_COMPILER=clang++ -GNinja
