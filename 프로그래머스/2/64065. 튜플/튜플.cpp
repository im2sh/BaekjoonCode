#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> dict;
vector<pair<int,int>> ret;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '"' || s[i] == '{' || s[i] == '}')
            continue;
        if(s[i] == ',' && s[i+1] != '{' && s[i-1] != '}'){
            dict[stoi(temp)]++;
            temp = "";
        }
        else if(s[i+1] != '{'){
            temp += s[i];
        }else if(s[i+1] == '{'){
            dict[stoi(temp)]++;
            temp = "";
        }
    }
    dict[stoi(temp)]++;
    
    for(auto it : dict){
        ret.push_back({it.first, it.second});
    }
    
    sort(ret.begin(), ret.end(), cmp);
    
    for(int i = 0; i < ret.size(); i++){
        answer.push_back(ret[i].first);
    }
    
    return answer;
}