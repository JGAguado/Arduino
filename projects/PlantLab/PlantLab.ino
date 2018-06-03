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
    int temp = myPlant.Temperature(true);
    int pres = myPlant.Pressure(true);
    int hum = myPlant.Humidity(true);
    int co2 = myPlant.CO2(true);
    myPlant.TVOC(true);

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
    myPlant.LCDprint("j0", String(var), 255*var/100, (255*(100-var))/100, 0);
    var = map(temp, 20, 40, 0, 100);
    myPlant.LCDprint("j1", String(var), 255*var/100, (255*(100-var))/100, 0);
    var = map(pres, 900, 1000, 0, 100);
    myPlant.LCDprint("j3", String(var), 255*var/100, (255*(100-var))/100, 0);
    var = map(hum, 0, 100, 0, 100);
    myPlant.LCDprint("j2", String(var), 255*var/100, (255*(100-var))/100, 0);
    var = map(wat, 0, 100, 0, 100);
    myPlant.LCDprint("j4", String(var), (255*(100-var))/100, 255*var/100, 0);
    var = moi;
    myPlant.LCDprint("j5", String(var), (255*(100-var))/100, 255*var/100, 0);
    var = lum;
    myPlant.LCDprint("j6", String(var), (255*(100-var))/100, 255*var/100, 0);
    myPlant.LCDprint("light", String(var));

    myPlant.LCDprint("t0", String(co2)+"ppm");
    myPlant.LCDprint("t1", String(temp)+"C");
    myPlant.LCDprint("t2", String(pres)+"hPa");
    myPlant.LCDprint("t3", String(hum)+"%");
    myPlant.LCDprint("t4", String(wat)+"%");
    myPlant.LCDprint("t5", String(moi)+"%");
    myPlant.LCDprint("t6", String(lum)+"%");
    delay(1000);
}