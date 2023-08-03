#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b;
    cin >> a >> b;
    
    double plus = -a + sqrt(a*a - b);
    double minus = -a - sqrt(a*a - b);
    if (plus == minus) cout << plus << '\n';
    else
        cout << minus << " " << plus << '\n';
    return 0;
}