/******************************************************************************

Taller_V.ino
Laser Tag
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <BotMod.h>

BotMod myBot;

int lum;
int lum_led;

void setup(){
    Serial.begin(9600);
}

void loop(){
    lum = myBot.Left_LDR();

    Serial.print("Luminosity: ");
    Serial.println(lum);
    
    if (lum < 80){
        myBot.Beep();
    }

    if (myBot.PushButton()){
        myBot.Laser(255);
    }
    else{
        myBot.Laser(0);
    }
}