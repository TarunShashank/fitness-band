 /*Note:
**In this program the Robot will move away from light source. 
1. DC Motors used in this program are generally Output devices
2. The light sensors used in this program are input devices
3. In this program you will need a dark room and a white light source. Eg: Mobile flash light. 
you have to stick a black insulation tape.
4. The robot will stay static when no light is incident on it.When light source is brought near the robot it will try moving away from the light source.

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


  if(r==HIGH && l==HIGH)                  // If both left & right sensor are sensing light
  {                                       // the left & right motor will go backward, thus moving away from light
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  else if(l==HIGH && r==LOW)             // If left sensor is sensing light and right sensor is in darkness
  {                                      // the left motor will go forward & right motor will go backward
    digitalWrite(10,HIGH);               
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  else if(l==LOW && r==HIGH)            // If left sensor is sensing light and right sensor is in darkness
  {                                     // the left motor will go backward & right motor will go forward.
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
   }
    else                           // the last condition is, if both left & right light sensor are in darkness
  {                                // the left & right will stop. 
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
   }
}
    /*The program for Photophia is same as Black Line Follower & Object Repeller, 
      only the surface and some condition are changed. */
