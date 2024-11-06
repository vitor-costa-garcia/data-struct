#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    int value;

};

class CircularLinkedList{
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
            Node* tempNode = new Node{head, num};
            head = tempNode;

            if(len != 0){
                len++;
                Node* lastNode = getLastNode();
                lastNode -> next = head;
            } else {
                len++;
                head -> next = head;
            };
        }

        void insertAtEnd(int num){
            Node* newNode = new Node{head, num};

            if(len == 0){
                head = newNode;
                head -> next = head;
            } else {
                Node* lastNode = getLastNode();
                lastNode -> next = newNode;
            }

            len++;
        }
        
        void insertAtIndex(int num, int index){
            Node* tempNode = head;
            Node* oldTempNode = nullptr;

            for(int i = 0; i < index; i++){
                oldTempNode = tempNode;
                tempNode = tempNode -> next;
            }
            
            if(oldTempNode != nullptr){
                Node* newNode = new Node{tempNode, num};
                oldTempNode -> next = newNode;
                len++;
            } else {
                insertAtBeginning(num);
            }
        }
        
        //Delete functions
        void deleteFromBeginning(){
            Node* lastNode = getLastNode();
            head = head -> next;
            lastNode -> next = head;
            len--;
        }
        
        void deleteFromEnd(){
            Node* lastNode = getLastNode();
            Node* secondLastNode = head;

            while(secondLastNode -> next != lastNode){
                secondLastNode = secondLastNode -> next;
            }

            secondLastNode -> next = head;
            len--;
            delete lastNode;
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
                len--;
            } else {
                deleteFromBeginning();
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

            do {
                if(tempNode -> value == num){
                    return counter;
                } else {
                    counter++;
                    tempNode = tempNode -> next;
                }
            } while(tempNode != head);
            return -1;
        }
        
        //Display function
        void display(){
            Node* tempNode = head;
            int counter = 0;

            cout << "h -> ";
            while(counter < len){
                if(tempNode -> next != head){
                    cout << tempNode -> value << " -> ";
                    tempNode = tempNode -> next;
                } else {
                    cout << tempNode -> value << " -> h" << endl;
                    break;
                }
                counter++;
            }
        }

        //Lenght function
        int getLength(){
            return len;
        }

};

int main(){
    CircularLinkedList lista;
    lista.insertAtBeginning(94);
    lista.insertAtBeginning(14);
    lista.insertAtBeginning(623);
    lista.insertAtEnd(27);
    lista.insertAtEnd(72);
    lista.insertAtEnd(24);
    lista.insertAtIndex(21, 0);
    lista.insertAtIndex(42, 2);
    lista.insertAtIndex(61, 1);

    lista.display();

    lista.deleteFromBeginning();
    lista.deleteFromEnd();

    lista.display();

    int num = lista.searchIndex(8);
    cout << num << endl;

    num = lista.searchValue(27);
    cout << num << endl;

    lista.deleteFromIndex(5);

    lista.display();

    return 0;
}
