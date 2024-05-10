#ifndef STACK_H
#define STACK_H
#include "Ds.h"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Stack : public DataStructure<T>
{
public:
// defining the size of the stack
#define SIZE 101

    T *st = new T[SIZE]; // creates the array of stack elements
    int top = -1;        // the top pointer to -1 which indicates the stack is empty
    T value;             // creates a template called value

    Stack();  // Default constructor
    ~Stack(); // Destructor

    bool isEmpty(); // function to return if stack is empty

    void Push(T); // function to push value to stack

    void Pop(); // function to pop value from stack

    void Print(); // function to print stack contents

    void showTop(); // function showTop

    bool search(T); // search function

    void sortAscending(); // sort ascending function

    void sortDescending(); // sort descending function

    void deleteDs(); // function to delete DS
};
#endif
