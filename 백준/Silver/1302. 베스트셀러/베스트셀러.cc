#include <iostream>
#include<map>

using namespace std;

int main() {
    map<string, int> book;
    int n, max = 0;;
    string ret, str;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        book[str]++;
    }

    for (auto it: book) {
        if (it.second > max) {
            max = it.second;
            ret = it.first;
        }
    }
    cout << ret;
    return 0;
}
