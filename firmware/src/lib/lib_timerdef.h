/*
		This file has been auto-generated by WebbotLib tools V1.1
				** DO NOT MODIFY BY HAND **
*/
#ifndef LIB_TIMERDEF_H
#define LIB_TIMERDEF_H
#include <libdefs.h>
#ifdef __cplusplus
extern "C" {
#endif
// ----------- Start Timer Definition -------------

// Define timer 0
extern const TimerCompare PROGMEM __timer0Compare[];
#define TIMER0_COMPAREA &__timer0Compare[0]
#define TIMER0_COMPAREB &__timer0Compare[1]

// Define timer 1
extern const TimerCompare PROGMEM __timer1Compare[];
#define TIMER1_COMPAREA &__timer1Compare[0]
#define TIMER1_COMPAREB &__timer1Compare[1]

// Define timer 2
extern const TimerCompare PROGMEM __timer2Compare[];
#define TIMER2_COMPAREA &__timer2Compare[0]
#define TIMER2_COMPAREB &__timer2Compare[1]

// Create table of timers
extern const PROGMEM Timer PROGMEM pgm_Timers[];
extern const uint8_t NUMBER_OF_TIMERS;
#define TIMER0 &pgm_Timers[0]
#define TIMER1 &pgm_Timers[1]
#define TIMER2 &pgm_Timers[2]
// ----------- End Timer Definition -------------

#ifdef __cplusplus
}
#endif
#endif
