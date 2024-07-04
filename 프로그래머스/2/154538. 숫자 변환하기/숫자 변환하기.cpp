#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
queue<int> q;
int visited[1000004];

int solution(int x, int y, int n) {
    int answer = 0;
    if(x == y)
        return answer;
    q.push(x);
    visited[x] = 0;
    while(q.size()){
        int cur = q.front();
        q.pop();
        if(cur == y)
            break;
        for(int next : {cur + n, cur * 2, cur * 3}){
            if(next > y || visited[next])
                continue;
            q.push(next);
            visited[next] = visited[cur] + 1;
        }        
    }
    answer = visited[y];
    if(answer == 0)
        answer = -1;
    return answer;
}

