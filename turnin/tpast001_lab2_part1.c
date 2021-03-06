/*	Author: tpast001
 *  Partner(s) Name: N/A
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #1
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
	DDRB = 0xFF; PORTB = 0x00;     	
	unsigned char tempA0 = 0x00;
	unsigned char tempA1 = 0x00;
	
	while(1){
		tempA0 = PINA & 0x01;
		tempA1 = PINA & 0x02;

		if(tempA0 == 1 && tempA1 == 0){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
	}

    return 0;
}
