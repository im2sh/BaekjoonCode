#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;
        cout << (s[0]-'0')+ (s[2]-'0')<<"\n";
    }
    return 0;
}