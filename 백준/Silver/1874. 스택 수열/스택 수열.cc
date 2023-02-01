#include <iostream>
#include <stack>

using namespace std;

int main(void){
    stack<int> s;
    int seq[100001];
    string result;
    int n;
    int temp = 0;

    cin >> n;

    for(int i = 0; i<n;i++){
        cin >> seq[i];
    }

    for(int i = 1; i< n+1; i++){
        s.push(i);
        result.push_back('+');

        while(!(s.empty()) && seq[temp] == s.top()){
            s.pop();
            result.push_back('-');
            temp++;
        }
    }

    if(s.empty()){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }
    else{
        cout << "NO" << "\n";
    }

}