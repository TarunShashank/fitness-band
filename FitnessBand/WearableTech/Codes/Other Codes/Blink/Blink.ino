//This is a simple blink program in which we will blink the LED connnected to Pin no:13.

void setup(){             //In the void setup method we define the pins that we 
pinMode(13,OUTPUT);      //want to use in the program

}

void loop(){            //In void loop method we work with pins used in 
digitalWrite(13,HIGH);  //LED 13 will be HIGH for 1 sec
delay(1000);     
digitalWrite(13,LOW);   //LED 13 will be low for 1 sec.
delay(1000);
}
