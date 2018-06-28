/******************************************************************************

HomeLab Project
Scaled model for domotic systems example.
Created by J.G.Aguado
June 20, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <DomoMod.h>

DomoMod myHome;

String valid_id = "xxx";
void setup(){
    Serial.begin(9600);
    myHome.DomoMod_init();
    delay(1000);
}

void loop(){

    int lum = myHome.Light();
    int temp = myHome.Temperature(true);
    int pres = myHome.Pressure();
    int hum = myHome.Humidity();
    int co2 = myHome.CO2();
    int tvoc = myHome.TVOC();

    if (myHome.PushButton()){
        myHome.Peltier(1);
    }
    else{
        myHome.Peltier(0);
    }

    int set_lum = map(myHome.Light(), 0, 1023, 255, 0);
    myHome.LED(set_lum);

    int temp_threshold = 35;
    if (temp >= temp_threshold){
        myHome.RGB(255,0,0);
        myHome.Fan(1);
        delay(5000);
        myHome.Fan(0);
        myHome.RGB(0,0,0);
    }


    // String id = myHome.RFID();
    // Serial.println(id);

    // if (id == valid_id){
    //     myHome.Servo(180);
    //     delay(5000);
    //     myHome.Servo(0);
    // }
    delay(50);
}