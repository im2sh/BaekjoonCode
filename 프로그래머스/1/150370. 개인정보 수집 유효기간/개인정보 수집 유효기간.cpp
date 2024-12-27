#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> dict;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < terms.size(); i++){
        int idx = terms[i].find(" ");
        dict[terms[i].substr(0, idx)] = stoi(terms[i].substr(idx + 1, terms[i].length()));
    }
    
    for(int i = 0; i < privacies.size(); i++){
        string S = privacies[i];
        string temp = "";
        int year = 0;
        int month = 0;
        int day = 0;
        for(int j = 0; j < S.length(); j++){
            if(S[j] == '.'){
                if(year == 0){
                    year = stoi(temp);
                }else{
                    month = stoi(temp);
                }
                temp = "";
            }else if(S[j] == ' '){
                day = stoi(temp);
                temp = "";
            }else{
                temp += S[j];
            }
        }
        month += dict[temp];
        if(month >= 13){
            int div = month / 12;
            if(month % 12 == 0){
                year += div - 1;
                month = 12;
            }else{
                year += div;
                month -= div * 12;
            }
        }
        day--;
        if(day == 0){
            month--;
            if(month == 0){
                month = 12;
                year--;
            }
            day = 28;
        }
        string stringYear = to_string(year);
        string stringMonth = to_string(month);
        string stringDay = to_string(day);
        
        if(month < 10)
            stringMonth = "0" + stringMonth;
        if(day < 10)
            stringDay = "0" + stringDay;
        
        string result = stringYear + "." + stringMonth + "." + stringDay;

        if(today > result)
            answer.push_back(i + 1);
    }
    return answer;
}