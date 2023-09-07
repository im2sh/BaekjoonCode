#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int BOARD[102][102];
int visited[102];
int ret = 987654321;

void dfs(int start,int n){
    visited[start] = 1;
    for(int i = 1; i <= n; i++){
        if(BOARD[start][i] && !visited[i]){
            dfs(i,n);
        }
    }
}

vector<int> cal(int n){
    int sum = 0;
    vector<int> temp;
    for(int y = 1; y <= n; y++){
        if(visited[y])
            sum++;
    }
    temp.push_back(sum);
    temp.push_back(n-sum);
    return temp;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    for(int i = 0; i < wires.size(); i++){
        int y = wires[i][0];
        int x = wires[i][1];
        
        BOARD[y][x] = 1;
        BOARD[x][y] = 1;
    }    
    for(int i = 0; i < wires.size(); i++){
        int one = wires[i][0];
        int two = wires[i][1];
        
        BOARD[one][two] = 0;
        BOARD[two][one] = 0;
        fill(&visited[0], &visited[0] + 102, 0);
        dfs(one, n);
        vector<int> temp = cal(n);
        
        BOARD[one][two] = 1;
        BOARD[two][one] = 1;
        
        ret = min(ret, abs(temp[0] - temp[1]));
    }
    answer = ret;
    return answer;
}