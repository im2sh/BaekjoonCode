#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, cnt = 0;
vector<pair<string, int>> ans;
vector<string> ex; // extension
string s, tmp;

int main()
{
	cin >> N;
    
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		s.erase(0, s.find('.') + 1);
		ex.push_back(s);
		
	}
	sort(ex.begin(), ex.end()); 

	tmp = ex[0]; 
	for (int i = 0; i < ex.size(); i++)
	{
		if (tmp == ex[i]) cnt++; 
		else if(tmp != ex[i])
		{
			ans.push_back(pair<string,int>(tmp, cnt));
			tmp = ex[i];
			cnt = 1;
		}
	}
	ans.push_back(pair<string, int>(tmp, cnt));

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << '\n';
	}
    return 0;
}