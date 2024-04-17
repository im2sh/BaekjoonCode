#include <iostream>
#include <map>

using namespace std;
int TC, N, M, Q;
map<int, string> S;
map<int, string> T;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    S.clear();
    T.clear();
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        S[i] = temp;
    }
    
    for(int i = 0; i < M; i++){
        string temp;
        cin >> temp;
        T[i] = temp;
    }
    cin >> Q;
}
void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        string ret = "";
        Init();
        for(int j = 0; j < Q; j++){
            int temp = 0;
            cin >> temp;
            temp -= 1;
            int targetS = temp % N;
            int targetT = temp % M;

            ret += S[targetS] + T[targetT];
            if(j != Q-1)
		        ret += " ";
        }
        cout << "#" << i <<" " << ret << '\n';
    }
}
int main(void){
    FastIO();
    solve();
    return 0;
}