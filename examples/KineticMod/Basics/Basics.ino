/******************************************************************************

Basics example
Example sketch for testing basic KineticMod functions.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <Servo.h>
#include <KineticMod.h>

KineticMod myKineticMod;

int pos = 0;
void setup(){
    myKineticMod.KineticMod_init();
}

void loop(){
    for (int servo=0; servo<=11; servo++){
        for (int pos=0; pos<=180; pos++){
            myKineticMod.Move_servo(servo, pos);
            delay(10);
        }
        
        for (int pos=180; pos>=0; pos--){
            myKineticMod.Move_servo(servo, pos);
            delay(10);
        }
    }
}
