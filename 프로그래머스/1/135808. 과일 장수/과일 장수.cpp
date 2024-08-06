#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<int,int> fruit;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    for(int i = 0; i < score.size(); i++){
        fruit[score[i]]++;
    }
    int pastFruit = 0;
    for(int i = k; i >= 1; i--){
        if(!fruit[i])
            continue;
        int nowFruit = fruit[i] + pastFruit;
        pastFruit = nowFruit % m;
        answer +=  (nowFruit/m) * m * i;
    }
    return answer;
}