#ifndef QUEUE_H
#define QUEUE_H
// Include any necessary headers here
#include <Arduino.h>
class Queue
{
public:
    int capacity, size;
    char** commands;
    void createQueue();
    void print();
    int isEmpty();
    void add(char item[]);
    char* get();
    void free();

};

#endif // QUEUE_H