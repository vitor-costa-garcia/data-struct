#include <iostream>

using namespace std;

class staticStack{
    public:
        int* stack;
        int currentTop = -1;
        int size;

        void push(int num){
            if(currentTop+1 >= size){cout<<"ERROR: Stack overflow."<<endl; return;}
    
            currentTop++;
            stack[currentTop] = num;
        }

        void pop(){
            if(currentTop <= -1){cout<<"ERROR: Stack underflow."<<endl; return;}
            currentTop--;
        }

        int top(){
            return stack[currentTop];
        }

        void display(){
            if(currentTop==-1){cout<<"ERROR: Stack is empty."<<endl; return;}

            for(int i = currentTop; i != -1; i--)
                cout << stack[i] << endl;
            cout<<"end"<<endl;
        }

        staticStack(int size){
            this -> size = size;
            stack = new int[size];
        }
};

int main(){
    staticStack stack(5);
    stack.pop();

    stack.display();

    stack.push(53);
    stack.push(523);
    stack.push(61);
    stack.push(77);
    stack.push(4);
    stack.push(5);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    return 0;
}