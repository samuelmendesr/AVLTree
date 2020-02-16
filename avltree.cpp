#include <iostream>
#include "avltree.h"

using std::cout;
using std::endl;

AVLTree::AVLTree()
{
    root = 0;
}

AVLTree::~AVLTree()
{
    clear(root);
}

void AVLTree::insert(int data)
{
    if( isEmpty() ) {
        AVLNode<int> *newNode = new AVLNode<int>(data);
        root = newNode;
    }
    else {
        insert(root, data);
        root = balance(root);
    }
}

void AVLTree::preorder()
{
    int x = analyseBal(root);
    preorder(root);
}

void AVLTree::inorder()
{
    inorder(root);
}

void AVLTree::postorder()
{
    postorder(root);
}

void AVLTree::remove(int data)
{
    AVLNode<int>* node = find(root, data);
    
    if (node) {
        remove(node);
        root = balance(root);
    }
}

bool AVLTree::search(int data)
{
    return find(root, data);
}

bool AVLTree::isEmpty()
{
    return root == 0;
}

void AVLTree::insert(AVLNode<int>* node, int data)
{
    if( data > node->getData() ) {
        
        if( node->getRight() == 0 ) {
            AVLNode<int> *newNode = new AVLNode<int>(data);
            node->setRight(newNode);
        }
        else
            insert(node->getRight(), data);
    }
    else if( data < node->getData() ) {
        
        if( node->getLeft() == 0 ) {
            AVLNode<int> *newNode = new AVLNode<int>(data);
            node->setLeft(newNode);
        }
        else
            insert(node->getLeft(), data);
    }
}

void AVLTree::preorder(AVLNode<int>* node)
{
    if(node != 0) {
        cout << node->getData();
        if ( node->getParent() )
            cout << "<-" << node->getParent()->getData();
        cout << endl;
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}

void AVLTree::inorder(AVLNode<int> *node)
{
    if(node != 0) {
        inorder(node->getLeft());
        cout << node->getData() << endl;
        inorder(node->getRight());
    }
}

void AVLTree::postorder(AVLNode<int> *node)
{
    if(node != 0) {
        postorder(node->getLeft());
        postorder(node->getRight());
        cout << node->getData() << endl;
    }
}

void AVLTree::remove(AVLNode<int> *node)
{    
    if ( node->getLeft() && node->getRight() ) {
        
        AVLNode<int> *min = findMin( node->getRight() );
        
        node->setData(min->getData());
        min->getParent()->setRight( min->getRight() );
        //remove(min);
    }
    else {
        void (AVLNode<int>::*setChild)(AVLNode<int> *node);
    
        if ( node->getParent() ) {
            if ( node->getParent()->getRight() == node )
                setChild = &AVLNode<int>::setRight;
            else
                setChild = &AVLNode<int>::setLeft;
        }
        
        if ( node->getLeft() ) {
            if ( node->getParent() ) {
                (node->getParent()->*setChild)( node->getLeft() );
            }
            else {
                root = node->getLeft();
                root->setParent(0);
            }
            delete node;
        }
        else if ( node->getRight() ) {
            if ( node->getParent() ) {
                (node->getParent()->*setChild)( node->getRight() );
            }
            else {
                root = node->getRight();
                root->setParent(0);
            }
            delete node;
        }
        else {
            if ( node->getParent() )
                (node->getParent()->*setChild)(0);
            else
                root = 0;
            delete node;
        }
    }
}

AVLNode<int>* AVLTree::find(AVLNode<int> *node, int data)
{    
    if (node) {
        if (node->getData() == data)
            return node;
        else if (node->getData() < data)
            return find(node->getRight(), data);
        else if (node->getData() > data)
            return find(node->getLeft(), data);
    }
    else
        return 0;
}

AVLNode<int>* AVLTree::findMin(AVLNode<int>* node)
{
    if ( node->getLeft() )
        return findMin(node->getLeft());
    else
        return node;
}

AVLNode<int>* AVLTree::findMax(AVLNode<int>* node)
{
    if ( node->getRight() )
        return findMax(node->getRight());
    else
        return node;
}

void AVLTree::clear(AVLNode<int> *node)
{
    if(node != 0) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

AVLNode<int>* AVLTree::rr(AVLNode<int>* x)
{
    AVLNode<int>* y = x->getRight();
    x->setRight( y->getLeft() );
    y->setLeft(x);

    return y;
}

AVLNode<int>* AVLTree::ll(AVLNode<int>* x)
{
    AVLNode<int>* y = x->getLeft();
    x->setLeft( y->getRight() );
    y->setRight(x);
    
    return y;
}

AVLNode<int>* AVLTree::rl(AVLNode<int>* x)
{
    x->setRight( ll(x->getRight()) );
    
    return rr(x);
}

AVLNode<int>* AVLTree::lr(AVLNode<int>* x)
{
    x->setLeft( rr(x->getLeft()) );
    
    return ll(x);
}

int AVLTree::analyseBal(AVLNode<int>* node)
{
    if (node) {
        int left = analyseBal(node->getLeft());
        int right = analyseBal(node->getRight());
        
        node->bal = right - left;
        
        return (left > right)? (left + 1): (right + 1);
    }
    
    return 0;
}

AVLNode<int>* AVLTree::balance(AVLNode<int>* node)
{    
    analyseBal(node);
    
    if (node->getLeft())
        node->setLeft( balance(node->getLeft()) );
    if (node->getRight())
        node->setRight( balance(node->getRight()) );
    
    analyseBal(node);
    
    if ( (node->bal > 1) || (node->bal < -1) ) {
        
        AVLNode<int>* y;
        
        if (node->bal > 1) {
            if (node->getRight()->bal > 0)
                y = rr(node);
            else
                y = rl(node);
        }
        
        if (node->bal < -1) {
            if (node->getLeft()->bal < 0)
                y = ll(node);
            else
                y = lr(node);
        }
        
        if(node == root)
            y->setParent(0);

        node = y;
    }
    
    return node;
}
