#include "BST.h"
#include "Ds.h"

template <class T>
// default constructor that initializes the root to nullptr
BST<T>::BST() : DataStructure<T>()
{
    root = nullptr;
}
template <class T>
BST<T>::~BST()
{
    deleteDs();
}

template <class T>
void BST<T>::deleteDs()
{

    clear();
}

template <class T>
bool BST<T>::search(T data)
{
    Node *current = root;

    while (current)
    {
        if (data == current->data)
        {
            cout << data << " has been found!" << endl;
            return true;
        }
        else if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    cout << "Error: " << data << " cannot be found!" << endl;
    return false;
}

template <class T>
void BST<T>::sortAscending()
{

    inOrderTraverse(root);
    cout << endl;
}

template <class T>
void BST<T>::sortDescending()
{

    reverseOrderTraverse(root);
    cout << endl;
}

// calls the private member function insert and pass the current root and value to be inserted.
template <class T>
void BST<T>::insert(T data)
{
    root = insert(root, data);

    cout << data << " has been inserted!" << endl;
}

// calls the private member function remove and pass the current root and value to be inserted.
template <class T>
void BST<T>::remove(T data)
{
    root = remove(root, data);
    cout << data << " has been removed!" << endl;
}

// return the root
template <class T>
typename BST<T>::Node *BST<T>::getRoot()
{
    cout << root->data << " is the root!" << endl;
    return root;
}

// call the private member function and pass the current root of the tree
template <class T>
void BST<T>::inOrderTraverse()
{

    inOrderTraverse(root);
    cout << endl;
}

// call the private member function and pass the current root of the tree
template <class T>
void BST<T>::preOrderTraverse()
{
    preOrderTraverse(root);
    cout << endl;
}

// call the private member function and pass the current root of the tree
template <class T>
void BST<T>::postOrderTraverse()
{
    postOrderTraverse(root);
    cout << endl;
}

// The function first checks if the passed node pointer is null,
// if it is, it creates a new node with the passed data and returns it. This is the base case for the recursion.
// If the passed data is less than the data stored in the node, it calls the function recursively on the left child of the node.
// If the passed data is greater than or equal to the data stored in the node,
// it calls the function recursively on the right child of the node.
template <class T>
typename BST<T>::Node *BST<T>::insert(Node *node, T data)
{
    if (!node)
    {
        return new Node(data);
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

// If the node has no children (is a leaf node), it is simply deleted
// If the node has one child, it is replaced with its child
// If the node has two children, the in-order successor (the smallest value in the right subtree)
// is found, the value of the node is replaced with that of the in-order successor, and the in-order successor is deleted.
// At the end, the function returns the node.
template <class T>
typename BST<T>::Node *BST<T>::remove(Node *node, T data)
{
    if (!node)
    {
        return nullptr;
    }
    else if (data < node->data)
    {
        node->left = remove(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = remove(node->right, data);
    }
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        else if (!node->left)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

// if node ==  nullptr, then return nullptr
// while node->left is nullptr, then update node to point to the left node
// then return node
template <class T>
typename BST<T>::Node *BST<T>::findMin(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// prints the node from left to root to then right trees
template <class T>
void BST<T>::inOrderTraverse(Node *node)
{
    if (node)
    {
        inOrderTraverse(node->left);
        cout << node->data << ":";
        inOrderTraverse(node->right);
    }
}

// prints the node from root to left then right trees
template <class T>
void BST<T>::preOrderTraverse(Node *node)
{
    if (node)
    {
        cout << node->data << ":";
        preOrderTraverse(node->left);
        preOrderTraverse(node->right);
    }
}

// prints from the lef to right and root tree
template <class T>
void BST<T>::postOrderTraverse(Node *node)
{
    if (node)
    {
        postOrderTraverse(node->left);
        postOrderTraverse(node->right);
        cout << node->data << ":";
    }
}

template <class T>
void BST<T>::reverseOrderTraverse(Node *node)
{
    if (node != nullptr)
    {
        reverseOrderTraverse(node->right);
        cout << node->data << ":";
        reverseOrderTraverse(node->left);
    }
}

template <class T>
void BST<T>::deleteTree(Node *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <class T>
void BST<T>::clear()
{
    deleteTree(root);
    root = nullptr;
}

template class BST<int>;
template class BST<string>;