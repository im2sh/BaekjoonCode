#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
map<string, int> dict;
vector<pair<string,int>> topGenres;
map<string, vector<pair<int,int>>> music;

bool genreCmp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

bool musicCmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;    
    for(int i = 0; i < genres.size(); i++){
        if(!dict[genres[i]])
            dict[genres[i]] = plays[i];
        else
            dict[genres[i]] += plays[i];
        music[genres[i]].push_back({i, plays[i]});
    }
    
    for(auto& it : dict){
        topGenres.push_back({it.first, it.second});
    }
    sort(topGenres.begin(), topGenres.end(), genreCmp);
    
    for(auto& it : music){
        sort(it.second.begin(), it.second.end(), musicCmp);
    }
    
    for(int i = 0; i < topGenres.size(); i++){
        for(int j = 0; j < music[topGenres[i].first].size(); j++){
            if(j > 1)
                break;
            answer.push_back(music[topGenres[i].first][j].first);
        }
    }
    
    return answer;
}