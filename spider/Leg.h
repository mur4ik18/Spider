//
// Created by Alex Kotov on 20/03/2024.
//

#ifndef SPIDER_LEG_H
#define SPIDER_LEG_H
#include <Servo.h>

class Leg {
public:
    int coxa, tibia;
    int ijointAngle, ikneeAngle;
    int jointAngle, kneeAngle;
    Servo jointServo, kneeServo;
    void init(int coxaPin, int tibiaPin, int kA, int jA);
    void move_joint(double jointAngle);
    void move_knee(double kA);
    void move(int kA, int jA);
    void goToZero();
    int get_iknee_angle();
    int get_ijoint_angle();
    int get_knee_angle();
    int get_joint_angle();
    void move_smothely_knee(int angle);
    void move_smothely_joint(int angle);
};


#endif //SPIDER_LEG_H
