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
    DDRA = 0x00; PORTA = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char inIgnition = 0x00;
    unsigned char driverSeated = 0x00;
    unsigned char sbFastened = 0x00;
    unsigned char sbIconOn = 0x00;
    unsigned char fuelLevel = 0x00;   

    while (1) {
        inIgnition = (PINA & 0x10);
        driverSeated = (PINA & 0x20);
        sbFastened = (PINA & 0x40);
        sbIconOn = inIgnition | driverSeated | sbFastened;
        if(sbIconOn == 0x30) {
            PORTC = (PORTC | 0x80);
        }

        fuelLevel = 0x00;
        switch(PINA) {
            case 15:
            case 14:
            case 13: fuelLevel = (fuelLevel & 0xFE) | 0x01;
            case 12:
            case 11:
            case 10: fuelLevel = (fuelLevel & 0xFD) | 0x02;
            case  9:
            case  8:
            case  7: fuelLevel = (fuelLevel & 0xFB) | 0x04;
            case  6:
            case  5: fuelLevel = (fuelLevel & 0xF7) | 0X08;
            case  4:
            case  3: fuelLevel = (fuelLevel & 0xEF) | 0x10;
            case  2:
            case  1: fuelLevel = (fuelLevel & 0xDF) | 0x20;
                     break;
            case  0: fuelLevel = 0x00;
       }

       if(PINA <= 4) {
          fuelLevel = (fuelLevel & 0xBF) | 0x40;
       }

       PORTC = fuelLevel;
    }
    return 1;
}
