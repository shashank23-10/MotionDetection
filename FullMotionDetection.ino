#include<Servo.h>
#define pir 12 
#define ldr A4
#define res 12

Servo mymotor;

void setup()
{
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(ldr, INPUT);
  mymotor.attach(6);
}

void loop()
{
  int pir_value = digitalRead(pir);
  Serial.println(pir_value);
  float ldr_value = analogRead(ldr);
  Serial.println(ldr_value);
  if (pir_value == HIGH && ldr_value > 250){
    Serial.println("Motion Detected");
    mymotor.write(120);
    delay(1500);
  }
  else{
    Serial.println("No Motion Detected");
    mymotor.write(0);
    delay(1500);
  }
}
