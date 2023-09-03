#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<char,int> check;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0; i < skip.length(); i++){
        check[skip[i]] = 1;
    }
    
    for(int i = 0; i < s.length(); i++){
        char temp = s[i];
        for(int j = 1; j <= index; j++){
            temp++;
            while(true){
                if(temp > 122)
                    temp -= 26;
                if(check[temp])
                    temp++;
                else
                    break;
            }
        }
        answer += temp;
    }
    return answer;
}