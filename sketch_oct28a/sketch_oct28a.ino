#include <Servo.h>

Servo servo_9;

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
 
void setup()
{
  Serial.begin(9600);
  servo_9.attach(5, 500, 2500);
  Serial.println("Lendo dados do sensor...");
}

int cm = 0;
#define ABERTO 5
#define  FECHADO 120

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(4, 3);
  delay(100);

  if (cm <= 5){
    Serial.println("Abrindo...");
    servo_9.write(ABERTO);
    delay(3000);
  }

  Serial.println("Fechando...");
  servo_9.write(FECHADO);
}