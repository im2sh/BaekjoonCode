#include <iostream>

using namespace std;
int TC;
double arr[3];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        double ret = 987654321;
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];
        
        double x = abs(arr[0] - (2 * arr[1] - arr[2]));
        double y = abs(arr[1] - ((arr[0] + arr[2]) / 2));
        double z = abs(arr[2] - (2 * arr[1] - arr[0]));
        
	   ret = min(ret,x);
	   ret = min(ret,y);
	   ret = min(ret,z);
        
        cout << fixed;
        cout.precision(1);
        cout << "#" << i << " " << ret << '\n';
    }
}

int main(void){
    FastIO();
    solve();
    return 0;
}