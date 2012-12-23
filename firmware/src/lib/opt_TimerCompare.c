
// Include hardware info for this device	
#include <avr/io.h>

		
#if defined (__AVR_ATmega328P__)
// Each timer has A,B channels etc
// Map the UART vectors
#  define USART0_RX_vect USART_RX_vect
#  define USART0_TX_vect USART_TX_vect
 

#define PA0 PORTA0		
#define PA1 PORTA1		
#define PA2 PORTA2		
#define PA3 PORTA3		
#define PA4 PORTA4		
#define PA5 PORTA5		
#define PA6 PORTA6		
#define PA7 PORTA7		
	
#define PB0 PORTB0		
#define PB1 PORTB1		
#define PB2 PORTB2		
#define PB3 PORTB3		
#define PB4 PORTB4		
#define PB5 PORTB5		
#define PB6 PORTB6		
#define PB7 PORTB7		
	
#define PC0 PORTC0		
#define PC1 PORTC1		
#define PC2 PORTC2		
#define PC3 PORTC3		
#define PC4 PORTC4		
#define PC5 PORTC5		
#define PC6 PORTC6		
#define PC7 PORTC7		
	
#define PD0 PORTD0		
#define PD1 PORTD1		
#define PD2 PORTD2		
#define PD3 PORTD3		
#define PD4 PORTD4		
#define PD5 PORTD5		
#define PD6 PORTD6		
#define PD7 PORTD7		
	
#else
#  error "Processor mismatch in utilities.xsl"
#endif
			
#include "lib_timerdef.h"
#include <timer.h>
#include <errors.h>
// Variable used by main library to link in this module
const uint8_t PROGMEM _timer_compare_error = TIMER_COMPARE_CALLBACK_EXISTS;
// The dummy routine used to denote that the compare is in use
// Only ever called from here but not static to avoid unused warnings
void nullTimerCompareCallback(const TimerCompare *timer_compare, void* data){}

// TIMER0_COMPAREA is in use
static void __attribute__ ((constructor)) init_TIMER0_COMPAREA(void){
	TimerDataCompare* data = compareGetData(TIMER0_COMPAREA);
	data->compare_callback = &nullTimerCompareCallback;
}

// Interrupt handler for  TIMER0_COMPAREB compare interrupt
ISR(TIMER0_COMPB_vect){
	__timer_compareService(TIMER0_COMPAREB);
}
// Interrupt handler for  TIMER1_COMPAREA compare interrupt
ISR(TIMER1_COMPA_vect){
	__timer_compareService(TIMER1_COMPAREA);
}
// TIMER1_COMPAREB is in use
static void __attribute__ ((constructor)) init_TIMER1_COMPAREB(void){
	TimerDataCompare* data = compareGetData(TIMER1_COMPAREB);
	data->compare_callback = &nullTimerCompareCallback;
}

// Interrupt handler for  TIMER2_COMPAREA compare interrupt
ISR(TIMER2_COMPA_vect){
	__timer_compareService(TIMER2_COMPAREA);
}
// Interrupt handler for  TIMER2_COMPAREB compare interrupt
ISR(TIMER2_COMPB_vect){
	__timer_compareService(TIMER2_COMPAREB);
}
