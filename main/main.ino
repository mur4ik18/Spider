#include <Servo.h>
#include "spider.h"
#include "Leg.h"

Servo ser;
Spider spider;

void setup() {
    Serial.begin(9600);
    Serial.println("Start programe");
    inirt();
    delay(2000);
    //delay(5000);
    //check_legs();
    //delay(5000);
    wakeup();
    //delay(1000);
    //_forward();

    //delay(5000);
    //sleep();

}

void inirt()
{
    spider.init(4);
    spider.addLeg(0,2, 3, 40, 60);
    spider.addLeg(1,4, 5, 40, 60);
    spider.addLeg(2,6, 7, 40, 50);
    spider.addLeg(3,8, 9, 40, 80);
    spider.legs[0].goToZero();
    spider.legs[1].goToZero();
    spider.legs[2].goToZero();
    spider.legs[3].goToZero();
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

void wakeup()
{
    for (int i = 0; i < 4; i++)
    {
        spider.legs[i].move_knee(60);
        delay(1000);
    }
    for (int i = 0; i < 4; i++)
    {
        spider.legs[i].move_knee(10);
        delay(1000);
    }
}
void move_leg(int leg, int knee, int hip)
{
    spider.legs[leg].move_knee(knee);
    delay(100);
    spider.legs[leg].move_joint(hip);
    delay(100);
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
void loop() {
    
}