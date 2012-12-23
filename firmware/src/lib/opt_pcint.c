#define BUILDING_LIBRARY
#include "lib_iopins.h"
#include <pinChange.h>
const uint8_t NUM_PCINT_PINS = 23;
const IOPin* PROGMEM const PCINT_PINS[]={B0,B1,B2,B3,null,B5,null,null,null,null,null,null,null,null,null,null,D0,D1,null,D3,null,D5,D6};
PIN_CHANGE pcCallbacks[23];
