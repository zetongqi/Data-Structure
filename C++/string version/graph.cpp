#include "graph.h"

//constructer
graph::graph()
{
	this->head = NULL;
	this->portal = NULL;
}

//function mainly used for destorying a "Node" class's list(key component of the destructor)
//also used in "delete_vertex" to delete a "Node" class's linked list connect 
//to a deleted vertex(adjacency node)
//and used in "destory_all_edges" to destory all the "Node" class elements in a adjacency list
void graph::destory_list(Node *leaf)
{
	if (leaf != NULL)
	{
		if (leaf->next != NULL)
		{
			destory_list(leaf->next);
			delete leaf;
		}
	}
}

//checked
void graph::destory_all_edges(adjacency_node *node)
{
	if (node != NULL)
	{
		if (node->follow != NULL)
		{
			destory_all_edges(node->follow);
			destory_list(node->next);
		}
	}
}

//checked
void graph::destory_adjacency_list(adjacency_node *node)
{
	if (node != NULL)
	{
		if (node->follow != NULL)
		{
			destory_adjacency_list(node->follow);
			delete node;
		}
	}
}

//checked
graph::~graph()
{
	destory_all_edges(this->head);
	destory_adjacency_list(this->head);
}

//checked
void graph::add_vertex(adjacency_node *node, string key)
{
	if (node != NULL)
	{
		if (node->follow != NULL)
		{
			add_vertex(node->follow, key);
		}
		else
		{
			node->follow = new adjacency_node;
			node->follow->value = key;
			node->follow->next = NULL;
			node->follow->follow = NULL;
		}
	}
}

//checked
void graph::add_vertex(string key)
{
	if (head != NULL)
		add_vertex(head,key);
	else
	{
		head = new adjacency_node;
		head->value = key;
		head->follow = NULL;
		head->next = NULL;
	}
}

//checked
void graph::add_edge(Node *leaf, string y)
{
	if (leaf != NULL)
	{
		if (leaf->next != NULL)
			add_edge(leaf->next, y);
		else
		{
			leaf->next = new Node;
			leaf->next->value = y;
			leaf->next->next = NULL;
		}
	}
}

//add an edge between two vertices,can prevent user from adding an edge twice
void graph::add_edge(string x, string y)
{
	if (adjacent(x, y))
		return;
	Node *temp = private_search(x);
	if(temp != NULL)
		add_edge(temp, y);
	else
	{
		temp = new Node;
		temp->value = y;
		temp->next = NULL;
		portal->next = temp;
	}
	temp = private_search(y);
	if (temp != NULL)
		add_edge(temp,x);
	else
	{
		temp = new Node;
		temp->value = x;
		temp->next = NULL;
		portal->next = temp;
	}
}

//search from the adjacency node list
//return value: 1.the searched key's adjacency node's "->next" member(Node class in "linked_list.h")
//              2.the searched key's adjacency node address(stored in the member "portal")
Node* graph::private_search(adjacency_node *node,string key)
{
	if (node != NULL)
	{
		if (node->value == key)
		{
			this->portal = node;
			return node->next;
		}
		else
		{
			return private_search(node->follow, key);
		}
	}
	else return NULL;
}

//public version of private_search(search from the head)
Node* graph::private_search(string key)
{
	return private_search(head,key);
}

//checked
void graph::neighbor(Node *leaf)
{
	if (leaf != NULL)
	{
		cout <<leaf->value;
		if (leaf->next != NULL)
			cout << "---->";
		neighbor(leaf->next);
	}
}

//checked
void graph::neighbor(string key)
{
	Node *temp = private_search(key);
	cout << key << "---->";
	if (temp == NULL)
		cout << "NULL";
	neighbor(temp);
	cout << endl;
}

//checked
bool graph::adjacent(Node *leaf, string y)
{
	if (leaf != NULL)
	{
		if (leaf->value == y)
			return 1;
		else
			return adjacent(leaf->next, y);
	}
	else return 0;
}

//checked
bool graph::adjacent(string x, string y)
{
	return adjacent(private_search(x),y);
}

//delete a specific node in the linked list
void graph::delete_a_node(adjacency_node *node, Node *leaf, string key)
{
	if (leaf != NULL)
	{
		Node *x = leaf;
		Node *y = leaf->next;
		if (x->value == key)
		{
			node->next = x->next;
			delete x;
			return;
		}
		while (x != NULL && y != NULL && y->value != key)
		{
			x = x->next;
			y = y->next;
		}
		if (y != NULL && y->value == key && y->next != NULL)
		{
			x->next = y->next;
			delete y;
			return;
		}
		if (y != NULL && y->value == key && y->next == NULL)
		{
			x->next = NULL;
			delete y;
			return;
		}
	}
}

//delete an ad_node
void graph::delete_an_ad_node(adjacency_node *node, string key)
{
	if (node != NULL)
	{
		adjacency_node *x = node;
		adjacency_node *y = node->follow;
		if (x->value == key)
		{
			this->head = x->follow;
			delete x;
			return;
		}
		while (y != NULL && y->value != key)
		{
			x = x->follow;
			y = y->follow;
		}
		if (y != NULL && y->value == key && y->follow != NULL)
		{
			x->follow = y->follow;
			delete y;
			return;
		}
		if (y != NULL && y->value == key && y->follow != NULL)
		{
			x->follow = NULL;
			delete y;
			return;
		}
	}
}

//delete one Node from all linked lists
void graph::delete_node_from_lists(adjacency_node *node, string key)
{
	adjacency_node *temp = node;
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			delete_a_node(temp,temp->next, key);
		}
		temp = temp->follow;
	}
}

//private version: delete a vertex
void graph::delete_vertex(adjacency_node *node, string key)
{
	delete_node_from_lists(node, key);
	destory_list(private_search(key));
	delete_an_ad_node(node, key);
}

//public version: delete a vertex
void graph::delete_vertex(string key)
{
	delete_vertex(head, key);
}

//print the entire graph(private version)
void graph::print(adjacency_node *node)
{
	if (node != NULL)
	{
		neighbor(node->value);
		print(node->follow);
	}
}

//print the entire graph(privatee version)
void graph::print()
{
	print(head);
	cout << endl;
}

//delete an edge between two vertices
void graph::delete_edge(string x, string y)
{
	Node *temp = private_search(x);
	delete_a_node(this->portal, temp, y);
	temp = private_search(y);
	delete_a_node(this->portal, temp, x);
}