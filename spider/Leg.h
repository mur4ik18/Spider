//
// Created by Alex Kotov on 20/03/2024.
//

#ifndef SPIDER_LEG_H
#define SPIDER_LEG_H
#include <Servo.h>

class Leg {
public:
  int coxa, femur, tibia;

  void init(int coxaPin, int tibiaPin, int kA, int jA);


};


#endif //SPIDER_LEG_H
