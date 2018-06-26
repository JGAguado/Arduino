/******************************************************************************

DomoMod.h
Library for managing the DomoMod board via ArduLab.
Created by J.G.Aguado
May 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#ifndef DomoMod_h
#define DomoMod_h
 
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "ArduLab.h"

class DomoMod : public ArduLab{
    public:
        DomoMod();   
        void DomoMod_init(bool NFC=false);
        float Temperature(bool debug = false);
        float Pressure(bool debug = false);
        float Humidity(bool debug = false);
        int CO2(bool debug = false);
        int TVOC(bool debug = false);
        int Presence(bool debug = false);
        String RFID(bool debug = false);
        void Servo(int pos);
        void LED(int power);
        int LDR(bool debug = false);
        int NTC(bool debug = false);
        int Moisture(bool debug = false);

    private:
        
        
        byte _servo_pin = 5;
        byte _led = 6;
        byte _power_moisture = 7;

        int _ldr = A1;
        int _presence = A2;
        int _moisture = A3;
        int _ntc = A4;
        
};
#endif