/*	Author: Albert Dang adang018@ucr.edu
 *      Partner(s) Name: Min-Hua Wu mwu057@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 3  Exercise 1
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
    DDRC = 0xFF; PORTC = 0x00;
    
    unsigned char portMask = 0x01;
    unsigned char oneCount = 0;

    while (1) {
        oneCount = 0;

        for (unsigned char i = 0; i < 8; ++i) {
            if ((PINA & portMask) == portMask) {
                ++oneCount;
            }
            if ((PINB & portMask) == portMask) {
                ++oneCount;
            }
            portMask << 1;
        }

        PORTC = oneCount;
    }
    return 1;
}
