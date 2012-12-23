#include "lib_timerdef.h"
#include <timer.h>
#include <errors.h>
// Variable used by main library to link in this module
const uint8_t PROGMEM _timer_capture_error = TIMER_CAPTURE_CALLBACK_EXISTS;
// The dummy routine used to denote that the capture is in use
// Only ever called from here but not static to avoid unused warnings
void nullTimerCaptureCallback(const Timer *timer, void* data){}
// Interrupt handler for timer 1 capture interrupt
ISR(TIMER1_CAPT_vect){
	__timer_captureService(TIMER1);
}