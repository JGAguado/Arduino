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

void ArduLab::LCD_bar(String component, int value, byte type)
/* Type variable explanation:
  0:  Min val -> red
      Medium val -> yellow
      Max val -> green

  1:  Min val -> green
      Medium val -> yellow
      Max val -> red

  2:  Min val -> red
      Medium val -> green
      Max val -> red
 */

{
  int r, g, b;
  b = 0;

  if (type == 0){
    if ((0<=value) && (value<50)){
      r = 255;
      g = 5.1 * value;        
    }
    if ((50<=value) && (value<=100)){  
      g = 255;
      r = 255 - 5.1 * (value-50);
    }
  }
  else if (type == 1){
    if ((0<=value) && (value<50)){
      g = 255;
      r = 5.1 * value;        
    }
    if ((50<=value) && (value<=100)){  
      r = 255;
      g = 255 - 5.1 * (value-50);
    }
  }
  else if (type == 2){
    if ((0<=value) && (value<33)){
      r = 255;
      g = 8.5 * value;        
    }
    if ((33<=value) && (value<50)){  
      g = 255;
      r = 255 - 15 * (value-33);
    }
    if ((50<=value) && (value<66)){  
      g = 255;
      r = 15.93 * (value-50);
    }
    if ((66<=value) && (value<=100)){
      r = 255;
      g = 255 - 7.5 * (value - 66); 
    }
  }

  unsigned int color = int(r/8)*2048+int(g/4)*32+int(b/8);

  LCD.print(component);
  LCD.print(".pco=");
  LCD.print(color);
  LCD.write(0xff);
  LCD.write(0xff);
  LCD.write(0xff);
    
  LCD.print(component);
  LCD.print(".val=");
  LCD.print(value);
  LCD.write(0xff);
  LCD.write(0xff);
  LCD.write(0xff);  
}

void ArduLab::LCD_text(String component, String value)
{    
  LCD.print(component);
  LCD.print(".txt=");
  LCD.write(0x22);
  LCD.print(value);
  LCD.write(0x22);
  LCD.write(0xff);
  LCD.write(0xff);
  LCD.write(0xff);  
}

void ArduLab::LCD_backlight(int value)
{
  LCD.print("dim=");
  LCD.print(value);
  LCD.write(0xff);
  LCD.write(0xff);
  LCD.write(0xff);
}