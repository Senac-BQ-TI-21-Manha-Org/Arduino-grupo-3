#include <Servo.h>

int const btnReset = 2, btnOpen = 3;

int const timeToOpen = 15, openTime = 3; //Em segundos
int const servoOpen = 200, servoClose = 0;

int runningTime = 0;

Servo servoBase;

void setup() {
  pinMode(btnReset, INPUT_PULLUP);
  pinMode(btnOpen, INPUT_PULLUP);
  servoBase.attach(A0);
}

void loop() {
  delay(1);
  servoBase.write(0);
  runningTime = runningTime + 1;
  if (runningTime >= (timeToOpen * 100) || digitalRead(btnOpen) == LOW) {
    runningTime = 0;
    servoBase.write(servoOpen);
    delay(openTime * 1000);
    servoBase.write(servoClose);
  }
  if (digitalRead(btnReset) == LOW)
    runningTime = 0;
}
