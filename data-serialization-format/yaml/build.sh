#!/bin/sh
show_usage() {
	echo "Usage: ./build.sh [OPTION]"
    echo "  example)"
    echo "   source build.sh"
    echo "   source build.sh clean"
}

if [ "$#" -eq 0 ]; then
    echo "build"
    pushd ./
    mkdir -p build
    cd build
    cmake ..
    make
    make install
    popd

elif [ "$#" -eq 1 ]; then
    option=$1

    if [ "${option}" == "clean" ]; then
        echo "clean sample app"
        rm -rf ./build
    else
        show_usage
    fi
else
    show_usage
fi
