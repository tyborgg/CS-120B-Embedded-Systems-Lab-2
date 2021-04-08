/*	Author: tpast001
 *  Partner(s) Name: N/A
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {	
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;	
	unsigned char tempAdd = 0;
	unsigned char tempSub = 0;
	unsigned char tmpA = 0;
	unsigned char tmpC = 0;

	while(1){
		tempAdd = 0;
		tempSub = 0;		
		tempAdd = PINA + PINB + PINC;
		tmpA = PINA;
		tmpC = PINC;
		if(tmpA > tmpC){
			tempSub = tmpA - tmpC;
		}
		else{
			tempSub = tmpC - tmpA;
		}

		if(tempAdd > 140){
			PORTD = 0x01;
		}
		else{
			PORTD = 0x00;
		}
		if(tempSub > 80){
			PORTD = PORTD | 0x02;
		}

		PORTD = PORTD | ((tempAdd >> 2) & 0xFC);
	}

    return 0;
}
