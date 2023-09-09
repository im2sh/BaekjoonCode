#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	long long temp;
	vector<long long> vec;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	int max = 0;
	int cnt = 0;
	long long result = vec[0];

	for (int i = 1; i < N; i++)
	{
		if (vec[i] == vec[i - 1])
		{
			cnt++;
			if (cnt > max)
			{
				max = cnt;
				result = vec[i];
			}
		}
		else
			cnt = 0;
	}

	cout << result;
	
	return 0;
}