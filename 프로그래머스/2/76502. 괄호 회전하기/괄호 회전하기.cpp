#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<char> st;

bool check(string S){
    for(int i = 0; i < S.length(); i++){
        if(S[i] == '(' || S[i] == '{' || S[i] == '['){
            st.push(S[i]);
        }else{
            if(st.empty()){
                return false;
            }else if(S[i] == ')' && st.top() == '('){
                st.pop();
            }else if(S[i] == '}' && st.top() == '{'){
                st.pop();
            }else if(S[i] == ']' && st.top() == '['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.size())
        return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++){
        answer += check(s);
        s += s[0];
        s.erase(s.begin() + 0);
    }
    
    return answer;
}