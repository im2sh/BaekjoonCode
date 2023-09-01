#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    string s;
    cin >> s;

    int sum = 0;
    int check_zero = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
        if (s[i] - '0' == 0) {
            check_zero = 1;
        }
    }

    if (sum % 3 != 0 || check_zero == 0) {
        cout << "-1" << '\n';
        return 0;
    }

    sort(s.begin(), s.end(), cmp);

    cout << s << '\n';

    return 0;
}