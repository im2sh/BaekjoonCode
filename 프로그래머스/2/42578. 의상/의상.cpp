#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, int> dict;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i <  clothes.size(); i++){
        dict[clothes[i][1]]++;
    }
    for(auto& it : dict){
        answer += (answer * it.second);
    }
    answer--;
    return answer;
}