#include <Servo.h>
#include "spider/Spider.h"
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
        else if (strcmp(token, "smove") == 0)
        {
          int leg = atoi(strtok(NULL, "_"));
          int knee = atoi(strtok(NULL, "_"));
          int hip = atoi(strtok(NULL, "_"));
          spider.legs[leg].move_smothely_knee(knee);
          spider.legs[leg].move_smothely_joint(hip);
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
