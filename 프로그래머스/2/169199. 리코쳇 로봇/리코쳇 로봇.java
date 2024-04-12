import java.util.*;

class Solution {
    static char[][] BOARD;
    static int N, M;
    static int[][] dist;
    static Pos start,end;
    
    private static int[] dy = {-1,1,0,0};
    private static int[] dx = {0,0,-1,1};
    
    public int solution(String[] board) {
        int answer = 0;
        N = board.length;
        M = board[0].length();
        dist = new int[N][M];
        BOARD = new char[N][M];
        for(int i = 0; i < board.length; i++){
            for(int j =0; j < board[i].length(); j++){
                BOARD[i][j] = board[i].charAt(j);
                if(BOARD[i][j] == 'R'){
                    start = new Pos(i,j);
                    BOARD[i][j] = '.';
                }else if(BOARD[i][j] == 'G'){
                    end = new Pos(i,j);
                }
            }
        }
        if(bfs())
            return dist[end.y][end.x] - 1;
        return -1;
    }
    
    public Pos moving(int ny, int nx, int dir){
        int cy = ny;
        int cx = nx;
        while(true){
            ny = cy + dy[dir];
            nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx] == 'D')
                return new Pos(cy,cx);
            cy = ny;
            cx = nx;
        }
    }
    
    public boolean bfs(){
        Queue<Pos> q = new LinkedList<>();
        q.offer(start);
        dist[start.y][start.x] = 1;
        while(!q.isEmpty()){
            Pos cur = q.poll();
            if(cur.y == end.y && cur.x == end.x)
                return true;
            for(int dir = 0; dir < 4;dir++){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];
                
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx] == 'D')
                    continue;
                Pos np = moving(ny,nx, dir);
                if(dist[np.y][np.x] > 0)
                    continue;
                dist[np.y][np.x] = dist[cur.y][cur.x] + 1;
                q.offer(np);
            }
        }
        return false;
    }
}


class Pos{
    int y;
    int x;
    
    Pos(int y, int x){
        this.y = y;
        this.x = x;
    }
}