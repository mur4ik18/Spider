//
// Created by Alex Kotov on 20/03/2024.
//
#ifndef SPIDER_LEG_H
#define SPIDER_LEG_H

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

class Leg {
public:
  // length of each element
  // need to change
  static int coxa = 10;
  static int femur = 20;
  static int tibia = 20;
  // addresses
  int a_coxa, a_femur, a_tibia;
  // direction
  bool d_coxa, d_femur, d_tibia;
  // joints position of each ..
  int coxaJoint, femurJoint, tibiaJoint;
  void Leg(
            int coxa_address,
            bool coxa_direction,
            int femur_address,
            bool femur_direction,
            int tibia_address,
            bool tibia_diretion
            );
  void move_coxa(int angle);
  void move_femur(int angle);
  void move_tibia(int angle);
  
};


#endif //SPIDER_LEG_H
