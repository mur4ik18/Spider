//
// Created by Alex Kotov on 20/03/2024.
//

#ifndef SPIDER_LEG_H
#define SPIDER_LEG_H
#include <Servo.h>

class Leg {
public:
    double coxa, tibia;
    double ijointAngle, ikneeAngle;
    double jointAngle, kneeAngle;
    Servo jointServo, kneeServo;
    void init(int coxaPin, int tibiaPin, int kA, int jA);
    void move_joint(double jointAngle);
    void move_knee(double kA);
    void goToZero();
};


#endif //SPIDER_LEG_H
