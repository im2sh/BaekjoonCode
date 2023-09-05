#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string name, state;
    map<string, string, greater<>> log;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name >> state;
        log[name] = state;
    }

    for (auto &it: log) {
        if (it.second == "enter") {
            cout << it.first << "\n";
        }
    }

    return 0;
}