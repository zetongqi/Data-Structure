#include "hash_table.h"

/*constructer*/
hash_table::hash_table()
{
    this->arr = new Node[this->table_size];
    for(int i = 0;i < this->table_size;i++)
    {
        (arr + i)->next = NULL;
    }
}

/*delete the entire linked list,release memory*/
void hash_table::destory_list(Node *leaf)
{
    if(leaf->next != NULL)
    {
        delete leaf;
        destory_list(leaf->next);
    }

}

/*delete the entire hash table*/
void hash_table::destory_table()
{
    for(int i = 0;i < this->table_size;i++)
    {
        destory_list(arr + i);
    }
}

/*destructer*/
hash_table::~hash_table()
{
    destory_table();
}

/*return the string's hash address*/
int hash_table::hash_func(string key)
{
    int address = 0;
    for(string::iterator it = key.begin();it != key.end();it++)
    {
        address += (int) *it;
    }
    address = address % this->table_size;
    return address;
}

/*insert(private):insert an element into the hash table*/
void hash_table::insert(string key,Node *leaf)
{
    if(leaf->next != NULL)
    {
        insert(key,leaf->next);
    }
    else
    {
        leaf->next = new Node;
        leaf->next->value = key;
        leaf->next->next = NULL;
    }
}

/*insert(public)*/
void hash_table::insert(string key)
{
    insert(key,(arr + hash_func(key)));
}

/*delete(private):delete an node from the hash table*/
void hash_table::delete_node(string key, Node *leaf)
{
    if(leaf->next == NULL)
    {
        cout << "the linked list at this hash address is empty !" << endl;
    }
    else
    {
        if(leaf->next->value == key)
        {
            Node *temp = leaf->next;
            leaf->next = leaf->next->next;
            delete temp;
        }
        else
        {
            delete_node(key,leaf->next->next);
        }
    }
}

/*delete(public)*/
void hash_table::delete_node(string key)
{
    delete_node(key,arr + hash_func(key));
}

/*search(private):return the address of the searched key*/
Node *hash_table::search(string key, Node *leaf)
{
    Node *x = leaf;
    while(x != NULL && x->value != key)
        x = x->next;
    return x;
}

/*search(public)*/
Node *hash_table::search(string key)
{
    return search(key,(arr + hash_func(key))->next);
}

/*display(private):display a linked list*/
void hash_table::display(Node *leaf)
{
    if(leaf != NULL)
    {
        cout << leaf->value;
        if(leaf->next != NULL)
            cout<< "------->";
        display(leaf->next);
    }
}

/*display(public):display the entire hash table*/
void hash_table::display()
{
    for(int i = 0;i < this->table_size;i++)
    {
        cout << i;
        if(i < 10)
            cout << " ";
        cout << "------->";
        display((arr + i)->next);
        cout << endl;
    }
}
