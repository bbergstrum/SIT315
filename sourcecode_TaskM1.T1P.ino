int baseLine = 0;

int potentiometer = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  baseLine =70;
  int celcius = map(((analogRead(A0)-20)*3.04),0,1023,-40,125);
  digitalWrite(11, LOW);
  
  if (celcius > baseLine) {
    digitalWrite(13, 255);
    digitalWrite(11, 0);
    digitalWrite(10, 0);
    Serial.print("Temperature above baseline");
    Serial.print("RGB: ");            
    Serial.println("Red");
    
    delay(500); // Wait for tempSensor millisecond(s)
    digitalWrite(13, 0);
    digitalWrite(11, 255);
    digitalWrite(10, 0);
    Serial.println("RGB: blue");
    delay(500); // Wait for tempSensor millisecond(s)
    
    digitalWrite(13, 0);
    digitalWrite(11, 0);
    digitalWrite(10, 255);
    Serial.println("RGB: Green");
    
    delay(500); // Wait for tempSensor millisecond(s)
  } else {
    Serial.println("Temperature below baseline");
    delay(500);
  }
}
