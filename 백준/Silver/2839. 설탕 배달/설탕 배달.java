import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] DP = new int[5001];

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        N = Integer.parseInt(br.readLine());
    }

    public static void solve() {
        for(int i = 0; i < 5001; i++){
            DP[i] = 5000;
        }
        
        DP[3] = 1;
        DP[5] = 1;

        for(int i = 6; i <= N; i++){
            DP[i] = Math.min(DP[i-3], DP[i-5]) + 1;
        }

        if (DP[N] >= 5000)
            System.out.print("-1");
        else
            System.out.print(DP[N]);
    }
}