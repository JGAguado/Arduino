/******************************************************************************

PlantLab Project
Fully working project of an smart Pot for hosting small plants.
Created by J.G.Aguado
May 29, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <DomoMod.h>

DomoMod myPlant;
void setup(){
    Serial.begin(9600);
    myPlant.DomoMod_init();
    delay(1000);
}

void loop(){
    myPlant.Temperature(true);
    myPlant.Pressure(true);
    myPlant.Humidity(true);
    myPlant.CO2(true);
    myPlant.TVOC(true);

    // if (myPlant.PushButton()){
    //     myPlant.MotorB(1);
    // }
    // else{
    //     myPlant.MotorB(0);
    // }
    int luminosity = map(myPlant.Light(), 0, 1023, 255, 0);
    myPlant.LED(luminosity);

    delay(1000);
}