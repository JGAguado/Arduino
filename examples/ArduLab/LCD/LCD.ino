/******************************************************************************

LCD example
Example sketch for testing LCD ArduLab functions.
Created by J.G.Aguado
June 20, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <ArduLab.h>

ArduLab myArduLab;
int ii = 0;

void setup(){

}

void loop(){
    myArduLab.LCD_text("Hello World");
    myArduLab.LCD_text
}