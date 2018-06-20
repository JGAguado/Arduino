/******************************************************************************

GPS example
Example sketch for testing GPS functions.
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
void setup(){
    myBot.BotMod_init();
    Serial.begin(9600);
    delay(100);
    }

void loop(){
    myBot.Latitude(true);
    myBot.Longitude(true);
    myBot.Altitude(true);
    myBot.N_sats(true);
}
