#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    
    int last = -1;
    for(auto it : targets){
        int start = it[0];
        int end = it[1];
        
        if(start < last && end >= last) {
            continue;
        }else{
            //cout << start << " " << end << "\n";
            last = end;
            answer++;
        }
        
    }
    return answer;
}