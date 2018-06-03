/******************************************************************************

ArduLab.cpp
Library for managing ArduLab board.
Created by J.G.Aguado
May 18, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/
 
#include "ArduLab.h"
#include <SoftwareSerial.h>

// Nextion LCD Init
  SoftwareSerial LCD(14, 15);

ArduLab::ArduLab()
{
  // Basic Outputs
  pinMode(_buzzer, OUTPUT);
  pinMode(_red, OUTPUT);
  pinMode(_green, OUTPUT);
  pinMode(_blue, OUTPUT);

  // H-Bridge for motor
  pinMode(_motor_a_1, OUTPUT);
  pinMode(_motor_a_2, OUTPUT);
  pinMode(_motor_b_1, OUTPUT);
  pinMode(_motor_b_2, OUTPUT);

  // Basic Inputs
  pinMode(_pushbutton, INPUT);
  
  // LCD Initialization
  LCD.begin(9600);
}
 
void ArduLab::Beep()
{
  digitalWrite(_buzzer, HIGH);
  delay(250);
  digitalWrite(_buzzer, LOW);
  delay(250);  
}

void ArduLab::RGB(int r, int g, int b)
{
	analogWrite(_red, r);
	analogWrite(_green, g);
	analogWrite(_blue, b);
}

boolean ArduLab::PushButton()
{
  return digitalRead(_pushbutton);
}

int ArduLab::Battery()
{
  return analogRead(_battery);
}

int ArduLab::Light()
{
  return analogRead(_ldr);
}

void ArduLab::MotorA(int dir)
{
  if (dir == 0){
    digitalWrite(_motor_a_1, LOW);
    digitalWrite(_motor_a_2, LOW);    
  }
  else if (dir == 1){
    digitalWrite(_motor_a_1, HIGH);
    digitalWrite(_motor_a_2, LOW);    
  }
  else if (dir == 2){
    digitalWrite(_motor_a_1, LOW);
    digitalWrite(_motor_a_2, HIGH);    
  }
}

void ArduLab::MotorB(int dir)
{
  if (dir == 0){
    digitalWrite(_motor_b_1, LOW);
    digitalWrite(_motor_b_2, LOW);    
  }
  else if (dir == 1){
    digitalWrite(_motor_b_1, HIGH);
    digitalWrite(_motor_b_2, LOW);    
  }
  else if (dir == 2){
    digitalWrite(_motor_b_1, LOW);
    digitalWrite(_motor_b_2, HIGH);    
  }
}

void ArduLab::LCDprint(String component, String value, int r, int g, int b)
{
  if ((r!=0)||(g!=0)||(b!=0)){
  unsigned int color = int(r/8)*2048+int(g/4)*32+int(b/8);

  LCD.print(component);
  LCD.print(".pco=");
  LCD.print(color);
  LCD.write(0xff);
  LCD.write(0xff);
  LCD.write(0xff);
  }
  if (component == "light"){
    LCD.print("dim=");
    LCD.print(value);
    LCD.write(0xff);
    LCD.write(0xff);
    LCD.write(0xff);
  }
  else if (component[0] == 't'){  
    LCD.print(component);
    LCD.print(".txt=");
    LCD.write(0x22);
    LCD.print(value);
    LCD.write(0x22);
    LCD.write(0xff);
    LCD.write(0xff);
    LCD.write(0xff);
  }
  else{
    LCD.print(component);
    LCD.print(".val=");
    LCD.print(value);
    LCD.write(0xff);
    LCD.write(0xff);
    LCD.write(0xff);
  }

}