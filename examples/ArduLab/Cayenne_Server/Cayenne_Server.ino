/******************************************************************************

Cayenne Server example 
Example sketch for testing Cayenne Server via Serial1 to a ESP8266 Wifi module.
Created by J.G.Aguado
May 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
#include <ArduLab.h>

#define INPUT_SIZE 30

ArduLab myArduLab;

int t_trans = 0;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
  Read_ESP8266();
  int light = myArduLab.Light();
  if (t_trans > 10){
    t_trans = 0;
    String msg = "10:" + String(light);
    Serial1.println(msg);
    Serial.println(msg);
  }
  t_trans = t_trans + 1; 
  delay(1000);
}

void Read_ESP8266(){
char input[INPUT_SIZE + 1];
byte size = Serial1.readBytes(input, INPUT_SIZE);
// Add the final 0 to end the C string
input[size] = 0;
char* separator = strchr(input, ' ');
if (separator != 0)
{
    *separator = 0;
    int id = atoi(input);
    ++separator;
    int value = atoi(separator);
    
    Serial.print("Id: ");
    Serial.print(id);
    Serial.print(" Value: ");
    Serial.println(value);
}
}