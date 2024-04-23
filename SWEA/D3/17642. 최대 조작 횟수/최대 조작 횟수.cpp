#include <iostream>

using namespace std;
typedef long long ll;
int TC;
ll A, B;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    cin >> A >> B;
}

ll go(){
	if(A == B)
        return 0;
    if(A > B)
        return -1;
    ll diff = B-A;
   	if(diff == 1)
        return -1;
    return diff / 2;
}

void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        Init();
        cout << "#" << i << " " << go() << '\n';
    }
}

int main(void){
    FastIO();
    solve();
    return 0;
}