#ifndef QUEUE_H
#define QUEUE_H

// Include any necessary headers here

class Queue
{
public:
    int capacity, size;
    char** commands;
    void print(Queue* queue);
    int isEmpty();
    void add(char item[]);
    char* get();
    void free();

};

#endif // QUEUE_H