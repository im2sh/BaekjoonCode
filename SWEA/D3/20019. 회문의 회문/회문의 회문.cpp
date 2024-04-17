#include <iostream>
#include <cstring>
#include <algorithm>

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
    for(int i = 1; i <= TC; i++){
        string s;
        string reversed_s;
        cin >> s;
        reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        if(s == reversed_s){
			string fs = s.substr(0,s.length()/2);
            string ss = reversed_s.substr(0,s.length()/2);
            reverse(ss.begin(), ss.end());
            if(fs == ss){
	            cout << "#" << i << " " << "YES\n";
            }else{
                cout << "#" << i << " " << "NO\n";
            }
        }else{
            cout << "#" << i << " " << "NO\n";
        }
        
    }
}

int main(void){
    FastIO();
    Init();
    solve();
    return 0;
}