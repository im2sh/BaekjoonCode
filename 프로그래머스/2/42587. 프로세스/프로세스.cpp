#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> pq;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }
    
    while(q.size()){
        pair<int,int> now = q.front();
        q.pop();
        
        if(pq.top() == now.second){
            pq.pop();
            answer++;
            if(location == now.first)
                break;
        }else{
            q.push(now);
        }
    }
    return answer;
}