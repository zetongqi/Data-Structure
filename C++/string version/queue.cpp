#include "queue.h"

queue::queue(unsigned int size)
{
    this->max_size = size;
    this->head = NULL;
    this->tail = NULL;
    this->queue_size = 0;
}

void queue::destory_all(Qnode *leaf)
{
    if(leaf->next != NULL)
    {
        destory_all(leaf->next);
        delete leaf;
    }
}

queue::~queue()
{
    destory_all(head);
}

void queue::enqueue(string key,Qnode *leaf)
{
   if(this->queue_size < this->max_size)
   {
       if(leaf->next != NULL)
           enqueue(key,leaf->next);
       else
       {
           leaf->next = new Qnode;
           leaf->next->data = key;
           leaf->next->next = NULL;
           leaf->next->prev = leaf;
           this->tail = leaf->next;
           this->queue_size++;
       }
   }
   else
   {
       this->queue_overflow_flag = 1;
       cout << "warning:queue overfolw !" << endl;
   }
}

void queue::enqueue(string key)
{
    if(head != NULL)
        enqueue(key,head);
    else
    {
        head = new Qnode;
        head->data = key;
        head->next = NULL;
        head->prev = NULL;
        this->queue_size++;
    }
}

void queue::dequeue()
{
    if(this->queue_size != 0)
    {
        Qnode *temp = head;
        head = head->next;
        head->next->prev = NULL;
        delete temp;
        this->queue_size--;
        if(this->queue_size < this->max_size)
        {
            this->queue_overflow_flag = 0;
        }
    }
    else
    {
        cout << "warning:queue underflow !" << endl;
    }
}

void queue::display(Qnode *leaf)
{
    if(leaf != NULL)
    {
        cout << leaf->data <<endl;
        display(leaf->next);
    }
}

void queue::display()
{
    display(this->head);
}
