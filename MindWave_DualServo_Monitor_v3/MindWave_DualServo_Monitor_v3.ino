////////////////////////////////////////////////////////////////////////
// Arduino Bluetooth Interface with Mindwave
// 
// Some of this is example code provided by NeuroSky, Inc. and is provided
// license free.

// This Code has been modified to control a Servo with it's signal wire attached to pin 13 and serial out info on which case it is using.
// Urban Reininger - urban@ross.org - 2014-02-07
////////////////////////////////////////////////////////////////////////

#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
 
int pos = 0;    // variable to store the servo position
int servo1Degrees = 0;
int servo2Degrees = 0;

#define BAUDRATE 57600
#define DEBUGOUTPUT 0

#define powercontrol 10

// checksum variables
byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {
  0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;

// Microprocessor Setup  ------------------------------------------

void setup() {
  
  servo1.attach(13);  // attaches the servo on pin 13 to the servo object 

  Serial.begin(BAUDRATE);           // USB
}

// Read data from Serial UART    ------------------------------------------
byte ReadOneByte() {
  int ByteRead;

  while(!Serial.available());
  ByteRead = Serial.read();

#if DEBUGOUTPUT  
  Serial.print((char)ByteRead);   // echo the same byte out the USB serial (for debug purposes)
#endif

  return ByteRead;
}

//MAIN LOOP//
void loop() {


  // Look for sync bytes
  if(ReadOneByte() == 170) {
    if(ReadOneByte() == 170) {

      payloadLength = ReadOneByte();
      if(payloadLength > 169)                      //Payload length can not be greater than 169
          return;

      generatedChecksum = 0;        
      for(int i = 0; i < payloadLength; i++) {  
        payloadData[i] = ReadOneByte();            //Read payload into memory
        generatedChecksum += payloadData[i];
      }   

      checksum = ReadOneByte();                      //Read checksum byte from stream      
      generatedChecksum = 255 - generatedChecksum;   //Take one's compliment of generated checksum

        if(checksum == generatedChecksum) {    

        poorQuality = 200;
        attention = 0;
        meditation = 0;

        for(int i = 0; i < payloadLength; i++) {    // Parse the payload
          switch (payloadData[i]) {
          case 2:
            i++;            
            poorQuality = payloadData[i];
            bigPacket = true;            
            break;
          case 4:
            i++;
            attention = payloadData[i];                        
            break;
          case 5:
            i++;
            meditation = payloadData[i];
            break;
          case 0x80:
            i = i + 3;
            break;
          case 0x83:
            i = i + 25;      
            break;
          default:
            break;
          } // switch
        } // for loop

#if !DEBUGOUTPUT

        // *** Add your code here ***

        if(bigPacket) {
          if(poorQuality == 0)
          Serial.print("Conencted! ");

          Serial.print("Noise: ");
          Serial.print(poorQuality, DEC);
          Serial.print(" Attention: ");
          Serial.print(attention , DEC);
          Serial.print(" Meditation: "); // added
          Serial.print(meditation, DEC); //added
          
          Serial.print(" Time since last packet: ");
          Serial.print(millis() - lastReceivedPacket, DEC);
          lastReceivedPacket = millis();
          Serial.print("\n");
          
          
// How the Servo's angle increases or decreases -------------------------------------

if(poorQuality == 0){
          
          if (meditation > servo1Degrees){  //tesing meditation 
            
            servo1Degrees=(servo1Degrees+3);
            servo1.write(servo1Degrees);
            Serial.print("Meditation Up - Servo Degrees: ");
            Serial.print(servo1Degrees);
            Serial.print("\n");
                  
            }
          if(meditation <= servo1Degrees){  //tesing meditation 
            servo1Degrees=(servo1Degrees-3);
            servo1.write(servo1Degrees);
            Serial.print("Meditation Down - Servo Degrees: ");
            Serial.print(servo1Degrees);
            Serial.print("\n");
            
          } // end meditation testing
          
          
           if (attention > servo2Degrees){  //tesing attention 
            
            servo2Degrees=(servo2Degrees+3);
            servo2.write(servo2Degrees);
            Serial.print("Attention Up - Servo Degrees: ");
            Serial.print(servo2Degrees);
            Serial.print("\n");
                  
            }
            
          if(attention <= servo2Degrees){  //tesing attention 
            servo2Degrees=(servo2Degrees-3);
            servo2.write(servo2Degrees);
            Serial.print("Attention Down - Servo Degrees: ");
            Serial.print(servo2Degrees);
            Serial.print("\n");
            
          } // end attention testing
        
        
} else {
  
       servo1Degrees=0;
       servo2Degrees=0;
       servo1.write(servo1Degrees);
       servo2.write(servo2Degrees);
       
       Serial.print("Poor connection, Servos set to 0 Degrees!!!");
       Serial.print("\n");
        } // end else
          
        }
#endif        
        bigPacket = false;        
      }
      else {
        // Checksum Error
      }  // end if else for checksum
    } // end if read 0xAA byte
  } // end if read 0xAA byte
}



