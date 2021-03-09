#!/usr/bin/env bash

#Update the submodule and initialize
git submodule update --init

make_program=make
make_flags=''
cmake_gen=''
cmake_flags=''
make_flags="$make_flags"

if [ ! -d "./build" ] 
then
    mkdir build
fi

cd build
cmake $cmake_flags .. $cmake_gen

if [ $? -ne 0 ]; then
    echo "Error in testing"
    exit -1
fi

$make_program $make_flags

if [ $? -ne 0 ]; then
    echo "Error in testing"
    exit -1
fi

if [ "$1" = "-t" ]; then
    #unit testing
    echo "Unit testing"
    $make_program $make_flags test
    if [ $? -ne 0 ]; then
        echo "Error in unit testing"
        exit -1
    fi
fi

echo "Everything is ok!"
exit 0
