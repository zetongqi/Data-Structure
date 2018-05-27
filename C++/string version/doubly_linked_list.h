#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

/*a node class for doubly linked list,bi-directional node*/
class Bnode
{
public:
    string data;
    Bnode *prev;
    Bnode *next;
};

/*a doubly linked list class,able to add elements to the front of the list*/
class doubly_linked_list
{
private:
    Bnode *head;
    unsigned int length;
    void insert_front(string key,Bnode *leaf);
    void insert_back(string key,Bnode *leaf);
    void delete_doubly_linked_list(Bnode *leaf);
    void delete_node(Bnode *leaf);
    void display(Bnode *leaf);
public:
    doubly_linked_list();
    ~doubly_linked_list();
    void insert_front(string key);
    void insert_back(string key);
    Bnode *search(string key);
    void delete_node(string key);
    void display();
    unsigned int get_length() {return this->length;}
};

#endif // DOUBLY_LINKED_LIST_H
