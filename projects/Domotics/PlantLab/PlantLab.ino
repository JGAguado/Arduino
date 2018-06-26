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
    int temp = myPlant.Temperature();
    int pres = myPlant.Pressure();
    int hum = myPlant.Humidity();
    int co2 = myPlant.CO2();
    myPlant.TVOC();

    if (myPlant.PushButton()){
        myPlant.MotorB(1);
    }
    else{
        myPlant.MotorB(0);
    }
    int luminosity = map(myPlant.Light(), 0, 1023, 255, 0);
    myPlant.LED(luminosity);

    int wat = 100;

    int moi = map(myPlant.Moisture(), 0, 1023, 0, 100);
    int lum = map(luminosity, 0, 255, 100, 0);

    int var = map(co2, 0, 8000, 0, 100);
    myPlant.LCD_bar("j0", var, 1);
    var = map(temp, 20, 40, 0, 100);
    myPlant.LCD_bar("j1", var, 2);
    var = map(pres, 850, 1050, 0, 100);
    myPlant.LCD_bar("j3", var, 2);
    myPlant.LCD_bar("j2", hum, 2);
    var = map(wat, 0, 100, 0, 100);
    myPlant.LCD_bar("j4", var, 0);
    myPlant.LCD_bar("j5", moi, 0);
    myPlant.LCD_bar("j6", lum, 0);
    myPlant.LCD_backlight(lum);

    myPlant.LCD_text("t0", String(co2)+"ppm");
    myPlant.LCD_text("t1", String(temp)+"C");
    myPlant.LCD_text("t2", String(pres)+"hPa");
    myPlant.LCD_text("t3", String(hum)+"%");
    myPlant.LCD_text("t4", String(wat)+"%");
    myPlant.LCD_text("t5", String(moi)+"%");
    myPlant.LCD_text("t6", String(lum)+"%");
    delay(1000);
}