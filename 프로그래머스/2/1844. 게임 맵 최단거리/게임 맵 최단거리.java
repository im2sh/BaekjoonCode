import java.util.*;

class Solution {
    private static int[] dy = {-1,1,0,0};
    private static int[] dx = {0,0,-1,1};
    static int[][] dist;
    static int N, M;
    
    public int solution(int[][] maps) {
        int answer = 0;
        N = maps.length;
        M = maps[0].length;
        dist = new int[N][M];
        BFS(maps);
        if(dist[N-1][M-1] == 0)
            return -1;
        return dist[N-1][M-1];
    }
    
    public void BFS(int[][] maps){
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(0,0));
        dist[0][0] = 1;
        while(!q.isEmpty()){
            Pos cur = q.poll();
            
            for(int dir = 0; dir < 4; dir++){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];
                
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || dist[ny][nx] != 0 || maps[ny][nx] == 0)
                    continue;
                q.offer(new Pos(ny,nx));
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
            }
        }
    }
}

class Pos{
    int y;
    int x;
    
    public Pos(int y, int x){
        this.y = y;
        this.x = x;
    }
}