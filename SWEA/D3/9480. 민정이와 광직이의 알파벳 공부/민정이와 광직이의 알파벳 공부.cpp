#include <iostream>
#include <vector>

using namespace std;
int TC, N, ret;
vector<string> dict;
vector<string> td;
bool visited[16];
bool alpha[26];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    fill(&visited[0], &visited[0] + 16, false);
    dict.clear();
    ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        dict.push_back(temp);
    }
}

bool check() {
    for (int i = 0; i < 26; i++) {
        alpha[i] = false;
    }

    for (int i = 0; i < td.size(); i++) {
        for (int j = 0; j < td[i].size(); j++) {
            alpha[td[i][j] - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] == false) {
            return false;
        }
    }
    return true;
}

void go(int idx) {
    if (check()) {
        ret++;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            td.push_back(dict[i]);
            go(i + 1);
            td.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        Init();
        go(0);

        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}