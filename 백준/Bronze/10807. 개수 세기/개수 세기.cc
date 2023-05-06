#include <iostream>
#include <vector>

using namespace std;

int N;
int target;
int ret;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> target;
}

void solve() {
    for (int i = 0; i < v.size(); i++) {
        if (target == v[i])
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