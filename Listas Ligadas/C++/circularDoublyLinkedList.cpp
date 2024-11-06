#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int value;

};

class CircularDoublyLinkedList{
    private:
        Node* getLastNode(){
            Node* tNode = head;
            for(int i = 0; i < len-1; i++){
                tNode = tNode -> next;
            }
            return tNode;
        }

    public:
        Node* head = nullptr;
        int len = 0;
    
        //Insert functions
        void insertAtBeginning(int num){
            if(len == 0){head = new Node{head, head, num};}

            Node* lastNode = getLastNode();
            Node* tempNode = new Node{head, lastNode, num};
            lastNode -> next = tempNode;
            head -> prev = tempNode;
            head = tempNode;
            len++;
        }

        void insertAtEnd(int num){
            if(len == 0){
                insertAtBeginning(num);
                return;
            }

            Node* lastNode = getLastNode();
            Node* newNode = new Node{head, lastNode, num};

            lastNode -> next = newNode;
            head -> prev = newNode;
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
                len++;
            } else {
                insertAtBeginning(num);
            }
        }
        
        // //Delete functions
        void deleteFromBeginning(){
            if(len == 0){return;}

            Node* lastNode = getLastNode();
            lastNode -> next = head -> next;
            head = head -> next;
            head -> prev = lastNode;
            len--;
        }
        
        void deleteFromEnd(){
            if(len == 0){return;}

            Node* guideNode = head;
            Node* tempNode = nullptr;

            while(guideNode -> next != head){
                tempNode = guideNode;
                guideNode = guideNode -> next;
            }
            
            if(tempNode != nullptr){
                tempNode -> next = head;
                head -> prev = tempNode;
                len--;
            } else {
                deleteFromBeginning();
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
                len--;
            } else {
                deleteFromBeginning();
            }
        }

        // //Search functions
        int searchIndex(int index){
            if(len == 0){return -1;}

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
            if(len == 0){return;}

            Node* tempNode = head;
            int counter = 0;

            cout << "h <-> ";
            while(counter < len){
                if(tempNode -> next != head){
                    cout << tempNode -> value << " <-> ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << " <-> h" << endl;
                    break;
                }
                counter++;
            }
        }
        
};

int main(){
    CircularDoublyLinkedList lista;
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
    lista.deleteFromBeginning();
    lista.deleteFromBeginning();
    lista.deleteFromIndex(0);

    lista.display();

    cout << lista.searchIndex(23) << endl;
    cout << lista.searchValue(561);

    return 0;
}
