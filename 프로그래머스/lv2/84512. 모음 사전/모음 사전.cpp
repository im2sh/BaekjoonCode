#include <string>
#include <vector>

using namespace std;

string alpha = "AEIOU";
int cnt = 0;
int ret;
void go(string temp, string word){
    cnt++;
    if(temp == word){
        ret = cnt;
        return;
    }
    if(temp.length() >= 5)
        return;
    
    for(int i = 0; i < 5; i++){
        go(temp + alpha[i], word);
    }
}

int solution(string word) {
    int answer = 0;
    string temp = "";
    for(int i = 0; i < 5; i++){
        temp = alpha[i];
        go(temp, word);
        
    }
    answer = ret;
    return answer;
}