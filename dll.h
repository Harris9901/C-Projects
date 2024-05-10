#ifndef DLL_H
#define DLL_H
#include "Ds.h"
#include <iostream>
#include <sstream>


// This is a template class called "Node" 
// that stores a piece of data of type T, 
// as well as pointers to the next and previous 
// nodes in a doubly-linked list. The constructor 
// initializes the data to the value passed in, 
// and sets the next and prev pointers to nullptr.
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList : public DataStructure<T> 
{
     


private:
    Node<T>* head;//pointer points to the first element in the list.
    Node<T>* tail;//pointer points to the last element in the list.
    Node<T>* pointer;// pointer is used to iterate through the list and 
                     //traverse the list, pointing to the current element the user is operating on.

public:

    DoublyLinkedList();//is a constructor
    ~DoublyLinkedList();//is a destructor

    void push_back(T data);//add an element to the end of the list
    void pop_back();//remove an element to the end of the list
    void push_front(T data);//add an element from the beginning of the list
    void pop_front();//remove an element from the beginning of the list
    void insert_after(T data, T after_data);//inserts an element after a specific element in the list.
    void begin();//sets the pointer to the first element
    void beginR();//sets the pointer to the last element
    bool end();//checks if pointer is at the end of the list
    void get_value_at_pointer(T &var);// retrieves the value at the current position of pointer
    void next();//move the pointer to the next element
    void prev();//move the pointer to the previous element
    bool isEmpty();//checks if the list is empty
    void Print();//print the list from the start
    void PrintR();//print the list from the end,meaning in reverse order.
    void deleteDs();//deletes the list
    bool search(T value); // search element in the DLL
    void sortAscending();
    void sortDescending();
};

 
#endif