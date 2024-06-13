//
// Created by Alex Kotov on 20/03/2024.
//

#include "Leg.h"
#include <Servo.h>
#include <Arduino.h>

void Leg::init(int coxaPin, int tibiaPin, int kA, int jA) {
    this->jointServo.attach(coxaPin);
    this->kneeServo.attach(tibiaPin);
    this->ijointAngle = -jA;
    this->ikneeAngle = -kA;
    this->jointAngle = 0;
    this->kneeAngle = 0;
    this->jointServo.write(jointAngle);
    this->kneeServo.write(kneeAngle);
}





