/******************************************************************************

BotMod.h
Library for managing the BotMod board via ArduLab.
Created by J.G.Aguado
May 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code includes part code of the Sparkfun Electronics library for controlling the VL53L1X written by Nathan Seidle
(https://github.com/sparkfun/SparkFun_VL53L1X_Arduino_Library)

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

#include <NMEAGPS.h>
#include <GPSport.h>

#include <Wire.h>
#include "SparkFun_VL53L1X.h"

#include "ArduLab.h"

class BotMod : public ArduLab{
    public:
        BotMod();   
        void init_servos();
        void init_IMU();
        void init_distance();
        void Servo_Left(int pos);   
        void Servo_Right(int pos); 
        void Led(int power);
        void Laser(int power); 
        int Left_LDR();
        int Right_LDR();
        int Left_IR();
        int Right_IR();
        int Get_Distance(bool debug = false);
        void Get_Acc(float *accel);
        void Get_Mag(float *mag);
        float Get_Pitch();
        float Get_Roll();
        float Get_Heading();
        double Latitude(bool debug = false);
        double Longitude(bool debug = false);
        double Altitude(bool debug = false);
        int N_sats(bool debug = false);

    private:
        Servo s_left;
        Servo s_right;

        LSM303 IMU;
        SFEVL53L1X distanceSensor;

        byte _s_left = 5;
        byte _s_right = 6;   

        byte _laser = 5; 	
        byte _led = 6;

        int _left_ldr = A2;
        int _right_ldr = A1;
        int _left_ir = A4;
        int _right_ir = A3;

};
#endif