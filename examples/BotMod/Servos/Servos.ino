/******************************************************************************

Servomotors example
Example sketch for testing basic ArduLab functions.
Created by J.G.Aguado
May 29, 2018  
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
    myBot.BotMod_init();
    Serial.begin(9600);
    delay(100);
}

void loop(){
    // Left Servo movement
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
    myBot.Servo_Left(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myBot.Servo_Left(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms for the servo to reach the position
    }

    // Right Servo movement
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
    myBot.Servo_Right(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myBot.Servo_Right(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms for the servo to reach the position
    }
}
