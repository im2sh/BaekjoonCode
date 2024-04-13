#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int e;
    int w;
} Node;

int N, M;
vector<Node> graph[1001];
int dist[1001];
int S, E;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
    }
    cin >> S >> E;
    S -= 1;
    E -= 1;
    for (int i = 0; i < N; i++) {
        dist[i] = 987654321;
    }
}

struct cmp {
    bool operator()(Node a, Node b) {
        return a.w > b.w;
    }
};

void solve() {
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({S, 0});

    while (pq.size()) {
        int cur = pq.top().e;
        int weight = pq.top().w;
        pq.pop();
        if (dist[cur] < weight)
            continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].e;
            int next_weight = graph[cur][i].w;

            if (dist[next] > weight + next_weight) {
                pq.push({next, weight + next_weight});
                dist[next] = weight + next_weight;
            }
        }
    }
    cout << dist[E];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}