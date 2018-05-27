#include "binary_tree.h"


/******************constructer**********************/
binary_tree::binary_tree()
{
    root = NULL;
}

/*******************destructer************************/
binary_tree::~binary_tree()
{
    destory_tree();
}

/******************destory_tree(public version)**********************/
void binary_tree::destory_tree()
{
    destory_tree(root);
}

/*******************destory_tree(private version)*******************/
void binary_tree::destory_tree(node *leaf)
{
    if(leaf != NULL)
    {
        destory_tree(leaf->left);
        destory_tree(leaf->right);
        delete leaf;
    }
}

/*********************insert function(public version)*************************/
void binary_tree::insert(string key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}

/**********************insert function(private version)************************/
void binary_tree::insert(string key, node *leaf)
{
  if(key < leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }
  else if(key >= leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

/*************************delete function(public)*****************************/
node *binary_tree::delete_node(string key)
{
    return delete_node(root,key);
}

/*************************delete function(private)****************************/
node *binary_tree::delete_node(node *leaf, string key)
{
    if(leaf == NULL)
        return leaf;
    else if(key < leaf->key_value)
        leaf->left = delete_node(leaf->left,key);
    else if(key > leaf->key_value)
        leaf->right = delete_node(leaf->right,key);
    else
    {
        //case 1:the node to be deleted has no child
        //then just simply delete the node(leaf)
        if(leaf->left==NULL && leaf->right == NULL)
        {
            delete leaf;
            leaf = NULL;
        }
        //case 2:the node has one child
        else if(leaf->left == NULL)
        {
            node *temp = leaf;
            leaf = leaf->right;
            delete temp;
        }
        else if(leaf->right == NULL)
        {
            node *temp = leaf;
            leaf = leaf->left;
            delete temp;
        }
        //case 3:the node has 3 children
        else
        {
            node *temp = find_min(leaf->right);
            leaf->key_value = temp->key_value;
            leaf->right = delete_node(leaf->right,temp->key_value);
        }
    }
    return leaf;
}

/************************search function(public version,search the entire tree)****************/
node *binary_tree::search(string key)
{
  return search(key, root);
}

/******************search function(private version,search from a certain node and below)************/
node *binary_tree::search(string key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key == leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

/****************find maximum(public)*****************/
string binary_tree::maximum()
{
    return maximum(root);
}

/****************find maximum(private)*****************/
string binary_tree::maximum(node *leaf)
{
    if(leaf->right == NULL)
        return leaf->key_value;
    else
        return maximum(leaf->right);
}

/****************find minimum(public)*****************/
string binary_tree::minimum()
{
    return minimum(root);
}

/****************find minimum(private)*****************/
string binary_tree::minimum(node *leaf)
{
    if(leaf->left == NULL)
        return leaf->key_value;
    else
        return minimum(leaf->left);
}

/***************return minimun leaf's address*********/
node *binary_tree::find_min(node *leaf)
{
    if(leaf->left == NULL)
        return leaf;
    else
        return find_min(leaf->left);
}

/*****************height public version****************/
int binary_tree::height()
{
    return height(root);
}

/*****************height private version:find the height of the tree****************/
int binary_tree::height(node *leaf)
{
    if(leaf == NULL)
        return -1;
    else
        return (max(height(leaf->left),height(leaf->right))+1);
}

/*************************print function(public version)**************************/
void binary_tree::print()
{
    print(root);
}

/*******************print function(private version:print the tree node keys)********************/
void binary_tree::print(node *leaf)
{
    if(leaf != NULL)
    {
        print(leaf -> left);
        print(leaf -> right);
        cout << leaf->key_value <<endl;
    }
}
