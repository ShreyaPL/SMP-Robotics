/*
This code is insired by David A. Mellis

Debouncing: When pushbuttons are pressed, they open and close multiple times at single press due to mechanical properties of the pushutton,
which can be interpreted by the software as multiple passes, creating abnormal responses at single press. Debouncing is a technique to remove this noise.

Code modified: july 15, 2024
Modified by: Shreya Lanjewar
*/

const int SwitchPin = 11;    // Pin connected to the button
const int ledPin = 13;      // Pin connected to the LED

int SwitchState;            // Current reading from the input pin
int lastSwitchState = LOW;  // Previous reading from the input pin

unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
const unsigned long debounceDelay = 50;  // Debounce delay in milliseconds

void setup() {
  pinMode(SwitchPin, INPUT);    // Initialize button pin as input
  pinMode(ledPin, OUTPUT);      // Initialize LED pin as output
  digitalWrite(ledPin, LOW);    // Turn off the LED initially
}

void loop() {
  int reading = digitalRead(SwitchPin);  // Read the state of the button

  // Check if the button state has changed
  if (reading != lastSwitchState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }

  // If the state has been stable for longer than the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed
    if (reading != buttonState) {
      SwitchState = reading;

      // Toggle the LED only if the button is pressed
      if (SwitchState == HIGH) {
        digitalWrite(ledPin, !digitalRead(ledPin));
      }
    }
  }

  // Save the reading as the last state
  lastSwitchState = reading;
}
