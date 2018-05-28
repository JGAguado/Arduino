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

void BotMod::Get_Acc(float *accel){
    bool debug = false;

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
    accel[0] = Mxx*(x-bx) + Mxy*(y-by) + Mxz*(z-bz);
    accel[1] = Myx*(x-bx) + Myy*(y-by) + Myz*(z-bz);
    accel[2] = Mzx*(x-bx) + Mzy*(y-by) + Mzz*(z-bz);
    
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

void BotMod::Get_Mag(float *mag){
    bool debug = false;

    IMU.read();
    int x, y, z;
    float X, Y, Z, bx, by, bz, Mxx, Mxy, Mxz, Myx, Myy, Myz, Mzx, Mzy, Mzz;
    x = IMU.m.y;
    y = IMU.m.x;
    z = IMU.m.z;
    
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

    //Calibration of the raw mag sensor
    mag[0] = Mxx*(x-bx) + Mxy*(y-by) + Mxz*(z-bz);
    mag[1] = Myx*(x-bx) + Myy*(y-by) + Myz*(z-bz);
    mag[2] = Mzx*(x-bx) + Mzy*(y-by) + Mzz*(z-bz);
    
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

float BotMod::Get_Pitch(){ 
    float accel[3];
    BotMod::Get_Acc(accel);
    
    pitch = asin(-accel[0]);
    return pitch;
}

float BotMod::Get_Roll(){ 
    float accel[3];
    BotMod::Get_Acc(accel);
    
    pitch = BotMod::Get_Pitch();

    roll = asin(accel[1]/cos(pitch));
    return roll;
}

float BotMod::Get_Heading(){ 
    float Mx, My, Mz;
    float mag[3];
    BotMod::Get_Mag(mag);
    
    pitch = BotMod::Get_Pitch();
    roll = BotMod::Get_Roll();

    // Tilt compensated magnetic sensor measurements
    Mx = mag[0] * cos(pitch) + mag[2] * sin(pitch);
    My = mag[0] * sin(roll) * sin(pitch) + mag[1] * cos(roll)  -mag[2] * sin(roll) * cos(pitch);
    Mz = -mag[0] * cos(roll) * sin(pitch) + mag[1] * sin(roll) + mag[2] * cos(roll) * cos(pitch);

    if (Mx>0 && My>=0){
        heading = atan(My/Mx);
    }
    else if (Mx<0){
        heading = 180 + atan(My/Mx);
    }
    else if (Mx>0 && My<=0){
        heading = 360 + atan(My/Mx);
    }
    else if (Mx==0 && My<0){
        heading = 90;
    }
    else if (Mx==0 && My>0){
        heading = 270;
    }

    return heading;
}
