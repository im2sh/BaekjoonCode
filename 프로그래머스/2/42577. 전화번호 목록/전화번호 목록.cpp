#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, bool> dict;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i <phone_book.size(); i++){
        dict[phone_book[i]] = true;
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        string temp = "";
        for(int j = 0; j < phone_book[i].length(); j++){
            temp += phone_book[i][j];
            if(dict[temp] && temp != phone_book[i])
                answer = false;
        }
        if(!answer)
            break;
    }
    return answer;
}