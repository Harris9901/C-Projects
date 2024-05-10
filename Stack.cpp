#include "Stack.h"
#include "Ds.h"
template <class T>

#define SIZE 101

// int A[MAX_SIZE];
T *st = new T[SIZE];

int top = -1;

template <class T>
Stack<T>::Stack() : DataStructure<T>() {}

// If the top of the stack is -1, it means the stack is empty
// and the function prints "Stack is empty!" and returns true
// Otherwise, the function prints "Stack is NOT empty" and returns false.
template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
    {
        cout << "Stack is empty!" << endl;
        return true;
    }
    else
    {

        cout << "Stack is NOT empty" << endl;
        return false;
    }
}

// destructor that calls the deleteDs function
template <class T>
Stack<T>::~Stack()
{
    deleteDs();
}

// This function prints the value that is being pushed onto the stack and increments
// the top pointer by 1. The value is then inserted into the array at the index pointed to by top.
template <class T>
void Stack<T>::Push(T value)
{

    if (top == SIZE - 1)
    {
        cout << "Stack is full!\n";
    }
    else
    {
        cout << value << " has been pushed to stack " << endl;
        top++;
        st[top] = value; // insert the element at the index pointed at top
    }
}

// If the stack is not empty, the function prints the value that is
// being removed from the stack and decrements the top pointer by 1.
// It pops the element from the top of the stack. The popped element is not returned, it just prints it out.
template <class T>
void Stack<T>::Pop()
{
    if (top == -1)
    {
        cout << "Error: Cannot Pop! The stack is empty" << endl;
    }
    else
    {
        cout << "Popped value: " << st[top] << endl;
        top--;
    }
}

// /If the stack is not empty, the function iterates through
// the stack array starting from the top pointer and going down to the 0th element
// It will print the elements in the order they
// were pushed into the stack, this is called LIFO (Last In First Out) order.
template <class T>
void Stack<T>::Print()
{
    if (top == -1)
    {
        cout << "Error: Cannot Print! The stack is empty" << endl;
    }
    else
    {

        int i;

        for (i = top; i >= 0; i--)
        {
            cout << st[i] << ":";
        }

        cout << endl;
    }
}

// If the stack is not empty, the function prints the element at the top of the stack
// by using the value of the top pointer to index into the stack array.
// It returns the top element of the stack without removing it
template <class T>
void Stack<T>::showTop()
{
    if (top == -1)
    {
        cout << "Error: Cannot show Top! The stack is empty" << endl;
    }
    else
    {
        cout << "Element at top is: " << st[top] << "\n";
    }
}

template <class T>
bool Stack<T>::search(T value)
{
    if (top == -1)
    {
        cout << "Error: Cannot search! The stack is empty" << endl;
        return false;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            if (st[i] == value)
            {
                cout << value << " found in the stack." << endl;
                return true;
            }
        }
        cout << value << " not found in the stack." << endl;
        return false;
    }
}

template <class T>
void Stack<T>::sortAscending()
{
    if (top == -1)
    {
        cout << "Error: Cannot sort! The stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i < top; i++)
        {
            for (int j = 0; j < top - i; j++)
            {
                if (st[j] > st[j + 1])
                {
                    T temp = st[j];
                    st[j] = st[j + 1];
                    st[j + 1] = temp;
                }
            }
        }

        cout << "Sorted Stack in ascending order: ";
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }
}

template <class T>
void Stack<T>::sortDescending()
{
    if (top == -1)
    {
        cout << "Error: Cannot sort! The stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i < top; i++)
        {
            for (int j = 0; j < top - i; j++)
            {
                if (st[j] < st[j + 1])
                {
                    T temp = st[j];
                    st[j] = st[j + 1];
                    st[j + 1] = temp;
                }
            }
        }

        cout << "Sorted Stack in descending order: ";
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }
}

// If the array(st) is not equal to nullptr
// then delete the array and set it to nullptr
template <class T>
void Stack<T>::deleteDs()
{

    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }

    else
    {
    }
}

template class Stack<int>;
template class Stack<string>;