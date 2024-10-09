#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> graph[201];
bool visited[201];

void dfs(int start){
    visited[start] = true;
    
    for(int i = 0; i < graph[start].size(); i++){
        int next = graph[start][i];
        if(visited[next])
            continue;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j || computers[i][j] == 0)
                continue;
            graph[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}