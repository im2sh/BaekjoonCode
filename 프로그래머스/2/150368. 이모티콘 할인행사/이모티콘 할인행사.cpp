#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

constexpr int rate[4] = {10,20,30,40};

int N, M, ret;
int arr[8];
vector<vector<int>> Users;
vector<int> Emoticons;
map<int, int> result;

void check(){
    int peopleCnt = 0;
    int moneySum = 0;
    for(int i = 0; i < Users.size(); i++){
        int R = Users[i][0];
        int money = Users[i][1];
        int sum = 0;
        for(int j = 0; j < Emoticons.size(); j++){
            if(R <= arr[j]){
                sum += Emoticons[j] * (1 - (arr[j] * 0.01));
            }    
        }
        if(sum >= money){
            peopleCnt++;
        }else{
            moneySum+=sum;
        }
    }
    ret = max(ret, peopleCnt);
    result[peopleCnt] = max(result[peopleCnt], moneySum);
}

void go(int depth, int idx){
    if(depth == M){
        check();
        return;
    }
    
    for(int i = 0; i < 4; i++){
        arr[idx] = rate[i];
        idx++;
        go(depth + 1, idx);
        idx--;
        arr[idx] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer (2);
    M = emoticons.size();
    for(int i = 0; i < users.size(); i++){
        vector<int> temp;
        for(int j = 0; j < users[0].size(); j++){
            temp.push_back(users[i][j]);
        }
        Users.push_back(temp);
    }
    
    for(int i = 0; i < emoticons.size(); i++){
        Emoticons.push_back(emoticons[i]);
    }
    go(0, 0);
    
    answer = {ret, result[ret]};
    return answer;
}