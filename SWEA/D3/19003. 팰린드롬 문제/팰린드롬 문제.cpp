#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int TC, ret;
int N, M;
vector<string> arr;
bool flag = false;
bool visited[101];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    arr.clear();
    flag = false;
    ret = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string temp;
        string reversed_s;
        cin >> temp;
        reversed_s = temp;
        arr.push_back(temp);
        visited[i] = false;
		reverse(reversed_s.begin(), reversed_s.end());        
        if(temp == reversed_s)
            flag = true;
    }
}

void solve(){
    cin >> TC;
    for(int i = 1; i <= TC; i++){
        Init();
        int cnt = 0;
        for(int j = 0; j < N; j++){
            string target = arr[j];
            if(visited[j])
                continue;
            for(int k = 0; k < N; k++){
                if(j == k || visited[k])
                    continue;
                string temp = arr[k];
                reverse(temp.begin(), temp.end());
                if(target == temp){
                    visited[j] = true;
                    visited[k] = true;
                    cnt+=2;
                }
            }
        }
        ret += cnt * M;
        
        if(flag)
            ret += M;
        cout << "#" << i << " " << ret << '\n';
    }
}

int main(void){
    FastIO();
    solve();
}