/*
** In this program we will check that both the left & right motor should go forward.

Pin Connection:
1. Connect wires of pin no: 10,11 to M1-IN socket of Motor driver.
2. Connect wires of pin no: 12,13 to M2-IN socket of Motor driver.
3. Connect the left motor wires to M1-OUT socket.
4. Connect the right motor wires to M2-OUT socket.

Output: 
In this program the robot will go 
*Forward for 2 sec.
*Backward for 2 sec.
*Left for 2 sec.
*Right for 2 sec.
*Stop for 2 sec.
and then the program will execute from beginning. 

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


digitalWrite(10,LOW);      // Backward
digitalWrite(11,HIGH);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
delay(2000);

digitalWrite(10,LOW);       // LEFT
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
delay(2000);

digitalWrite(10,HIGH);        // RIGHT
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
delay(2000);

digitalWrite(10,HIGH);        // STOP
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
delay(2000);
}
}
