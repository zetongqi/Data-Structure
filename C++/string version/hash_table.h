#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

/*a hash table class include basic insert,delete,search and traversal angorithms
uses the same Node class as the linked list class*/
class hash_table
{
private:
    int table_size = 26;
    Node* arr;
    void insert(string key, Node *leaf);
    void delete_node(string key,Node *leaf);
    void destory_list(Node *leaf);
    void destory_table();
    int hash_func(string key);
    Node *search(string key,Node *leaf);
    void display(Node *leaf);
public:
    void insert(string key);
    void delete_node(string key);
    hash_table();
    ~hash_table();
    Node *search(string key);
    void display();
};

#endif // HASH_TABLE_H
