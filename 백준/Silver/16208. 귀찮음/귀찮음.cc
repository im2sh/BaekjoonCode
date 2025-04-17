#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N, sum, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        sum -= arr[i];
        ret += arr[i] * sum;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}