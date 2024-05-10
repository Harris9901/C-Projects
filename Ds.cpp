#include "Ds.h"

template <class T>
DataStructure<T>::DataStructure()
{
}

template <class T>
bool DataStructure<T>::isEmpty()
{

    cout << "empty data structure" << endl;
    return true;
}

template <class T>
void DataStructure<T>::Push(T value)
{
    cout << "push data structure" << endl;
}
template <class T>
void DataStructure<T>::Pop()
{
    cout << "pop data structure" << endl;
}

template <class T>
void DataStructure<T>::Print()
{
    cout << "print data structure" << endl;
}

template <class T>
void DataStructure<T>::showTop()
{
    cout << "show the top of data structure" << endl;
}

template <class T>
void DataStructure<T>::deleteDs()
{
    cout << "Data Structure deleted" << endl;
}

template <typename T>
bool DataStructure<T>::front()
{
    cout << "Front of DataStructure" << endl;
    return true;
}

// If the queue is not empty then get the rear index
template <typename T>
bool DataStructure<T>::back()
{
    cout << "Back of DataStructure" << endl;
    return true;
}

template <typename T>
void DataStructure<T>::resize(int newCapacity)
{
    cout << "Resize DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::push_back(T data)
{
    cout << "Push back DataStructure" << endl;
}
template <typename T>
void DataStructure<T>::pop_back()
{
    cout << "Pop back DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::push_front(T data)
{
    cout << "Push front DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::pop_front()
{
    cout << "Pop front DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::insert_after(T data, T after_data)
{
    cout << "insert After for DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::begin()
{
    cout << "Begin of DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::beginR()
{
    cout << "BeginR DataStructure " << endl;
}

template <typename T>
void DataStructure<T>::get_value_at_pointer(T &var)
{
    cout << "get value at pointer DataStructure" << endl;
}

template <typename T>
void DataStructure<T>::next()
{
    cout << "next DataStructure " << endl;
}

template <typename T>
void DataStructure<T>::prev()
{
    cout << "prev DataStructure " << endl;
}

template <typename T>
bool DataStructure<T>::end()
{
    cout << "End DataStructure " << endl;
    return true;
}

template <typename T>
void DataStructure<T>::PrintR()
{
    cout << "PrintR DataStructure" << endl;
}

template <class T>
void DataStructure<T>::insert(T data)
{
    cout << "insert DataStructure" << endl;
}

template <class T>
void DataStructure<T>::remove(T data)
{
    cout << "remove DataStructure" << endl;
}

template <class T>
void DataStructure<T>::inOrderTraverse()
{

    cout << "inOrderTraverse DataStructure" << endl;
}

template <class T>
void DataStructure<T>::preOrderTraverse()
{
    cout << "preOrderTraverse DataStructure" << endl;
}

template <class T>
void DataStructure<T>::postOrderTraverse()
{
    cout << "postOrderTraverse DataStructure" << endl;
}

template <class T>
bool DataStructure<T>::search(T data)
{
    cout << "search DataStructure" << endl;
    return true;
}

template <class T>
void DataStructure<T>::sortAscending()
{
    cout << "Sort dataStructure in ascending" << endl;
}

template <class T>
void DataStructure<T>::sortDescending()
{
    cout << "Sort data structure in descending" << endl;
}

template class DataStructure<int>;
template class DataStructure<string>;