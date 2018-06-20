/******************************************************************************

Taller VII.ino

Created by J.G.Aguado
June 20, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <BotMod.h>

BotMod myBot;

int ii = 0;

float pitch, roll, heading;
double latitude, longitude, altitude = 0;

void setup(){
    Serial.begin(9600);
    myBot.BotMod_init();
    delay(100);
}

void loop(){
    ii++;
    // IMU sensor of attitude
    pitch = myBot.Get_Pitch();    
    roll = myBot.Get_Roll();
    heading = myBot.Get_Heading();
        
    // GPS (refresh passed 5 secs)
    if (ii >= 50){
        ii = 0;
        latitude = myBot.Latitude();   
        longitude = myBot.Longitude();
        altitude = myBot.Altitude();
    }
    // Serial print

    Serial.print("Pitch = ");
    Serial.print(pitch);
    Serial.print("º, Roll = ");
    Serial.print(roll);
    Serial.print("º, Heading = ");
    Serial.print(heading);
    
    
    Serial.print("º, Latitude = ");
    Serial.print(latitude);
    Serial.print("  Longitude = ");
    Serial.print(longitude);
    Serial.print("  Altitude = ");
    Serial.print(altitude);
    Serial.println("m");
    delay(10);
}
