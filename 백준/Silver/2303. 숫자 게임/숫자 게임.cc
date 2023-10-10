#include <iostream>
using namespace std;

int N,num;
int maxNum = 0;
int card[1000][5]; 
int score[1000];

int main() {  
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++){
			cin >> card[i][j]; 
		}
	}
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					if (score[i] < (card[i][j] + card[i][k] + card[i][l])%10)
						score[i] = (card[i][j] + card[i][k] + card[i][l])%10;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (maxNum < score[i]) {
			maxNum = score[i];
			num = i;
		}
		if (maxNum == score[i]) {
			if (i > num) num = i;
		}
	}
	cout << num+1 << '\n';

	return 0;
}