#include <iostream>
#include <stack>

using namespace std;
int N, C, X;
stack<int> S;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

void solve() {
    cin >> N;
    while (N--) {
        cin >> C;
        if (C == 1) {
            cin >> X;
            S.push(X);
        }
        else if (C == 2) {
            if (S.empty()) {
                cout << "-1\n";
            }
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (C == 3) {
            cout << (int)S.size() << "\n";
        }
        else if (C == 4) {
            if (S.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (C == 5) {
            if (S.empty()) {
                cout << "-1\n";
            }
            else {
                cout << S.top() << "\n";
            }
        }
    };
}

int main() {
    FastIO();
    solve();
    return 0;
}