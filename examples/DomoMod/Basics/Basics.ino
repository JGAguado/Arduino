/******************************************************************************

Basics example
Example sketch for testing basic DomoMod board functions.
Created by J.G.Aguado
May 29, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <DomoMod.h>

DomoMod myHome;
void setup(){
    myHome.DomoMod_init();
    Serial.begin(9600);
    delay(1000);
}

void loop(){
    myHome.Temperature(true);
    myHome.Pressure(true);
    myHome.Humidity(true);
    myHome.CO2(true);
    myHome.TVOC(true);

    if (myHome.PushButton()){
        myHome.LED(255);
    }
    else{
        myHome.LED(0);
    }
    delay(1000);
}
