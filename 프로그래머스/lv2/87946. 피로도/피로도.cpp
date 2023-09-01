#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[9];
int ret = 0;

void go(int k, vector<vector<int>> dungeons, int where, int cnt){
    ret = max(cnt, ret);
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = 1;
            go(k - dungeons[i][1], dungeons, i, cnt+1);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    go(k,dungeons,0,0);
    answer = max(answer, ret);
    return answer;
}