/******************************************************************************

KineticMod.cpp
Library for managing the KineticMod board via ArduLab.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "KineticMod.h"


KineticMod::KineticMod()
{  
}

void KineticMod::KineticMod_init(){
    pwm.begin();
    pwm.setPWMFreq(60);
    delay(10);
}

void KineticMod::Move_servo(int servo, int pos){
    uint16_t pulselen = map(pos, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(servo, 0, pulselen);
}

int KineticMod::Read_pot(int pot){
    int value = 0;
    switch(pot){
        case 0:
            value = analogRead(A1);
            break;
            
        case 1:
            value = analogRead(A2);
            break;

        case 2:
            value = analogRead(A3);
            break;

        case 3:
            value = analogRead(A4);
            break;
    }
    value = map(value, 0,1023,0,330);

    return value;
}
