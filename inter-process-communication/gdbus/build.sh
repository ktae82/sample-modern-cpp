#!/bin/sh
show_usage() {
	echo "Usage: ./build.sh [OPTION]"
    echo "  example)"
    echo "   source build.sh"
    echo "   source build.sh clean"
}

if [ "$#" -eq 0 ]; then
    #server build
    echo "build server"
    pushd ./server
    mkdir -p build
    cd build
    cmake ..
    make
    popd

    #client build
    echo "build client"
    pushd ./client
    mkdir -p build
    cd build
    cmake ..
    make
    popd

elif [ "$#" -eq 1 ]; then
    option=$1

    if [ "${option}" == "clean" ]; then
        echo "clean sample app"
        rm -rf ./gdbus-gen/
        rm -rf ./server/build
        rm -rf ./client/build
    else
        show_usage
    fi
else
    show_usage
fi
