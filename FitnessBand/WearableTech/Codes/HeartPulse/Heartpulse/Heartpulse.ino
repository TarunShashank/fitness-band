
int ledPin=13;
int sensorPin=0;

float alpha=0.75;
int period=50;
float change=0.0;

void setup()
{
  // Built-in arduino board pin
  pinMode(ledPin,OUTPUT);

  Serial.begin(9600);
  Serial.print("Heartrate detection.\n");
  delay(100);
}

float max =0.0;

void loop()
{
  static float oldValue=1009;
  static float oldChange=0.2;

  // This is generic code provided with the board.
  int rawValue=analogRead(sensorPin);
  float value= alpha*oldValue +(1-alpha)* rawValue;
  change=value-oldValue;

  // Display data on the LED via a blip:
  // Empirically, if we detect a peak as being X% from
  // absolute max, we find the pulse even when amplitude
  // varies on the low side.
  
  // Reset max every time we find a new peak
  if (change >= max) {
    max= change;
    Serial.println("  |");
    digitalWrite(ledPin,1);
  } else {
    Serial.println("|");
    digitalWrite(ledPin,0);
  }
  // Slowly decay max for when sensor is moved around
  // but decay must be slower than time needed to hit
  // next heartbeat peak.
  max = max * 0.98;
  
  // Display debug data on the console
//  Serial.print(value);
//  Serial.print(", ");
//  Serial.print(change);
//  Serial.print(", ");
//  Serial.println(max);

  oldValue=value;
  oldChange=change;
  delay(period);
}
