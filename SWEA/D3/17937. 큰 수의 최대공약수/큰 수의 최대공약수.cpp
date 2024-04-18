#include <iostream>

using namespace std;
typedef long long ll;

int TC;
string a,b;

void FastIO(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        string ret = "";
       cin >> a >> b;
        
        if(a==b)
            ret = a;
        else
            ret = "1";
        
        cout << "#" << i << " " << ret << '\n';
    }
}

int main(void){
    FastIO();
    solve();
    return 0;
}