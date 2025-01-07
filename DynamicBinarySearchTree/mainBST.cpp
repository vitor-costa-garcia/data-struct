#include "BinarySearchTree.cpp"
#include <iostream>

using namespace std;

int main(){
    BinaryTree<int> t(10);

    t.insert(12);
    t.insert(16);
    t.insert(11);
    t.insert(7);
    t.insert(9);
    t.insert(3);

    t.show();
}
