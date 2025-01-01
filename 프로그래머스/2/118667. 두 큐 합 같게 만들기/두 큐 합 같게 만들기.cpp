#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    queue<int> A, B;
    int N = queue1.size();

    for(int i = 0; i < queue1.size(); i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
        A.push(queue1[i]);
        B.push(queue2[i]);
    }
    
    ll target = (sum1 + sum2) / 2;
    
    while (true) {
        if (answer > N * 3) 
            break;
        if(sum1 < target){
            int temp = B.front();
            B.pop();
            A.push(temp);
            sum1 += (ll) temp;
            answer++;
        }else if(sum1 > target){
            int temp = A.front();
            A.pop();
            B.push(temp);
            sum1 -= (ll) temp;
            answer++;
        }
        
        if(sum1 == target)
            return answer;
    }
    return -1;
}