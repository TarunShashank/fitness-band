
#include <SoftwareSerial.h>
SoftwareSerial btserial(10, 11);
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include "I2Cdev.h"
#include "MPU6050.h"
char s;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az,axpre=0, aypre=0, azpre=0;
int count = 0;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO



#define LED_PIN 13
bool blinkState = false;
int value,hb,temp, time1, time2,c=0;
void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    //lcd.begin(16, 2);

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(9600);
    btserial.begin(9600);

    // initialize device
    Serial.println("Initializing PEDOMETER ...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "Pedometer connection successful" : "Pedometer connection failed");

    pinMode(LED_PIN, OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
}

void loop() {
    // read raw accel/gyro measurements from device
   if(btserial.available()>0)
   {
   char s=btserial.read(); 
    if(s=='S')
    {
      while(1)
      {
    
    Serial.print("Steps counted so far : ");
    Serial.println(EEPROM.read(100));
    
    
    axpre = ax; aypre = ay; azpre = az;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


    #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
        
        if((ax > (axpre + 2500))&&(ay > (aypre + 2500))||(az > (azpre + 2500))&&(ay > (aypre + 2500))||(ax > (axpre + 2500))&&(az > (azpre + 2500)))
        {
          count ++;
        }
        
        if(digitalRead(3) == LOW)
        {
          
        //printing X, Y, Z co-ordinates  
        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.print(gz);Serial.print("\t");
        Serial.println(count);
        }
        else
        {
          Serial.println();
          Serial.print("Total number of Steps : ");
          
          
          Serial.println(count);
          
          EEPROM.write(100, count);
          value = EEPROM.read(100); 
          Serial.print("Value Stored in EEPROM");
          Serial.println(value);
          if(digitalRead(A1)==HIGH)
          {
            c++;
            if(c==1)
            {
              time1=millis();
            }
            else if(c==6)
            {
              time2=millis();
              c=0;
          hb=time2-time1;
          hb=hb/5;
          hb=60000/hb;
            }
              
            while(digitalRead(A1)==HIGH);
          }
         
          temp= (5.0 * analogRead(A0) * 100.0) / 1024;
  btserial.print(value);
  btserial.print(",");
  btserial.print(value*0.3);
  btserial.print(",");
  btserial.print(value*0.3*0.061);
  btserial.print(",");
  btserial.print(hb);
  btserial.print(",");
  btserial.print(temp);
  btserial.println();        
      }
        
    #endif

    #ifdef OUTPUT_BINARY_ACCELGYRO
        Serial.write((uint8_t)(ax >> 8)); Serial.write((uint8_t)(ax & 0xFF));
        Serial.write((uint8_t)(ay >> 8)); Serial.write((uint8_t)(ay & 0xFF));
        Serial.write((uint8_t)(az >> 8)); Serial.write((uint8_t)(az & 0xFF));
        Serial.write((uint8_t)(gx >> 8)); Serial.write((uint8_t)(gx & 0xFF));
        Serial.write((uint8_t)(gy >> 8)); Serial.write((uint8_t)(gy & 0xFF));
        Serial.write((uint8_t)(gz >> 8)); Serial.write((uint8_t)(gz & 0xFF));
    #endif

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
    char s=btserial.read();
if(s=='P'||s=='R')
break;
        }
    }
else if(s=='P')
{
while(s!='S')
{
  char s=btserial.read();
  value=EEPROM.read(100);
}
}
else if(s=='R')
{
  count==0;
  EEPROM.write(100, count);
  value=EEPROM.read(100);

}
else
{
  value=EEPROM.read(100);
}
    }

}
