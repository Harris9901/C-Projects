#ifndef BST_H
#define BST_H
#include "Ds.h"
#include <iostream>
#include <sstream>

template <class T>
class BST : public DataStructure<T>
{
    struct Node
    {
        T data;      // a template variable called data
        Node *left;  // a pointer called left
        Node *right; // a pointer called right
        // takes an input from data and initializes left and right to nullptr
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node *root; // creates a pointer called root

public:
    BST();                    // default constructor
    ~BST();                   // destructor
    void deleteTree(Node *node);
    void deleteDs();
    void clear();        
    void insert(T data);      /// inserts data into the tree
    void remove(T data);      // remove data from the tree
    Node *getRoot();          // return the root
    void inOrderTraverse();   // prints the tree inorder traversal
    void postOrderTraverse(); // prints the tree postorder traversal
    void preOrderTraverse();
    bool search(T data); // prints the tree preOrder traversal
    void sortAscending();  // sort ascending
    void sortDescending(); // sort descending

private:
    Node *insert(Node *node, T data);   // insert function that takes template variable called data
    Node *remove(Node *node, T data);   // remove function that takes template variable called data
    Node *findMin(Node *node);          // find the minimum node
    void inOrderTraverse(Node *node);   // prints the tree inorder traversal
    void preOrderTraverse(Node *node);  // prints the tree preorder traversal
    void postOrderTraverse(Node *node); // prints the tree postOrder traversal
    void reverseOrderTraverse(Node* node); // print in the reverse order
};

#endif