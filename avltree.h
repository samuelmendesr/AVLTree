#ifndef AVLTree_H
#define AVLTree_H

#include "avlnode.h"
 
class AVLTree
{
public:    
    AVLTree();
    ~AVLTree();
    void insert(int data);
    void preorder();
    void inorder();
    void postorder();
    void remove(int data);
    bool search(int data);
    
private:
    bool isEmpty();
    void insert(AVLNode<int>*, int);
    void preorder(AVLNode<int>*);
    void inorder(AVLNode<int>*);
    void postorder(AVLNode<int>*);
    void remove(AVLNode<int>*);
    AVLNode<int>* find(AVLNode<int>*, int);
    AVLNode<int>* findMin(AVLNode<int>*);
    AVLNode<int>* findMax(AVLNode<int>*);
    void clear(AVLNode<int>*);
    //avl
    AVLNode<int>* rr(AVLNode<int>*);
    AVLNode<int>* ll(AVLNode<int>*);
    AVLNode<int>* rl(AVLNode<int>*);
    AVLNode<int>* lr(AVLNode<int>*);
    int analyseBal(AVLNode<int>*);
    AVLNode<int>* balance(AVLNode<int>*);
    
    AVLNode<int> *root;

};

#endif
