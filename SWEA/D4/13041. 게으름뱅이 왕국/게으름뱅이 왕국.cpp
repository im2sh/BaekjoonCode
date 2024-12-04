#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct People {
    int workIdx, time; //일의 번호와 설득 시간
};

int TC, N, K, target;
long long ret;
vector<int> work; // 일
vector<People> people; // 한 사람당 일의 번호와 설득 시간
int job[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(People a, People b) {
    return a.time < b.time;
}

void Init() {
    fill(&job[0], &job[0] + 100001, 0);
    work.clear();
    people.clear();
    ret = 0;
    target = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        work.push_back(temp);
        job[temp]++;
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        people.push_back({work[i], temp});
    }

    sort(people.begin(), people.end(), cmp);
}

void go() {
    for (int i = 1; i <= K; i++) {
        if (job[i] == 0)
            target++;
    }
    if(target == 0)
        return;
    
    for (auto &it: people) {
        if (job[it.workIdx] == 1)
            continue;
        ret += it.time;
        job[it.workIdx]--;

        if (--target == 0)
            break;
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