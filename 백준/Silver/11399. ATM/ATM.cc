#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, ret;
vector<int> ATM;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        ATM.push_back(temp);
    }
}

void solve() {
    int temp = 0;
    sort(ATM.begin(), ATM.end());
    for (int i = 0; i < N; i++) {
        temp += ATM[i];
        ret += temp;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}