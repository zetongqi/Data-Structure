#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

//a special node class for adjacency list,used to represent header
class adjacency_node
{
public:
	string value;
	adjacency_node *follow;
	Node *next;
};

//a graph data structure implemented with adjacency list
class graph
{
private:
	//a private member variable used to store the head of the adjacency list
	adjacency_node *head;

	//a private member variable used to store the address of the searched key's adjacency node
	adjacency_node *portal;

	//delete a "Node" class linked list
	void destory_list(Node *leaf);

	//delete all the "Node" class in the adjacency list
	void destory_all_edges(adjacency_node *node);

	//delete the entire adjacency list
	void destory_adjacency_list(adjacency_node *node);
	Node *private_search(adjacency_node *node, string key);
	void add_vertex(adjacency_node *node,string key);
	void add_edge(Node *leaf,string y);
	void neighbor(Node *leaf);
	bool adjacent(Node *leaf, string y);

	//a function to delete a specific node in a linked list
	void delete_a_node(adjacency_node *node, Node *leaf, string key);

	//a function to delete an ad_node
	void delete_an_ad_node(adjacency_node *node, string key);

	//delete a node from all the linked lists
	void delete_node_from_lists(adjacency_node *node,string key);

	//delete a vertex
	void delete_vertex(adjacency_node *node, string key);

	//print the graph in the form of an adjacency list
	void print(adjacency_node *node);
public:
	graph();
	~graph();
	void add_vertex(string key);
	void add_edge(string x,string y);
	void neighbor(string key);
	bool adjacent(string x, string y);
	Node *private_search(string key);
	void delete_vertex(string key);
	void print();

	//delete an adge between two vertices
	void delete_edge(string x, string y);
};

#endif // GRAPH_H
