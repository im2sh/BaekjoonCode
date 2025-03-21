#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

set<string> dict;
map<string,int> mp;
vector<pair<int, pair<int,int>>> ret;

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(a.first == b.first)
        return a.second.first < b.second.first;
    return a.first < b.first;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int left = 0;
    int right = 0;
    map<string, bool> temp;
    for(int i = 0; i < gems.size(); i++){
        temp[gems[i]] = true;
    }
    int size = temp.size();
    dict.insert(gems[0]);
    if(size == 1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }
    mp[gems[0]]++;
    while(left <= right){
        if(dict.size() < size){
            right++;
            if(right >= gems.size()){
                break;
            }
            dict.insert(gems[right]);
            mp[gems[right]]++;
        }else{
            mp[gems[left]]--;
            if(mp[gems[left]] == 0)
                dict.erase(gems[left]);
            left++;
            dict.insert(gems[left]);
        }
        
        if(dict.size() == size){
            ret.push_back({right - left, {left + 1, right + 1}});
        }
    }
    
    sort(ret.begin(), ret.end(), cmp);
    
    answer.push_back(ret[0].second.first);
    answer.push_back(ret[0].second.second);
    
    return answer;
}