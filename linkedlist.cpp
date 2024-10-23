#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    int value;

};

class LinkedList{
    public:
        Node* head = nullptr;

        //Insert functions
        void insertAtBeginning(int num){
            Node* tempNode = new Node{head, num};
            head = tempNode;
        }

        void insertAtEnd(int num){
            Node* newNode = new Node{nullptr, num};

            if(head == nullptr){
                head = newNode;
                return;
            }

            Node* tempNode = head;
            while(tempNode -> next != nullptr){
                tempNode = tempNode -> next;
            }
            tempNode -> next = newNode;
        }
        
        void insertAtIndex(int num, int index){
            Node* tempNode = head;
            Node* oldTempNode = nullptr;

            for(int i = 0; i < index; i++){
                oldTempNode = tempNode;
                tempNode = tempNode -> next;
            }

            Node* newNode = new Node{tempNode, num};
            
            if(oldTempNode != nullptr){
                oldTempNode -> next = newNode;
            }
        }
        
        //Delete functions
        void deleteFromBeginning(){
            Node* delNode = head;
            head = head -> next;
            delete delNode;
        }
        
        void deleteFromEnd(){
            Node* guideNode = head;
            Node* tempNode = nullptr;

            while(guideNode -> next != nullptr){
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
            
            if(tempNode != nullptr){
                tempNode -> next = nullptr;
                delete guideNode;
            }
        }
        
        void deleteFromIndex(int index){
            Node* guideNode = head;
            Node* tempNode = nullptr;

            for(int i = 0; i < index; i++){
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
            
            if(tempNode != nullptr){
                tempNode -> next = guideNode -> next;
            } else {
                head = head -> next;
            }
            
            delete guideNode;
        }

        //Search functions
        int searchIndex(int index){
            Node* tempNode = head;
            for(int i = 0; i < index; i++){
                tempNode = tempNode -> next;
            }
            return tempNode -> value;
        }
        
        int searchValue(int num){
            Node* tempNode = head;
            int counter = 0;
            while(tempNode -> next != nullptr){
                if(tempNode -> value == num){
                    return counter;
                } else {
                    counter++;
                    tempNode = tempNode -> next;
                }
            }
            return -1;
        }
        
        //Display function
        void display(){
            Node* tempNode = head;
            while(1==1){
                if(tempNode -> next != nullptr){
                    cout << tempNode -> value << " -> ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << endl;
                    break;
                }
            }
        }
        
};

int main(){
    LinkedList lista;
    lista.insertAtEnd(20);
    lista.insertAtEnd(83);
    lista.insertAtEnd(42);
    lista.insertAtBeginning(561);
    lista.insertAtBeginning(32);
    lista.insertAtBeginning(24);

    int num = lista.searchIndex(2);
    cout << num << endl;
    
    lista.insertAtIndex(333, 2);
    
    num = lista.searchIndex(2);
    cout << num << endl;
    num = lista.searchIndex(3);
    cout << num << endl;
    
    num = lista.searchValue(999);
    cout << num << endl;
    
    lista.display();
    
    lista.deleteFromBeginning();
    
    lista.display();
    
    lista.deleteFromEnd();
    
    lista.display();
    
    lista.deleteFromIndex(2);
    
    lista.display();

    return 0;
}