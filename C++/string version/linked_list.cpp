#include "linked_list.h"

/* class constructer */
linked_list::linked_list()
{
    head = NULL;
    length = 0;
}

/* delete_list:to delete the entire linked list,release memory */
void linked_list::delete_list(Node *leaf)
{
    if(leaf->next != NULL)
    {
        delete_list(leaf->next);
        delete leaf;
    }
}

/* destructer */
linked_list::~linked_list()
{
    delete_list(head);
}

/* public version:insert an element to the back of a list*/
void linked_list::insert_back(string key)
{
    if(head != NULL)
        insert_back(key,head);
    else
    {
        head = new Node;
        head->value = key;
        head->next = NULL;
        length++;
    }
}

/* private version of insert_back */
void linked_list::insert_back(string key, Node *leaf)
{
    if(leaf->next != NULL)
    {
        insert_back(key,leaf->next);
    }
    else
    {
        leaf->next = new Node;
        leaf->next->value = key;
        leaf->next->next = NULL;
        length++;
    }
}

/* public version:print all the elements */
void linked_list::display()
{
    display(head);
	cout << endl;
}

/* private version:print all the elements*/
void linked_list::display(Node *leaf)
{
	if (leaf != NULL)
	{
		cout << leaf->value;
		if (leaf->next != NULL)
			cout << "------->";
		display(leaf->next);
	}
}

/* private version:delete a node from the list */
//checked
void linked_list::delete_node(string key, Node *leaf)
{
	if (leaf != NULL)
	{
		Node *x = leaf;
		Node *y = leaf->next;
		if (x->value == key)
		{
			this->head->next = x->next;
			delete x;
		}
		while (y != NULL && y->value != key)
		{
			x = x->next;
			y = y->next;
		}
		if (y != NULL && y->value == key && y->next != NULL)
		{
			x->next = y->next;
			delete y;
		}
		if (y != NULL && y->value == key && y->next == NULL)
		{
			x->next = NULL;
			delete y;
		}
	}
}

/* public version:delete a node from the list*/
void linked_list::delete_node(string key)
{
    return delete_node(key,head);
}

/* search function:return the address of the searched key */
Node *linked_list::search(string key)
{
    Node *x = this->head;
    while(x != NULL && x->value != key)
        x = x->next;
    return x;
}
