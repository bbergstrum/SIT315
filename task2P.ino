volatile int LEDState = 0;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(2), toggleLED, CHANGE);
}

void loop()
{
  
}

void toggleLED() {
  LEDState = !LEDState;
  
  digitalWrite(13, LEDState);
  
  Serial.print("Button Activated.");
  
  Serial.println(LEDState);
}
