#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(void) {
    int n;
    int t;
    cin >> n;
    string name;
    string category;
    for (int i = 0; i < n; i++) {
        cin >> t;
        map<string, int> haebin;
        for (int j = 0; j < t; j++) {
            cin >> name >> category;
            haebin[category]++;
        }
        int result = 1;
        for (auto temp: haebin) {
            result *= ((temp.second) + 1);
        }
        result--;
        cout << result << "\n";
    }
    return 0;
}
