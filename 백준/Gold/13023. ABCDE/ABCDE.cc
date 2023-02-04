#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
bool flag[2001];
bool result = false;
vector<vector<int>> graph;

void search_graph(int start, int depth){
    if(depth == 4){
        result = true;
        return;
    }
    flag[start] = true;

    for(int i = 0; i <graph[start].size();i++){
        int next_idx = graph[start][i];
        if(!flag[next_idx])
            search_graph(next_idx,depth+1);
    }

    flag[start] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    int m = 0;
    int x,y;
    cin >> n >> m;
    graph.assign(n+1,vector<int>(0,0));
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 0; i < m; i++){
        memset(flag,false,sizeof(flag));
        search_graph(i,0);
        if(result == true)
            break;
    }
    cout << result << "\n";

    return 0;

}