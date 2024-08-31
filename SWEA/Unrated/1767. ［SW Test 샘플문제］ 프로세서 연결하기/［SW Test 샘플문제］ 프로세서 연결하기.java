import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    static int TC, N, maxCore, resultLength;
    static int[][] BOARD;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static ArrayList<Pos> core;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int i = 1; i <= TC; i++) {
            Init();
            solve(0,0,0,0);
            sb.append("#").append(i).append(" ").append(resultLength).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        N = Integer.parseInt(br.readLine());
        BOARD = new int[N + 1][N + 1];
        visited = new boolean[N + 1][N + 1];
        core = new ArrayList<>();
        maxCore = 0;
        resultLength = 0;
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
                if (BOARD[y][x] == 1) {
                    if (y == 0 || y == N - 1 || x == 0 || x == N - 1) {
                        continue;
                    }
                    core.add(new Pos(y, x));
                }
            }
        }
    }


    public static void solve(int depth, int idx, int coreCnt, int length) {
        if (depth == core.size()) {
            if (maxCore < coreCnt) {
                maxCore = coreCnt;
                resultLength = length;
            } else if(maxCore == coreCnt){
                resultLength = Math.min(resultLength, length);
            }
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            boolean canMove = true;
            int cnt = 0;
            ArrayList<Pos> temp = new ArrayList<>();
            int cy = core.get(idx).y;
            int cx = core.get(idx).x;

            while (true) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N)
                    break;
                if (BOARD[ny][nx] == 1 || visited[ny][nx]) {
                    canMove = false;
                    break;
                }
                cy = ny;
                cx = nx;
                cnt++;
                visited[ny][nx] = true;
                temp.add(new Pos(ny, nx));
            }
            if (canMove) {
                solve(depth + 1, idx + 1, coreCnt + 1, length + cnt);
                for (int i = 0; i < temp.size(); i++) {
                    visited[temp.get(i).y][temp.get(i).x] = false;
                }
            } else {
                for (int i = 0; i < temp.size(); i++) {
                    visited[temp.get(i).y][temp.get(i).x] = false;
                }
                solve(depth + 1, idx + 1, coreCnt, length);
            }
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