#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> d, t;
long long l;

bool check(int target){
    long long sum = 0;
    for(int i = 1; i < d.size(); i++){
        if(target < d[i]){
            sum += (d[i] - target) * (t[i] + t[i-1]) + t[i];
        }else{
            sum += t[i];
        } 
    }
    if(sum <= l)
        return true;
    return false;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int low = 1;
    int high = 0;
    d.push_back(1);
    t.push_back(0);
    for(int i = 0; i < diffs.size(); i++){
        d.push_back(diffs[i]);
        t.push_back(times[i]);
    }
    l = limit;
    
    for(int i = 1; i < diffs.size(); i++){
        high = max(high, diffs[i]);
    }
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return answer;
}