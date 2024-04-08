//
// Created by Alex Kotov on 08/04/2024.
//

#ifndef SPIDER_COMPORT_H
#define SPIDER_COMPORT_H

#include <termios.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

class ComPort {
public:
    ComPort(char *port);
    int init();
    int write_message(char *message);
    char* read_message();
private:
    char *port;
    int fd;
};


#endif //SPIDER_COMPORT_H
