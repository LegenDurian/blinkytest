#include <Arduino.h>
#include <Servo.h>

const int ledPin = 13;    // Replace with the appropriate pin number where the LED is connected
int blinkInterval = 1000; // Default blinking interval in milliseconds

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char receivedChar = Serial.read();

    if (receivedChar == '1')
    {
      blinkInterval = 1000; // Set blinking interval to 1 second
    }
    else if (receivedChar == '2')
    {
      blinkInterval = 2000; // Set blinking interval to 2 seconds
    }
  }

  digitalWrite(ledPin, HIGH); // Turn on the LED
  delay(blinkInterval / 2);   // Half of the interval
  digitalWrite(ledPin, LOW);  // Turn off the LED
  delay(blinkInterval / 2);   // Half of the interval
}
