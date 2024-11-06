#include <string>
#include <vector>
#include <iostream>

using namespace std;
int DP[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    DP[0][0] = triangle[0][0];
    int N = triangle.size();
    for(int i = 1; i < N; i++){
        int M = triangle[i].size();
        cout << M << '\n';
        for(int j = 0; j < M; j++){
            if(j == 0){
                DP[i][j] = DP[i-1][0] + triangle[i][0];
            }else if(j == M - 1){
                DP[i][j] = DP[i-1][M - 2] + triangle[i][M - 1];
            }else{
                DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j];
            }
        }
    }
    for(int i = 0; i < triangle[triangle.size()-1].size(); i++){
        answer = max(answer, DP[triangle.size()-1][i]);
    }
    return answer;
}