//
// Created by Alex Kotov on 20/03/2024.
//

#include "Leg.h"
#include <Servo.h>

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
void Leg::move_joint(double jointAngle) {
    this->jointServo.write(jointAngle);
    this->ijointAngle += jointAngle;
    this->jointAngle += jointAngle;
}
void Leg::move_knee(double kA) {
    this->kneeServo.write(kA);
    this->ikneeAngle += kneeAngle;
    this->kneeAngle += kneeAngle;
}

void Leg::goToZero() {
    this->jointServo.write(0-this->ijointAngle);
    this->kneeServo.write(0-this->ikneeAngle);
    this->jointAngle = this->jointAngle - this->ijointAngle;
    this->kneeAngle = this->kneeAngle - this->ikneeAngle;
}