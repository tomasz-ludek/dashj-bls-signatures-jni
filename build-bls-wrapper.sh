#! /bin/sh
rm -r build
mkdir build
cd build
cmake ../
cmake --build . -- -j 6
cd ..
java -cp src/java -Djava.library.path=/mnt/c/dev/bls/playground/build/ org.dash.bls.DashBlsJni