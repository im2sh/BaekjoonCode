#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector< pair<int, int>> score(8); 
	int sum = 0;
	int arr[5] = {};

	for (int i = 0; i < 8; i++)
	{
		cin >> score[i].first;
		score[i].second = i;
	}

	sort(score.begin(), score.begin() + 8);

	for (int i = 7; i > 2; i--)
	{
		arr[7 - i] = score[i].second;
		sum += score[i].first;
	}

	sort(arr, arr + 5);

	cout << sum << "\n";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] + 1 << " ";
	}
    return 0;
}