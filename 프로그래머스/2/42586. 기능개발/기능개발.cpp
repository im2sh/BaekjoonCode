#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cntDay = 0;
    for(int i = 0; i < progresses.size(); i++){
        int sum = 1;
        int remain = 100 - progresses[i];
        int day = ceil((double) remain / (double) speeds[i]) + cntDay;

        for(int j = i + 1; j < progresses.size(); j++){
            if(progresses[j] + speeds[j] * (day - cntDay) >= 100){
                sum++;
                i++;
            }else{
                break;
            }
        }
        
        for(int j = i; j < progresses.size(); j++){
            progresses[j] += speeds[j] * (day - cntDay);
        }
        
        cntDay = day;
        answer.push_back(sum);
    }
    return answer;
}

