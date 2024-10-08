#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

bool solution(string s)
{
    bool answer = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push('(');
        }else{
            if(st.empty())
                return false;
            st.pop();    
        }
    }
    if(!st.empty())
        answer = false;
    return answer;
}