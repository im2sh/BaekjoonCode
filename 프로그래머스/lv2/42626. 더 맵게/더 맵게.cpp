#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
priority_queue<long long,vector<long long>, greater<long long>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(1){
        if(pq.top() >= K || pq.size() <= 1)
            break;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int sum = first + (second * 2);
        pq.push(sum);
        
        answer++;
    }
    if(pq.top() < K)
        return -1;
    return answer;
}