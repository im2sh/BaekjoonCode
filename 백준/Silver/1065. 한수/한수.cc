#include <iostream>
 
using namespace std;
 
int cal(int num) {
	int cnt = 0; 
	if (num < 100) {
		return num;
	} else {
		cnt = 99;
		for (int i = 100; i <= num; i++) {
			int hun = i / 100;		 
			int ten = (i / 10) % 10; 
			int one = i % 10;
			if ((hun - ten) == (ten - one)) { 
				cnt++;
			}
		}
	}
	return cnt;
}
 
int main(void) {
	int N;
	cin >> N;
 
	int result = cal(N);
	cout << result;
	return 0;
}