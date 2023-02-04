#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double A,B,V;
    cin >> A >> B >> V;
    double result = 0;

    result = (V-A)/(A-B)+1;
    result = ceil(result);
    cout << int(result);
    return 0;
}