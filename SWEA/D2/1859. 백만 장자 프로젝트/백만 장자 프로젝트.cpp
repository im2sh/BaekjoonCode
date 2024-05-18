#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int TC, N;
ll ret;
vector<ll> goods;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ret = 0;
    goods.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        goods.push_back(temp);
    }
}

void go() {
    ll standard = goods[N - 1];
    ll sum = 0;
    ll cnt = 0;
    for (int i = goods.size() - 2; i >= 0; i--) {
        if (standard > goods[i]) {
            cnt++;
            sum += goods[i];
        } else if (standard < goods[i]) {
            ret += (standard * cnt) - sum;
            cnt = 0;
            sum = 0;
            standard = goods[i];
        }
    }
    if (cnt != 0 || sum != 0) {
        ret += (standard * cnt) - sum;
    }
}

void solve() {
    cin >> TC;
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