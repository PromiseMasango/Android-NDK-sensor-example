all:
	arm-linux-androideabi-gcc sensor.c -o sensor -w libandroid.so
send:
	adb push sensor /data/local/tmp/
