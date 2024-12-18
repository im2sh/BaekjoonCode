#include <string>
#include <vector>
#include <queue>
#include <map> 
#include <iostream>

using namespace std;

int N;
map<char, int> dict;
int pos[21];
bool visited[21];
int cnt = 0;

int solution(string name) {
    int answer = 0;
    N = name.length();
    
    for(int i = 0; i < 13; i++){
        dict['A' + i] = i;
    }
    
    for(int i = 0; i < 13; i++){
        dict['Z' - i] = i + 1;
    }
    
    
    for(int i = 0; i < N; i++){
        if(name[i] != 'A'){
            pos[i] = true;
            cnt++;
        }
        answer += dict[name[i]];
    }
    
    vector<int> temp;
    temp.push_back(0);
    queue<pair<pair<int,vector<int>>, int>> q;
    q.push({{0,temp}, 0});
    
    while(q.size()){
        int now = q.front().first.first;
        vector<int> posList = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        if(posList.size() >= cnt){
            int posCnt = 0;
                
            for(int i = 0; i < posList.size(); i++){
                if(pos[posList[i]] == true && !visited[posList[i]]){
                    posCnt++;
                    visited[posList[i]] = true;
                }
            }
            fill(&visited[0], &visited[0] + 21, false);
            if(posCnt == cnt){
                answer += depth;
                break;
            }
        }
        
        vector<int> onePosList = posList;
        int next = (now + 1) % N;
        onePosList.push_back(next);
        q.push({{next, onePosList}, depth + 1});
        
        vector<int> twoPosList = posList;
        next = (now + N - 1) % N;
        twoPosList.push_back(next);
        q.push({{next, twoPosList}, depth + 1});
    }
    
    return answer;
}