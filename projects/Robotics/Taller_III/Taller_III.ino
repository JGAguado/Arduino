/******************************************************************************

Taller_III.ino

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

int t_step = 10;

void setup(){
}

void loop(){
    for (int i=0; i<=255; i++){         //255, 0, 0
        myArduLab.RGB(255-i, i, 0);
        delay(t_step);                  //0, 255, 0
    }

    for (int i=0; i<=255; i++){         //0, 255, 0
        myArduLab.RGB(0, 255-i, i);
        delay(t_step);                  //0, 0, 255 
    }
    
    for (int i=0; i<=255; i++){         //0, 0, 255
        myArduLab.RGB(i, 0, 255-i);
        delay(t_step);                  //255, 0, 0
    }

    for (int i=0; i<=255; i++){         //255, 0, 0
        myArduLab.RGB(255, i, 0);
        delay(t_step);                  //255, 255, 0
    }

    for (int i=0; i<=255; i++){         //255, 255, 0
        myArduLab.RGB(255-i, 255, i);
        delay(t_step);                  //0, 255, 255
    }

    for (int i=0; i<=255; i++){         //0, 255, 255
        myArduLab.RGB(i, 255-i, 255);
        delay(t_step);                  //255, 0, 255
    }

    for (int i=0; i<=255; i++){         //255, 0, 255
        myArduLab.RGB(255, 0, 255-i);
        delay(t_step);                  //255, 0, 0
    }
}