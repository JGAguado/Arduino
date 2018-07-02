/******************************************************************************

Taller_II.ino

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

int t_pause = 100;

void setup(){

}

void loop(){
    if (myArduLab.PushButton()){
        myArduLab.Play(a, 500, 100); 
        myArduLab.Play(a, 500, 100);     
        myArduLab.Play(a, 500, 100); 
        myArduLab.Play(f, 350, 100); 
        myArduLab.Play(cH, 150, 100);
        
        myArduLab.Play(a, 500, 100);
        myArduLab.Play(f, 350, 100);
        myArduLab.Play(cH, 150, 100);
        myArduLab.Play(a, 1000, 100);
        //first bit
        
        myArduLab.Play(eH, 500, 100);
        myArduLab.Play(eH, 500, 100);
        myArduLab.Play(eH, 500, 100);    
        myArduLab.Play(fH, 350, 100); 
        myArduLab.Play(cH, 150, 100);
        
        myArduLab.Play(gS, 500, 100);
        myArduLab.Play(f, 350, 100);
        myArduLab.Play(cH, 150, 100);
        myArduLab.Play(a, 1000, 100);
        //second bit...
        
        myArduLab.Play(aH, 500, 100);
        myArduLab.Play(a, 350, 100); 
        myArduLab.Play(a, 150, 100);
        myArduLab.Play(aH, 500, 100);
        myArduLab.Play(gSH, 250, 100); 
        myArduLab.Play(gH, 250, 100);
        
        myArduLab.Play(fSH, 125, 100);
        myArduLab.Play(fH, 125, 100);    
        myArduLab.Play(fSH, 250, 100);
        delay(250);
        myArduLab.Play(aS, 250, 100);    
        myArduLab.Play(dSH, 500, 100);  
        myArduLab.Play(dH, 250, 100);  
        myArduLab.Play(cSH, 250, 100);  
        //start of the interesting bit
        
        myArduLab.Play(cH, 125, 100);  
        myArduLab.Play(b, 125, 100);  
        myArduLab.Play(cH, 250, 100);      
        delay(250);
        myArduLab.Play(f, 125, 100);  
        myArduLab.Play(gS, 500, 100);  
        myArduLab.Play(f, 375, 100);  
        myArduLab.Play(a, 125, 100); 
        
        myArduLab.Play(cH, 500, 100); 
        myArduLab.Play(a, 375, 100);  
        myArduLab.Play(cH, 125, 100); 
        myArduLab.Play(eH, 1000, 100); 
        //more interesting stuff (this doesn't quite get it right somehow)
        
        myArduLab.Play(aH, 500, 100);
        myArduLab.Play(a, 350, 100); 
        myArduLab.Play(a, 150, 100);
        myArduLab.Play(aH, 500, 100);
        myArduLab.Play(gSH, 250, 100); 
        myArduLab.Play(gH, 250, 100);
        
        myArduLab.Play(fSH, 125, 100);
        myArduLab.Play(fH, 125, 100);    
        myArduLab.Play(fSH, 250, 100);
        delay(250);
        myArduLab.Play(aS, 250, 100);    
        myArduLab.Play(dSH, 500, 100);  
        myArduLab.Play(dH, 250, 100);  
        myArduLab.Play(cSH, 250, 100);  
        //repeat... repeat
        
        myArduLab.Play(cH, 125, 100);  
        myArduLab.Play(b, 125, 100);  
        myArduLab.Play(cH, 250, 100);      
        delay(250);
        myArduLab.Play(f, 250, 100);  
        myArduLab.Play(gS, 500, 100);  
        myArduLab.Play(f, 375, 100);  
        myArduLab.Play(cH, 125, 100); 
            
        myArduLab.Play(a, 500, 100);            
        myArduLab.Play(f, 375, 100);            
        myArduLab.Play(c, 125, 100);            
        myArduLab.Play(a, 1000, 100);
    }
}
