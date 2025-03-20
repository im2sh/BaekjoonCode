#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int target, int k){
    vector<int> S;
    for(int i = 0; i < stones.size(); i++){
        S.push_back(stones[i]);
    }
    for(int i = 0; i < S.size(); i++){
        S[i] -= (target - 1);
        if(S[i] < 0)
            S[i] = 0;
    }
    
    S.push_back(1);
    
    int past = -1;
    
    for(int i = 0; i < S.size(); i++){
        if(S[i] > 0){
            if(i - past <= k)
                past = i;
            else
                return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 1;
    int high = 0;
    for(int i = 0; i < stones.size(); i++){
        high = max(high, stones[i]);
    }
    
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(check(stones, mid, k)){
            answer = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return answer;
}