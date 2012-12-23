#include "lib_timerdef.h"
#include <timer.h>
#include <errors.h>
// Variable used by main library to link in this module
const uint8_t PROGMEM _timer_overflow_error = TIMER_OVERFLOW_CALLBACK_EXISTS;
// The dummy routine used to denote that the overflow is in use
// Only ever called from here but not static to avoid unused warnings
void nullTimerOverflowCallback(const Timer *timer, void* data){}
// Interrupt handler for timer 0 overflow interrupt
ISR(TIMER0_OVF_vect){
	__timer_overflowService(TIMER0);
}// Interrupt handler for timer 1 overflow interrupt
ISR(TIMER1_OVF_vect){
	__timer_overflowService(TIMER1);
}// Interrupt handler for timer 2 overflow interrupt
ISR(TIMER2_OVF_vect){
	__timer_overflowService(TIMER2);
}