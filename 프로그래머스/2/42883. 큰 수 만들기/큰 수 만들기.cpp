#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    char temp;
    int len = number.length() - k;
    int check = -1;
    for(int i = 0; i < len; i++){
        char choice = '0';
        for(int j = check + 1; j <= k + i; j++){
            temp = number[j];
            if(choice < temp){
                choice = temp;
                check = j;
            }
        }
        answer += choice;
    }
    return answer;
}