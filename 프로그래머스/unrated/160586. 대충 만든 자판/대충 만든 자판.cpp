#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i = 0; i < targets.size(); i++){
        int temp = 0;
        for(int j = 0; j < targets[i].length(); j++){
            char t = targets[i][j];
            int idx = 987654321;
            for(int a = 0; a < keymap.size(); a++){
                for(int b = 0; b < keymap[a].length(); b++){
                    if(t == keymap[a][b]){
                        idx = min(idx, b + 1);
                    }
                }
            }    
            temp += idx;
            if(temp >= 987654321)
                break;
        }
        if(temp >= 987654321)
            temp = -1;
        answer.push_back(temp);
    }
    return answer;
}