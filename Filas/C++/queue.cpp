#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int value;
};

class Queue{
    public:
        Node* head = nullptr;
        int len = 0;

        void push(int num){
            Node* newNode = new Node{nullptr, num};

            if(head == nullptr){
                head = newNode;
                len++;
                return;
            }

            Node* tempNode = head;
            while(tempNode -> next != nullptr){
                tempNode = tempNode -> next;
            }
            tempNode -> next = newNode;
            len++;
        }
        
        void pop(){
            if(len == 0){return;}
            
            Node* delNode = head;
            head = head -> next;
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

            while(tempNode -> next != nullptr){
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
                if(tempNode -> next != nullptr){
                    cout << tempNode -> value << " <- ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << endl;
                    break;
                }
            }
        }
        
};

int main(){
    Queue lista;

    lista.push(52);
    lista.push(872);
    lista.push(45);
    lista.push(728);
    
    lista.display();
    
    lista.pop();
    
    lista.display();
    
    int tamanho = lista.size();
    
    int isempty = lista.empty();
    cout << isempty << endl;
    
    for(int i = 0; i <= tamanho; i++){
        lista.pop();
    }
    
    isempty = lista.empty();
    cout << isempty << endl;
    
    lista.push(52);
    lista.push(872);
    lista.push(45);
    lista.push(728);
    
    lista.display();
    
    lista.swap(0,4);
    lista.display();

    return 0;
}
