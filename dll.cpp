#include "dll.h"
// #include "Node.h"
#include "Ds.h"
#include <iostream>
using namespace std;

// template <typename T>
// Node<T>::Node(T data) {
//     this->data = data;
//     this->next = nullptr;
//     this->prev = nullptr;
// }

// This is the implementation of the constructor for the DoublyLinkedList
// class. The constructor initializes the head, tail, and pointer pointers
// to nullptr. It also calls the constructor of the base class
// "DataStructure" using the syntax DataStructure<T>().
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : DataStructure<T>()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->pointer = nullptr;
}

// Checks if the list is empty using the is_empty() function,
// and if it is not empty, it removes elements from the end of the list using
// the pop_back() function until the list is empty.
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    deleteDs();
}

// If the list is empty,the new node becomes the head and tail of the list
// Else,the function assigns the new node to be the next node of the current tail, and the
// previous node of the new node is set to the current tail.
// Then the tail pointer is updated to the new node.
//  This function is used to insert new element at the end of the list.
template <typename T>
void DoublyLinkedList<T>::push_back(T data)
{
    std::cout << data << " has been pushed to List " << std::endl;
    Node<T> *newNode = new Node<T>(data);
    if (tail == nullptr)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// If,it checks if the tail pointer is the same as the head pointer,
// which means there is only one element in the list. In this case,
// it deletes the tail node, sets the head and tail pointers to nullptr, and returns.
// Else, it creates a temporary pointer to store the current tail pointer,
// updates the tail pointer to the previous node, sets the next pointer of the new tail to nullptr,
// deletes the temporary pointer, and print a message that the tail has been deleted.
template <typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (tail == nullptr)
    {
        cout << "Error: Can't delete end node! The list is empty!" << endl;
        return;
    }
    if (tail == head)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node<T> *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    cout << "Tail has been deleted!" << endl;
    delete temp;
}

// If the head pointer is nullptr, it means that the list is empty, so the new node becomes
// the head and tail of the list.
//  Else, the function assigns the new node to be the previous node of the current
//  head, and the next node of the new node is set to the current head. Then the head
//  pointer is updated to the new node.
template <typename T>
void DoublyLinkedList<T>::push_front(T data)
{
    Node<T> *newNode = new Node<T>(data);
    cout << data << " has been pushed to the front of the list! " << endl;
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// If, it checks if the head pointer is the same as the tail pointer,
//  which means there is only one element in the list. In this case, it deletes
//  the head node, sets the head and tail pointers to nullptr, and returns.
//  Else, it creates a temporary pointer to store the current head pointer,
//  updates the head pointer to the next node, sets the prev pointer of the new
//  head to nullptr, deletes the temporary pointer
template <typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (head == nullptr)
    {
        cout << "Error: Can't delete front node! The list is empty!" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    head->prev = nullptr;
    cout << "Head has been deleted!" << endl;
    delete temp;
}

// Creates a pointer called current and initializes it to the head of the list,
// then it iterates over the list using a while loop until it finds the element that
// matches the data passed in, if the element is found, it creates a new node object with the after_data,
// If the current node is not the tail , it updates the next and prev pointers of the current node and
// the new node, to maintain the consistency of the doubly linked list. If the current node
// is the tail, it updates the tail pointer to the new node.

template <typename T>
void DoublyLinkedList<T>::insert_after(T data, T after_data)
{
    if (head == nullptr)
    {
        cout << "Error: You can't add after! The list is empty" << endl;
        return;
    }
    Node<T> *current = head;
    while (current != nullptr)
    {

        if (current->data == data)
        {

            cout << after_data << " has been pushed to List " << endl;
            Node<T> *new_node = new Node<T>(after_data);
            if (current->next != nullptr)
            {
                new_node->prev = current;
                new_node->next = current->next;
                current->next->prev = new_node;
                current->next = new_node;
            }

            if (current == tail)
            {
                tail = new_node;
            }
            break;
        }
        current = current->next;
    }
}

// The function sets the pointer to the head of the list, so that the user can iterate
// through the list starting from the first element. It is useful for traversing the list in a forward direction.
// It is used to set the pointer to the first element of the list, so user can traverse from the first element.
template <typename T>
void DoublyLinkedList<T>::begin()
{
    pointer = head;
}

// The function sets the pointer to the tail of the list, so that the user can iterate through the list
// starting from the last element. It is useful for traversing the list in a backward direction.
// It is used to set the pointer to the last element of the list, so user can traverse from the last element.
template <typename T>
void DoublyLinkedList<T>::beginR()
{
    pointer = tail;
}

// The function checks if the pointer is nullptr and returns a Boolean value.
//  If pointer is nullptr it means that the pointer is pointing to the end of the list,
//  so it returns true, otherwise it returns false.
template <typename T>
bool DoublyLinkedList<T>::end()
{
    return pointer == nullptr;
}

// The function moves the pointer to the next element in the list. It checks if the pointer is not nullptr,
// and if it is not, it updates the pointer to point to the next element in the list by assigning it to pointer->next.
template <typename T>
void DoublyLinkedList<T>::next()
{
    if (pointer != nullptr)
    {
        pointer = pointer->next;
    }
}

// The function moves the pointer to the previous element in the list. It checks if the pointer is not nullptr,
// and if it is not, it updates the pointer to point to the previous element in the list by assigning it to pointer->prev.
template <typename T>
void DoublyLinkedList<T>::prev()
{
    if (pointer != nullptr)
    {
        pointer = pointer->prev;
    }
}

// The function is used to get the value of the element that the pointer is currently pointing to and
// stores it in the variable passed as a reference. It first checks if the pointer is not nullptr, and
// if it is not, it assigns the value of the data member of the current node pointed by the pointer to
// the variable passed as a reference.
template <typename T>
void DoublyLinkedList<T>::get_value_at_pointer(T &var)
{
    if (pointer != nullptr)
    {
        var = pointer->data;
    }
}

// The function is used to check if the list is empty or not. It returns true if the head pointer is nullptr,
// which means that the list is empty, otherwise it returns false. It can be used to check if the list is empty
// or not, before calling any function that modifies the list.
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return head == nullptr;
}

