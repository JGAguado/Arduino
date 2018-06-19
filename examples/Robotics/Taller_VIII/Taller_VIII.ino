/******************************************************************************

Taller_V.cpp
Laser Tag
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

int BCD_0 = 10 ;
int BCD_1 = 5;
int BCD_2 = 6;
int BCD_3 = 7;

int Dig_0 = 8;
int Dig_1 = 9;
void setup(){
    Serial.begin(9600);

    pinMode(BCD_0, OUTPUT);
    pinMode(BCD_1, OUTPUT);
    pinMode(BCD_2, OUTPUT);
    pinMode(BCD_3, OUTPUT);
    pinMode(Dig_0, OUTPUT);
    pinMode(Dig_1, OUTPUT);
}

void loop(){
    for (int ii=0; ii<100; ii++){
        Serial.println(ii);
        if (ii>=10){
            multi_display(ii, 100);
        }
        else{
            digitalWrite(Dig_0, HIGH);
            digitalWrite(Dig_1, LOW);
            dec_2_bcd(ii);
            delay(1000);            
        }
    }    
}

void dec_2_bcd(int num){
    switch (num){
        case 0:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, LOW);
            Serial.println(0);
            break;
        
        case 1:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, HIGH);
            Serial.println(1);
            break;
            
        case 2:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, HIGH);
            Serial.print(1);
            digitalWrite(BCD_3, LOW);
            Serial.println(0);
            break;
            
        case 3:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, HIGH);
            Serial.print(1);
            digitalWrite(BCD_3, HIGH);
            Serial.println(1);
            break;
            
        case 4:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, HIGH);
            Serial.print(1);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, LOW);
            Serial.println(0);
            break;
                 
        case 5:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, HIGH);
            Serial.print(1);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, HIGH);
            Serial.println(1);
            break;
            
        case 6:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, HIGH);
            Serial.print(1);
            digitalWrite(BCD_2, HIGH);
            Serial.print(1);
            digitalWrite(BCD_3, LOW);
            Serial.println(0);
            break;
            
        case 7:
            digitalWrite(BCD_0, LOW);
            Serial.print(0);
            digitalWrite(BCD_1, HIGH);
            Serial.print(1);
            digitalWrite(BCD_2, HIGH);
            Serial.print(1);
            digitalWrite(BCD_3, HIGH);
            Serial.println(1);
            break;
            
        case 8:
            digitalWrite(BCD_0, HIGH);
            Serial.print(1);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, LOW);
            Serial.println(0);
            break;
                 
        case 9:
            digitalWrite(BCD_0, HIGH);
            Serial.print(1);
            digitalWrite(BCD_1, LOW);
            Serial.print(0);
            digitalWrite(BCD_2, LOW);
            Serial.print(0);
            digitalWrite(BCD_3, HIGH);
            Serial.println(1);
            break;
    }
}

void multi_display(int num, int duration){
    int dig1 = int(num/10);
    int dig2 = num - dig1 * 10;

    for (int t=0; t<=duration/2; t++){
        digitalWrite(Dig_0, HIGH);
        digitalWrite(Dig_1, LOW);
        dec_2_bcd(dig2);
        delay(10);

        digitalWrite(Dig_0, LOW);
        digitalWrite(Dig_1, HIGH);
        dec_2_bcd(dig1);
        delay(10);
    }
}