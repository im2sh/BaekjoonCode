#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w = 0;
    int h = 0;
    for(int i = 1; i < brown/2; i++){
        int temp = i * 2;
        int d = (brown - temp) / 2;
        if((i - 2) * d == yellow){
            w = i;
            h = d + 2;
        }
    }
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}
