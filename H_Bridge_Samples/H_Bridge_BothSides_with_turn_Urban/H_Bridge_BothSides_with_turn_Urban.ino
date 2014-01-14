int motorOUT1 = 1;    //declares the first pin for the motor 
int motorOUT2 = 2;    //declares the other pin for the motor
int motorOUT3 = 3;
int motorOUT4 = 4;

int motorPWM = 9;      // this is the pmw that will set how much battery power the motor is getting (speed)
 
void setup()
{
pinMode(motorOUT1, OUTPUT);           //
pinMode(motorOUT2, OUTPUT);           // these simply are declaring them as outputs
pinMode(motorOUT3, OUTPUT);           //
pinMode(motorOUT4, OUTPUT);           // 
pinMode(motorPWM, OUTPUT);     //
}
 
void loop()
{
analogWrite(motorPWM,255);      // this is the analog speed value for the arduino (0-255)
digitalWrite(motorOUT1, HIGH);         
digitalWrite(motorOUT2, LOW);          //turns the motors on - forwards
digitalWrite(motorOUT3, HIGH);         
digitalWrite(motorOUT4, LOW);          //turns the motors on - forwards
delay(1000);     

analogWrite(motorPWM,255);      // this is the analog speed value for the arduino (0-255)
digitalWrite(motorOUT1, LOW);         
digitalWrite(motorOUT2, HIGH);          //turns the motors on - forwards
digitalWrite(motorOUT3, HIGH);         
digitalWrite(motorOUT4, LOW);          //turns the motors on - forwards
delay(1000);     

//digitalWrite(motorOUT1, LOW);
//digitalWrite(motorOUT2, HIGH);      //makes motor go backwards
//digitalWrite(motorOUT3, LOW);
//digitalWrite(motorOUT4, HIGH);      //makes motor go backwards
//delay(1000);                                //summons demons to influence the creation of man into waiting for exactly 1 second.
}
