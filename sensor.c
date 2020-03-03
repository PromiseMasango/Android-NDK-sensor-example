#include <stdio.h>
#include <android/looper.h>
#include <android/sensor.h>

int main(int argv, char *argc[] ){
	/*create a sensor manager*/
	ASensorManager *sensorManager = ASensorManager_getInstance();

	/*get list of all sensors in the device*/
	ASensorList sensorList;
	int numSensors = ASensorManager_getSensorList(sensorManager, &sensorList);

	for( int count = 0 ; count < numSensors ; count++ ){
		printf("************Sensors Available********************\n");
		printf("Name :%s\n", ASensor_getName(sensorList[count]));
		printf("Vendor :%s\n", ASensor_getVendor(sensorList[count]));
		printf("Type :%s\n", ASensor_getStringType(sensorList[count]));
	}
	
	/*pause for few seconds. visually inspect available sensors*/
	sleep(2);


	int looperId = 1;
	ASensorEventQueue* eventQueue = ASensorManager_createEventQueue(sensorManager, ALooper_prepare(ALOOPER_PREPARE_ALLOW_NON_CALLBACKS), looperId, NULL, NULL );
	if ( eventQueue == NULL ){
		printf("error, cannot create event queue\n");
		return -1;
	}

	/*turn on all available sensors*/
	for( int count = 0 ; count < numSensors ; count++ ){
		if( ASensorEventQueue_enableSensor( eventQueue, sensorList[count]) != 0 )
			printf("error, cannot enable sensor %s\n", ASensor_getName(sensorList[count]));
	}

	/*get events from sensors*/
	int numEvents = 1; //number of events to read before returning
	int kTimeoutMilliSecs = 10000; //wait for milliseconds before returning
	ASensorEvent events;
	int identity = 0;

	for( int count = 0 ; count < 50 ; count++ ){
		memset( &events, 0, sizeof(events));

		/*poll for events*/
		identity = ALooper_pollAll( kTimeoutMilliSecs, NULL, NULL, NULL );
		/* if timeout */
		if (identity != looperId)
			continue;

		/*retrieve events*/
		if ( ASensorEventQueue_getEvents( eventQueue, &events, 1) < 1 )
			continue; // no pending event

		if( events.type = ASENSOR_TYPE_ACCELEROMETER ){
			printf("%s[Accelerometer] x = %f  y = %f  z = %f\n","\x1B[32m", events.acceleration.x, events.acceleration.y, events.acceleration.z );
		}
		sleep(1);


		if ( events.type = ASENSOR_TYPE_PROXIMITY ){
			printf("%s[proximity sensor] distance :%f\n","\x1B[33m", events.distance );
		}

	}


	/*turn off all available sensors*/
	for( int count = 0 ; count < numSensors ; count++ ){
		if( ASensorEventQueue_disableSensor( eventQueue, sensorList[count]) != 0 ){
			printf("error, cannot disable sensor %s\n", ASensor_getName(sensorList[count]));
		}
	}

	/* free resources */
	ASensorManager_destroyEventQueue( sensorManager, eventQueue );

	return 0;
}
