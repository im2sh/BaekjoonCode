#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int q = n;
    int r = -1;
    
    while(q > 0){
        r = q % 3;
        q/=3;
        
        if(r == 0){
            answer += '4';
            q -= 1;
        }
        else if(r==1){
            answer += to_string(r);
        }
        else{
            answer += to_string(r);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}