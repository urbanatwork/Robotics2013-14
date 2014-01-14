
//This is a simple version of some RedBotBoard motor code. 
// by Urban Reininger urban@ross.org http://github.com/urbanatwork/  2014-01-14 
// Done in part of the Ross School's Arduino Robotics course http://www.ross.org


// Include the RebBot libraries. This allows you to use RodBot specific commands like "RedBotMotor"
#include <RedBot.h>

// Renames 
RedBotMotor motor;

void setup(){
// Call the motor control class. This only needs to be done once
// and indeed SHOULD only be done once!

// Speed levels for looking for line and following once it's found. Go
//  too fast and you're liable to lose the line.
#define forwardSpeed   200
#define backwardSpeed  200
}

void loop(){
// Just sit there for 2 seconds for dramtic effect!
delay(2000); 

 // Make the right motor go forward at the speed defined.
 motor.rightDrive(forwardSpeed); 
 delay(300); // do the previous command for .3 seconds
 
  // Make the right motor brake (stop)
 motor.rightBrake();
 delay(300); // do the previous command for .3 seconds
 
  // Make the left motor go forward at the speed defined.
 motor.leftDrive(forwardSpeed); 
 delay(200); // do the previous command for .2 seconds
 
  // Make the left motor brake (stop)
 motor.leftBrake();
 delay(200); //do the previous command for .2 seconds
  
}

    /*      
     * If _speed_ is a positive integer, drives both motors forward, and if
     * _speed_ is a negative integer, drives both motors backward. In either
     * case, the motors are driven at the absolute value at _speed_. Allowable
     * values for _speed_ are -255 to 255 inclusive, however values in -75 to 0
     * and 0 to 75 inclusive may not provide enough torque to start the motor
     * turning.
     
     */
