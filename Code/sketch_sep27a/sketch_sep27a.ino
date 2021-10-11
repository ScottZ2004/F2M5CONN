/**
  Rui Santos
  Complete project details at https://randomnerdtutorials.com/esp8266-nodemcu-hc-sr04-ultrasonic-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
**/

const int trigPin = D5; // 8;
const int echoPin = D6; // 7;
const int LedR = D3; // led red
const int LedB = D2; // led blue


//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;

int timeRunning = 0;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LedR, OUTPUT); // Sets the LedR as an Output
  pinMode(LedB, OUTPUT); // Sets the LedB as an Output
}

void loop() {
  // Clears the trigPin
  // SB
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;

  // Convert to inches
  

  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  
  delay(1000);
  checkBehindDesk();
  countTimeRunning();
}

void checkBehindDesk(){
  if(distanceCm < 100){
    digitalWrite(LedB, HIGH);
    digitalWrite(LedR, LOW);
  }else{
    digitalWrite(LedB, LOW);
    digitalWrite(LedR, HIGH);
  }
}

void countTimeRunning(){
  timeRunning += 1;
  Serial.print("Tijd in seconden: ");
  Serial.println(timeRunning);
}

//hier komt nog een void die gaat kijken of er langer dan ... seconden meer dan ... cm afstand is geweest tussen mens en Ultrason
