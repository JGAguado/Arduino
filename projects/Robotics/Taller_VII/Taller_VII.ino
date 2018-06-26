/******************************************************************************

Taller_VII.ino

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

long distance;
int distance_mapped;

void setup(){
    myBot.BotMod_init()
}

void loop(){
    distance = myBot.Get_Distance();

    Serial.print("Distance: ");
    Serial.print(lum);
    Serial.println(" cm.");
    
    distance_mapped = map(distance, 0,250, 0, 100);
    myBot.LCD_text("t0", distance);
    myBot.LCD_bar("j0", distance_mapped, 0);
}