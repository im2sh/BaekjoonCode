#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

#define SIZE 64
using namespace std;


int N, Q, L;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
int map[SIZE][SIZE];
int temp_map[SIZE][SIZE] = {0,};
int copy_map[SIZE][SIZE] = {0,};
//queue<pair<int, int>> temp;
int visited[SIZE][SIZE];
int cnt_visited[SIZE][SIZE];
int ret = 0;
int cnt;

 

int bfs(int y, int x) {
    cnt = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    int cy, cx;
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = dy[d] + cy;
            int nx = dx[d] + cx;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx] || map[ny][nx] == 0)
                continue;
            cnt++;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    return cnt;
}

void search(int y, int x) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            copy_map[y][x] = map[y][x];
        }
    }


    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;
                if (map[ny][nx] != 0)
                    cnt++;
            }
            if (cnt < 3) {
                if (copy_map[y][x] == 0)
                    continue;
                copy_map[y][x] = copy_map[y][x] - 1;
            }
        }
    }


    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            map[y][x] = copy_map[y][x];
        }
    }
}

void rotate(int cy, int cx, int len) {
    for (int y = 0; y < len; y++) {
        for (int x = 0; x < len; x++) {
            copy_map[cy + y][cx + x] = 0;
        }
    }
    for (int y = 0; y < len; y++) {
        for (int x = 0; x < len; x++) {
            temp_map[cy + x][len + cx - 1 - y] = map[cy + y][cx + x];
        }
    }


}

void copyArr(int cy, int cx, int len) {
    for (int y = 0; y < len; y++) {
        for (int x = 0; x < len; x++) {
            map[y + cy][cx + x] = temp_map[cy + y][cx + x];
        }
    }
}

void solve(int y, int x, int len, int L) {
    if (len == L) {
        rotate(y, x, len);
        copyArr(y, x, len);
        return;
    }
    len /= 2;

    solve(y, x, len, L);
    solve(y, x + len, len, L);
    solve(y + len, x, len, L);
    solve(y + len, x + len, len, L);
}


void Init() {
    cin >> N >> Q;
    N = (1 << N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0;
    int cnt = 0;
    Init();
    for (int i = 0; i < Q; i++) {
        cin >> L;
        solve(0, 0, N, pow(2, L));
        search(0, 0);
    }
    fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            sum += map[y][x];
            if (!visited[y][x] && map[y][x] != 0) {
                ret = max(ret, bfs(y, x));
            }
        }
    }
    cout << sum << "\n" << ret << "\n";
    return 0;
}
