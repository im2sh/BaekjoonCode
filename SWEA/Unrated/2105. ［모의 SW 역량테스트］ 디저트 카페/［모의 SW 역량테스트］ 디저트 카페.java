import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    final static int[] dy = {1,1,-1,-1};
    final static int[] dx = {1,-1,-1,1};
    static int TC, N, ret;
    static int[][] BOARD;
    static boolean[] visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for(int i = 1; i <= TC; i++){
            Init();
            solve();
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        ret = -1;
        N = Integer.parseInt(br.readLine());
        BOARD = new int[N+1][N+1];
        for(int y = 0; y <N;y++ ){
            st = new StringTokenizer(br.readLine());
            for(int x= 0; x < N; x++){
                BOARD[y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void dfs(int sy, int sx, int y, int x, int depth, int direction){
        for(int dir = direction; dir <= direction + 1 && dir <= 3; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(sy == ny && sx == nx) {
                ret = Math.max(ret, depth);
                return;
            }

            if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[BOARD[ny][nx]])
                continue;
            visited[BOARD[ny][nx]] = true;
            dfs(sy,sx, ny,nx,depth+1,dir);
            visited[BOARD[ny][nx]] = false;
        }
    }

    public static void solve(){
        for(int y = 0; y < N - 2; y++){
            for(int x = 1; x < N - 1; x++){
                visited = new boolean[101];
                visited[BOARD[y][x]] = true;
                dfs(y,x,y,x,1,0);
            }
        }
    }

}