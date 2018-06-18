/******************************************************************************

Taller_VI.cpp
Parktronic
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
int freq;
int duration;

int intensity;

void setup(){
    Serial.begin(9600);
}

void loop(){
    distance = myBot.Get_Distance();

    Serial.print("Distance: ");
    Serial.print(lum);
    Serial.println(" cm.");
    
    freq = map(distance, 0, 150, 5000, 300);
    duration = map(distance, 0, 150, 75, 800);
    myBot.Play(tone, duration);

    intensity = map(distance, 0, 150, 255, 0);

    myBot.RGB(intensity, 255-intensity, 0);
}