#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> temp;

bool cmp(string A, string B){
    return (A + B) > (B + A);
}

string solution(vector<int> numbers) {
    string answer = "";
    for(int i = 0; i < numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i = 0; i < temp.size(); i++){
        answer += temp[i];
    }
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}