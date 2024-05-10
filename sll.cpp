#include "sll.h"
#include "Ds.h"

// this constructor initializes the head,tail and pointer to nullptr
template <typename T>
SLL<T>::SLL() : DataStructure<T>()
{
    head = nullptr;
    tail = nullptr;
    pointer = nullptr;
}

// destructor that calls the deleteDs function
template <class T>
SLL<T>::~SLL()
{
    deleteDs();
}

// Add node to the end
// If the tail is nullptr, then creates a new node object with the passed data
// and sets both the head and tail pointers to point to this new Node.
// if the not then, sets the next pointer of the current tail Node to point
// to a new Node object created with the passed data
// then updates the tail pointer to point to this new node
template <typename T>
void SLL<T>::push_back(T data)
{
    cout << data << " has been pushed to the end of the list! " << endl;

    if (tail == nullptr)
    {
        tail = new Node(data);
        head = tail;
    }
    else
    {

        tail->next = new Node(data);
        tail = tail->next;
    }
}

// Delete a node from the end
// if head = tail then delete the head and set the head and tail to nullptr
// If there are more than one elements in the list,
// the function iterates through the list starting at the head pointer until it reaches the second to last node.
// then it deletes the tail node and set tail to second last node
// it then also sets the next pointer to nullptr.
template <typename T>
void SLL<T>::pop_back()
{
    if (head == nullptr)
    {
        cout << "Error: Can't delete end node! The list is empty!" << endl;
        return;
    }

    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }

    else
    {
        Node *current = head;
        while (current->next != tail)
            current = current->next;
        delete tail;
        tail = current;
        current->next = nullptr;

        cout << "Tail has been deleted!" << endl;
    }
}

// Add node to the front
// if head == nullptr then it creat a new node and set tail and head to point to the new node
// else the function creates a new Node with the passed data,
// sets the next pointer of the new node to the current head, and then updates
// the head pointer to point to this new Node
template <typename T>
void SLL<T>::push_front(T data)
{
    cout << data << " has been pushed to the front of the list! " << endl;
    if (head == nullptr)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *new_head = new Node(data);
        new_head->next = head;
        head = new_head;
    }
}

// Delete a node from the front
// if head == tail is pointing to the same node it then deletes the head and set the head and tail to nullptr
// else the function creates a new pointer new_head that points to the second element in the list,
// deletes the current head, and sets the head pointer to the new_head
template <typename T>
void SLL<T>::pop_front()
{
    if (head == nullptr)
    {
        cout << "Error: Can't delete front node! The list is empty!" << endl;
        return;
    }

    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *new_head = head->next;
        delete head;
        head = new_head;
        cout << "Head has been deleted!" << endl;
    }
}

// Insert value after a node
// The function iterates through the list starting at the head pointer, using a current pointer,
// until it reaches the node with the specific data value. When it finds that node,
// the function creates a new Node object with the passed data, sets the next pointer of the new node
// to the current next pointer, sets the next pointer of current node to point to the new node, and updates
// the tail pointer if the current node is the tail.
// then update current pointer to point to the next node
template <typename T>
void SLL<T>::insert_after(T data, T after_data)
{
    if (head == nullptr)
    {
        cout << "Error: You can't add after! The list is empty" << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {

        if (current->data == data)
        {

            cout << after_data << " has been pushed to List " << endl;
            Node *new_node = new Node(after_data);
            new_node->next = current->next;
            current->next = new_node;
            if (current == tail)
                tail = new_node;

            break;
        }
        current = current->next;
    }
}

// Point to the beginning of the list
// set pointer to the head
template <typename T>
void SLL<T>::begin()
{

    pointer = head;
}

// Get the value at a pointer and store it in var
// if the pointer is not nullptr then make var = pointer->data
template <typename T>
void SLL<T>::get_value_at_pointer(T &var)
{
    if (pointer != nullptr)
    {
        var = pointer->data;
    }
}

// Move the pointer forward
// if the pointer is not nullptr then make pointer = pointer->data
template <typename T>
void SLL<T>::next()
{
    if (pointer != nullptr)
    {
        pointer = pointer->next;
    }
}

template <typename T>
bool SLL<T>::search(T value)
{
    if (head == nullptr)
    {
        cout << "Error: Cannot search! The list is empty" << endl;
        return false;
    }
    else
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << value << " found in the list." << endl;
                return true;
            }
            current = current->next;
        }
        cout << value << " not found in the list." << endl;
        return false;
    }
}

// prints the list
// uses begin(), get_value_at_pointer(),end() and next() to print the list.
template <typename T>
void SLL<T>::Print()
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

// Check if ptr reached the end of list
template <typename T>
bool SLL<T>::end()
{
    return pointer == nullptr;
}

template <typename T>
void SLL<T>::sortAscending()
{
    if (head == nullptr)
    {
        cout << "Error: Can't sort list! The list is empty!" << endl;
        return;
    }

    bool swapped;
    Node *current;
    Node *last = nullptr;
    do
    {
        swapped = false;
        current = head;
        while (current->next != last)
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

        last = current;
    } while (swapped);

    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void SLL<T>::sortDescending()
{
    if (head == nullptr)
    {
        cout << "Error: Can't sort list! The list is empty!" << endl;
        return;
    }

    bool swapped;
    Node *current;
    Node *last = nullptr;
    do
    {
        swapped = false;
        current = head;
        while (current->next != last)
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

        last = current;
    } while (swapped);

    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// while head is not equal to nullptr create a pointer(temp) and assign it to head
// then update the head to point to the next node
// then delete the node temp is pointing
// then set head and tail null ptr
template <typename T>
void SLL<T>::deleteDs()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
}

template class SLL<int>;
template class SLL<string>;