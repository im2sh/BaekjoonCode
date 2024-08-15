import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, M, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] prefix;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        TC = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= TC; i++) {
            Init();
            solve();
            System.out.println("#" + i + " " + ret);
        }
    }

    public static void Init() throws IOException {
        ret = 0;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        prefix = new int[N + 1][N + 1];

        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 1; x <= N; x++) {
                int temp = Integer.parseInt(st.nextToken());
                prefix[y][x] = temp + prefix[y - 1][x] + prefix[y][x - 1] - prefix[y - 1][x - 1];
            }
        }
    }

    public static void solve() {
        for (int y = M; y <= N; y++) {
            for (int x = M; x <= N; x++) {
                ret = Math.max(ret, prefix[y][x] - prefix[y - M][x] - prefix[y][x - M] + prefix[y - M][x - M]);
            }
        }
    }
}