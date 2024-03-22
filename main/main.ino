#include <Servo.h>
#include "spider.h"
#include "Leg.h"


Spider spider;

void setup() {
    inirt();
    delay(5000);
    stay();
}

void inirt()
{
    spider.init(4);
    spider.addLeg(0,2, 3, 40, 60);
    spider.addLeg(1,4, 5, 40, 60);
    spider.addLeg(2,6, 7, 40, 30);
    spider.addLeg(3,8, 9, 40, 100);
    spider.legs[0].goToZero();
    spider.legs[1].goToZero();
    spider.legs[2].goToZero();
    spider.legs[3].goToZero();
}
void stay()
{
    spider.legs[0].move_knee(120);
    spider.legs[1].move_knee(120);
    spider.legs[2].move_knee(120);
    spider.legs[3].move_knee(120);
}
void loop() {
    
}