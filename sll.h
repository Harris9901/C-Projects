#ifndef SLL_H
#define SLL_H
#include "Ds.h"
#include <iostream>
#include <sstream>

template <class T>
class SLL : public DataStructure<T>
{
    struct Node // a structure called node
    {
        T data;                                     // creates a template var called data
        Node *next;                                 // creates a pointer called next
        Node(T data) : data(data), next(nullptr) {} // it takes a single input of template variable data and
                                                    // initializes the next pointer
    };

    // creates Node pointers
    Node *head;
    Node *tail;
    Node *pointer;

public:
    SLL();  // default constructor
    ~SLL(); // destructor
    // Add node to the end
    void push_back(T data);
    // Delete a node from the end
    void pop_back();
    // delete entire list
    void deleteDs();
    // Add node to the front
    void push_front(T data);
    // Delete a node from the front
    void pop_front();
    // Insert value after a node
    void insert_after(T data, T after_data);
    // Point to the beginning of the list
    void begin();
    // Get the value at a pointer and store it in var
    void get_value_at_pointer(T &var);
    // Move the pointer forward
    void next();
    // Check if ptr reached the end of list
    bool end();
    bool search(T value); // function to search the element in list
    // Prints the entire list
    void Print();
    void sortAscending(); //
    void sortDescending();
};

#endif