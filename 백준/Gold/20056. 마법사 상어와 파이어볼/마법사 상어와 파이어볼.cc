#include <iostream>
#include <queue>

using namespace std;

int N, M, K;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Pos {
    int y, x;
};

struct Info {
    int m, s, v;
};

struct Ball {
    Pos pos;
    Info In;
};

vector<int> map[54][54];
vector<Ball> fireBall;
int ret = 0;
int dir1[4] = {0, 2, 4, 6};
int dir2[4] = {1, 3, 5, 7};

void magic() {
    vector<Ball> tempBall;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x].size() == 0) {
                continue;
            } else if (map[y][x].size() == 1) {
                int num = map[y][x][0];
                tempBall.push_back(fireBall[num]);
                continue;
            }
            bool odd = false, even = false;
            int ms = 0; // 질량 합
            int ss = 0; // 속도 합
            for (int i = 0; i < map[y][x].size(); i++) {
                int num = map[y][x][i];
                Ball temp = fireBall[num];
                int m = temp.In.m;
                int s = temp.In.s;
                int v = temp.In.v;

                ms += m;
                ss += s;

                if (v % 2 == 0) {
                    odd = true;
                } else if (v % 2 == 1) {
                    even = true;
                }
            }

            ms /= 5;
            if (ms == 0)
                continue;
            ss /= map[y][x].size();

            for (int i = 0; i < 4; i++) {
                if (!odd || !even)
                    tempBall.push_back({y, x, ms, ss, dir1[i]});
                else
                    tempBall.push_back({y, x, ms, ss, dir2[i]});
            }
        }
    }
    fireBall = tempBall;
}

void move() {
    vector<int> tempMap[54][54];
    for (int i = 0; i < fireBall.size(); i++) {
        int cd = fireBall[i].In.v; // 방향
        int cy = fireBall[i].pos.y;
        int cx = fireBall[i].pos.x;
        int cs = fireBall[i].In.s % N; // 속도

        int ny = (cy + dy[cd] * cs + N) % N;
        int nx = (cx + dx[cd] * cs + N) % N;

        fireBall[i].pos.y = ny;
        fireBall[i].pos.x = nx;
        tempMap[ny][nx].push_back(i);
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            map[y][x] = tempMap[y][x];
        }
    }
}

void Init() {
    cin >> N >> M >> K;
    int a, b, c, d, e;
    Ball temp;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d >> e;
        temp.pos.y = a - 1;
        temp.pos.x = b - 1;
        temp.In.m = c;
        temp.In.s = d;
        temp.In.v = e;
        fireBall.push_back(temp);
        map[temp.pos.y][temp.pos.x].push_back(i);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();
    for (int i = 0; i < K; i++) {
        move();
        magic();
    }

    for (int i = 0; i < fireBall.size(); i++) {
        ret += fireBall[i].In.m;
    }
    cout << ret << "\n";
    return 0;
}