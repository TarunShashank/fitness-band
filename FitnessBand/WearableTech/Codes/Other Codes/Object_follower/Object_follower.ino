 /*Note:
** In this program the robot will follow lighter color Object. 
1. DC Motors are Output devices
2. Light sensors are input devices so
3. For this program to execute properly you will need a normal room & lighter color object.
4. The object that you will use should be of lighter color, if you take a dark color object
   then this program will not execute properly as your light sensor will sense 
   darkness from the dark object. 

Pin Connection & Setup:
1. Connect wires of pin no: 10,11 to M1-IN socket of Motor driver.
2. Connect wires of pin no: 12,13 to M2-IN socket of Motor driver.
3. Connect the left motor wires to M1-OUT socket.
4. Connect the right motor wires to M2-OUT socket.
5. Sensors should be placed in front of the robot chassis in perpendicular position.
6. When sensors are placed in perpendicular position, it will bydefault sense darkness. 

*/

int l,r;                                  // initializing two variables l & r for storing inputs from Light sensors.
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


  if(r==HIGH && l==HIGH)                  // If both left & right sensor are sensing the object
  {                                       // the left & right motor will go forward
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else if(l==HIGH && r==LOW)             // If left sensor is sensing the object and right sensor is darkness
  {                                      // the left motor will go backward & right motor will go forward
    digitalWrite(10,LOW);               
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else if(l==LOW && r==HIGH)            // If left sensor is in darkness and right sensor is sensing the object. 
  {                                     // the left motor will go forward & right motor will go backward.
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
   }
    else                           // the last condition is, if both left & right light sensor are sensing darkness
  {                                // the left & right will stop. 
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
   }
}
    
