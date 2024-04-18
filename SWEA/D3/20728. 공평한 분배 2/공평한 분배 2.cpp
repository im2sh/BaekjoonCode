#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

int TC, N, K;
ll ret = LLONG_MAX;
vector<ll> numbers;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    ret = LLONG_MAX;
    numbers.clear();
    cin >> N >> K;
     for(int j = 0; j < N; j++){
        ll temp = 0;
        cin >> temp;
     	numbers.push_back(temp);
     }
    sort(numbers.begin(), numbers.end());
}

void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        Init();
        for(int j = 0; j < N; j++){
            if((j + K -1) > (N-1))
                continue;
            ret = min(ret, numbers[j+K-1] - numbers[j]);
        }
        
        cout << "#" << i <<" " << ret << '\n';
    }
}

int main(void){
    FastIO();
    solve();
    return 0;
}	