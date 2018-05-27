#include "doubly_linked_list.h"

/*constructer*/
doubly_linked_list::doubly_linked_list()
{
    head = NULL;
    length = 0;
}

/*function for destructer*/
void doubly_linked_list::delete_doubly_linked_list(Bnode *leaf)
{
    if(leaf->next != NULL)
    {
        delete_doubly_linked_list(leaf->next);
        delete leaf;
    }
}

/*destructer*/
doubly_linked_list::~doubly_linked_list()
{
    delete_doubly_linked_list(head);
}

/*insert an element at the front of the list(private version)*/
void doubly_linked_list::insert_front(string key, Bnode *leaf)
{
    leaf->prev = new Bnode;
    leaf->prev->data = key;
    leaf->prev->next = leaf;
    leaf->prev->prev = NULL;
    this->head = leaf->prev;
}


/*insert at front(public version)*/
void doubly_linked_list::insert_front(string key)
{
    if(head != NULL)
        insert_front(key,head);
    else
    {
        head = new Bnode;
        head->data = key;
        head->prev = NULL;
        head->next = NULL;
        this->length++;
    }
}

/*insert at the back(private)*/
void doubly_linked_list::insert_back(string key, Bnode *leaf)
{
    if(leaf->next != NULL)
        insert_back(key,leaf->next);
    else
    {
        leaf->next = new Bnode;
        leaf->next->data = key;
        leaf->next->next = NULL;
        leaf->next->prev = leaf;
        this->length++;
    }
}

/*insert at the back(public)*/
void doubly_linked_list::insert_back(string key)
{
    if(head != NULL)
        insert_back(key,head);
    else
    {
        head = new Bnode;
        head->data = key;
        head->next = NULL;
        head->prev = NULL;
    }
}

/*search for an element,return the element's address*/
Bnode *doubly_linked_list::search(string key)
{
    Bnode *x = this->head;
    while(x != NULL && x->data != key)
        x = x->next;
    return x;
}

/*delete a node in the list(private)*/
void doubly_linked_list::delete_node(Bnode *leaf)
{
    if(leaf->prev != NULL)
        leaf->prev->next = leaf->next;
    else
        this->head = leaf->next;
    if(leaf->next != NULL)
        leaf->next->prev = leaf->prev;
}

/*delete a node in the list(public)*/
void doubly_linked_list::delete_node(string key)
{
    delete_node(search(key));
}

/*traversal*/
void doubly_linked_list::display(Bnode *leaf)
{
    if(leaf != NULL)
    {
        cout << leaf->data <<endl;
        display(leaf->next);
    }
}

/*print all the node's data(public)*/
void doubly_linked_list::display()
{
    display(head);
}
