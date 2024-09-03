import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    static int N, ret, TC = 1;
    static int[][] BOARD;
    static int[][] visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        while (true) {
            N = Integer.parseInt(br.readLine());
            if (N == 0) {
                break;
            }
            Init();
            solve();
            sb.append("Problem ").append(TC++).append(": ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        BOARD = new int[N + 1][N + 1];
        visited = new int[N + 1][N + 1];
        ret = Integer.MAX_VALUE;
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                visited[y][x] = Integer.MAX_VALUE;
            }
        }
    }

    public static void solve() {
        Queue<Moving> q = new ArrayDeque<>();
        q.offer(new Moving(0, 0));
        visited[0][0] = BOARD[0][0];

        while (!q.isEmpty()) {
            Moving cur = q.poll();

            for(int dir = 0; dir < 4; dir++){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;
                if(visited[ny][nx] > visited[cur.y][cur.x] + BOARD[ny][nx]){
                    visited[ny][nx] = visited[cur.y][cur.x] + BOARD[ny][nx];
                    q.offer(new Moving(ny,nx));
                }
            }
        }
        ret = Math.min(ret, visited[N-1][N-1]);
    }
}

class Moving {
    int y, x;

    public Moving(int y, int x) {
        this.y = y;
        this.x = x;
    }
}