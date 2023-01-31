#include <iostream>
using namespace std;

class Stack{
private:
    int top;
    string sen;
    int max_size;
public:
    Stack(int size);
    void spush(char word);
    char spop();
    int sisempty();
    bool sisfull();
    void stackfree();
};

Stack::Stack(int size) {
    max_size = size;
    top = -1;
}

bool Stack::sisfull() {
    if(top == max_size)
        return -1;
    return 0;
}

int Stack::sisempty() {
    if(top == -1)
        return -1;
    return 0;
}

void Stack::spush(char word) {
    if(sisfull() == -1){
        cout<<"Stack is full!"<<endl;
    }
    sen[++top] = word;
}

char Stack::spop() {
    if(sisempty() == -1){
        return -1;
    }
    sen[top] = 0;
    return sen[top--];
}


int main(void){
    int n;
    int L_count = 0;
    int R_count = 0;
    cin >> n;
    cin.ignore();
    while(n--){
        Stack stack(1000);
        L_count = 0;
        R_count = 0;
        string sen;
        getline(cin,sen);
        for(int i =0;i<sen.size();i++){
            if(sen[i] == '(') {
                stack.spush(sen[i]);
                L_count++;
            }
            else if(sen[i] == ')') {
                stack.spop();
                R_count++;
            }
        }
        if(stack.sisempty() == -1 && (L_count == R_count))
            cout << "YES" <<endl;
        else{
            cout << "NO" << endl;
        }

    }
}