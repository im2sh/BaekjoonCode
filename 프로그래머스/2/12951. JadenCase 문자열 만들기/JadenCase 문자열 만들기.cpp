#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            answer += s[i];
            idx++;
        }
        else
            break;
    }
    if(97 <= s[idx] && s[idx] <= 122){
        answer += s[idx] - 32;
    }else{
        answer += s[idx];
    }
    
    for(int i = idx + 1; i < s.length(); i++){
        answer += s[i];
        if(s[i] == ' '){
            if(97 <= s[i+1] && s[i+1] <= 122){
                answer += s[i + 1] - 32;   
                i++;
            }
            continue;
        }
        else if(65 <= s[i] && s[i] <= 90 && s[i - 1] != ' '){
            answer[i] += 32;
        }
    }
    return answer;
}