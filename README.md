# dashj-bls-signatures-jni

DashJ JNI Wrapper for [bls-signatures](https://github.com/Chia-Network/bls-signatures)

## Prerequisites

Instead of Cygwin I decided to use more convinient [Windows Subsystem For Linux](https://docs.microsoft.com/pl-pl/windows/wsl/about) which is an integral part of Windows 10. The same approach was adopted in Dash Core, as you can see here: https://github.com/dashevo/dash/blob/evo/doc/build-windows.md

My environment configuration is mostly the same as for Dash Core building.

## Getting Started
```bash
git clone git@github.com:tomasz-ludek/dashj-bls-signatures-jni.git
cd dashj-bls-signatures-jni/

./build-bls-signatures.sh
./build-bls-wrapper.sh
```
## Launch the sample java code:
```bash
java -cp src/java -Djava.library.path=build/ org.dash.bls.DashBlsJni
```
It should print the following message:
```
Fingerprint (native):           1495849596
Fingerprint (native/java):      1495849596
Fingerprint (java):             1495849596
```
This simple example illustrates how we can implement two-way communication between our Java code and bls-signatures lib
