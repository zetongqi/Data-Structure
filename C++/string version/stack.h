#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>

using namespace std;

/*An abstract stack*/
class stack
{
private:
    int stack_size_default = 128;
    vector<int> i_vec;
    vector<int>::iterator i_in = i_vec.begin();
    int size = 0;
    bool stack_full_flag = 0;
public:
    //push function
    void push(int &a)
    {
        if(size < stack_size_default)
        {
            i_vec.push_back(a);
            i_in++;
            size++;
        }
        if(size == 127)
            stack_full_flag = 1;
    }

    //bool function of stack overflow
    bool stack_full(){return stack_full_flag;}

    //pop function
    void pop(){i_vec.pop_back();i_in--;size--;}

    //copy a vector into the stack
    void copy(vector<int> &tar_vec)
    {
        for(int i = 0;i < stack_size_default;i++)
        {
            i_vec.push_back(tar_vec[i]);
            size++;
            i_in++;
        }
    }

    //return the element at the top
    int top_element(){return i_vec[size-1];}

    //return the current stack size
    int stack_size() {return this->size;}

    //print all the elements in the stack
    void print()
    {
        for(vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); it++)
            cout << *it << "    ";
        cout << endl;
    }
};

#endif // STACK_H
