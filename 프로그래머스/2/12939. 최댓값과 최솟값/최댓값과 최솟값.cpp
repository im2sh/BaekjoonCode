#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<int> ret;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            ret.emplace_back(stoi(temp));
            temp = "";
        }else{
            temp += s[i];
        }
    }
    ret.emplace_back(stoi(temp));
    
    sort(ret.begin(), ret.end());
    answer = to_string(ret[0]) + " " + to_string(ret[ret.size() - 1]);
    return answer;
}