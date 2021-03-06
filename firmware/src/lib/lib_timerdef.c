/*
		This file has been auto-generated by WebbotLib tools V1.1
				** DO NOT MODIFY BY HAND **
*/
#define BUILDING_LIBRARY
#include <avr/io.h>
#include <libdefs.h>
#include "lib_timerdef.h"
#include "lib_iopins.h"

// Type of interrupt handler to use for timer interrupts.
// Do not change unless you know what you're doing.
#ifndef TIMER_INTERRUPT_HANDLER
#define TIMER_INTERRUPT_HANDLER	ISR
#endif
// ----------- Start Timer Definition -------------

// Define timer 0
static TimerData __timer0_data = MAKE_TIMER_DATA(0);
static TimerDataCompare __timer0CompareA_data = MAKE_TIMER_COMPARE_DATA();
static TimerDataCompare __timer0CompareB_data = MAKE_TIMER_COMPARE_DATA();
const TimerCompare PROGMEM __timer0Compare[] = {
	MAKE_TIMER_COMPARE(__timer0CompareA_data,0,TIMSK0,OCIE0A,OCR0A,TIFR0,OCF0A,TCCR0A,COM0A0,D6),
	MAKE_TIMER_COMPARE(__timer0CompareB_data,0,TIMSK0,OCIE0B,OCR0B,TIFR0,OCF0B,TCCR0A,COM0B0,D5)
};

// Define timer 1
static TimerData __timer1_data = MAKE_TIMER_DATA(0);
static TimerDataCompare __timer1CompareA_data = MAKE_TIMER_COMPARE_DATA();
static TimerDataCompare __timer1CompareB_data = MAKE_TIMER_COMPARE_DATA();
const TimerCompare PROGMEM __timer1Compare[] = {
	MAKE_TIMER_COMPARE(__timer1CompareA_data,1,TIMSK1,OCIE1A,OCR1A,TIFR1,OCF1A,TCCR1A,COM1A0,B1),
	MAKE_TIMER_COMPARE(__timer1CompareB_data,1,TIMSK1,OCIE1B,OCR1B,TIFR1,OCF1B,TCCR1A,COM1B0,B2)
};

// Define timer 2
static TimerData __timer2_data = MAKE_TIMER_DATA(0);
static TimerDataCompare __timer2CompareA_data = MAKE_TIMER_COMPARE_DATA();
static TimerDataCompare __timer2CompareB_data = MAKE_TIMER_COMPARE_DATA();
const TimerCompare PROGMEM __timer2Compare[] = {
	MAKE_TIMER_COMPARE(__timer2CompareA_data,2,TIMSK2,OCIE2A,OCR2A,TIFR2,OCF2A,TCCR2A,COM2A0,B3),
	MAKE_TIMER_COMPARE(__timer2CompareB_data,2,TIMSK2,OCIE2B,OCR2B,TIFR2,OCF2B,TCCR2A,COM2B0,D3)
};

// Create table of timers
const PROGMEM Timer PROGMEM pgm_Timers[] = {
	MAKE_TIMER(__timer0_data,TCNT0,TCCR0B,false,false,TIMER_3BIT_MODES,
		TCCR0A,WGM00,TCCR0A,WGM01,TCCR0B,WGM02,UNUSED_PORT,0,
		__timer0Compare,TIMSK0,TOIE0,TIFR0,TOV0,UNUSED_PORT,UNUSED_PORT,0,UNUSED_PORT,0,UNUSED_PORT,0,null),
	MAKE_TIMER(__timer1_data,TCNT1,TCCR1B,true,false,TIMER_ALL_MODES,
		TCCR1A,WGM10,TCCR1A,WGM11,TCCR1B,WGM12,TCCR1B,WGM13,
		__timer1Compare,TIMSK1,TOIE1,TIFR1,TOV1,ICR1,TIMSK1,ICIE1,TIFR1,ICF1,TCCR1B,ICES1,B0),
	MAKE_TIMER(__timer2_data,TCNT2,TCCR2B,false,true,TIMER_3BIT_MODES,
		TCCR2A,WGM20,TCCR2A,WGM21,TCCR2B,WGM22,UNUSED_PORT,0,
		__timer2Compare,TIMSK2,TOIE2,TIFR2,TOV2,UNUSED_PORT,UNUSED_PORT,0,UNUSED_PORT,0,UNUSED_PORT,0,null)
};
const uint8_t NUMBER_OF_TIMERS =  (sizeof(pgm_Timers)/sizeof(Timer));
// ----------- End Timer Definition -------------

