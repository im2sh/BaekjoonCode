#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int N, M, R;
int cnt = 1;
vector<int> graph[MAX];
int visited[MAX] = {0,};
bool checked[MAX];

void dfs(int start) {
    checked[start] = true;
    visited[start] = cnt;
    int next_idx = 0;
    for (int i = 0; i < graph[start].size(); i++) {
        next_idx = graph[start][i];
        if (!checked[next_idx]) {
            cnt++;
            dfs(next_idx);
        }
    }
}

void graph_init() {
    cin >> N >> M >> R;
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graph_init();

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << "\n";
    }
    return 0;
}