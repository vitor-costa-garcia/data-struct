#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    int value;

};

class DynamicStack{
    public:
        Node* head = nullptr;
        int len = 0;

        void push(int num){
            Node* tempNode = new Node{head, num};
            head = tempNode;
            len++;
        }

        void pop(){
            head = head -> next;
            len--;
        }

        int top(){
            return head -> value;
        }

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
    DynamicStack stack;
    stack.push(101);
    stack.push(72);
    stack.push(16);
    stack.push(24);
    stack.push(222);

    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();

    stack.display();

    cout << stack.top();

    return 0;
}
