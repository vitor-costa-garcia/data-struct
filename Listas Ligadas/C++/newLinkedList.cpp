#include <iostream>

using namespace std;

template <typename T>
struct Node{
    Node<T>* next;
    T val;
};


template <typename T>
class LinkedList{
    public:
        Node<T>* head = nullptr;
        int len = 0;

        void append(T value){
            //Adds a value to the end of the list | Time Complexity: O(n)
            Node<T>* newNode = new Node<T>{nullptr, value};
            if(!len){head = newNode; len++; return;}

            Node<T>* tempNode = head;
            while(tempNode -> next != nullptr){
                tempNode = tempNode -> next;
            }
            tempNode -> next = newNode;
            len++;
        };

        void pop(int index = 0){
            //Pops an item from the list based on its index | Time Complexity: O(n)
            if(!len){return;}

            if(!index){
                Node<T>* deleteNode = head;
                head = head -> next;
                delete deleteNode;
                len--;
                return;
            }

            Node<T>* deleteNode = head;
            Node<T>* tempNode = nullptr;
            for(int i = 0; i < index; i++){
                tempNode = deleteNode;
                deleteNode  = deleteNode -> next;
            }
            tempNode -> next = tempNode -> next -> next;
            delete deleteNode;
            len--;
        }

        void insert(T value, int index = 0){
            //Inserts a value to the list based on a index.
            //The item is placed to the left of the current value at the given index | Time Complexity: O(n)
            if(!index){
                Node<T>* newNode = new Node<T>{head, value};
                head = newNode;
                len++;
                return;
            }

            Node<T>* tempNode = head;
            for(int i = 0; i < index-1; i++){
                tempNode = tempNode -> next;
            }
            Node<T>* newNode = new Node<T>{tempNode -> next, value};
            tempNode -> next = newNode;
            len++;
        }

        int index(T value){
            //Returns the index of a given value. If the value isn't found, returns -1 | Time Complexity: O(n)
            int counter = 0;
            Node<T>* tempNode = head;

            while(tempNode != nullptr){
                if(tempNode -> val == value){
                    return counter;
                }
                tempNode = tempNode -> next;
                counter++;
            }
            return -1;
        }

        void clear(){
            //Deletes all nodes on the list | Time Complexity: O(n)
            Node<T>* tempNode = head;
            while(head != nullptr){
                head = head -> next;
                cout << "Deleting " << tempNode << "..." << endl;
                delete tempNode;
                tempNode = head;
            }
            len = 0;
        }

        void remove(T value){
            //Removes a given value from the list. If the value isn't found, nothing is done | Time Complexity: O(n)
            if(!len){return;}

            Node<T>* guideNode = head;
            if(guideNode -> val == value){
                head = head -> next;
                delete guideNode;
                len--;
                return;
            }

            Node<T>* tempNode = guideNode;
            guideNode = guideNode -> next;

            while(guideNode != nullptr){
                if(guideNode -> val == value){
                    tempNode -> next = guideNode -> next;
                    delete guideNode;
                    len--;
                    return;
                }
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
        }

        void reverse(){
            //Reverses the list inplace | Time Complexity: O(n)
            if(len < 2){return;}

            if(len = 2){
                Node<T>* newHead = head -> next;
                newHead -> next = head;
                newHead -> next -> next = nullptr;
                head = newHead;
                return;
            }

            Node<T>* prevNode = head;
            Node<T>* currNode = head -> next;
            Node<T>* nextNode = head -> next -> next;

            prevNode -> next = nullptr;
            while(nextNode != nullptr){
                currNode -> next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
                nextNode = nextNode -> next;
            }
                currNode -> next = prevNode;
                head = currNode;
        }

        void sort(){
            //Sorts the list using BubbleSort algorithm | Time Complexity : O(n^2)¢
            for(int i = 0; i < len-1; i++){
                Node<T>* leftNode = head;
                Node<T>* rightNode = head -> next;
                for(int j = 0; j < len - 1 - i; j++){
                    if(leftNode -> val > rightNode -> val){
                        T tempVar = leftNode -> val;
                        leftNode -> val = rightNode -> val;
                        rightNode -> val = tempVar;
                    }
                    leftNode = rightNode;
                    rightNode = rightNode -> next;
                }
            }
        }

        int count(T value){
            //Counts how many of a given value there if on the list | Time Complexity: O(n)
            Node<T>* tempNode = head;
            int counter = 0;
            while(tempNode){
                if(tempNode -> val == value){
                    counter += 1;
                }
                tempNode = tempNode -> next;
            }
            return counter;
        }

        void extend(LinkedList<T>* list){
            //Adds a given list of same data-type to the end of the list
            //OBS: The values are copied then added instead of linking the two lists together || Time Complexity: O(n)
            Node<T>* mainNode = head;
            Node<T>* supportNode = list -> head;

            while(mainNode -> next){
                mainNode = mainNode -> next;
            }

            while(supportNode){
                mainNode -> next = new Node<T>{nullptr , supportNode -> val};
                supportNode = supportNode -> next;
                mainNode = mainNode -> next;
                len++;
            }
        }

//        void concat(LinkedList<T>* list){
//        //Links two lists together | Time Complexity: O(n)
//            Node<T>* mainNode = head;
//                Node<T>* supportNode = list -> head;
//
//            while(mainNode -> next){
//                mainNode = mainNode -> next;
//            }
//            mainNode -> next = supportNode;
//        }

        void show(){
            //Prints the list | Time Complexity: O(n)
            if(!len){cout << "[]\n"; return;}

            Node<T>* tempNode = head;
            cout << '[';
            while(tempNode -> next != nullptr){
                cout << tempNode -> val << ", ";
                tempNode = tempNode -> next;
            };
            cout << tempNode -> val;
            cout << "]\n";
        };

        ~LinkedList(){
            //Deletes all list nodes | Time Complexity: O(n)
            Node<T>* tempNode = head;
            while(head){
                head = head -> next;
                cout << "Deleting " << tempNode << "..." << endl;
                delete tempNode;
                tempNode = head;
            }
            delete head;
        }
};
