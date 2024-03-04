#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.assign(2,0);
    int start = 0;
    int end = 1;
    int sum = sequence[start];
    int len = 987654321;

    while(start < sequence.size() && end < sequence.size()){
        sum += sequence[end];
        if(sum == k){
            int temp = end - start;
            if(len > temp){
                len = temp;
                answer[0] = start;
                answer[1] = end;
            }
            end++;
        }
        else if(sum < k){
            end++;
        }else if(sum > k){
            sum -= sequence[start];
            sum -= sequence[end];
            start++;
        }
    }
    
    if(sequence[0] == k){
        answer[0] = answer[1] = 0;
    }

    return answer;
}