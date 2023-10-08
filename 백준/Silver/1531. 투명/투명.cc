#include <iostream>

using namespace std;

int n, m, picture[101][101], ret;
int a, b, c, d;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        for(int j = a; j <= c; j++){
            for(int k = b; k <= d; k++){
                picture[j][k]++;
            }
        }
    }
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(picture[i][j] > m)
                ret++;
        }
    }
    
    cout << ret;
    
    return 0;
}