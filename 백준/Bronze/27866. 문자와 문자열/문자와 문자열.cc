#include <iostream>

using namespace std;

string s;
int n;
int main(void){
    cin >> s;
    cin >> n;
    
    for(int i = 0; i < s.length(); i++){
        if(i == n-1)
            cout << s[i];
    }
    return 0;
}