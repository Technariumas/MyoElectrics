/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor
The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph
Resources:
This program requires a Processing sketch to view the data in real time.
Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Pro 3.3V/8MHz
  AD8232 Heart Monitor Version: 1.0
This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
******************************************************************************/
int led = 13; //internal Arduino LED
int volt = 5; //enable pin for Mstim board
int threshold = 600;
int currentVoltage  = 0;         // current voltage value
int previousVoltage = 0;     // previous voltage value    
int interval = 5;
unsigned long previousMillis = 0; 

void setup() {
  // initialize the needed digital pins as outputs.
  pinMode(led, OUTPUT);  
  pinMode(volt, OUTPUT);
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -

}

void loop() {
  unsigned long currentMillis = millis(); //saves current time
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){ //checks if electrodes are not disconnected
    Serial.println('!');
  }
  else {
      currentVoltage = analogRead(A0); //reads the voltage from ECG board
      Serial.println(currentVoltage);    
    // send the value of analog input 0:
    if (currentMillis - previousMillis >= interval) {
      if (currentVoltage > threshold) {
      digitalWrite(led, HIGH); //switch internal LED on
      digitalWrite(volt, HIGH); //switch Mstim board on
        }
      else {
        digitalWrite(led, LOW);
        digitalWrite(volt, LOW);
        }
      }
      previousMillis = currentMillis;
      }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
