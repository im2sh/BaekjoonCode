#include <string>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int visited[7];
map<unsigned long long, int> M;
bool isPrime(string temp){
    //cout << temp << "\n";
    
    if(temp == "" || stoi(temp) < 2)
        return false;
    int tn = stoi(temp);
    for(int i = 2; i < tn; i++){
        if(tn % i == 0)
            return false;
    }
    return true;
}

void go(string temp, string numbers){
    if(isPrime(temp)){
        M[stoi(temp)]++;    
    }
    
    for(int i = 0; i < numbers.length(); i++){
        if(!visited[i]){
            visited[i] = 1;
            go(temp + numbers[i], numbers);
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    string temp = "";
    go(temp, numbers);
    
    // for(int i = 0; i <= 9999999; i++){
    //     M[i] = 0;
    // }
    
    for(int i = 0; i <= 9999999; i++){
        if(M[i] >= 1){
            cout << i << "\n";
            answer++;
        }
    }
    return answer;
}