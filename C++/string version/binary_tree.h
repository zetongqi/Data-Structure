#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//a node class
class node
{
public:
    string key_value;
    node *left;
    node *right;
};

//a binary search tree class
class binary_tree
{
public:
    binary_tree();
    ~binary_tree();
    void insert(string key);
    node *search(string key);
    void destory_tree();
    void print();
    int height();
    string minimum();
    string maximum();
    node *delete_node(string key);
private:
    node *find_min(node *leaf);
    string maximum(node *leaf);
    string minimum(node *leaf);
    node *delete_node(node *leaf,string key);
    int height(node *leaf);
    void print(node *leaf);
    node *root;
    void destory_tree(node *leaf);
    void insert(string key,node *leaf);
    node *search(string key,node *leaf);
};

#endif // BINARY_TREE_H
