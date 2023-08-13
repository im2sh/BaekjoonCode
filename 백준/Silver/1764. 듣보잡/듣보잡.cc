#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N, M;
map<string, int> list;
vector<string> ret;

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
        list[temp]++;
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        list[temp]++;
    }
}

void solve() {
    int temp = 0;
    for (auto &it: list) {
        if (it.second >= 2)
            ret.push_back(it.first);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}