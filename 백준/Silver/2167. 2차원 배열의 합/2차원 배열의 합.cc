#include<iostream>

using namespace  std;
int n, m, t, i, j, x, y;
int main() {
	cin >> n >> m;
	int arr[300][300];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> t;

	
	for (int k = 0; k < t; k++) {
		cin >> i >> j >> x >> y;
		int sum = 0;
		for (int r = i - 1; r < x; r++) {
			for (int c = j - 1; c < y; c++) {
				sum += arr[r][c];
			}
		}
		cout << sum<< '\n';
		
	}
    return 0;
}