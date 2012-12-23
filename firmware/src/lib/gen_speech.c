
// Its a component of the library
#define BUILDING_LIBRARY

#define CLOCK_TOP ( 400 - 1)		 

	
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
#include <Audio/Text2Speech/Text2Speech.h>	

	
static const uint16_t PROGMEM speechVolume[16] = {
	(CLOCK_TOP * 0) / 15,
	(CLOCK_TOP * 1) / 15,
	(CLOCK_TOP * 2) / 15,
	(CLOCK_TOP * 3) / 15,
	(CLOCK_TOP * 4) / 15,
	(CLOCK_TOP * 5) / 15,
	(CLOCK_TOP * 6) / 15,
	(CLOCK_TOP * 7) / 15,
	(CLOCK_TOP * 8) / 15,
	(CLOCK_TOP * 9) / 15,
	(CLOCK_TOP * 10) / 15,
	(CLOCK_TOP * 11) / 15,
	(CLOCK_TOP * 12) / 15,
	(CLOCK_TOP * 13) / 15,
	(CLOCK_TOP * 14) / 15,
	(CLOCK_TOP * 15) / 15
};	


#define roundup(x,y) (((x) + ((y)>>1))/(y))

uint8_t _speech_timeFactor = roundup(F_CPU,550000UL);

		
		
	
void _speech_set_volume(uint8_t b){	
	uint16_t val = pgm_read_word(&speechVolume[b]);
	OCR1B = val;	
	/* compareSetThreshold(channel,val); */
}	


void speechInit(const IOPin* pin){
	pin_make_output(pin,FALSE);
	// Activate non-inverted PWM on the hardware pin
	TCCR1A |= (BV( COM1B0) << 1);
	

}

	