/******************************************************************************

Basics example
Example sketch for testing basic ArduLab functions.
Created by J.G.Aguado
May 18, 2018  
https://github.com/SpaceDIY/ArduLab

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
    delay(100);
}

void loop(){
    int l_ldr = myBot.Left_LDR();
    int r_ldr = myBot.Right_LDR();
    int l_ir = myBot.Left_IR();
    int r_ir = myBot.Right_IR();
    long distance = myBot.Get_Distance();

    if (myBot.PushButton()){
        myBot.Led(255);
    }
    else{
        myBot.Led(0);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm Left LDR: ");
    Serial.print(l_ldr);
    Serial.print(" Right LDR: ");
    Serial.print(r_ldr);
    Serial.print(" Left IR: ");
    Serial.print(l_ir);
    Serial.print(" Right IR: ");
    Serial.println(r_ir);
    delay(100);
}
