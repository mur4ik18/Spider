#include <Servo.h>
#include "Spider.h"
#include "Leg.h"
#include "Queue.h"
Servo ser;
Spider spider;

Queue queue;
void setup() {
    Serial.begin(9600);
    Serial.println("Start program");
    //inirt();
    queue.createQueue();
}


void loop() {
  // 0 - queue not empty
  // 1 - executing
  // 2 - run command detected
  int f0 = 0;
  int f2 = 0;

  // Read serial input
  if (Serial.available() > 0) {
      String flow = Serial.readString();
      String command = "";
      for (int i = 0; flow[i] != '\n'; i++) {
          char c = flow[i];
          if (c == ' ') {
              if (strcmp(command.c_str(), "run") == 0){
                Serial.println("Run detected, changing flag status\n");
                f2 = 1;
              }
              queue.add(strdup(command.c_str()));
              command = "";
          } else {
              command += c;
          }
      }
      //queue.print();
  }

    // run command detected and queue is not empty
    if (f2)
    {
      char* command = queue.get();
      while(strcmp(command, "run") != 0)
      {
        char *token = strtok(command, "_");



        if (strcmp(token, "init") == 0)
        {
          int num = atoi(strtok(NULL, "_"));
          spider.init(num);
        }
        else if (strcmp(token, "addleg") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          int port1 = atoi(strtok(NULL, "_"));
          int port2 = atoi(strtok(NULL, "_"));
          int angle1 = atoi(strtok(NULL, "_"));
          int angle2 = atoi(strtok(NULL, "_"));
          spider.addLeg(leg,port1, port2, angle1, angle2);
        }

        else if (strcmp(token, "gotoZero") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          spider.legs[leg].goToZero();
        }
        else if (strcmp(token, "delay") == 0)
        {
          int delay_time = atoi(strtok(NULL, "_"));
          delay(delay_time);
        }
        else if (strcmp(token, "sleep") == 0)
        {
          sleep();
        }
        else if (strcmp(token, "wakeup") == 0)
        {
          wakeup();
        }
        else if (strcmp(token, "move") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          int knee = atoi(strtok(NULL, "_"));
          int hip = atoi(strtok(NULL, "_"));
          spider.legs[leg].move_knee(knee);
          spider.legs[leg].move_joint(hip);
        }
        else if (strcmp(token, "getK") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          Serial.print("resK_");
          Serial.print(leg);
          Serial.print("_");
          Serial.println(spider.legs[leg].get_knee_angle());

        }
        else if (strcmp(token, "getJ") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          Serial.print("resJ_");
          Serial.print(leg);
          Serial.print("_");
          Serial.println(spider.legs[leg].get_joint_angle());
        } 
        command = queue.get();
      }
      f2 = 0;
    }
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
        spider.legs[i].move_knee(-(-30 +spider.legs[i].get_knee_angle())+60);
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