#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<int, int> student;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i <= n; i++){
        student[i] = 1;
    }
    
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]] = 0;
    }
    
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(student[i] == 0){
            if(student[i-1] > 1){
                student[i-1]--;
                student[i] = 1;
            }else if(student[i+1] > 1){
                student[i+1]--;
                student[i] = 1;
            }
        }
    }
    
    for(int i = 1; i <=n; i++){
        if(student[i] != 0)
            answer++;
    }
    return answer;
}