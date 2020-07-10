#include <Servo.h>
#include <NewPing.h>


int trigPin = A1; // Trigger Pin connected to A1
int echoPin = A0; // Echo Pin connected to A0

int minPing = 5; // Setting the minimum Ping to 5 cm
int maxPing = 60; // Setting the maximum Ping to 60 cm
float duration, distance;

Servo myservo; // creating the servo object

   
void setup() // Defines the pin location for Servo signal & I/O for sensor.
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
 

}

void calc() // Calculates distance
{
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(6);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration*0.034/2;
  }

  
void loop() // Calls on the distance calculated. Control flow for which direction to move servo based on distance calculated from object.
{

  calc();
  myservo.write(90);
 
    if (distance <= maxPing  && distance >= 16)
    {
    myservo.write(0);
    } 
    else if (distance <= 15 && distance >= minPing)  
    {
      myservo.write(180);
    }
    else
    {
   delay(300);
     }
 }
