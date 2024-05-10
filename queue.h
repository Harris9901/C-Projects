#ifndef QUEUE_H
#define QUEUE_H
#include "Ds.h"
#include <iostream>
#include <sstream>

template <typename T>
class Queue : public DataStructure<T>
{
private:
    T *data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;

public:
    Queue(int initialCapacity = 10); // A param Constructor that initialize the capacity to 10
    ~Queue();                        // Destructor
    void Push(T item);               // Adds the item to the queue
    bool front();                       // get the front of the queue
    bool back();                        // get the back of the queue
    void Pop();                      // removes the item from the queue
    void Print();                    // prints the queue
    bool isEmpty();                  // check if the queue is empty
    void resize(int newCapacity);    // resize the queue
    void deleteDs();                 // delete the queue
    bool search(T value);            // search the queue elements
    void sortDescending();
    void sortAscending();
};

#endif
