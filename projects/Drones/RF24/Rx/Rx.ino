/******************************************************************************

Tx.ino
2,4GHz RF Transmissor.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <ArduLab.h>

const int pinCE = 8;
const int pinCSN = 7;
RF24 radio(pinCE, pinCSN);
ArduLab myArduLab;

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
int data[2];
 
void setup()
{
   radio.begin();
   Serial.begin(9600); 
   radio.openReadingPipe(1, pipe);
   radio.startListening();
}
 
void loop()
{
   if (radio.available())
   {    
      radio.read(data, sizeof data);
      Serial.print("Dato0= " );
      Serial.print(data[0]);
      Serial.println("");
      if (data[0]<50){
          myArduLab.Beep();
          myArduLab.RGB(255,0,0);
      }
      else{
          myArduLab.RGB(0,255,0);
      }
   }
   delay(1000);
}