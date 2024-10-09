#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, ret = 987654321;
vector<int> tools;
vector<string> m;
vector<int> t;

int cal(){
    int sum = 0;
    int idx = 0;
    int now = t[idx];
    
    for(int i = 0; i < m.size(); i++){
        if(i >= t.size() * 5)
            break;
        if(i != 0 && i % 5 == 0){
            now = t[++idx];
        }
        if(now == 0){
            sum++;
        }
        else if(now == 1){
            if(m[i] == "diamond")    
                sum +=5;
            else
                sum++;
        }else{
            if(m[i] == "diamond")
                sum += 25;
            else if(m[i] == "iron")
                sum += 5;
            else
                sum++;
        }
    }
    return sum;
}

void go(){
    if(t.size() * 5 >= m.size() || t.size() == N){
        ret = min(ret, cal());
        return;
    }
    
    for(int i = 0; i < tools.size(); i++){
        if(tools[i]){
            tools[i]--;
            t.push_back(i);
            go();
            t.pop_back();
            tools[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    for(int i = 0; i < picks.size(); i++){
        N += picks[i];
    }
    tools = picks;
    m = minerals;
    go();
    answer =ret;
    return answer;
}