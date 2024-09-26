#include <string>
#include <vector>
#include <iostream>

using namespace std;
int BOARD[101][101];
int DP[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    DP[0][0] = 1;
    
    for(int i = 0; i < puddles.size(); i++){
        BOARD[puddles[i][1] - 1][puddles[i][0] - 1] = 1;
    }
    for(int i = 0; i < m; i++){
        if(BOARD[0][i] == 1)
            break;
        DP[0][i] = 1;
    }
    for(int i = 0; i < n; i++){
        if(BOARD[i][0] == 1)
            break;
        DP[i][0] = 1;
    }
    
    for(int y = 1; y < n; y++){
        for(int x = 1; x < m; x++){
            if(BOARD[y][x] == 1)
                continue;
            if(BOARD[y-1][x] != 1)
                DP[y][x] += DP[y-1][x] % 1000000007;
            if(BOARD[y][x-1] != 1)
                DP[y][x] += DP[y][x-1] % 1000000007;
            
        }
    }

            
    return DP[n-1][m-1] % 1000000007;
}