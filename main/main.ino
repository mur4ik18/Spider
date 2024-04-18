#include <Servo.h>
#include "Spider.h"
#include "Leg.h"
#include "Queue.h"
Servo ser;
Spider spider;

Queue* queue = createQueue();

void setup() {
    Serial.begin(9600);
    Serial.println("Start program");
    //inirt();

}

void inirt()
{
    spider.init(4);
    spider.addLeg(0,3, 2, 40, 60);
    spider.addLeg(1,4,5, 40, 60);
    spider.addLeg(2,6, 7, 40, 50);
    spider.addLeg(3,9, 8, 40, 80);
    spider.legs[0].goToZero();
    spider.legs[1].goToZero();
    spider.legs[2].goToZero();
    spider.legs[3].goToZero();
    delay(1000);
}

void sleep()
{
  for (int i = 0; i < 4; i++)
    {
        spider.legs[i].move_knee(-(-30 +spider.legs[i].get_knee_angle()));
        delay(1000);
    }
    spider.legs[0].goToZero();
    spider.legs[1].goToZero();
    spider.legs[2].goToZero();
    spider.legs[3].goToZero();
}

void gotoZero()
{
    spider.legs[0].goToZero();
    spider.legs[1].goToZero();
    spider.legs[2].goToZero();
    spider.legs[3].goToZero();
}

void wakeup()
{
    for (int i = 0; i < 4; i++)
    {
        spider.legs[i].move_knee(60);
        delay(100);
    }
    for (int i = 0; i < 4; i++)
    {
        spider.legs[i].move_knee(10);
        delay(100);
    }
}
void move_leg(int leg, int knee, int hip)
{
    spider.legs[leg].move_knee(knee);
    spider.legs[leg].move_joint(hip);
}

void run()
{
    int a0, b0;
    int a1, b1;
    int a2, b2;
    int a3, b3;

    a0 = spider.legs[0].get_joint_angle();
    b0 = spider.legs[0].get_knee_angle();

    a1 = spider.legs[1].get_joint_angle();
    b1 = spider.legs[1].get_knee_angle();

    a2 = spider.legs[2].get_joint_angle();
    b2 = spider.legs[2].get_knee_angle();

    a3 = spider.legs[3].get_joint_angle();
    b3 = spider.legs[3].get_knee_angle();

    move_leg(1, 0, 30);
    move_leg(3, 0, -30);
    move_leg(0, -10, 0);
    move_leg(2, -10, 0);

    move_leg(1, -40, -60);

    move_leg(1, 50, 0);
    for (int i = 0; i < 30; i++) {
        move_leg(3, 0, 1);
        move_leg(1, 0, 1);
    }
    move_leg(1, -10, 0);
    move_leg(0, 10, 0);
    move_leg(2, 10, 0);

    move_leg(0, 0, -30);
    move_leg(2, 0, 60);

    move_leg(0, -30, 60);
    move_leg(0, 50, 0);

    for (int i = 0; i < 30; i++) {
        move_leg(0, 0, -1);
        move_leg(2, 0, -1);
    }
    move_leg(0, -10, 0);

    move_leg(0, b0 - spider.legs[0].get_knee_angle(), a0 - spider.legs[0].get_joint_angle());
    move_leg(1, b1 - spider.legs[1].get_knee_angle(), a1 - spider.legs[1].get_joint_angle());
    move_leg(2, b2 - spider.legs[2].get_knee_angle(), a2 - spider.legs[2].get_joint_angle());
    move_leg(3, b3 - spider.legs[3].get_knee_angle(), a3 - spider.legs[3].get_joint_angle());
}

void go_forward()
{
    delay(1000);

    move_leg(0, -30, 40);
    move_leg(0, 30, 0);

    move_leg(1, -30, -40);
    move_leg(1, 30, 0);


    move_leg(2, -30, 60);
    move_leg(2, 30, 0);


    move_leg(3, -30, -60);
    move_leg(3, 30, 0);

    move_leg(0, 0, -40);
    move_leg(1, 0, 40);
}





char *command = "";
void loop() {
    
    if (Serial.available() > 0) {
        char c = Serial.read();
        if (c == ' ') {
            add(queue, command);
            command = "";
        } else {
            command += c;
        }
    }
}