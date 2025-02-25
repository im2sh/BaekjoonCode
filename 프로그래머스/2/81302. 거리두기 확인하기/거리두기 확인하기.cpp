#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

constexpr int dy[4] = {0,0,-1,1};
constexpr int dx[4] = {1,-1,0,0};

bool visited[5][5];

typedef struct pos{
    int y, x, depth;
}Pos;

int go(vector<string> BOARD){
    for(int i = 0; i < BOARD.size(); i++){
        for(int j = 0; j < BOARD[j].size(); j++){
            if(BOARD[i][j] == 'P'){
                fill(&visited[0][0], &visited[0][0] + 5 * 5, false);
                queue<Pos> q;
                q.push({i,j, 0});
                visited[i][j] = true;
                
                while(q.size()){
                    int cy = q.front().y;
                    int cx = q.front().x;
                    int depth = q.front().depth;
                    q.pop();
                    
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        
                        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx] || (depth + 1) > 2 || BOARD[ny][nx] == 'X')
                            continue;
                        if(BOARD[ny][nx] == 'P')
                            return 0;
                        q.push({ny,nx, depth + 1});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++){
        int ret = go(places[i]);
        answer.push_back(ret);
    }
    return answer;
}