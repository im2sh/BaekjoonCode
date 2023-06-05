#include <iostream>

using namespace std;

int arr[9][9];
int maxN = -1;
int maxY,maxX;
void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
        }
    }
}

void solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(maxN < arr[i][j]) {
                maxN = arr[i][j];
                maxY = i + 1;
                maxX = j + 1;
            }
        }
    }

    cout << maxN << "\n";
    cout << maxY << " " << maxX;
}

int main(void){
    FastIO();
    Init();
    solve();
    return 0;
}