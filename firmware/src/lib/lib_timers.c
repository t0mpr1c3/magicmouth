#define BUILDING_LIBRARY
#include <avr/io.h>
#include <libdefs.h>
#include <timer.h>
extern const PROGMEM Timer PROGMEM pgm_Timers[];
void __initTimers(void){
 
// Set Timer0 to the following:-
//		Mode 	 = TIMER_MODE_CTC_OCR
//		Prescale = 1024
	// Save the timer mode
	timerGetData(&pgm_Timers[0])->mode = TIMER_MODE_CTC_OCR;
	// Set the timer mode
	
	// Mode TIMER_MODE_CTC_OCR is 2
	// Assume current mode settings are all 0	
		
			
	if(2 & 1){
		sbi(TCCR0A,WGM00);
	} 
		
			
	if(2 & 2){
		sbi(TCCR0A,WGM01);
	} 
		
			
	if(2 & 4){
		sbi(TCCR0B,WGM02);
	} 
		
	// Top is stored in Compare A OCR
				OCR0A = 250;			
				
	// Turn on the timer by setting prescaler
	timerGetData(&pgm_Timers[0])->prescale_value = 1024;
	TCCR0B |= 5;
	 
// Set Timer1 to the following:-
//		Mode 	 = TIMER_MODE_PWM_PHASE_FREQ_ICR
//		Prescale = 1
	// Save the timer mode
	timerGetData(&pgm_Timers[1])->mode = TIMER_MODE_PWM_PHASE_FREQ_ICR;
	// Set the timer mode
	
	// Mode TIMER_MODE_PWM_PHASE_FREQ_ICR is 8
	// Assume current mode settings are all 0	
		
			
	if(8 & 1){
		sbi(TCCR1A,WGM10);
	} 
		
			
	if(8 & 2){
		sbi(TCCR1A,WGM11);
	} 
		
			
	if(8 & 4){
		sbi(TCCR1B,WGM12);
	} 
		
			
	if(8 & 8){
		sbi(TCCR1B,WGM13);
	} 
		
	// Top is stored in ICR register
	ICR1 = 400;			
			
	// Turn on the timer by setting prescaler
	timerGetData(&pgm_Timers[1])->prescale_value = 1;
	TCCR1B |= 1;
	}
