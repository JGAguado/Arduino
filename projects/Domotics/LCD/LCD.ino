/******************************************************************************

LCD example
Small assembly requiring LCD Nextion and DomoMod for monitoring temperature and graphic display it.
Created by J.G.Aguado
June 20, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <DomoMod.h>

DomoMod myMonitor;


void setup(){
    Serial.begin(9600);
    myMonitor.DomoMod_init();
    delay(1000);
}

void loop(){
    int temp = myMonitor.Temperature();

    int luminosity = map(myMonitor.Light(), 0, 1023, 255, 0);
    myMonitor.LED(luminosity);

    int lum = map(luminosity, 0, 255, 100, 0);

    int var = map(temp, 20, 40, 0, 100);
    myMonitor.LCD_bar("j0", var, 0);

    myMonitor.LCD_backlight(lum);

    myMonitor.LCD_text("t0", String(temp)+"C");0
    delay(1000);
}