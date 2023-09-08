#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int BOARD[101][101];
int visited[101][101];
int ret = 0;
int n,m;

const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = 1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == n-1 && x == m-1)
            return;
        
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !BOARD[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    for(int y = 0; y < maps.size(); y++){
        for(int x = 0; x < maps[y].size(); x++){
            if(maps[y][x])
                BOARD[y][x] = 1;
        }
    }
    bfs(0,0);
    answer = visited[n-1][m-1];
    if(answer == 0)
        return -1;
    return answer;
}