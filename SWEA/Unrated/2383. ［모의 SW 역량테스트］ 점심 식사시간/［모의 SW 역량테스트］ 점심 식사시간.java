import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, ret, exitCnt, peopleCnt, cnt;
    static int[][] BOARD;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static ArrayList<Integer> combination = new ArrayList<>();
    static ArrayList<Pos> peoples = new ArrayList<>();
    static ArrayList<Exit> exits = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int i = 1; i <= TC; i++) {
            Init();
            solve(0);
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        ret = 987654321;
        exitCnt = 0;
        peopleCnt = 0;
        combination.clear();
        peoples.clear();
        exits.clear();
        N = Integer.parseInt(br.readLine());
        BOARD = new int[N + 1][N + 1];
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                BOARD[y][x] = Integer.parseInt(st.nextToken());
                if (BOARD[y][x] != 0 && BOARD[y][x] != 1) {
                    exitCnt++;
                    exits.add(new Exit(y, x, BOARD[y][x]));
                } else if (BOARD[y][x] == 1) {
                    peopleCnt++;
                    peoples.add(new Pos(y, x));
                }
            }
        }
    }

    public static int cal(ArrayList<Integer> stair, int exitNum) {
        if (stair.size() == 0) {
            return 0;
        }
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < stair.size(); i++) {
            if (q.size() >= 3) {
                /*
                아직 출구에 도착하지 못했다면 -> stair.get(i)
                출구에 도착한 상태라면 -> exits.get(exitNum).distance
                 */
                int next = Math.max(stair.get(i), q.poll() + exits.get(exitNum).distance);
                q.offer(next);
            } else {
                q.offer(stair.get(i));
            }
        }
        return q.pollLast() + exits.get(exitNum).distance + 1;
    }

    public static int go() {
        ArrayList<Integer> oneStair = new ArrayList<>();
        ArrayList<Integer> twoStair = new ArrayList<>();
        for (int i = 0; i < combination.size(); i++) {
            if (combination.get(i) == 0) {
                int y = Math.abs(peoples.get(i).y - exits.get(0).y);
                int x = Math.abs(peoples.get(i).x - exits.get(0).x);
                int dist = y + x;
                oneStair.add(dist);
            } else {
                int y = Math.abs(peoples.get(i).y - exits.get(1).y);
                int x = Math.abs(peoples.get(i).x - exits.get(1).x);
                int dist = y + x;
                twoStair.add(dist);
            }
        }
        Collections.sort(oneStair);
        Collections.sort(twoStair);

        return Math.max(cal(oneStair, 0), cal(twoStair, 1));
    }

    public static void solve(int depth) {
        if (depth == peopleCnt) {
            ret = Math.min(ret, go());
            return;
        }

        for (int i = 0; i < exitCnt; i++) {
            combination.add(i);
            solve(depth + 1);
            combination.remove(combination.size() - 1);
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

class Exit {
    int y, x, distance;

    Exit(int y, int x, int distance) {
        this.y = y;
        this.x = x;
        this.distance = distance;
    }
}