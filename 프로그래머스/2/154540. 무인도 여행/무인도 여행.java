import java.util.*;

class Solution {
    static int N, M, sum;
    static char[][] BOARD;
    static boolean[][] visited;
    List<Integer> result = new ArrayList<>();
    private static int[] dy = {-1,1,0,0};
    private static int[] dx = {0,0,-1,1};
    
    public int[] solution(String[] maps) {
        int[] answer;
        N = maps.length;
        M = maps[0].length();
        BOARD = new char[N][M];
        visited = new boolean[N][M];
        
        for(int y= 0; y <N; y++){
            for(int x =0; x < M; x++){
                BOARD[y][x] = maps[y].charAt(x);
            }
        }
        for(int y=0; y <N; y++){
            for(int x =0 ;x<M;x++){
                sum = 0;
                if(BOARD[y][x] != 'X' && !visited[y][x]){
                    dfs(y,x);
                    result.add(sum);
                }
            }
        }
        answer = new int[result.size()];
        if(result.size() == 0){
            answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        int idx = 0;
        for(int r : result){
            answer[idx] = r;
            idx++;
        }
        Arrays.sort(answer);
    
        return answer;
    }
    
    public void dfs(int y, int x){
        sum += BOARD[y][x] - '0';
        visited[y][x] = true;
        
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == 'X')
                continue;
            dfs(ny,nx);
        }
        
    }
}

