#include <iostream>
#include <list>

using namespace std;
int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        list<char> l;
        string temp;
        cin >> temp;
        auto cursor = l.begin();
        for (auto t: temp) {
            if (t == '<') {
                if (cursor != l.begin()) 
                    cursor--;
            } else if (t == '>') {
                if (cursor != l.end()) 
                    cursor++;
            } else if (t == '-') {
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            } else
                l.insert(cursor, t);

        }
        for (auto e: l) 
            cout << e;
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
