#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    int temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve(){
    sort(arr.begin(), arr.end());
    cout << arr[M-1];
}

int main(void){
    FastIO();
    Init();
    solve();
    return 0;
}