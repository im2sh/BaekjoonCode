#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<int> t;

bool check(long long mid){
    long long cnt = 0;
    for(int i = 0; i < t.size(); i++){
        cnt += (mid/t[i]);
    }
    return cnt >= N;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long low = 1;
    int temp = 0;
    
    N = n;
    t = times;
    
    for(int i = 0; i < times.size(); i++){
        temp = max(temp, times[i]);
    }
    long long high = (long long) n * (long long) temp;
    
    while(low <= high){
        long long mid = (low + high) / 2;
        
        if(check(mid)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return answer;
}