#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
int N, M, ret;
int BOARD[2001][2001];
vector<pair<int, int>> fan;
int visited[2001][2001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 9)
                fan.push_back({y, x});
        }
    }
}

void go(int y, int x) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    q.push({{y, x}, 1});
    q.push({{y, x}, 2});
    q.push({{y, x}, 3});

    while (q.size()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        int ny = cy + dy[dir];
        int nx = cx + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (BOARD[ny][nx] == 9)
            continue;
        visited[ny][nx] = 1;
        if (BOARD[ny][nx] == 1) {
            if (dir == 2 || dir == 3)
                continue;
        } else if (BOARD[ny][nx] == 2) {
            if (dir == 0 || dir == 1)
                continue;
        } else if (BOARD[ny][nx] == 3) {
            if (dir == 0)
                dir = 3;
            else if (dir == 1)
                dir = 2;
            else if (dir == 2)
                dir = 1;
            else
                dir = 0;
        } else if (BOARD[ny][nx] == 4) {
            if (dir == 0)
                dir = 2;
            else if (dir == 1)
                dir = 3;
            else if (dir == 2)
                dir = 0;
            else
                dir = 1;
        }
        q.push({{ny, nx}, dir});
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    go(y, x);
}

void solve() {
    for (int i = 0; i < fan.size(); i++) {
        bfs(fan[i].first, fan[i].second);
        visited[fan[i].first][fan[i].second] = 1;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (visited[y][x])
                ret++;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}