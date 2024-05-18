#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 10;
int N, ret;
vector<int> building;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ret = 0;
    building.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        building.push_back(temp);
    }
}

void go() {
    for (int i = 2; i < building.size() - 2; i++) {
        int maxLeftHeight = max(building[i - 1], building[i - 2]);
        int maxRightHeight = max(building[i + 1], building[i + 2]);
        int maxHeight = max(maxLeftHeight, maxRightHeight);

        int sum = building[i] - maxHeight;
        if (sum < 0)
            continue;
        ret += sum;
    }
}

void solve() {
    for (int i = 1; i <= TC; i++) {
        Init();
        go();
        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}