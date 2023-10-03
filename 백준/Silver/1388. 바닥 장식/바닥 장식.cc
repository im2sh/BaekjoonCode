#include <iostream>

using namespace std;

int n, m;
string arr[51];
bool visited[51][51];

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y) {
	visited[x][y] = true;
	int d[] = { -1, 1 };

	for (int i = 0; i < 2; i++) {
		int nx = x, ny = y;
		if (arr[x][y] == '|')
		{
			nx += d[i];
		}
		else {
			ny += d[i];
		}
		if (!inRange(nx, ny))
			continue;
		if (arr[nx][ny] != arr[x][y])
			continue;
		if (visited[nx][ny])
			continue;
		dfs(nx, ny);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				continue;
			else {
				dfs(i, j);
				ret++;
			}
		}
	}
	cout << ret << '\n';

	return 0;
}