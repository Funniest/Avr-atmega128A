# 74LS373
### Do you know 74LS373?
74LS373은 다중 제어(?)를 위한 IC같습니다.

하나의 데이터 포트를 이용하여 LE, OE만으로여러개의 74LS373을 효율적으로 사용할 수 있습니다.

74LS373의 내부 구조는 아래 그림과 같습니다.

![Alt text](https://github.com/Funniest/Avr-atmega128A/blob/master/74LS373/img/struct.PNG)

위의 그림과 같이 LE에 HIGH신호를 주면 Data들이 들어갈수 있는 상태로 바뀌게 됩니다.

그 후 그 데이터들을 내보내고 싶다면, QE에 LOW신호를 주면 Data들이 나가게 됩니다.

데이터 시트는 Data Sheet폴더에 첨부하여 놓았습니다.

### 소스코드
이 소스코드는 Code Vision에서 작성되었습니다.
```
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
```
