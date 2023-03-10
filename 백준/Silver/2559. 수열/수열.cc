#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    int tem[100000];
    int psum[100000] = {0,};
    int result = -10000001;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> tem[i];
        psum[i] = psum[i - 1] + tem[i];
    }

    for (int i = K; i <= N; i++) {
        result = max(result, psum[i] - psum[i - K]);
    }
    
    cout << result << "\n";
    
    return 0;
}