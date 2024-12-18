#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int changeToLen(string s){
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1')
            temp += s[i];
    }
    return temp.length();
}

string changeToString(int len){
    string temp = "";
    while(len != 0){
        temp += to_string(len % 2); 
        len /= 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int sum = 0;
    int cnt = 0;
    while(s != "1"){
        int len = changeToLen(s);
        sum += s.length() - len;
        s = changeToString(len);
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(sum);
    return answer;
}