#include "Queue.h"
#include <Arduino.h>

void Queue::createQueue()
{
    this->size = 0;
    this->capacity = 10;
    this->commands = new char*[capacity];
}
 
// Queue is empty when size is 0
int Queue::isEmpty()
{
    return (this->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void Queue::add(char item[])
{
    this->commands[this->size++] = item;
    Serial.println(item);
    Serial.println(" enqueued to queue\n");
}

void Queue::print()
{
    for (int i = 0; i < this->size; i++) {
        Serial.println(this->commands[i]);
    }
    Serial.println();
}
char* Queue::get()
{
    char* command = this->commands[0];
    for (int i = 0; i < this->size - 1; i++) {
        this->commands[i] = this->commands[i + 1];
    }
    this->size--;
    return command;
}

void Queue::free()
{
    delete[] this->commands;
}
/*
int main() {
    Queue* queue = createQueue();
    string flow = "init_0_3_2_40_60 init_1_4_5_40_60 init_2_6_7_40_50 run init_3_9_8_40_80 goto_zero_0 goto_zero_1 goto_zero_2 goto_zero_3 delay_1000";

    string command = "";
    for (int i = 0; flow[i] != '\0'; i++) {
        char c = flow[i];
        if (c == ' ') {
            if (command == "run") {
                cout << "run command found" << endl;
                cout << command << endl;
            }
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
*/
