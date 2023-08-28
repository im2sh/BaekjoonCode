#include <iostream>
#include <map>

using namespace std;

int N, M, ret;
map<string, int> s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        s[temp]++;
    }
}

void solve() {
    string temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (s[temp])
            ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}