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
	DDRC = 0xFF; PORTC = 0x00;	
	unsigned char tmpA0;
	unsigned char tmpA1;
	unsigned char tmpA2;
	unsigned char tmpA3;
	unsigned char cntavail;
	unsigned char cnt;

	while(1){
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		tmpA2 = PINA & 0x04;
		tmpA3 = PINA & 0x08;
		cntavail = 0;
		cnt = 15;

		if(tmpA0 == 0){
			cntavail++;
			cnt -= 1;
		}
		if(tmpA1 == 0){
			cntavail++;
			cnt -= 2;
		}
		if(tmpA2 == 0){
			cntavail++;
			cnt -= 4;
		}
		if(tmpA3 == 0){
			cntavail++;
			cnt -= 8;
		}
		
		if(cntavail == 0){
			PORTC = 0x8F;	
		}
		else{
			PORTC = cnt;
			PORTC = PORTC & 0x0F;
		}
			
	}

    return 0;
}