// Else calls the begin() function to set the pointer to the head of the list. It uses a while loop to iterate
// through the list until the end() function returns true.
// Inside the while loop, it declares a variable of type T, and uses the get_value_at(T &var) function to
// get the value of the element that the pointer is currently pointing to and stores it in the variable.
// It then prints the value and calls the next() function to move the pointer to the next element in the list.
template <typename T>
void DoublyLinkedList<T>::Print()
{
    if (head == nullptr)
    {
        cout << "Error: Can't print! The list is empty." << endl;
        return;
    }
    begin();
    while (!end())
    {
        T value;
        get_value_at_pointer(value);
        cout << value << ":";
        next();
    }

    cout << endl;
}

// The function is used to delete all the elements of the list and free up the memory that was allocated for them.
// It uses a while loop to iterate through the list until the head pointer is nullptr.
// It creates a temporary pointer, sets it to the current head pointer and updates the head pointer to the next
// element in the list. Then it deletes the temporary pointer.

template <typename T>
void DoublyLinkedList<T>::deleteDs()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
bool DoublyLinkedList<T>::search(T value)
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "Value " << value << " found in the list!" << endl;
            return true;
        }
        current = current->next;
    }
    cout << "Value " << value << " not found in the list!" << endl;
    return false;
}

template <typename T>
void DoublyLinkedList<T>::sortAscending()
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }

        current = head;
        while (current != nullptr)
        {
            std::cout << current->data << ":";
            current = current->next;
        }
        cout << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::sortDescending()
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            if (current->data < current->next->data)
            {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    }
    Node<T> *current = head;
    current = head;
    while (current != nullptr)
    {
        std::cout << current->data << ":";
        current = current->next;
    }
}

// The function is used to print out the elements of the list in a reverse order.
// First, it checks if the tail pointer is nullptr, which means the list is empty,
// it prints an error message and returns.Else, it calls the beginR() function to
// set the pointer to the tail of the list. It uses a while loop to iterate through the
// list until the pointer is nullptr. Inside the while loop, it prints the data of the
// current node pointed by the pointer and calls the prev() function to move the pointer
// to the previous element in the list. It stops the loop when the pointer reaches the
// head of the list and breaks the loop.

template <typename T>
void DoublyLinkedList<T>::PrintR()
{
    if (tail == nullptr)
    {
        cout << "Error: Can't print! The list is empty." << endl;
        return;
    }
    beginR();
    while (pointer != nullptr)
    {
        cout << pointer->data << ":";
        if (pointer != head)
        {
            prev();
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<string>;
