/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int volt = 5;
int analogPin = 0; 
int val = 0;
// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; 
const long interval = 1000;

//Kaireje: pries LR iki galo -- OFF
//Desineje: pagal LR iki galo -- OFF

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(volt, OUTPUT);
  pinMode(analogPin, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = millis();
  val = analogRead(analogPin);     // read the input pin
  Serial.println(val);
    if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
        // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    }
    // set the LED with the ledState of the variable:
    digitalWrite(led, ledState);
    digitalWrite(volt, ledState);
   
}
