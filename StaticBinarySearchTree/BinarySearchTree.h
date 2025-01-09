#include <cmath>

#ifndef BINARY_TREE
#define BINARY_TREE

using namespace std;

namespace bt
{
    template<typename T>
    class BinarySearchTree{
        public:
            BinarySearchTree(int depth){
                this -> depth = depth;
                this -> size = 1;

                for(int i = 1; i <= depth; i++){ 
                    size += pow(2, i);
                }

                tree = new T[size];
                filled = new int[size];

                for(int i = 0; i <= size; i++){ 
                    filled[i] = 0;
                }
            };

            void insert(T value){
                recursive_insert(1, value);
            };

            void pop(T value){
                int currIndex = 0;
                while(tree[currIndex] != value && currIndex < size){
                    currIndex++;
                }
                if(currIndex >= size){return;};
                currIndex++;

                if(currIndex*2-1 > size){filled[currIndex-1] = 0; return;};
                
                recursive_pop(currIndex);
            };

            void show(){
                int counter = 1;
                for(int i = 0; i < size; i++){

                    if(filled[i]){
                        cout << tree[i] << " ";
                    } else {
                        cout << "X ";
                    }

                    if(i == counter-1){
                        counter = counter * 2+1;
                        cout << endl;
                    }
                }
            }

            bool find(T value){
                
            }

        private:
            T get_successor(int index){
                int sup = index*2+1;
                index = index*2+1;
                while(index < size && filled[index-1]){
                    sup = index;
                    index = index * 2;
                }
                filled[sup-1] = 0;
                return tree[sup-1];
            }

            void recursive_pop(int currIndex){
                if(filled[currIndex*2] && filled[currIndex*2-1]){
                    T succ = get_successor(currIndex);
                    tree[currIndex-1] = succ;
                } else if(!filled[currIndex*2-1] && filled[currIndex*2]) {
                    tree[currIndex-1] = tree[currIndex*2];
                    recursive_pop(currIndex*2);
                    filled[currIndex*2] = 0;
                } else if(filled[currIndex*2-1] && !filled[currIndex*2]) {
                    tree[currIndex-1] = tree[currIndex*2-1];
                    recursive_pop(currIndex*2-1);
                    filled[currIndex*2-1] = 0;
                } else {
                    filled[currIndex-1] = 0;
                    return;
                }
            }

            void recursive_insert(int index, T value){
                if(!filled[index-1]){
                    tree[index-1] = value;
                    filled[index-1] = 1;
                    return;
                }

                if(value > tree[index-1]){
                    recursive_insert(index*2+1, value);
                } else if (value < tree[index-1]){
                    recursive_insert(index*2, value);
                } else {
                    return;
                }
            }

            int depth;
            int size;
            int* filled;
            T* tree;
    };
}

#endif
