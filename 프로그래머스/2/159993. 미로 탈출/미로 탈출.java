import java.util.*;

class Solution {
    static char[][] BOARD;
    static boolean[][] visited;
    static int[][] dist;
    static int N;
    static int M;
    static Pos start;
    static Pos lever;
    static Pos exit;
    static boolean findLever = false;
    private static int dy[] = {-1,1,0,0};
    private static int dx[] = {0,0,-1,1};
    
    public int solution(String[] maps) {
        int answer = 0;
        N = maps.length;
        M = maps[0].length();
        BOARD = new char[N][M];
        visited = new boolean[N][M];
        dist = new int[N][M];
         
        for(int i = 0; i < maps.length; i++){
            for(int j = 0; j < maps[i].length(); j++){
                BOARD[i][j] = maps[i].charAt(j);
                if(BOARD[i][j] == 'S')
                    start = new Pos(i,j);
                else if(BOARD[i][j] == 'L')
                    lever = new Pos(i,j);
                else if(BOARD[i][j] == 'E')
                    exit = new Pos(i,j);
            }
        }
        
        bfs(start);
        if(dist[lever.y][lever.x] == 0)
            return -1;
        
        answer = dist[lever.y][lever.x] - 1;
        findLever = true;
        init();
        bfs(lever);
        if(dist[exit.y][exit.x] == 0)
            return -1;
        answer += dist[exit.y][exit.x] - 1;
        return answer;
    }

    public void init(){
        for(int y= 0; y <N; y++){
            for(int x= 0; x < M; x++){
                visited[y][x] = false;
                dist[y][x] = 0;
            }
        }
    }
    
    public void bfs(Pos p){
        Queue<Pos> q = new LinkedList<Pos>();
        q.offer(p);
        visited[p.y][p.x] = true;
        dist[p.y][p.x] = 1;
        while(!q.isEmpty()){
            Pos cur = q.poll();
            if(!findLever && BOARD[cur.y][cur.x] == 'L')
                break;
            if(findLever && BOARD[cur.y][cur.x] == 'E')
                break;
            for(int dir = 0; dir < 4; ++dir){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];
                
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx] == 'X' || visited[ny][nx])
                    continue;
                q.offer(new Pos(ny,nx));
                visited[ny][nx] = true;
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
            }
        }
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