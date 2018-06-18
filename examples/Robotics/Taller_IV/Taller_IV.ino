/******************************************************************************

Taller_IV.cpp

Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <ArduLab.h>

ArduLab myArduLab;

int lum;
int lum_led;

void setup(){
    Serial.begin(9600);
}

void loop(){
    lum = myArduLab.Light();

    Serial.print("Luminosity: ");
    Serial.println(lum);
    
    lum_led = map(lum, 0,100, 0, 255);
    myArduLab.RGB(lum_led,0,0);

    if (lum < 50){
        myArduLab.Beep();
    }
}