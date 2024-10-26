#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int value;

};

class DoublyLinkedList{
    private:
        Node* head = nullptr;
        int len = 0;
    
        Node* getLastNode(){
            Node* tNode = head;
            for(int i = 0; i < len-1; i++){
                tNode = tNode -> next;
            }
            return tNode;
        }

    public:
        //Insert functions
        void insertAtBeginning(int num){
            Node* tempNode = new Node{head, nullptr, num};
            head -> prev = tempNode;
            head = tempNode;
            len++;
        }

        void insertAtEnd(int num){
            Node* lastNode = getLastNode();
            Node* newNode = new Node{nullptr, lastNode, num};

            if(len == 0){
                head = newNode;
                len++;
                return;
            }

            lastNode -> next = newNode;
            len++;
        }
        
        void insertAtIndex(int num, int index){
            Node* tempNode = head;
            Node* oldTempNode = nullptr;

            for(int i = 0; i < index; i++){
                oldTempNode = tempNode;
                tempNode = tempNode -> next;
            }

            Node* newNode = new Node{tempNode, oldTempNode, num};
            
            if(oldTempNode != nullptr){
                oldTempNode -> next = newNode;
                tempNode -> prev = newNode;
            } else {
                insertAtBeginning(num);
            }
        }
        
        // //Delete functions
        void deleteFromBeginning(){
            if(len == 0){return;}

            head = head -> next;
            head -> prev = nullptr;
        }
        
        void deleteFromEnd(){
            if(len == 0){return;}

            Node* guideNode = head;
            Node* tempNode = nullptr;

            while(guideNode -> next != nullptr){
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
            
            if(tempNode != nullptr){
                tempNode -> next = nullptr;
                delete guideNode;
            } else {
                head = nullptr;
            }
        }
        
        void deleteFromIndex(int index){
            if(len == 0 || index >= len){return;}

            Node* guideNode = head;
            Node* tempNode = nullptr;

            for(int i = 0; i < index; i++){
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
            
            if(tempNode != nullptr){
                tempNode -> next = guideNode -> next;
                tempNode -> next -> prev = tempNode; 
            } else {
                head = head -> next;
                head -> prev = nullptr;
            }
        }

        // //Search functions
        int searchIndex(int index){
            if(len == 0 || index >= len){return -1;}

            Node* tempNode = head;
            for(int i = 0; i < index; i++){
                tempNode = tempNode -> next;
            }
            return tempNode -> value;
        }
        
        int searchValue(int num){
            Node* tempNode = head;
            int counter = 0;
            while(tempNode != nullptr){
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
                    cout << tempNode -> value << " <-> ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << endl;
                    break;
                }
            }
        }
        
};

int main(){
    DoublyLinkedList lista;
    lista.insertAtEnd(20);
    lista.insertAtEnd(83);
    lista.insertAtEnd(42);
    lista.insertAtBeginning(561);
    lista.insertAtBeginning(32);
    lista.insertAtBeginning(24);
    lista.insertAtIndex(100, 2);
    lista.insertAtIndex(20, 0);

    lista.display();
    
    lista.deleteFromEnd();
    lista.deleteFromEnd();
    lista.deleteFromIndex(2);

    lista.display();

    cout << lista.head -> next -> prev -> next -> next -> prev -> next -> next -> next -> value;

    return 0;
}