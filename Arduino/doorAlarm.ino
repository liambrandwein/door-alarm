#include <SoftwareSerial.h>

SoftwareSerial Bserial(2,3);

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

int openCounter;
int closeCounter;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  
  Serial.begin(9600);
  Bserial.begin(9600);

  openCounter = 0;
  closeCounter = 0;

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  if (distance <  107 || distance > 121) 
    openCounter++;
  else
    closeCounter++;

  if (openCounter >= 5) {
    Bserial.print((int)0);
    openCounter = 0;  
    closeCounter = 0;
  } else if (closeCounter >= 5) {
    Bserial.print((int)1);
    openCounter = 0;
    closeCounter = 0;
  }
  delay(300);
}
