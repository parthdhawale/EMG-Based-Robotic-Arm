#include <Servo.h>

#define THRESHOLD 150 //In order to determine the state of the hand (opened/closed)
#define EMGPIN 3 //Analog pin connected to Muscle Sensor V3 Board
#define FINGER1PIN 3 //Digital pin used by Little servo
#define FINGER2PIN 5 //Digital pin used by FINGER2 servo
#define FINGER3PIN 6 //Digital pin used by FINGER3 servo
#define FINGER4PIN 9 //Digital pin used by FINGER4 servo
#define FINGER5PIN 10 //Digital pin used by FINGER5 servo



//Constants used to open and close the fingers
//FINGER1 Corresponds to pinky finger and FINGER5 Corresponds to FINGER5 finger
//Based on EMG sensor placement on the left hand


#define FINGER1 1 
#define FINGER2 2
#define FINGER3 3
#define FINGER4 4
#define FINGER5 5


// Define servo fingers

Servo FINGER1;        
Servo FINGER2;         
Servo FINGER3;         
Servo FINGER4;         
Servo FINGER5;         

int finger;

// Motion routines for handopen and handclose

void openhand(){for(finger = 1; finger < 6; finger++){openFinger(finger);}}
void closehand(){for(finger = 1; finger < 6 ; finger++){closeFinger(finger);}}

// You have to rewrite properly the functions to open and close the fingers 
// In our assembly FINGER3 and FINGER4 fingers are opened when servo is at 170 degrees and the others when servo is at 0 degrees
// In our project MG996R servos were used


void openFinger(int finger){
  if(finger==FINGER1){FINGER1.write(0);} // FINGER1 finger
  else if(finger==FINGER2){FINGER2.write(170);}// FINGER2 finger
  else if(finger==FINGER3){FINGER3.write(170);}// FINGER3 finger
  else if(finger==FINGER4){FINGER4.write(170);}// FINGER4 finger
  else if(finger==FINGER5){FINGER5.write(0);}//FINGER5 finger
}


void closeFinger(int finger){
  if(finger==FINGER1){FINGER1.write(170);} // FINGER1 finger 
  else if(finger==FINGER2){FINGER2.write(0);}// FINGER2 finger
  else if(finger==FINGER3){FINGER3.write(0);}// FINGER3 finger
  else if(finger==FINGER4){FINGER4.write(0);}// FINGER4 finger
  else if(finger==FINGER5){FINGER5.write(170);}//FINGER5 finger
}


void setup(){

  //BAUDRATE set to 115200, You can change in based on your hardware
  Serial.begin(115200); 

  FINGER1.attach(FINGER1PIN);  // Set FINGER1 finger servo to digital pin 3
  FINGER2.attach(FINGER2PIN);  // Set FINGER2 finger servo to digital pin 5
  FINGER3.attach(FINGER3PIN);  // Set FINGER3 finger servo to digital pin 6
  FINGER4.attach(FINGER4PIN);  // Set FINGER4 finger servo to digital pin 9
  FINGER5.attach(FINGER5PIN);  // Set FINGER5 finger servo to digital pin 10

}//end setup

void loop() {

  //Sampling analog signal
  int value = analogRead(EMGPIN); 
  if(value>THRESHOLD) 
  //If the value of the sample is greater than THRESHOLD means that the hand has been closed
      {closehand();}
  else //Otherwise the hand is open
      {openhand();}
  Serial.println(value); 
  //Use the serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand
}
