#include <iostream>
#include <string>

using namespace std;
int N;
string s;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        cout << s[0] << s[s.length() - 1] << "\n";
    }
    return 0;
}