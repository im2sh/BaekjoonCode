#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M, num;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    vector<int> A(N), B(M), ret;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        if (!binary_search(B.begin(), B.end(), A[i])) {
            ret.push_back(A[i]);
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i: ret) {
        cout << i << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}