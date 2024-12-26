#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int N;
bool first = true;
map<string, int> dict;

void refill(vector<string> want, vector<int> number){
    for(int i = 0; i < want.size(); i++){
        if(first)
            N += number[i];
        dict[want[i]] = number[i];
    }
    first = false;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i = 0; i <= discount.size() - 10; i++){
        int cnt = 0;
        refill(want, number);
        for(int j = i; j < i + 10; j++){
            dict[discount[j]]--;
            if(dict[discount[j]] == 0)
                cnt++;
        }
        if(cnt == want.size())
            answer++;
    }
    return answer;
}