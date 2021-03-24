/* Sweep

 by Dr Carl Strathearn
 Updated to include a photo resistor for light responsivity
 for a robotic eyes system that can respond to light and emotion
 
 by BARRAGAN <http://barraganstudio.com> 
 Updated and emotion enabled by: po lyu and ben anding
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
byte incomeByte; 
int pos = 0;    // variable to store the servo position 
int postarg=0;
int pulseRate;
int button = (A5);
int sensorValue = analogRead(A5);
void positiveemo();
void negativeemo();
void lightmode();

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
   // for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  //{                                  // in steps of 1 degree 
   // myservo.write(pos);              // tell servo to go to position in variable 'pos' 
   // delay(10);                       // waits 10ms for the servo to reach the position 
     pinMode(pos, OUTPUT);
  pinMode(button, INPUT); 
 
    if(Serial.available()>0)
  { 
   incomeByte = Serial.read();
   Serial.print(incomeByte);
   Serial.print("\n");
   
   if (incomeByte==0 || incomeByte==0) 
   {
    lightmode(); 
   } 
   if (incomeByte==48 || incomeByte==82) 
   {
    positiveemo(); 
   } 
   if (incomeByte==49 || incomeByte==76) { 
    negativeemo();    
  }
}
}

void lightmode () {
  int lightValue = analogRead(A0);
  lightValue = map (lightValue, 0, 1023, 0 ,180);
 
  if (analogRead(button) <20) postarg=lightValue;
   if (analogRead(button)>100) postarg=90;
  if(pos<postarg) pos++;
  if(pos>postarg) pos--;
  myservo.write(postarg);  
  Serial.println(sensorValue);
  delay(1); 
}

void positiveemo() 
{
    int pulseRate=random(20-24);
   int pos=random(50-55);  // random from (20-24) degrees to random (50-55) for pulsation sweep, random 10-20 pupil dilation frequency. 
   if(pulseRate>19){
   if(pos>10){
  int velocity=25+random(60);
   int pos=20+random(60);
   pos <= random(33,37); // random 33-37ms for the servo to reach the position for a smooth transition
   myservo.write(pos); // tell servo to go to position in variable 'pos'
   delay(rand);
  
   { 
     

  {                                
   myservo.write(20);              // tell servo to go to position in variable 'pos' 
    //delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   }
     
   }   }   }

   void negativeemo()

{
    int pulseRate=random(55-77);
   int pos=random(50-55);  // random from (55-77) degrees to random (50-55) for pulsation greater than 19, pupil dilation frequency 20 degrees plus random 60. 
   if(pulseRate>19){
   if(pos>10){
  int velocity=25+random(60);
   int pos=20+random(60);
   pos <= random(17,20); // random 17-20ms for the servo to reach the position for a smooth transition
   myservo.write(pos); // tell servo to go to position in variable 'pos'
   delay(rand);
  
  {                                
   myservo.write(20);              // tell servo to go to position in variable 'pos' 
    //delay(15);                       // waits 15ms for the servo to reach the position 
  } }}}

  
void loop() 
    
{ 
  if(Serial.available()>0)
  {
   incomeByte = Serial.read();
   Serial.print(incomeByte);
   Serial.print("\n");
   if (incomeByte==48) 
   {
    positiveemo(); 
   } 
   if (incomeByte==49) { 
    negativeemo();  }  

if(Serial.available()<0)
  { 
   incomeByte = Serial.read();
   if (incomeByte==0) 
   {
    lightmode(); }
   
  }}}
  
