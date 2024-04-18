#include <iostream>
#include "Queue.h"
using namespace std;
Queue* createQueue()
{
    Queue* queue = new Queue();
    queue->size = 0;
    queue->capacity = 10;

    queue->commands = new char*[queue->capacity];
    return queue;
}
 
// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void add(Queue* queue, char item[])
{
    queue->commands[queue->size++] = item;
    cout << item << " enqueued to queue\n";
}

void print(Queue* queue)
{
    for (int i = 0; i < queue->size; i++) {
        cout << queue->commands[i] << " ";
    }
    cout << endl;
}
char* get(Queue* queue)
{
    char* command = queue->commands[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->commands[i] = queue->commands[i + 1];
    }
    queue->size--;
    return command;
}

void free(Queue* queue)
{
    delete[] queue->commands;
    delete queue;
}

int main() {
    Queue* queue = createQueue();
    string flow = "init_0_3_2_40_60 init_1_4_5_40_60 init_2_6_7_40_50 init_3_9_8_40_80 goto_zero_0 goto_zero_1 goto_zero_2 goto_zero_3 delay_1000";

    string command = "";
    for (int i = 0; flow[i] != '\0'; i++) {
        char c = flow[i];
        if (c == ' ') {
            add(queue, strdup(command.c_str()));
            command = "";
        } else {
            command += c;
        }
    }
    // Ajouter la dernière commande si elle n'est pas vide
    if (!command.empty()) {
        add(queue, strdup(command.c_str()));
    }

    print(queue);
    while (!isEmpty(queue)) {
        cout << get(queue) << " dequeued from queue\n";
    }

    free(queue);
    return 0;
}