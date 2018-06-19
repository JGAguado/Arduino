/******************************************************************************

Taller_X.ino
Robotic Arm simple sketch. 
Thanks to this sketch the many different articulations of the robotic arm (6DoF) can be rotated according to 3 potentiometers and 1 switching potentiometer.
The switching pottentiometer defines which pairs of servomotors move.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

#include <KineticMod.h>

KineticMod myRobotArm;

int pot_0;
int pot_1;
int pot_2;
int pot_3;

int base = 0;
int shoulder = 1;
int elbow = 2;
int wrist_1 = 3;
int wrist_2 = 4;
int clamp = 5;

void setup(){
    myRobotArm.KineticMod_init();
}

void loop(){
    // Reading of potentiometers
    int pot_0 = myRobotArm.Read_pot(0);
    int pot_1 = myRobotArm.Read_pot(1);
    int pot_2 = myRobotArm.Read_pot(2);
    int pot_3 = myRobotArm.Read_pot(3);

    //Converts the 0-360 deg of the pottentiometer to a 0-180 deg of the servomotors
    int pos_0 = map(pot_0, 0, 360, 0, 180);
    int pos_1 = map(pot_1, 0, 360, 0, 180);
    int pos_2 = map(pot_2, 0, 360, 0, 180); 

    //Writes the servo pos according to the pot_3 position.
    if (pot_3<180){
        myRobotArm.Move_servo(base, pos_0);
        myRobotArm.Move_servo(shoulder, pos_1);
        myRobotArm.Move_servo(elbow, pos_2);
    }
    else{
        myRobotArm.Move_servo(wrist_1, pos_0);
        myRobotArm.Move_servo(wrist_2, pos_1);
        myRobotArm.Move_servo(clamp, pos_2);
    }
}
