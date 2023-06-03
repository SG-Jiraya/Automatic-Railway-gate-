#include<Servo.h>
#define BUZZER A0
int ir1 = 2;
int ir2 = 3;
int ir3 = 4;
int ir4 = 5;
Servo servo1;
Servo servo2;
#define TRIGGER_PIN 13
#define ECHO_PIN 12



void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo1.attach(11);
  servo2.attach(10);
  pinMode(ir2, INPUT);
  pinMode(ir1, INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(6, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

}
void closeGate()
{
  long duration, inches, cm;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH); // using pulsin function to determine total time
  cm = microsecondsToCentimeters(duration); // calling method
  delay(100);
  if(cm == 560){
    servo1.write(45);
    servo2.write(45);
  }
  else if(cm <= 560){
    servo1.write(90);
    servo2.write(90);
  }
  else{
    servo1.write(0);
    servo2.write(0);
  }
}

long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}

void loop() {

if (digitalRead(ir1) == HIGH && digitalRead(ir2) == LOW && digitalRead(ir3) == LOW && digitalRead(ir4) == LOW)
{
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  tone(BUZZER, 900);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  noTone(BUZZER);
}

else if (digitalRead(ir1) == HIGH && digitalRead(ir2) == HIGH && digitalRead(ir3) == LOW && digitalRead(ir4) == LOW){
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  tone(BUZZER, 900);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  noTone(BUZZER);
  closeGate();
  delay(500); // Wait 5 seconds before checking again
}
else if (digitalRead(ir1) == HIGH && digitalRead(ir2) == HIGH && digitalRead(ir3) == HIGH && digitalRead(ir4) == LOW){
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  tone(BUZZER, 900);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  noTone(BUZZER);
  closeGate();
  delay(500); // Wait 5 seconds before checking again
}
else if (digitalRead(ir1) == HIGH && digitalRead(ir2) == HIGH && digitalRead(ir3) == HIGH && digitalRead(ir4) == HIGH){
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  tone(BUZZER, 900);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  noTone(BUZZER);
  closeGate();
  delay(500); // Wait 5 seconds before checking again
}
else
{
  servo1.write(0);
  servo2.write(0);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  }
}
