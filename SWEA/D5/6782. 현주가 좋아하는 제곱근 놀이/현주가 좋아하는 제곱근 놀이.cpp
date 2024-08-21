#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
 
using namespace std;
typedef long long ll;
 
int TC, ret;
ll N;
 
void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
void Init() {
    ret = 0;
    cin >> N;
}
 
void go(){
    queue<ll> q;
    q.push(N);
 
    while(q.size()){
        ll cur = q.front();
        q.pop();
        if(cur == 2)
            break;
        ll temp = (ll) sqrt(cur);
        if(pow(temp,2) == cur){
            q.push(temp);
            ret++;
        }else{
            temp = pow(temp + 1, 2);
            q.push(temp);
            ret += (temp - cur);
        }
    }
}
 
void solve() {
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        Init();
        go();
        cout << '#' << i << ' ' << ret << '\n';
    }
}
 
int main(void) {
    FastIO();
    solve();
    return 0;
}