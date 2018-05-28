/******************************************************************************

BotMod.cpp
Library for managing the BotMod board via ArduLab.
Created by J.G.Aguado
May 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <Servo.h>
#include <Wire.h>
#include <LSM303.h>

#include "BotMod.h"


BotMod::BotMod()
{  
    pinMode(_led, OUTPUT);
    pinMode(_laser, OUTPUT);  
}

void BotMod::Servos_init(){
    s_left.attach(_s_left);
    s_right.attach(_s_right);
}

void BotMod::Servo_Left(int pos){
    if ((pos > 0) && (pos < 180)){
        s_left.write(pos);
        delay(20);
    }
}

void BotMod::Servo_Right(int pos){
    if ((pos > 0) && (pos < 180)){
        s_right.write(pos);
        delay(20);
    }
}

void BotMod::Led(int power){
    analogWrite(_led, power);
}

void BotMod::Laser(int power){
    analogWrite(_laser, power);
}

void BotMod::IMU_init(){
    Wire.begin();
    IMU.init();
    IMU.enableDefault();
    
}

void BotMod::Get_Acc(boolean debug){
    IMU.read();
    int x, y, z;
    float X, Y, Z, bx, by, bz, Mxx, Mxy, Mxz, Myx, Myy, Myz, Mzx, Mzy, Mzz;
    x = IMU.a.y;
    y = IMU.a.x;
    z = IMU.a.z;
    
    //Experimental coefficients for adjusting according to R = M*(r-b)
    bx = 273.23;
    by = -526.71; 
    bz = 17.52;

    Mxx = 5.98e-05;
    Mxy = -1.06e-05; 
    Mxz = -3.14e-06;
    Myx = -1.063e-05; 
    Myy = 5.91e-05;
    Myz = -3.08e-06; 
    Mzx = -3.14e-06; 
    Mzy = -3.08e-06; 
    Mzz = 6.18e-05;

    //Calibration of the raw acc sensor
    X = Mxx*(x-bx) + Mxy*(y-by) + Mxz*(z-bz);
    Y = Myx*(x-bx) + Myy*(y-by) + Myz*(z-bz);
    Z = Mzx*(x-bx) + Mzy*(y-by) + Mzz*(z-bz);
    
    if (debug){
    Serial.print("[");
    Serial.print(X);
    Serial.print(", ");
    Serial.print(Y);
    Serial.print(", ");
    Serial.print(Z);
    Serial.println("],");
    }
}