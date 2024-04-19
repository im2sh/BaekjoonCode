#include <iostream>
#include <cstring>
using namespace std;
int TC, len;
string S, ret;
void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    cin >> TC;
    for(int i =1;i <= TC; i++){
        cin >> len;
       	cin >> S;
        
        string leftS = S.substr(0, len/2);
        string rightS = S.substr(len/2, S.length());
        if(leftS == rightS)
            ret = "Yes";
        else
            ret = "No";
        
     	cout << "#" << i << " " << ret << '\n';   
     }
}

int main(void){
    FastIO();
    solve();
}