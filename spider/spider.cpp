//
// Created by Alex Kotov on 20/03/2024.
//

#include "spider.h"
#include "Leg.h"

void Spider::init(int numLegs) {
    this->numLegs = numLegs;
    this->legs = new Leg[numLegs];
}

void Spider::addLeg(int legNum,int coxaPin, int tibiaPin, int kneeAngle, int jointAngle) {
    legs[legNum].init(coxaPin, tibiaPin, kneeAngle, jointAngle);
}