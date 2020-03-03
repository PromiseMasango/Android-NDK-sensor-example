# Android NDK sensor example #

## Use C and NDK to access sensors without using Java.

## Prerequisites ##
* Android NDK - API-19
_ NDK comes with a C compiler and header files. If you want to compile the program for a different android API level(other than API 19), replace libandroid.so with the one of the API level you want to compile for _

## Getting started ##
1. Setup environment
* Go to the terminal.
* export $PATH to your NDK bin folder(I assumed you already installed NDK.
* eg. type : export PATH=/root/NDK/android-ndk-r19/bin:$PATH
1. Clone the repository
* git clone  https://github.com/PromiseMasango/Android-NDK-sensor-example
* Enter the Android-NDK-sensor-example folder and open terminal
* type make on the terminal to compile.
