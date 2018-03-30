 /*Note:
 ** In this program the robot will follow a white surface. 
1. DC Motors are Output devices.
2. Light sensors are input devices.
3. In this program you will need a black surface and on that black surface 
you have to stick a white tape.
4. The robot sensors will detect black and white surface and then move accordingly following the white line. 

Pin Connection:
1. Connect wires of pin no: 10,11 to M1-IN socket of Motor driver.
2. Connect wires of pin no: 12,13 to M2-IN socket of Motor driver.
3. Connect the left motor wires to M1-OUT socket.
4. Connect the right motor wires to M2-OUT socket.
*/

int l,r;                                   // initializing two variables l & r for storing inputs from Light sensors.
void setup()
{
  pinMode(10,OUTPUT);                     //10,11 for left motor
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);                     //12,13 for right motor
  pinMode(13,OUTPUT);
  pinMode(4,INPUT);                       // At pin no:4 we will connect the right light sensor which will act as an input device
  pinMode(3,INPUT);                       // At pin no:3 we will connect the left light sensor which will act as input device.
}
void loop()
{
  r=digitalRead(4);                       // Reading the input of right sensor and storing the value in pin no:4 of Arduino
  l=digitalRead(3);                       // Reading the input of left sensor and storing the value in pin no:3 of Arduino


  if(r==LOW && l==LOW)                  // If both left & right sensor are on black surface
  {                                     // the left & right motor will go forward
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else if(l==HIGH && r==LOW)             // If left sensor is on white surface and right sensor is on black surface
  {                                      // the left motor will go forward & right motor will go backward
    digitalWrite(10,LOW);               
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else if(l==LOW && r==HIGH)            // If left sensor is on white and right sensor is on black surface
  {                                     // the left motor will go backward & right motor will go forward.
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
   }
    else                           // the last condition is, if both left & right light sensor are on WHITE surface
  {                                // the left & right will stop. 
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
   }
}
    
