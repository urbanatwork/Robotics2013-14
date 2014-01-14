 
// This is code modified by Urban Reininger 2012-05-29 for the Magician Chasis Robot with an Ardumoto shield. 
// this code based off of http://www.sparkfun.com/tutorials/195


//int pwm_a = 10; //PWM control for motor outputs 1 and 2 is on digital pin 10
int pwm_a = 3;  //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //dir control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //dir control for motor outputs 3 and 4 is on digital pin 13


void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  
  analogWrite(pwm_a, 255);        
  analogWrite(pwm_b, 255);
  
}

void loop()
{
  
  // Wait (pause for drama and allow me time to place the robot at the start)  
  analogWrite(pwm_a, 0);  // motor set to zero speed      
  analogWrite(pwm_b, 0);  // motor set to zero speed
  delay(1000); // do nothing

// ==================================

  
  // Set direction "Forward"
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  
  delay(1000);
  
  // run the moters fast for as long as the delay is set for
  analogWrite(pwm_a, 255);      
  //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
  delay(1800); // how long the motors are running
  
// ==================================

// Wait (pause for drama)  
  analogWrite(pwm_a, 0);  // motor set to zero speed      
  analogWrite(pwm_b, 0);  // motor set to zero speed
  delay(1000); // do nothing

// ==================================

// Turn Right - one motor going forward the other motor going backwards
  digitalWrite(dir_a, HIGH);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  
  delay(1000); 
  
  analogWrite(pwm_a, 255);      
  //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
  
  delay(1000); // How long it takes to turn (this isn't very accurate but can be played with to work depending on the robot's motors, the configuration, weight distribution, and battery strength.  

// ==================================
// Wait (pause for drama)  
//  analogWrite(pwm_a, 0);  // motor set to zero speed      
//  analogWrite(pwm_b, 0);  // motor set to zero speed
//  delay(1000); // do nothing

}

