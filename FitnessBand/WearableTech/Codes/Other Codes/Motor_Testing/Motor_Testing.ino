/*
** In this program we will check whether left & right motor are going forward. The robot motors will keep on moving. 

Pin Connection:
1. Connect wires of pin no: 10,11 to M1-IN socket of Motor driver.
2. Connect wires of pin no: 12,13 to M2-IN socket of Motor driver.
3. Connect the left motor wires to M1-OUT socket.
4. Connect the right motor wires to M2-OUT socket.

Output: 
After uploading this program you may get three types of output.
1. Both motors will go forward.
2. One motor will go forward and other backward. 
3. Both the motors will go backward

4. If both your motors are moving forward then your program is running properly, 
5. If anyone of your motor is going backward then you have to swap 
the wires of that motor in the Mx-OUT section of the motor driver.

Eg: Suppose the color of your left motor wires are black & white and after connecting the wires in 
M1-OUT socket of motor driver the motor is moving backward then you will swap the wires in M1-OUT socket.
i.e You will place white wire in place of black and black wire in place of white.

*/

void setup(){
pinMode(10,OUTPUT);       //Pin No: 10, 11, 12, 13  are output pins
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}

void loop(){
digitalWrite(10,HIGH);     // Forward
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
delay(2000);
digitalWrite(11,HIGH);     // Backward
digitalWrite(10,LOW);
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
delay(2000);
}
