#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> ret;
bool visited[11];

void go(int depth, int idx, string order, string path){
    ret[path]++;
    if(depth == order.length())
        return;
    
    for(int i = idx; i < order.length(); i++){
        if(!visited[i]){
            visited[i] = true;
            go(depth + 1, i + 1, order, path + order[i]);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        string temp = "";
        sort(orders[i].begin(), orders[i].end());
        go(0,0,orders[i], temp);
    }
    
    for(int i = 0; i < course.size(); i++){
        int maxNum = 0;
        for(auto& it : ret){
            if(course[i] == it.first.length())
                maxNum = max(maxNum, it.second);
        }
        
        for(auto& it : ret){
            if(it.second == maxNum && it.second >= 2 && it.first.length() == course[i]){
                answer.push_back(it.first);
            }
        }
    }    
    
    sort(answer.begin(), answer.end());
    return answer;
}