#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct info {
	int idx, y, x, distance;
	bool isDead;
}Info;

typedef struct taxi {
	int y, x, fuel;
}Taxi;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int N, M, ret;
pair<int,int> BOARD[21][21];
int visited[21][21];
vector<Info> guestDistanceList;
Info guest[404];
Info destination[404];
Taxi taxi;

void FastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void Init() {
	cin >> N >> M >> taxi.fuel;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> BOARD[y][x].second;
			BOARD[y][x].first = 0;
		}
	}
	cin >> taxi.y >> taxi.x;
	taxi.y--;
	taxi.x--;

	for (int i = 1; i <= M; i++) {
		int gY, gX, desY, desX;
		cin >> gY >> gX >> desY >> desX;
		BOARD[gY - 1][gX - 1].second = 2;
		BOARD[gY - 1][gX - 1].first = i;
		guest[i] = {i, gY - 1,gX - 1, 0, false};
		destination[i] = {i, desY - 1, desX - 1, 0, false};
	}
}

bool isDead() {
	for (int i = 1; i <= M; i++) {
		if (guest[i].isDead == false)
			return true;
	}
	return false;
}

bool cmp(Info a, Info b) {
	if(a.distance == b.distance) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.distance < b.distance;
}
void display2() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << BOARD[y][x].first << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}


void findGuest() {
	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
	guestDistanceList.clear();
	queue<pair<int, int>> q;
	q.push({ taxi.y, taxi.x });
	visited[taxi.y][taxi.x] = 1;
	guest[BOARD[taxi.y][taxi.x].first].distance = 1;
	while(q.size()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx].second == 1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[cy][cx] + 1;
			guest[BOARD[ny][nx].first].distance = visited[ny][nx] - 1;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (!guest[i].isDead && visited[guest[i].y][guest[i].x] != 0)
			guestDistanceList.push_back({ i,guest[i].y, guest[i].x, guest[i].distance, false});
	}
	for (int i = 0; i < guestDistanceList.size(); i++) {
		if (guestDistanceList[i].y == taxi.y && guestDistanceList[i].x == taxi.x) {
			guestDistanceList[i].distance--;
		}
	}

	sort(guestDistanceList.begin(), guestDistanceList.end(), cmp);
}

void display() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << BOARD[y][x].first << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool getGuest() {
	if (taxi.fuel < guestDistanceList[0].distance) {
		return false;
	}
	taxi.y = guestDistanceList[0].y;
	taxi.x = guestDistanceList[0].x;
	BOARD[taxi.y][taxi.x].first = 0;
	BOARD[taxi.y][taxi.x].second = 0;
	guest[guestDistanceList[0].idx].isDead = true;
	return true;
}

int goDestination() {
	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
	queue<pair<int,int>> q;
	q.push({ taxi.y, taxi.x });
	visited[taxi.y][taxi.x] = 1;

	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (destination[guestDistanceList[0].idx].y == cy && destination[guestDistanceList[0].idx].x == cx) {
			return visited[cy][cx] - 1;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx].second == 1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[cy][cx] + 1;
		}
	}
	return -1;
}

bool getDestination() {
	int usedFuel = goDestination();
	if (usedFuel == -1)
		return false;
	if (taxi.fuel - guestDistanceList[0].distance < usedFuel)
		return false;
	taxi.y = destination[guestDistanceList[0].idx].y;
	taxi.x = destination[guestDistanceList[0].idx].x;
	destination[guestDistanceList[0].idx].isDead = true;
	BOARD[guestDistanceList[0].y][guestDistanceList[0].x].first = 0;
	BOARD[guestDistanceList[0].y][guestDistanceList[0].x].second = 0;
	taxi.fuel = taxi.fuel - guestDistanceList[0].distance - usedFuel + (usedFuel * 2); 
	return true;
}

void solve() {
	while (true) {
		if (!isDead())
			break;
		findGuest();
		if (guestDistanceList.size() == 0) {
			cout << -1;
			return;
		}
		if (!getGuest()) {
			cout << -1;
			return;
		}
		if (!getDestination()) {
			cout << -1;
			return;
		}
	}
	cout << taxi.fuel;
}

int main() {
	FastIO();
	Init();
	solve();
	return 0;
}