#include "avlnode.h"

template< typename T >
AVLNode<T>::AVLNode( const T d )
    :right(0), left(0), parent(0), bal(0), data(d)
{
            
}

template< typename T >
AVLNode<T>* AVLNode<T>::getRight() const 
{
    return right;
}

template< typename T >
AVLNode<T>* AVLNode<T>::getLeft() const 
{
    return left;
}

template< typename T >
AVLNode<T>* AVLNode<T>::getParent() const 
{
    return parent;
}

template< typename T >
T AVLNode<T>::getData() const 
{
    return data;
}

template< typename T >
void AVLNode<T>::setRight(AVLNode<T> *node) 
{
    right = node;
    if (node)
        right->setParent(this);
}

template< typename T >
void AVLNode<T>::setLeft(AVLNode<T> *node) 
{
    left = node;
    if (node)
        left->setParent(this);
}

template< typename T >
void AVLNode<T>::setParent(AVLNode<T> *node) 
{
    parent = node;
}

template< typename T >
void AVLNode<T>::setData(T data) 
{
    this->data = data;
}

template class AVLNode<int>;
