/******************************************************************************

Taller_I.1.cpp

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

void setup(){

}

void loop(){
    myArduLab.RGB(0,255,0);

    if (myArduLab.PushButton()){
        delay(2000);
        myArduLab.RGB(255,255,0);
        delay(3000);
        myArduLab.RGB(255,0,0);
        delay(5000); 
    }
}