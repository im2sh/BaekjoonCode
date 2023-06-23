#include <string>
#include <vector>

using namespace std;
char char_board[31][31] = {0, };
int check[31][31];
bool isMoved = true;

void MoveToBoard(vector<string> board){
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[i].length(); j++){
            char_board[i][j] = board[i][j];    
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    MoveToBoard(board);
    while(isMoved){
        fill(&check[0][0], &check[0][0] + 31 * 31, 0);
        isMoved = false;
        
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                if(char_board[y][x] == '#')
                    continue;
                if(char_board[y-1][x-1] == char_board[y][x-1] && char_board[y-1][x-1] == char_board[y-1][x] && char_board[y-1][x-1] == char_board[y][x]){
                    check[y][x] = 1;
                    check[y-1][x] = 1;
                    check[y][x-1] = 1;
                    check[y-1][x-1] = 1;
                    isMoved = true;
                }
            }
        }

        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                if(check[y][x]){
                    char_board[y][x] = '#';
                    answer++;
                }
            }
        }
        
        for(int y = 1; y < m; y++){
            for(int x = 0; x < n; x++){
                if(char_board[y][x] == '#'){
                    for(int k = y; k > 0; k--){
                        char_board[k][x] = char_board[k-1][x];
                        char_board[k-1][x] = '#';
                    }
                }
            }
        }
    }
    return answer;
}