/******************************************************************************

Taller_II.cpp

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

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;


void setup(){

}

void loop(){
    if (myArduLab.PushButton()){
        myArduLab.Play(a, 500);
        myArduLab.Play(a, 500);    
        myArduLab.Play(a, 500);
        myArduLab.Play(f, 350);
        myArduLab.Play(cH, 150);  
        myArduLab.Play(a, 500);
        myArduLab.Play(f, 350);
        myArduLab.Play(cH, 150);
        myArduLab.Play(a, 650);
        
        delay(500);
        
        myArduLab.Play(eH, 500);
        myArduLab.Play(eH, 500);
        myArduLab.Play(eH, 500);  
        myArduLab.Play(fH, 350);
        myArduLab.Play(cH, 150);
        myArduLab.Play(gS, 500);
        myArduLab.Play(f, 350);
        myArduLab.Play(cH, 150);
        myArduLab.Play(a, 650);
        
        delay(500);

        myArduLab.Play(aH, 500);
        myArduLab.Play(a, 300);
        myArduLab.Play(a, 150);
        myArduLab.Play(aH, 500);
        myArduLab.Play(gSH, 325);
        myArduLab.Play(gH, 175);
        myArduLab.Play(fSH, 125);
        myArduLab.Play(fH, 125);    
        myArduLab.Play(fSH, 250);
        
        delay(325);
        
        myArduLab.Play(aS, 250);
        myArduLab.Play(dSH, 500);
        myArduLab.Play(dH, 325);  
        myArduLab.Play(cSH, 175);  
        myArduLab.Play(cH, 125);  
        myArduLab.Play(b, 125);  
        myArduLab.Play(cH, 250);  
        
        delay(350);
    }
}