//
// Created by Alex Kotov on 08/04/2024.
//
#include <iostream>
#include <unistd.h>

#include "ComPort.h"

int main(int argc, char *argv[])
{
    ComPort c = *new ComPort("/dev/tty.usbserial");
    if (c.init() == 1) return -1;
    char *message = (char *) malloc(25);
    message = "test";
    if(c.write_message(message) == -1) return -1;

    return 0;
}