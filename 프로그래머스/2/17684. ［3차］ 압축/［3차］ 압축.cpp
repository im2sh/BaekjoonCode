#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

map<string, int> dict;
int val = 27;
void init(){
    for(int i = 0; i < 26; i++){
        string temp = "";
        temp += 'A' + i;
        dict[temp] = i + 1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    string findStr = "";
    for(int i = 0; i < msg.length(); i++){
        findStr = msg[i];
        int idx = 0;
        for(int j = i; j < msg.length(); j++){
            string ret = findStr;
            ret += msg[j + 1];
            if(!dict[ret]){
                dict[ret] = val++;
                answer.push_back(dict[findStr]);
                i += idx;
                break;
            }
            idx++;
            findStr = ret;
        }
    }
    return answer;
}