#include <SR04.h>

int trigPin = 12;
int echoPin = 11;
int motorPin = 3;
SR04 sr04 = SR04(echoPin, trigPin);  
long distance;
float factor;
int motorSpeed;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
  motorSpeed = 0;
  if(distance < 30){
    factor = distance / 30.0;
    motorSpeed = 255 - (factor * 255);
  }
  Serial.print(motorSpeed);
  Serial.println(" speed");
  analogWrite(motorPin, motorSpeed);
}
