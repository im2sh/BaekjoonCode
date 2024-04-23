#include <iostream>
#include <map>

using namespace std;
int TC;
string S;
map<char,int> alpha;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    cin >> TC;
    char temp = 'a';
    for(int i = 0; i < 26; i++){
        alpha[temp] = i;
       	temp++;
    }
    for(int i = 1; i <= TC; i++){
        cin >> S;
        int ret = 0;
        for(int j = 0; j < S.length(); j++){
            if(alpha[S[j]] ==j)
                ret++;
            else
                break;
        }
        cout << "#" << i << " " << ret << '\n';
    }
}

int main(void){
    FastIO();
    solve();
    return 0;
}