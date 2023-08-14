#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        arr.push_back(s[i] - '0');
    }
}

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    s = "";
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < arr.size(); i++)
        s += arr[i] + '0';
    cout << s << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}