import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    static int TC, N, K, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] BOARD;
    static boolean[][] visited;
    static ArrayList<Pos> highMountains;
    static boolean flag = false;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int i = 1; i <= TC; i++) {
            Init();
            solve();
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        BOARD = new int[N + 1][N + 1];
        visited = new boolean[N + 1][N + 1];
        highMountains = new ArrayList<>();
        ret = 0;
        int temp = 0;
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
                temp = Math.max(temp, BOARD[y][x]);
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (BOARD[y][x] == temp) {
                    highMountains.add(new Pos(y, x));
                }
            }
        }
    }

    public static void go(int y, int x, int now) {
        ret = Math.max(ret, now);

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
                continue;
            }

            if(!flag && BOARD[y][x] <= BOARD[ny][nx]){
                if(BOARD[ny][nx] - K < BOARD[y][x]){
                    int temp = BOARD[ny][nx];
                    BOARD[ny][nx] = BOARD[y][x] - 1;
                    flag = true;
                    visited[ny][nx] = true;
                    go(ny, nx, now + 1);
                    BOARD[ny][nx] = temp;
                    flag = false;
                    visited[ny][nx] = false;
                }
            }else if(BOARD[y][x] > BOARD[ny][nx]){
                visited[ny][nx] = true;
                go(ny,nx,now+ 1);
                visited[ny][nx] = false;
            }
        }
    }
    public static void solve () {
        for (int i = 0; i < highMountains.size(); i++) {
            visited[highMountains.get(i).y][highMountains.get(i).x] = true;
            go(highMountains.get(i).y, highMountains.get(i).x, 1);
            visited[highMountains.get(i).y][highMountains.get(i).x] = false;
        }
    }
}

class Pos {
    int y, x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}