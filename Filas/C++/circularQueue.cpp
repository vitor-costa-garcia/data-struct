#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int value;
};

class CircularQueue{
    public:
        Node* head = nullptr;
        int len = 0;

        void push(int num){
            Node* newNode = new Node{head, num};

            if(head == nullptr){
                head = newNode;
                len++;
                return;
            }

            Node* tempNode = head;
            if(tempNode -> next == nullptr){
                tempNode -> next = newNode;
                len++;
                return;
            }

            while(tempNode -> next != head){
                tempNode = tempNode -> next;
            }
            tempNode -> next = newNode;
            len++;
        }
        
        void pop(){
            if(len == 0){return;}
            if(len == 1){head = nullptr; return;}

            Node* tempNode = head;
            while(tempNode -> next != head){
                tempNode = tempNode -> next;
            }
            
            Node* delNode = head;
            head = head -> next;
            tempNode -> next = head;
            delete delNode;
            len--;
        }

        void swap(int i1, int i2){
            if(i1 == i2){return;}
            
            int max, min;
            if (i1 > i2){
                max = i1;
                min = i2;
            } else {
                max = i2;
                min = i1;
            }

            if(len-1 < max){return;}

            Node* guideNode = head;
            Node* tempNode;

            for(int i = 0; i < max; i++){
                if(i == min){
                    tempNode = guideNode;
                }
                guideNode = guideNode -> next;
            }

            int tempValue;
            tempValue = guideNode -> value;
            guideNode -> value = tempNode -> value;
            tempNode -> value = tempValue;

        }

        int front(){
            return head -> value;
        }
        
        int back(){
            Node* tempNode = head;
            if(tempNode -> next == nullptr){
                return tempNode -> value;
            }

            while(tempNode -> next != head){
                tempNode = tempNode -> next;
            }

            return tempNode -> value;
        }

        int size(){
            return len;
        }

        int empty(){
            if(len == 0){
                return 1;
            }
            return 0;
        }
        
        void display(){
            Node* tempNode = head;
            while(1==1){
                if(tempNode -> next != head){
                    cout << tempNode -> value << " <- ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << " <- front" << endl;
                    break;
                }
            }
        }
        
};

int main(){
    CircularQueue lista;

    lista.push(52);
    lista.push(872);
    lista.push(45);
    lista.push(2);
    
    lista.display();

    lista.pop();
    lista.pop();

    lista.display();

    lista.swap(0,1);

    lista.display();

    cout << lista.back() << endl;
    cout << lista.front() << endl;

    cout << lista.head -> next -> next -> next -> next -> next -> value << endl;

    return 0;
}
