#ifndef JOINT_H
#define JOINT_H

#include <stdint.h>


struct Joint {
  uint16_t servomin = 150;
  uint16_t servomax = 600;
  uint8_t address;
  uint8_t angle;
  int8_t angle;
} joint;

#endif //JOINT_H
