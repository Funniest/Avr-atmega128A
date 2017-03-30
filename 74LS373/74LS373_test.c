/*
 * test.c
 *
 * Created: 2017-03-30 오전 9:38:04
 * Author: Minsungkim
 */

#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA = 0xFF; //DDRA DATA
    DDRE = 0x04; //DDRP IS LE, OE
    
    //EX) LE = HIGH -> OE = LOW => NOT ACTIVE
    //EX) LE = HIGH -> OE = HIGH => ACTIVE!
    PORTE.0 = 1; //LE 1
    PORTE.1 = 0; //OE 0
    
    while (1){
    // Please write your application code here
        PORTA.0 = 1;
        delay_ms(1000);
        PORTA.0 = 0;
        delay_ms(3000);
    }
}
