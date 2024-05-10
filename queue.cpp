#include "queue.h"
#include "Ds.h"
using namespace std;

template <typename T>
Queue<T>::Queue(int initialCapacity)
{
    data = new T[initialCapacity]; // create a new queue with initialCapacity
    frontIndex = 0;                // create frontIndex and set = 0
    rearIndex = 0;                 //  create rearIndex and set = 0
    size = 0;                      //"size" is used to keep track of the number of elements currently in the queue
    capacity = initialCapacity;    //"capacity", which refers to the maximum number of elements the queue can hold
}

// A destructor that calls the deleteDs Function
template <class T>
Queue<T>::~Queue()
{
    deleteDs();
}

// if the array(data) is not empty,
// then delete data and set data to nullptr
template <class T>
void Queue<T>::deleteDs()
{

    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }

    else
    {
    }
}

// If the queue is not full, the function prints the value
// that is being pushed onto the queue, and assigns the value to the current rearIndex of the queue
// It then increases the size of the queue by one.
// The rearIndex is updated by applying the modulo operator with the capacity,
// allowing the index to wrap around to the start of the array when it reaches the end.
template <typename T>
void Queue<T>::Push(T value)
{
    if (size == capacity)
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << value << " has been pushed to queue " << endl;

        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
    }
}

// If the queue is not empty then get the front index
template <typename T>
bool Queue<T>::front()
{
    if (size == 0)
    {
        cout << "Error: Cannot show front element! The queue is empty" << endl;
        return false;
    }
    else
    {

        T frontValue = data[frontIndex];
        cout << "The front value is: " << frontValue << endl;
        return true;
    }
}

// If the queue is not empty then get the rear index
template <typename T>
bool Queue<T>::back()
{
    if (size == 0)
    {
        cout << "Error: Cannot show back element! The queue is empty" << endl;
        return false;
    }
    T backValue = data[(rearIndex - 1 + capacity) % capacity];
    cout << "The back value is: " << backValue << endl;
    return true;
}

// If the queue is not empty then pop the front index
template <typename T>
void Queue<T>::Pop()
{
    if (size == 0)
    {
        cout << "Error: Cannot Pop! The queue is empty" << endl;
    }
    else
    {
        T frontValue = data[frontIndex];
        cout << "Popped value: " << frontValue << endl;
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }
}

// if the queue is not empty
// the function iterates through the queue array starting from the frontIndex
// and going to the rearIndex, using the modulo operator to handle the circular buffer implementation
// /It will print the elements in the order they were pushed into the queue,
// this is called FIFO (First In First Out) order.
template <typename T>
void Queue<T>::Print()
{
    if (size == 0)
    {
        cout << "Error: Cannot Print! The queue is empty" << endl;
    }
    else
    {
        int i;
        for (i = frontIndex; i < frontIndex + size; i++)
        {
            cout << data[i % capacity] << ":";
        }
        cout << endl;
    }
}

// to check if the queue is empty if yes the return true if not return false
template <typename T>
bool Queue<T>::isEmpty()
{
    if (size == 0)
    {

        cout << "Queue is empty" << endl;
        return true;
    }

    else
    {
        cout << "Queue is NOT empty" << endl;
        return false;
    }
}

template <typename T>
bool Queue<T>::search(T value)
{
    if (size == 0)
    {
        cout << "Error: Cannot search! The queue is empty" << endl;
        return false;
    }
    else
    {
        for (int i = frontIndex; i < frontIndex + size; i++)
        {
            if (data[i % capacity] == value)
            {
                cout << value << " found in the queue." << endl;
                return true;
            }
        }
        cout << value << " not found in the queue." << endl;
        return false;
    }
}

template <typename T>
void Queue<T>::sortAscending()
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (data[(frontIndex + j) % capacity] > data[(frontIndex + j + 1) % capacity])
            {
                T temp = data[(frontIndex + j) % capacity];
                data[(frontIndex + j) % capacity] = data[(frontIndex + j + 1) % capacity];
                data[(frontIndex + j + 1) % capacity] = temp;
            }
        }
    }
    cout << "Sorted Queue in ASCENDING order: ";
    for (int i = 0; i < size; i++)
    {
        cout << data[(frontIndex + i) % capacity] << ":";
    }
    cout << endl;
}

template <typename T>
void Queue<T>::sortDescending()
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (data[(frontIndex + j) % capacity] < data[(frontIndex + j + 1) % capacity])
            {
                T temp = data[(frontIndex + j) % capacity];
                data[(frontIndex + j) % capacity] = data[(frontIndex + j + 1) % capacity];
                data[(frontIndex + j + 1) % capacity] = temp;
            }
        }
    }
    cout << "Sorted Queue in DESCENDING order: ";
    for (int i = frontIndex; i < frontIndex + size; i++)
    {
        cout << data[i % capacity] << ":";
    }
    cout << endl;
}

// this function resizes the initialCapacity
// The function takes in a single input, the new capacity of the queue
// The function creates a new array of type T with the new capacity.
// It then copies the elements of the old queue array to the new array
// After copying it will delete the old array and assign the new data array
template <typename T>
void Queue<T>::resize(int newCapacity)
{
    T *newData = new T[newCapacity];
    int j = frontIndex;
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[j];
        j = (j + 1) % capacity;
    }
    delete[] data;
    data = newData;
    frontIndex = 0;
    rearIndex = size;
    capacity = newCapacity;
}

template class Queue<int>;
template class Queue<string>;