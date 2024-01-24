#include <iostream>

using namespace std;

int N, ret, rA, rB;
int A[] = {1, 2, 3, 4, 5, 6};
int A_reward[] = {500, 300, 200, 50, 30, 10};
int B[] = {1, 2, 4, 8, 16};
int B_reward[] = {512, 256, 128, 64, 32};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        ret = 0;
        rA = 0;
        rB = 0;
        for (int j = 0; j < sizeof(A) / sizeof(A[0]); j++) {
            rA += A[j];
            if (a <= rA && a != 0) {
                ret += A_reward[j];
                break;
            }
        }

        for (int j = 0; j < sizeof(B) / sizeof(B[0]); j++) {
            rB += B[j];
            if (b <= rB && b != 0) {
                ret += B_reward[j];
                break;
            }
        }

        cout << ret * 10000 << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}