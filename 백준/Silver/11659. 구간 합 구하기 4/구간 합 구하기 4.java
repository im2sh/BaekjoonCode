import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static ArrayList<Integer> numList = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();
    static int[] arr;
    static int[] prefix;

    public static void main(String[] args) throws IOException {
        Init();
        Solve();
    }
    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        prefix = new int[N + 1];

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        prefix[1] = arr[0];

        for(int i = 2; i <= N; i++){
            prefix[i] = prefix[i-1] + arr[i - 1];
        }
    }

    public static void Solve() throws IOException {
        for(int m = 0; m < M; m++){
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j =  Integer.parseInt(st.nextToken());
            sb.append(prefix[j] - prefix[i-1]).append('\n');
        }
        System.out.print(sb);
    }
}