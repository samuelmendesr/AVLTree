#ifndef AVLNODE_H
#define AVLNODE_H

template< typename T > 
class AVLNode
{
public:    
    AVLNode( const T d );
    AVLNode<T>* getRight() const;
    AVLNode<T>* getLeft() const;
    AVLNode<T>* getParent() const;
    T getData() const;
    void setRight(AVLNode<T>*);
    void setLeft(AVLNode<T>*);
    void setParent(AVLNode<T>*);
    void setData(T);
    int bal;
    
private:
    AVLNode<T> *right;
    AVLNode<T> *left;
    AVLNode<T> *parent;
    T data;
};

#endif
