import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};

    static int TC, N, ret, maxCheese;
    static int[][] BOARD = new int[101][101];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
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
        N = Integer.parseInt(br.readLine());
        ret = 1;
        maxCheese = 1;

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
                maxCheese = Math.max(maxCheese, BOARD[y][x]);
            }
        }
    }

    public static void go(int cheese, int y, int x, boolean[][] visited) {
        visited[y][x] = true;
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] <= cheese) {
                continue;
            }
            go(cheese, ny, nx, visited);
        }
    }

    public static void solve() {
        int temp = 0;
        for (int i = 1; i <= maxCheese; i++) {
            boolean[][] visited = new boolean[N + 1][N + 1];
            int sum = 0;
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (!visited[y][x] && BOARD[y][x] > i) {
                        go(i, y, x, visited);
                        sum++;
                    }
                }
            }
            ret = Math.max(ret, sum);
        }
    }
}

class Pos {
    int y, x;

    Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}