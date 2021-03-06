/*
		This file has been auto-generated by WebbotLib tools V1.1
				** DO NOT MODIFY BY HAND **
*/
#define BUILDING_LIBRARY
#include "lib_iopins.h"
#include <avr/io.h>
// ----------- Define the used ports ------------
static const IOPort PROGMEM _PORTB={_SFR_MEM_ADDR(PORTB),_SFR_MEM_ADDR(DDRB),_SFR_MEM_ADDR(PINB)};
static const IOPort PROGMEM _PORTD={_SFR_MEM_ADDR(PORTD),_SFR_MEM_ADDR(DDRD),_SFR_MEM_ADDR(PIND)};

// ----------- Define the used pins ------------
const IOPin PROGMEM _B0 = { &_PORTB, BV(0)};
const IOPin PROGMEM _B1 = { &_PORTB, BV(1)};
const IOPin PROGMEM _B2 = { &_PORTB, BV(2)};
const IOPin PROGMEM _B3 = { &_PORTB, BV(3)};
const IOPin PROGMEM _B5 = { &_PORTB, BV(5)};
const IOPin PROGMEM _D0 = { &_PORTD, BV(0)};
const IOPin PROGMEM _D1 = { &_PORTD, BV(1)};
const IOPin PROGMEM _D3 = { &_PORTD, BV(3)};
const IOPin PROGMEM _D5 = { &_PORTD, BV(5)};
const IOPin PROGMEM _D6 = { &_PORTD, BV(6)};
const uint16_t PROGMEM AVcc_MV = 5000;
