import java.util.*;

class Solution {
    private static int dy[] = {-1,1,0,0};
    private static int dx[] = {0,0,-1,1};
    
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int N = board.length;
        for(int dir = 0; dir < 4; dir++){
            int ny = h + dy[dir];
            int nx = w + dx[dir];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if(board[h][w].equals(board[ny][nx]))
                answer++;
        }
        
        return answer;
    }
}