/******************************************************************************

Taller_IX.ino

Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <BotMod.h>

BotMod myBot;

void setup(){
    myBot.BotMod_init();
}

void loop(){
    // Move motor DC
    delay(1000);
    myBot.MotorA(1);    //CW
    delay(1000);
    myBot.MotorA(2);    //CCW
    delay(1000);
    myBot.MotorA(0);    //STOP

    // Move stepper motor
    myBot.Stepper(0, 5);    // Direction (1: CW, 2: CCW), Turns (by default 1), Speed (by default 60 rpm)
    delay(100);
    myBot.Stepper(1, 5, 120);
    
    // Move servomotor
    for (int pos=0; pos<=180; pos++){
        myBot.Servo_Left(pos);
    }
    for (int pos=180; pos>=0; pos--){
        myBot.Servo_Left(pos);
    }
}
