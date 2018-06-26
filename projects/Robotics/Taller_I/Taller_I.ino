/******************************************************************************

Taller_I.ino

Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

int pin_red = 13;
int pin_green = 5;
int pin_blue = 6;

int pin_pushbutton = 16;
bool pushed;

void setup(){
    pinMode(pin_pushbutton, INPUT);
    pinMode(pin_red, OUTPUT);
    pinMode(pin_green, OUTPUT);
    pinMode(pin_blue, OUTPUT);
}

void loop(){
    digitalWrite(pin_red, LOW);
    digitalWrite(pin_green, HIGH);

    pushed = digitalRead(pin_pushbutton);
    
    if (pushed){
        delay(2000);
        digitalWrite(pin_red, HIGH);
        delay(3000);
        digitalWrite(pin_green, LOW);
        delay(5000); 
    }
}