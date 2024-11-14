#include <iostream>

using namespace std;

template <typename T>
struct Node{
    Node<T>* next;
    T val;
};


template <typename T>
class SortedLinkedList{
    private:
        Node<T>* head = nullptr;

    public:
        int len = 0;

        void push(T value){
            if(!len){
                head = new Node<T>{nullptr, value};
                len++;
                return;
            }

            Node<T>* guideNode = head;
            Node<T>* supportNode = nullptr;
            while(guideNode){
                if(guideNode -> val > value){
                    break;
                }
                supportNode = guideNode;
                guideNode = guideNode -> next;
            }

            if(!supportNode){
                Node<T>* newNode = new Node<T>{head, value};
                head = newNode;
            } else {
                Node<T>* newNode = new Node<T>{guideNode, value};
                supportNode -> next = newNode;
            }
            len++;
        }

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

        ~SortedLinkedList(){
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

int main(){
    SortedLinkedList<int> lista;
    lista.push(43);
    lista.push(10);
    lista.push(1);
    lista.push(9);
    lista.push(100);
    lista.push(43);
    lista.push(43);
    lista.push(43);
    lista.push(9);
    lista.push(9);
    lista.push(32);
    lista.push(7);
    lista.push(920);
    lista.push(0);
    lista.push(2);


    lista.show();
}
