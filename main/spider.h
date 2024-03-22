//
// Created by Alex Kotov on 20/03/2024.
//

#ifndef SPIDER_SPIDER_H
#define SPIDER_SPIDER_H
#include "Leg.h"

class Spider {
    public:
        Leg *legs;
        int numLegs;
        void init(int numLegs);
        void addLeg(int legNum,int coxaPin, int tibiaPin, int kneeAngle, int jointAngle);
};


#endif //SPIDER_SPIDER_H
