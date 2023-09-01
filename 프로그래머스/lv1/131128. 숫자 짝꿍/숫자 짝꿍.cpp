#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<char, int> X1;
map<char, int> Y1;
vector<int> aa;

bool cmp(int a, int b){
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    string temp = "";
    bool flag = false;
    
    for(int i = 0; i < X.length(); i++){
        X1[X[i]]++;
    }
    for(int i = 0; i < Y.length(); i++){
        Y1[Y[i]]++;
    }
    
    // for(int i = 0; i < X.length(); i++){
    //     int t = X[i];
    //     for(int j = 0; j < Y.length(); j++){
    //         if(Y1[t] && X1[t]){
    //             aa.push_back(t-'0');
    //             Y1[t]--;
    //             X1[t]--;
    //         }
    //     }
    // }
    
    if(X.length() > Y.length())
        temp = X;
    else
        temp = Y;
    
    for(int i = 0; i < 10; i++){
        if(X1[i + '0'] == 0 || Y1[i + '0'] == 0)
            continue;
        if(X1[i + '0'] > Y1[i + '0']){
            for(int j = 0; j < Y1[i+ '0']; j++){
                aa.push_back(i);
            }
        }
        else{
            for(int j = 0; j < X1[i+'0']; j++){
                aa.push_back(i);
            }
        }
    }
    
    sort(aa.begin(), aa.end(), cmp);
    
    for(int i = 0; i < aa.size(); i++){
        if(aa[i] != 0)
            flag = true;
        answer += aa[i] + '0';
    }
    
    if(answer == "")
        answer = "-1";
    else if(!flag)
        answer = "0";
    
    return answer;
}