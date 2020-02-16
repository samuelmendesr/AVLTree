#include <iostream>
#include "avltree.h"

using std::cout;
using std::endl;

int main() {

    AVLTree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60); 
    tree.insert(70);
    tree.insert(80);
    tree.remove(60);
    //tree.insert(90);
    //tree.insert(100);

    
    tree.preorder();
    
    return 0;
}
