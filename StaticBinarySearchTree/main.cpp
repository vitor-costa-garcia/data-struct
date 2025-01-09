#include <iostream>
#include "BinarySearchTree.h"

using namespace std;
using namespace bt;

int main(){
    BinarySearchTree<float> t(2);
    t.insert(10);
    t.insert(15);
    t.insert(8);
    t.insert(6);
    t.insert(9);
    t.insert(12);
    t.insert(19);

    t.show();

    t.pop(10);

    t.show();
}