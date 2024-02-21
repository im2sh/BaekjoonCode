#include <iostream>
#include <vector>

using namespace std;

int N, M;
int visited[2001];
vector<int> graph[2001];
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int cur, int depth) {
    if (depth == 4) {
        flag = true;
        return;
    }
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
    visited[cur] = 0;
}

void solve() {
    for (int i = 0; i < M; i++) {
        fill(&visited[0], &visited[0] + 2001, 0);
        dfs(i, 0);
        if (flag) {
            cout << "1";
            return;
        }
    }
    cout << "0";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}