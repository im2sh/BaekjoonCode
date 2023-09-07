#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <map>

using namespace std;
int A[10001] = {1,2,3,4,5};
int B[10001] = {2,1,2,3,2,4,2,5};
int C[10001] = {3,3,1,1,2,2,4,4,5,5};

int cnt[3];
map<int, char> M;

bool cmp(int a, int b){
    return a > b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int temp = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == A[i%5])
            cnt[0]++;;
        if(answers[i] == B[i%8])
            cnt[1]++;
        if(answers[i] == C[i%10])
            cnt[2]++;
    }
    
    for(int i = 0; i < 3; i++){
        temp = max(temp, cnt[i]);
    }    
    
    for(int i = 0; i < 3; i++){
        if(temp == cnt[i]){
            answer.push_back(i+1);
        }
    }

    return answer;
}