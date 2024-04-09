import java.util.*;

class Solution {
    static int[][] BOARD = new int[102][102];
    static int N, M, ret = 987654321;
    static Pos start;
    static Pos end;
    static int[][] dist = new int[102][102];
    private static int[] dy = {1,-1,0,0};
    private static int[] dx = {0,0,1,-1};
    private static int[] edy = {0,-1,-1,-1,0,1,1,1};
    private static int[] edx = {-1,-1,0,1,1,1,0,-1};
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        start = new Pos(characterY * 2, characterX * 2);
        end = new Pos(itemY * 2, itemX * 2);
        
        for(int i = 0; i < rectangle.length; i++){
            int y1 = rectangle[i][1] * 2;
            int x1= rectangle[i][0] * 2;
            int y2 = rectangle[i][3] * 2;
            int x2 = rectangle[i][2] * 2;
            
            N = Math.max(N, y2);
            M = Math.max(M, x2);
        }
        N++;
        M++;
        System.out.println(N + " - " + M);
        drawing(rectangle);
        
        bfs();
        answer = dist[end.y][end.x] / 2;
        return answer;
    }
    
    public void bfs(){
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(start.y, start.x));
        dist[start.y][start.x] = 1;
  
        while(!q.isEmpty()){
            Pos cur = q.poll();
            if(cur.y == end.y && cur.x == end.x)
                return;
            for(int dir = 0; dir < 4; dir++){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];
                
                if(ny < 0 || ny >= N + 1|| nx < 0 || nx >= M + 1|| dist[ny][nx] > 0 || BOARD[ny][nx] == 0 || BOARD[ny][nx] == 1)
                    continue;
                q.offer(new Pos(ny,nx));
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
            }
        }
    }
    
    public void drawing(int[][] rectangle){
        for(int i = 0; i < rectangle.length; i++){
            int y1 = rectangle[i][1] * 2;
            int x1= rectangle[i][0] * 2;
            int y2 = rectangle[i][3] * 2;
            int x2 = rectangle[i][2] * 2;
            
            for(int y = y1; y <= y2; y++){
                for(int x = x1; x <= x2; x++){
                    BOARD[y][x] = 1;
                }
            }
        }
        
        for(int y=0;y <= N; y++){
            for(int x= 0; x <= M; x++){
                if(BOARD[y][x] == 1){
                    for(int dir = 0; dir < 8; dir++){
                        int ny = y + edy[dir];
                        int nx = x + edx[dir];
                        
                        if(ny < 0 || ny >= N + 1|| nx < 0 || nx >= M + 1)
                            continue;
                        if(BOARD[ny][nx] == 0){
                            BOARD[y][x] = 2;
                            break;
                        }
                        
                    }
                }
            }
        }
    }
    
}

class Pos{
    int y;
    int x;
    public Pos(int y,int x){
        this.y = y;
        this.x = x;
    }
}