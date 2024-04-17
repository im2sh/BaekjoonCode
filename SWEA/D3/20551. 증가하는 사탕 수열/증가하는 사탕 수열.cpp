#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int TC;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
	cin >> TC;    
}

void solve(){
    int a,b,c;
    for(int i = 1; i<=TC; i++){
        vector<int> temp;
        int ret = 0;
        
        cin >> a >> b >> c;
        if(c == 2 || c == 1){
            cout << '#' << i << " " << -1 << '\n';
            continue;
        }
        
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        
       reverse(temp.begin(), temp.end());
      	if(temp[0] <= temp[1]){
	       int t = (temp[1] - temp[0]) + 1;
           temp[1] -= t;
            ret += t;
        }
        
        if(temp[1] <= temp[2]){
            int t = (temp[2] - temp[1]) + 1;
            temp[2] -= t;
            ret += t;
        }
        
        if(temp[0] == 0 || temp[1] == 0 || temp[2] == 0){        
	        cout << '#' << i << " " << -1 << '\n';
            continue;
        }
        cout << '#' << i << " " << ret << '\n';
    }   
}

int main(void){
    FastIO();
    Init();
    solve();
    return 0;
}