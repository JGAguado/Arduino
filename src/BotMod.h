/******************************************************************************

BotMod.h
Library for managing the BotMod board via ArduLab.
Created by J.G.Aguado
May 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#ifndef BotMod_h
#define BotMod_h
 
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Servo.h>
#include <Wire.h>
#include <LSM303.h>

class BotMod{
    public:
        BotMod();   
        void Servos_init();
        void IMU_init();
        void Servo_Left(int pos);   
        void Servo_Right(int pos); 
        void Led(int power);
        void Laser(int power); 
        void Get_Acc(float *accel);
        void Get_Mag(float *mag);
        float Get_Pitch();
        float Get_Roll();
        float Get_Heading();
    private:
        Servo s_left;
        Servo s_right;

        LSM303 IMU;

        int _s_left = 5;
        int _s_right = 6;   

        int _laser = 5; 	
        int _led = 6;
};
#endif