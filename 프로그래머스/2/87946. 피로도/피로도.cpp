#include <vector>
#include <algorithm>

using namespace std;

int ret = 0;
bool visited[9];

void go(int depth, int k, vector<vector<int>> dungeons){
    if(k < 0)
        return;
    
    ret = max(ret, depth);
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            go(depth + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons){
    int answer = -1;
    go(0, k, dungeons);
    answer = ret;
    return answer;
}