#include <Servo.h>

int const btnReset = 2, btnOpen = 3;

int const timeToOpen = 15, openTime = 3; //Em segundos
int runningTime = 0;

Servo servoBase;

void setup() {
  Serial.begin(9600);
  pinMode(btnReset, INPUT_PULLUP);
  pinMode(btnOpen, INPUT_PULLUP);
  servoBase.attach(A0);
}

void loop() {
  delay(1);
  servoBase.write(0);
  runningTime = runningTime + 1;
  Serial.println(runningTime / 100);
  if (runningTime >= (timeToOpen * 100) || digitalRead(btnOpen) == LOW) {
    runningTime = 0;
    Serial.println("open");
    servoBase.write(200);
    delay(openTime * 1000);
    Serial.println("close");
    servoBase.write(0);
  }
  if (digitalRead(btnReset) == LOW)
    runningTime = 0;
}
