#include <Arduino.h>
#include <Poti.h>

Poti Poti1 {10, 255, true, 1500, 7600};

void setup() 
{
  Serial.begin(9600);
  pinMode(16, OUTPUT);

  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);
  delay(100);
  digitalWrite(17, LOW);
}

void loop() 
{
  Poti1.updatePotiValue();
  Serial.print("PotiValue: ");
  Serial.println(Poti1.getPotiValue());
  Serial.print("PotiValueNature: ");
  Serial.println(analogRead(10));
  Serial.println("");

  if (Poti1.potiUnderValue(100, 20))
  {
    digitalWrite(16, HIGH);
  } else
  {
    digitalWrite(16, LOW);
  }

  if (Poti1.potiUnderValue(200, 20))
  {
    digitalWrite(17, HIGH);
  } else
  {
    digitalWrite(17, LOW);
  }
}