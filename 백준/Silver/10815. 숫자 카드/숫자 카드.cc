#include <iostream>
#include <map>

using namespace std;

int N, M;
map<int, int> card;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        card[temp]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (card[temp])
            cout << card[temp] << " ";
        else
            cout << "0" << " ";
    }

}

int main(void) {
    FastIO();
    solve();
    return 0;
}