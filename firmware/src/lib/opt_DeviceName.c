#include "../hardware.h"
static const char PROGMEM name_led[] = "led";
static const char PROGMEM name_myUart[] = "myUart";
static const char PROGMEM name_speech[] = "speech";
static const char PROGMEM unknown[] = "?";

#define NUM_DEVICES 3
static const void* PROGMEM const tbl[]={
	&led, name_led,
	&_myUart, name_myUart,
	speech, name_speech
	};

const char* getDeviceName(const void* device){
	const char* rtn = unknown;
	for(int i=0 ; i<NUM_DEVICES*2; i+=2){
		const void* addr = (const void*)pgm_read_word(&tbl[i]);
		if( addr == device){
			rtn = (const void*)pgm_read_word(&tbl[i+1]);
		}
	}
	return rtn;
}
