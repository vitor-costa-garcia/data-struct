#include <iostream>
#include <cmath>
#include <algorithm>
#include "BinarySearchTree.h"

using namespace std;
using namespace bt;

template<class T>
void BinaryTree<T>::rDeleteNode(Node<T>* node){
    if(node -> l)
        rDeleteNode(node -> l);

    if(node -> r)
        rDeleteNode(node -> r);

    delete node;
//    cout << "Deleting content in address " << node << endl;
};

template<class T>
BinaryTree<T>::~BinaryTree(){
    BinaryTree<T>::rDeleteNode(root);
};

template<class T>
void BinaryTree<T>::insert(T value){
    if(!BinaryTree<T>::root){
        BinaryTree<T>::root = new Node<T>{nullptr, nullptr, value};
        BinaryTree<T>::n_nodes++;
        return;
    }

    Node<T>* temp = BinaryTree<T>::root;
    while(temp){
        if(temp -> val > value){
            if(temp -> l){
                temp = temp -> l;
            } else {
                temp -> l = new Node<T>{nullptr, nullptr, value};
                BinaryTree<T>::n_nodes++;
                return;
            }
        } else if (temp -> val < value){
            if(temp -> r){
                temp = temp -> r;
            } else {
                temp -> r = new Node<T>{nullptr, nullptr, value};
                BinaryTree<T>::n_nodes++;
                return;
            }
        } else {
            return;
        }
    }
};

template<class T>
bool BinaryTree<T>::find(T value){
    if(rFind(BinaryTree<T>::root, value) != nullptr){
        return 1;
    }
    return 0;
}

template<class T>
Node<T>* BinaryTree<T>::get_successor(Node<T>* node){
    Node<T>* temp = node -> r;
    while(temp -> l && temp){
        temp = temp -> l;
    }
    return temp;
};

template<class T>
Node<T>* BinaryTree<T>::rFind(Node<T>* node, T value){
    if(!node){return nullptr;}

    if(value == node -> val){
        return node;
    } else if(value > node -> val){
        return BinaryTree<T>::rFind(node -> r, value);
    } else if(value < node -> val) {
        return BinaryTree<T>::rFind(node -> l, value);
    }
    return nullptr;
};

template<class T>
void BinaryTree<T>::pop(T value){
    recursiveDeletion(BinaryTree<T>::root, value);
};

template<class T>
Node<T>* BinaryTree<T>::recursiveDeletion(Node<T>* node, T value){;
    if(!node)
        return node;

    if(node -> val > value)
        node -> l = BinaryTree<T>::recursiveDeletion(node -> l, value);
    else if(node -> val < value)
        node -> r = BinaryTree<T>::recursiveDeletion(node -> r, value);
    else{
        if(!node -> l){
            Node<T>* temp = node -> r;
            delete node;
            return temp;
        } else if(!node -> r){
            Node<T>* temp = node -> l;
            delete node;
            return temp;
        }
        Node<T>* successor = BinaryTree<T>::get_successor(node);
        node -> val = successor -> val;
        node -> r = BinaryTree<T>::recursiveDeletion(node -> r, successor -> val);
    }
    return node;
};

template<class T>
int BinaryTree<T>::find_depth(Node<T>* node, int depth){
    if(node == nullptr || (node -> l == nullptr && node -> r == nullptr)){
        return depth;
    }

    return max(BinaryTree<T>::find_depth(node -> l, depth++), BinaryTree<T>::find_depth(node -> r, depth++));
}

template<class T>
int BinaryTree<T>::get_depth(){
    return BinaryTree<T>::find_depth(BinaryTree<T>::root, 0);
}

template<class T>
void BinaryTree<T>::rShow(Node<T>* node, T* arr, int currIndex){
    arr[currIndex-1] = node->val;
    if(!node->l && !node->r){
        return;
    }
    if(node->l){
        rShow(node->l, arr, currIndex*2);
    }
    if(node->r){
        rShow(node->r, arr, currIndex*2+1);
    }
}

template<class T>
void BinaryTree<T>::show(){
    int max_nodes = 0;

    for(int i = 0; i <= BinaryTree<T>::get_depth(); i++){
        max_nodes += pow(2, i);
    }

    T* arr = new T[max_nodes];
    for(int i = 0; i < max_nodes; i++){
        arr[i] = -1;
    }

    BinaryTree<T>::rShow(BinaryTree<T>::root, arr, 1);

    int counter[] = {0, 0};
    for(int i = 0; i < max_nodes; i++){
        arr[i]!=-1 ? cout << arr[i] << " " : cout << "X ";
        if(i == counter[0]){
            cout << endl;
            counter[1]++;
            counter[0] += pow(2, counter[1]);
        }
    }
}
