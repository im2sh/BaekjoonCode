#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

// dlru
constexpr int dx[4] = {1,0,0,-1};
constexpr int dy[4] = {0,-1,1,0};

map<int, string> dict = {{0, "d"}, {1,"l"}, {2,"r"}, {3,"u"}};
int N, M, X, Y, R, C, K;
string ret = "impossible";
bool flag = false;
bool visited[51][51];

int getDistance(int x, int y){
    return abs(R - x) + abs(C - y);
}

void go(int depth, int x, int y, string path){
    if(flag || depth + getDistance(x,y) > K)
        return;
    
    if(depth == K){
        if(x == R && y == C){
            flag = true;
            ret =  path;
        }
        return;
    }
    
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        go(depth + 1, nx, ny, path + dict[dir]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    N = n, M = m, X = x, Y = y, R = r, C = c, K = k;
    X--, Y--, R--, C--;
    
    if((k - getDistance(x,y)) % 2 == 1)
        return ret;
    go(0,X,Y,answer);
    answer = ret;
    return answer;
}