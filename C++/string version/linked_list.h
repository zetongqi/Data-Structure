#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

/* a Node class,with a string value and a pointer pointing to the next Node */
class Node
{
public:
    string value;
    Node *next;
    string get_value() {return this->value;}
};

/*  a singly linked list */
class linked_list
{
private:
    Node *head;
    unsigned int length;
    void insert_back(string key,Node *leaf);
    void display(Node *leaf);
    void delete_list(Node *leaf);
    void delete_node(string key,Node *leaf);
public:
    linked_list();
    ~linked_list();
    void insert_back(string key);
    unsigned int return_length(){return length;}
    void display();
    void delete_node(string key);
    Node *search(string key);
};

#endif // LINKED_LIST_H
