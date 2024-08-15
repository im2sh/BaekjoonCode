import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer sc;
    static int[][] prefix;

    public static void main(String[] args) throws IOException {
        Init();
        Solve();
    }

    public static void Init() throws IOException {
        sc = new StringTokenizer(br.readLine());
        N = Integer.parseInt(sc.nextToken());
        M = Integer.parseInt(sc.nextToken());
        prefix = new int[N+1][N+1];

        for(int y = 1; y <= N; y++){
            sc = new StringTokenizer(br.readLine());
            for(int x = 1; x <= N; x++){
                prefix[y][x] = Integer.parseInt(sc.nextToken());
            }
        }

        for(int y = 1; y <= N; y++){
            for(int x = 1; x <= N; x++){
                prefix[y][x] += prefix[y][x-1] + prefix[y-1][x] - prefix[y-1][x-1];
            }
        }
    }

    public static void Solve() throws IOException {
        for(int i = 0; i < M; i++){
            sc = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(sc.nextToken());
            int y1 = Integer.parseInt(sc.nextToken());
            int x2 = Integer.parseInt(sc.nextToken());
            int y2 = Integer.parseInt(sc.nextToken());

            System.out.println(prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]);
        }
    }
}