# Android NDK sensor example #

## Use C and NDK to access sensors without using Java.

## Prerequisites ##
* Android NDK - API-19
_ NDK comes with a C compiler and header files. If you want to compile the program for a different android API level(other than API 19), replace libandroid.so with the one of the API level you want to compile for.

## Getting started ##
### Setup environment ###
1. Go to the terminal.
2. export $PATH to your NDK bin folder(I assumed you already installed NDK.
3. eg. type : export PATH=/root/NDK/android-ndk-r19/bin:$PATH
4. Clone the repository
5. git clone  https://github.com/PromiseMasango/Android-NDK-sensor-example
6. Enter the Android-NDK-sensor-example folder and open terminal inside.
7. type *make* on the terminal to compile.
8. Use ADB to send the executable file to target device.
