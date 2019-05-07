#include <NewPing.h>
#include <Servo.h>

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 500

NewPing sonar(trigPin,echoPin,MAX_DISTANCE);
int LED1 = 3;
int LED2 = 2;
Servo myservo;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  myservo.attach(9);

}

void loop() {
  int duration,jarak,posisi=0,i;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 jarak = (duration/2) / 29.1;
  Serial.print(jarak);
  Serial.println(" cm");

if(jarak<=30)
 {
   digitalWrite(LED1, LOW); 
   digitalWrite(LED2, HIGH); 
   myservo.write(180); 
   delay(450); 
   digitalWrite(LED2, LOW); 
   myservo.write(90);
   delay(450); 
   digitalWrite(LED2, HIGH); 
   myservo.write(0); 
   delay(450); 
   digitalWrite(LED2, LOW); 
   myservo.write(90); 
}

 else{ 
   digitalWrite(LED2, LOW); 
   digitalWrite(LED1, HIGH); 
   myservo.write(90);
 }
delay(450);
}
