import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int N, M, R;
    static int[][] BOARD = new int[301][301];
    static int[][] COPY_BOARD = new int[301][301];
    static boolean[][] visited = new boolean[301][301];

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }
    static void Init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < M; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void display() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                System.out.print(COPY_BOARD[y][x] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void go(int y, int x) {
        int dir = 0;
        while (true) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
                dir = (dir + 1) % 4;
                ny = y + dy[dir];
                nx = x + dx[dir];
            }
            if (visited[ny][nx]) break;
            COPY_BOARD[ny][nx] = BOARD[y][x];
            y = ny;
            x = nx;
            visited[ny][nx] = true;
        }
    }

    static void solve() {
        for (int r = 0; r < R; r++) {
            for (int i = 0; i < 301; i++) {
                for (int j = 0; j < 301; j++) {
                    visited[i][j] = false;
                    COPY_BOARD[i][j] = 0;
                }
            }
            for (int i = 0; i < N; i++) {
                if (visited[i][i] || BOARD[i][i] == 0) break;
                go(i, i);
            }
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < M; x++) {
                    BOARD[y][x] = COPY_BOARD[y][x];
                }
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                System.out.print(BOARD[y][x] + " ");
            }
            System.out.println();
        }
    }
}