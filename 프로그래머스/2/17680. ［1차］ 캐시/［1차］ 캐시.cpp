#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

deque<string> q;
map<string, bool> cache;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); i++) {
        string temp = "";
        for (int j = 0; j < cities[i].length(); j++) {
            if (97 <= cities[i][j] && cities[i][j] <= 122)
                temp += cities[i][j] - 32;
            else
                temp += cities[i][j];
        }
        cities[i] = temp;
    }

    if (cacheSize == 0) {
        return 5 * cities.size();
    }

    for (int i = 0; i < cities.size(); i++) {
        if (cache[cities[i]]) {
            deque<string> temp;
            while (true) {
                string now = q.front();
                q.pop_front();
                if (now == cities[i]) {
                    while (temp.size()) {
                        q.push_front(temp.back());
                        temp.pop_back();
                    }
                    q.push_back(now);
                    break;
                }
                temp.push_back(now);
            }
            answer += 1;
        } else {
            if(q.size() == cacheSize){
                cache[q.front()] = false;
                q.pop_front();
            }
            cache[cities[i]] = true;
            q.push_back(cities[i]);

            answer += 5;
        }
    }

    return answer;
}