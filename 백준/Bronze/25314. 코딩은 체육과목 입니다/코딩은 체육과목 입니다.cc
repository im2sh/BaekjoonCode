#include <iostream>

using namespace std;
string s = "int";
int N;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int temp = N / 4;
    for (int i = 0; i < temp; i++) {
        s = "long " + s;
    }
    cout << s << '\n';
}

int main(void) {
    fastIO();
    Init();
    solve();
    return 0;
}