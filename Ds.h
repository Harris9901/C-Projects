#ifndef DS_H
#define DS_H
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class DataStructure
{

public:
    DataStructure();
    virtual bool isEmpty();
    virtual void Push(T);
    virtual void Pop();
    virtual void Print();
    virtual void showTop();
    virtual void deleteDs();
    virtual bool front();
    virtual bool back();
    virtual void resize(int newCapacity);
    virtual void push_back(T data);
    virtual void pop_back();
    virtual void push_front(T data);
    virtual void pop_front();
    virtual void insert_after(T data, T after_data);
    virtual void begin();
    virtual void beginR();
    virtual void get_value_at_pointer(T &var);
    virtual void next();
    virtual void prev();
    virtual bool end();
    virtual void PrintR();
    virtual void insert(T data);
    virtual void remove(T data);
    virtual void inOrderTraverse();
    virtual void postOrderTraverse();
    virtual void preOrderTraverse();
    virtual bool search(T data);
    virtual void sortAscending();
    virtual void sortDescending();

};

#endif