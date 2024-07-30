//
// Created by Alex Kotov on 20/03/2024.
//

#include "Leg.h"
#include <Servo.h>
#include <Arduino.h>

#include <Adafruit_PWMServoDriver.h>

void move(int address, int angle)
{
  pwm.setPWM(address, 0, SERVOMIN+((SERVOMAX/270)*angle));
}


void Leg::Leg(
            int coxa_address,
            bool coxa_direction,
            int femur_address,
            bool femur_direction,
            int tibia_address,
            bool tibia_diretion
)
{
  this->a_coxa = coxa_address;
  this->a_femur = femur_address;
  this->a_tibia = tibia_address;

  this->d_coxa = coxa_direction;
  this->d_femur = femur_direction;
  this->d_tibia = tibia_direction;

  this->coxaJoint = 0;
  this->femurJoint= 0;
  this->tibiaJoint= 0;
}



void Leg::move_coxa(int angle)
{
  move(a_coxa, angle);
}

void Leg::move_femur(int angle)
{
  move(a_femur, angle);
}

void Leg::move_tibia(int angle)
{
  move(a_tibia, angle);
}

