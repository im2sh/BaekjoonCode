#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> seq;

string go(int n, int t, int m, int p){
    string makeN = "0";
    string temp = "";
    string N = "0123456789ABCDEF";
    int num = 1;
    int nextNum = 2;
    while(true){
        if(makeN.length() >= p + (m * t))
            break;
        while(num > 0){
            int mol = num % n;
            num /= n;
            temp += N[mol];
        }
        if(num != 0)
            temp += N[num];
        reverse(temp.begin(), temp.end());
        makeN += temp;
        temp = "";
        num = nextNum;
        nextNum++;
    }
    return makeN;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string number = go(n, t, m, p);
    for(int i = p - 1, cnt = 0; cnt < t; i+=m, cnt++){
        answer += number[i];
    }
    return answer;
}