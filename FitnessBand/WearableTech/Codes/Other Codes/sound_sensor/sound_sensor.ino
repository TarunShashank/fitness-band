/*
Note
** In this program the robot will run when the sound sensor INPUT is HIGH
& will stop when the sound sensor INPUT is LOW
*/
int s;                                 // initializing one variable "s" for storing input from sound sensor.
void setup() {
  pinMode(10,OUTPUT);                  //10, 11 for Left motor
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);                  // 12, 13 for right motor
  pinMode(13,OUTPUT);
  pinMode(5,INPUT);                   // At pin no:5 we connect the sound sensor which act as an input device

}

void loop() {
  s = digitalRead(5);                  // Reading the input of sound sensor and storing the value in pin no:5 of Arduino
  if(s==HIGH){                         // If sound sensor detects any sound or if the sound sensor is activated
  digitalWrite(10,HIGH);               // The motors will move forward
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  }
  else                              // The else condition will be if sound sensor becomes low
  {
  digitalWrite(10,HIGH);            // The motors will stop
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  }

}
