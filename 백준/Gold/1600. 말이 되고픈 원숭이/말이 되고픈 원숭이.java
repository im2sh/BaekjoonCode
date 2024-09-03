import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static final int[] my = {-1,1,0,0};
    static final int[] mx = {0,0,-1,1};

    static final int[] hy = {-1,-2,-2,-1,1,2,2,1};
    static final int[] hx = {-2,-1,1,2,2,1,-1,-2};
    static int K, W, H, ret = Integer.MAX_VALUE;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] BOARD;
    static int[][][] visited;
    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        K = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        ret = Integer.MAX_VALUE;
        BOARD = new int[H+1][W+1];
        visited = new int[H+1][W+1][K+1];
        for(int y = 0; y < H; y++){
            st = new StringTokenizer(br.readLine());
            for(int x =0;x <W; x++){
                BOARD[y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void display(){
        for(int i = 0; i <= K; i++){
            for(int y = 0; y < H; y++){
                for(int x = 0;x  <W;x++){
                    System.out.print(visited[y][x][i] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void solve(){
        Queue<MonkeyMoving> q = new ArrayDeque<>();
        q.offer(new MonkeyMoving(0,0,0));
        visited[0][0][0] = 1;
        while(!q.isEmpty()){
            MonkeyMoving cur = q.poll();
            for(int dir = 0; dir < 4; dir++){
                int ny = cur.y + my[dir];
                int nx = cur.x + mx[dir];

                if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx][cur.moving] > 0 || BOARD[ny][nx] == 1) {
                    continue;
                }
                q.add(new MonkeyMoving(ny,nx,cur.moving));
                visited[ny][nx][cur.moving] = visited[cur.y][cur.x][cur.moving] + 1;
            }
            if(cur.moving + 1 > K)
                continue;

            for(int dir = 0; dir < 8; dir++){
                int ny = cur.y + hy[dir];
                int nx = cur.x + hx[dir];

                if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx][cur.moving + 1] > 0 || BOARD[ny][nx] == 1)
                    continue;
                q.add(new MonkeyMoving(ny,nx,cur.moving + 1));
                visited[ny][nx][cur.moving+1] = visited[cur.y][cur.x][cur.moving] + 1;
            }
        }

        for(int i = 0; i <= K; i++){
            if(visited[H-1][W-1][i] == 0)
                continue;
            ret = Math.min(ret, visited[H-1][W-1][i] - 1);
        }
        if(ret == Integer.MAX_VALUE)
            ret = -1;
        System.out.print(ret);
    }
}

class MonkeyMoving{
    int y,x,moving;

    public MonkeyMoving(int y, int x, int moving) {
        this.y = y;
        this.x = x;
        this.moving = moving;
    }
}