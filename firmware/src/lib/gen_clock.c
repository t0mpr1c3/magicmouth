
// Its a component of the library
#define BUILDING_LIBRARY

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
			
	
#include <libdefs.h>	
#include <clock.h>	
		
		
#define CLOCK_PRESCALE 			1024		 
#define CLOCK_TOP 				250		 


// #define msPerTop (CLOCK_TOP*1000U*CLOCK_PRESCALE/F_CPU)
#define msPerTop 16
		 
#define usPerTop (msPerTop * 1000U)  	// convert to uS		 
static volatile TICK_COUNT wholeTicks;

		
#define CLOCK_INT_PENDING bit_is_set(TIFR0,OCF0A)		
#define CLOCK_INT_CLEAR sbi(TIFR0,OCF0A)		
		
#define CLOCK_INT_ENABLE sbi(TIMSK0,OCIE0A)		
#define CLOCK_INT_DISABLE cbi(TIMSK0,OCIE0A)		
		
#define CLOCK_TOP_REG OCR0A

void clockGetSnapshot(TIMER_SNAPSHOT* snapshot){
	// Clock timer uses TIMER_MODE_CTC_OCR which generate compare interrupts on channel A
	CRITICAL_SECTION{
		// get the current ticks from the timer
		uint8_t tcnt = TCNT0;
		// get the number of whole ticks
		snapshot->whole  = wholeTicks;
		// get the current ticks again
		snapshot->part   = TCNT0;
		// If the second reading of tcnt has gone down then there must have been an overflow
		// since reading the 'rtn' value. Or there may be a pending interrupt which may be
		// because interrupts are currently turned off. In either case increment the 'rtn' value
		// as if the interrupt has happened
		if(snapshot->part < tcnt || CLOCK_INT_PENDING ){
			snapshot->whole += usPerTop;
			// get the current ticks again
			snapshot->part = TCNT0;
		}
	}
}

TICK_COUNT clockSnapshotToTicks(const TIMER_SNAPSHOT* snapshot){
	TICK_COUNT rtn = snapshot->whole;

	// top = usPerTop
	// part     x
	TICK_COUNT frac  = snapshot->part;
	frac *= usPerTop;
	frac /= CLOCK_TOP;

	rtn += frac;

	return rtn;
}

// Get the current clock time in uS
TICK_COUNT clockGetus(void){
	TIMER_SNAPSHOT snapshot;
	clockGetSnapshot(&snapshot);

	return clockSnapshotToTicks(&snapshot);
}

// Initialise the clock timer and turn it on
void __clockInit(void){
	// Set interrupt pending = false
	CLOCK_INT_CLEAR;
	
	// Enable interrupts
	CLOCK_INT_ENABLE;
}

// ISR for clock overflow. Occurs every msPerTop
ISR(TIMER0_COMPA_vect) {
	wholeTicks += usPerTop;

	
}
	