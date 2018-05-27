#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

class Qnode
{
public:
    string data;
    Qnode *next;
    Qnode *prev;
};

/*an FIFO data structure*/
class queue
{
private:
    Qnode *head;
    Qnode *tail;
    unsigned int max_size;
    unsigned int queue_size;
    bool queue_overflow_flag;
    void destory_all(Qnode *leaf);
    void enqueue(string key,Qnode *leaf);
    void display(Qnode *leaf);
public:
    queue(unsigned int size);
    ~queue();
    void enqueue(string key);
    void dequeue();
    unsigned int get_queue_size() {return this->queue_size;}
    bool if_overflow() {return this->queue_overflow_flag;}
    void display();
};

#endif // QUEUE_H
