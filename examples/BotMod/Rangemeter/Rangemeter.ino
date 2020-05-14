/******************************************************************************

Rangemeter example
Example sketch for testing the range measurement functions from the BotMod R2.
Created by J.G.Aguado
May 14, 2020  
https://github.com/SpaceDIY/BotMod

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <Servo.h>
#include <BotMod.h>

BotMod myBot;
int pos = 0;
void setup(){
    Serial.begin(9600);
    myBot.init_distance();
    delay(100);
}

void loop(){

    int distance = myBot.Get_Distance();

    if (myBot.PushButton()){
        myBot.Laser(100);
    }
    else{
        myBot.Laser(0);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("mm");
    delay(100);
}