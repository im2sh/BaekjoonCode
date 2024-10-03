#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> dict;
vector<pair<string, string>> commandSeq;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i = 0; i < record.size(); i++){
        bool first = false;
        bool second = false;
        bool leave = false;
        string command, id, name;
        string temp = "";
        for(int j = 0; j < record[i].length(); j++){
            if(record[i][j] == ' ' && !first){
                command = temp;
                if(command == "Leave")
                    leave = true;
                first = true;
                temp = "";
            }else if(record[i][j] == ' ' && !second){
                id = temp;
                second = true;
                temp = "";
            }else{
                temp += record[i][j];
            }
        }
        if(!leave)
            commandSeq.push_back({command, id});
        else
            commandSeq.push_back({command, temp});
        
        if(!leave){
            name = temp;
            dict[id] = name;
        }
    }  
    for(int i = 0; i < commandSeq.size(); i++){
        if(commandSeq[i].first == "Enter"){
            answer.push_back(dict[commandSeq[i].second] + "님이 들어왔습니다.");
        }else if(commandSeq[i].first == "Leave"){
            answer.push_back(dict[commandSeq[i].second] + "님이 나갔습니다.");
        }
    }
    return answer;
}