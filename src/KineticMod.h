/******************************************************************************

KineticMod.h
Library for managing the KineticMod board via ArduLab.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#ifndef KineticMod_h
#define KineticMod_h
 
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "ArduLab.h"

class KineticMod : public ArduLab{
    public:
        KineticMod();   
        void KineticMod_init();
        void Move_servo(int servo, int pos);
        int Read_pot(int pot);

    private:
        Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
        
        int SERVOMIN = 150;
        int SERVOMAX = 600;
        };
#endif