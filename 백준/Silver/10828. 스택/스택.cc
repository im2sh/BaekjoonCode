#include <iostream>

using namespace std;

class Stack{
private:
    int* arr;
    int max_size;
    int top;
public:
    Stack(int size);
    bool isFull(), isEmpty();
    void spush(int data);
    int spop();
    int stop();
    int size();
    void print();
};

Stack::Stack(int size){
    max_size = size;
    arr = new int[max_size];
    top = -1;
}

bool Stack::isFull() {
    if(top == max_size - 1) {
        return 1;
    }
    return 0;
}

bool Stack::isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void Stack::spush(int data) {
    if(isFull()==1){
        cout << "Stack is Full" << endl;
    }
    arr[++top] = data;
}

int Stack::spop() {
    if(isEmpty() == 1){
        return -1;
    }
    return arr[top--];
}

int Stack::stop() {
    if(isEmpty()==1){
        return -1;
    }
    return arr[top];
}

void Stack::print() {
    for(int i= 0;i<max_size;i++){
        cout << arr[i] <<endl;
    }
}

int Stack::size() {
    return top;
}

int main(){
    Stack stack(10000);
    int x;
    int k = 0;
    cin >> x;
    string str;
    for(int i = 0; i < x; i++){
        cin >> str;
        if(str == "push"){
            int n;
            cin >> n;
            stack.spush(n);
        }
        else if(str == "pop"){
            if((k = stack.spop()) == -1)
                cout << "-1" << endl;
            else
                cout << k << endl;
        }
        else if(str == "size"){
            cout << stack.size() + 1 << endl;
        }
        else if(str == "empty"){
            cout << stack.isEmpty() << endl;
        }
        else if(str == "top"){
            cout << stack.stop() << endl;
        }
    }
}