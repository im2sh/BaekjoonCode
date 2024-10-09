#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
map<string,bool> visited;
queue<pair<string, int>> q;

bool isDiff(string original, string target){
    int diff = 0;
    for(int i = 0; i < original.length(); i++){
        if(original[i] != target[i])
            diff++;
    }
    if(diff == 1)
        return true;
    return false;;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    q.push({begin, 0});
    
    while(q.size()){
        string cur = q.front().first;
        int cnt = q.front().second;

        q.pop();
        if(cur == target){
            answer = cnt;
            break;
        }
        for(int i = 0; i < words.size(); i++){
            if(isDiff(cur, words[i]) && !visited[words[i]]){
                visited[words[i]] = true;
                q.push({words[i], cnt + 1 });
            }
        }
    }
    return answer;
}