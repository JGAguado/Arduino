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

void BotMod::BotMod_init(){
    s_left.attach(_s_left);
    s_right.attach(_s_right);
    Wire.begin();
    IMU.init();
    IMU.enableDefault();
}

void BotMod::Servo_Left(int pos){
    s_left.write(pos);
}

void BotMod::Servo_Right(int pos){
    s_right.write(pos);
}

void BotMod::Led(int power){
    analogWrite(_led, power);
}

void BotMod::Laser(int power){
    analogWrite(_laser, power);
}

int BotMod::Left_LDR(){
    return analogRead(_left_ldr);
}

int BotMod::Right_LDR(){
    return analogRead(_right_ldr);
}

int BotMod::Left_IR(){
    return analogRead(_left_ir);
}

int BotMod::Right_IR(){
    return analogRead(_right_ir);
}

long BotMod::Get_Distance(){
    long duration, distance;
   
    digitalWrite(_trig, LOW);  
    delayMicroseconds(4);
    digitalWrite(_trig, HIGH);  
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    duration = pulseIn(_echo, HIGH);  

    distance = duration / 58.2;
    return distance;
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
    X = Mxx*(x-bx) + Mxy*(y-by) + Mxz*(z-bz);
    Y = Myx*(x-bx) + Myy*(y-by) + Myz*(z-bz);
    Z = Mzx*(x-bx) + Mzy*(y-by) + Mzz*(z-bz);

    //Rotation for adapting to ArduLab board
    accel[0] = -Z;
    accel[1] = Y;
    accel[2] = X;
    
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
    bx = 626.16;
    by = 398.65; 
    bz = 382.97;

    Mxx = 3.90137186e-04;
    Mxy = 3.75774743e-06; 
    Mxz = 3.05695794e-07;
    Myx = 3.75774743e-06; 
    Myy = 3.89430035e-04;
    Myz = -6.43488239e-06; 
    Mzx = 3.05695794e-07; 
    Mzy = -6.43488239e-06; 
    Mzz = 4.12210499e-04;

    //Calibration of the raw mag sensor
    X = Mxx*(x-bx) + Mxy*(y-by) + Mxz*(z-bz);
    Y = Myx*(x-bx) + Myy*(y-by) + Myz*(z-bz);
    Z = Mzx*(x-bx) + Mzy*(y-by) + Mzz*(z-bz);
    
    mag[0] = -Z;
    mag[1] = Y;
    mag[2] = X;
    if (debug){
    Serial.print("[");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.println("],");
    }
}

float BotMod::Get_Pitch(){ 
    double pitch;
    float accel[3];
    BotMod::Get_Acc(accel);
    
    //Calculations
    pitch = asin(accel[0]);
    
    //Conversion to degrees
    pitch = pitch * RAD_TO_DEG; 
    return pitch;
}

float BotMod::Get_Roll(){    
    double pitch, roll; 
    float accel[3];
    BotMod::Get_Acc(accel);
    
    pitch = BotMod::Get_Pitch() * -DEG_TO_RAD;
    
    //Calculations
    roll = asin(accel[1]/cos(pitch));
    
    // Conversion to degrees
    roll = roll * RAD_TO_DEG;
    return roll;
}

float BotMod::Get_Heading(){

    double pitch, roll, heading, Mx, My, Mz;
    float mag[3];
    BotMod::Get_Mag(mag);
    
    pitch = BotMod::Get_Pitch() * -DEG_TO_RAD;
    roll = BotMod::Get_Roll() * DEG_TO_RAD;

    // Tilt compensated magnetic sensor measurements
    Mx = mag[0] * cos(pitch) + mag[2] * sin(pitch);
    My = mag[0] * sin(roll) * sin(pitch) + mag[1] * cos(roll)  -mag[2] * sin(roll) * cos(pitch);
    Mz = -mag[0] * cos(roll) * sin(pitch) + mag[1] * sin(roll) + mag[2] * cos(roll) * cos(pitch);

    if (Mx>0 && My>=0){
        heading = atan(My/Mx) * RAD_TO_DEG;
    }
    else if (Mx<0){
        heading = 180 + atan(My/Mx) * RAD_TO_DEG;
    }
    else if (Mx>0 && My<=0){
        heading = 360 + atan(My/Mx) * RAD_TO_DEG;
    }
    else if (Mx==0 && My<0){
        heading = 90;
    }
    else if (Mx==0 && My>0){
        heading = 270;
    }

    return heading;
}
