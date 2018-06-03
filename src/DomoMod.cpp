/******************************************************************************

DomoMod.cpp
Library for managing the DomoMod board via ArduLab.
Created by J.G.Aguado
May 29, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_CCS811.h>
#include <Adafruit_BME280.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

#include <DomoMod.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Servo _servo;

Adafruit_CCS811 ccs;
Adafruit_BME280 bme;
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

DomoMod::DomoMod()
{  
    pinMode(_led, OUTPUT);
    pinMode(_power_moisture, OUTPUT);
}

void DomoMod::DomoMod_init(){
    _servo.attach(_servo_pin);
    
    // CCS811 - Air Quality Sensor
    if(!ccs.begin()){
        Serial.println("Failed to init CCS811 sensor!");
        // while(1);
    }    

    // BME280 - Air Properties Sensor
    if (!bme.begin()) {
        Serial.println("Failed to init BME280 sensor!");
        // while(1);
    }    

    // PN532 - NFC RFID Reader
    nfc.begin();
   
}
float DomoMod::Temperature(bool debug){
    float temp = bme.readTemperature();

    if (debug){
        Serial.print("Temperature = ");
        Serial.print(temp);
        Serial.println(" ºC");
    }

    return temp;
 }
float DomoMod::Pressure(bool debug){ 
    float press = bme.readPressure() / 100.0F;

    if (debug){
        Serial.print("Pressure = ");
        Serial.print(press);
        Serial.println(" hPa");
    }

    return press;
}
float DomoMod::Humidity(bool debug){ 
    float hum = bme.readHumidity();

    if (debug){
        Serial.print("Humidity = ");
        Serial.print(hum);
        Serial.println(" %");
    }

    return hum;
}
int DomoMod::CO2(bool debug){
    int CO2 = 0;
    if(ccs.available()){
        float temp = ccs.calculateTemperature();
        if(!ccs.readData()){
            CO2 = ccs.geteCO2();
        }
    }

    if (debug){
        Serial.print("CO2 = ");
        Serial.print(CO2);
        Serial.println(" ppm");
    }

    return CO2;
}
int DomoMod::TVOC(bool debug){ 
    int TVOC = 0;
    if(ccs.available()){
        float temp = ccs.calculateTemperature();
        if(!ccs.readData()){
            TVOC = ccs.getTVOC();
        }
    }

    if (debug){
        Serial.print("TVOC = ");
        Serial.print(TVOC);
        Serial.println(" ppb");
    }

    return TVOC;
}

int DomoMod::Presence(){ 
    return analogRead(_presence);
}
String DomoMod::RFID(bool debug){ 
    String id = "";
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read();
        id = tag.getUidString();
        
        if (debug){
            Serial.println(id);
        }
    }
    return id;

}
void DomoMod::Servo(int pos){ 
    _servo.write(pos);
}

void DomoMod::LED(int power){
    analogWrite(_led, power);
 }

int DomoMod::LDR(bool debug){
    int ldr = analogRead(_ldr);

    if (debug){
        Serial.println(ldr);
    } 
    return ldr;
 }

int DomoMod::NTC(bool debug){
    int ntc = analogRead(_ntc);

    if (debug){
        Serial.println(ntc);
    } 
    return ntc;
}

int DomoMod::Moisture(bool debug){ 
    digitalWrite(_power_moisture, HIGH);
    delay(100);
    int moisture = analogRead(_moisture);
    digitalWrite(_power_moisture, LOW);

    if (debug){
        Serial.println(moisture);
    }
    return moisture;
}
