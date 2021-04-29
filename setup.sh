#!/bin/bash

apt-get install -y uuid-dev brotli cmake build-essential libc-ares-dev libjsoncpp-dev zlib
cd ..
wget https://github.com/an-tao/drogon/archive/refs/tags/v1.5.1.zip
unzip v1.5.1.zip
mv drogon-1.5.1 drogon
rm v1.5.1.zip
cd drogon
rm -r trantor
wget https://github.com/an-tao/trantor/archive/refs/tags/v1.4.0.zip
unzip v1.4.0.zip
mv trantor-1.4.0 trantor
rm v1.4.0.zip
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
make install -j8
