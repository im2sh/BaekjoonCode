#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret = 1;
vector<pair<int, int>> room;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        room.push_back({y, x}); // sort 편하게 x : 시작 시간 y : 종료 시간
    }
    sort(room.begin(), room.end());
}

void solve() {
    int from = room[0].second;
    int to = room[0].first;
    for (int i = 1; i < N; i++) {
        if (room[i].second < to)
            continue;
        from = room[i].second;
        to = room[i].first;
        ret++;
    }
    cout << ret << "\n";
}


int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}