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

void Leg::move(int kA, int jA) {
    this->move_joint(jA);
    this->move_knee(kA);
}


void Leg::move_joint(double jointAngle) {
    Serial.print(this->jointAngle);
    int gotovalue = this->jointAngle + jointAngle;
    Serial.print(gotovalue);
    if (gotovalue <= 0)
    {
        gotovalue = 0;
    }
    for (int i = this->jointAngle; i >= gotovalue; i--) {
        this->jointServo.write(i);
        this->jointAngle = i;
    }
    for (int i = this->jointAngle; i <= gotovalue; i++)
    {
        this->jointServo.write(i);
        this->jointAngle = i;
    }
}

void Leg::move_knee(double kA) {
    Serial.print(this->kneeAngle);
    int gotovalue = this->kneeAngle + kA;
    Serial.print(gotovalue);
    if (gotovalue <= 0)
    {
        gotovalue = 0;
    }
    for (int i = this->kneeAngle; i >= gotovalue; i--) {
        this->kneeServo.write(i);
        this->kneeAngle = i;
    }
    for (int i = this->kneeAngle; i <= gotovalue; i++)
    {
        this->kneeServo.write(i);
        this->kneeAngle = i;
    }
}

void Leg::goToZero() {
    this->jointServo.write(0-this->ijointAngle);
    this->kneeServo.write(0-this->ikneeAngle);
    this->jointAngle = this->jointAngle - this->ijointAngle;
    this->kneeAngle = this->kneeAngle - this->ikneeAngle;
}

int Leg::get_iknee_angle()
{
    return this->ikneeAngle;
}

int Leg::get_ijoint_angle()
{
    return this->ijointAngle;
}

int Leg::get_knee_angle()
{
    return this->kneeAngle;
}

int Leg::get_joint_angle()
{
    return this->jointAngle;
}

void Leg::move_smothely_joint(int angle)
{
    Serial.print(this->jointAngle);
    int gotovalue = this->jointAngle + angle;
    Serial.print(gotovalue);
    if (gotovalue <= 0)
    {
        gotovalue = 0;
    }
    for (int i = this->jointAngle; i >= gotovalue; i--) {
        delay(1);
        this->jointServo.write(i);
        this->jointAngle = i;
    }
    for (int i = this->jointAngle; i <= gotovalue; i++)
    {
        delay(1);
        this->jointServo.write(i);
        this->jointAngle = i;
    }
}

void Leg::move_smothely_knee(int angle)
{
    Serial.print(this->kneeAngle);
    int gotovalue = this->kneeAngle + angle;
    Serial.print(gotovalue);
    if (gotovalue <= 0)
    {
        gotovalue = 0;
    }
    for (int i = this->kneeAngle; i >= gotovalue; i--) {
        delay(5);
        this->kneeServo.write(i);
        this->kneeAngle = i;
    }
    for (int i = this->kneeAngle; i <= gotovalue; i++)
    {
        delay(5);
        this->kneeServo.write(i);
        this->kneeAngle = i;
    }
}

