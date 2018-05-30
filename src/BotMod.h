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

#include "ArduLab.h"

class BotMod : public ArduLab{
    public:
        BotMod();   
        void BotMod_init();
        void Servo_Left(int pos);   
        void Servo_Right(int pos); 
        void Led(int power);
        void Laser(int power); 
        int Left_LDR();
        int Right_LDR();
        int Left_IR();
        int Right_IR();
        long Get_Distance();
        void Get_Acc(float *accel);
        void Get_Mag(float *mag);
        float Get_Pitch();
        float Get_Roll();
        float Get_Heading();

    private:
        Servo s_left;
        Servo s_right;

        LSM303 IMU;

        byte _s_left = 5;
        byte _s_right = 6;   

        byte _laser = 5; 	
        byte _led = 6;

        byte _trig = 8;
        byte _echo = 7;

        int _left_ldr = A2;
        int _right_ldr = A1;
        int _left_ir = A4;
        int _right_ir = A3;
};
#endif