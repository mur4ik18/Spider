//
// Created by Alex Kotov on 20/03/2024.
//
#ifndef SPIDER_LEG_H
#define SPIDER_LEG_H
#include <Servo.h>

class Leg {
public:
  // length of each element
  // need to change
  static int coxa = 10;
  static int femur = 20;
  static int tibia = 20;
  // joints of each ..
  int coxaJoint, femurJoint, tibiaJoint;
  void Leg();


};


#endif //SPIDER_LEG_H
