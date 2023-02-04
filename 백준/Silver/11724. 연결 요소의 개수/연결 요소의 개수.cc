#include <iostream>
#include <vector>

using namespace std;

bool flag[1001] = {false, };
vector<vector<int>> graph;
int cnt = 0;

void dfs(int start){
    flag[start] = true;
    for(int i = 0; i < graph[start].size();i++){
        int next_idx = graph[start][i];
        if(!flag[next_idx])
            dfs(next_idx);
    }
}


int main(void){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    int x,y;
    cin >> N >> M;
    graph.assign(N+1, vector<int>(0,0));
    for(int i = 0; i< M;i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= N; i++){
        if(!flag[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt <<"\n";
}