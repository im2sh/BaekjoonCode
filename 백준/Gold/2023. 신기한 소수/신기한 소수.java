import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static int N;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            arr.add(i + 1);
        }
    }

    public static boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void go(int depth, int temp) {
        if (depth == N) {
            System.out.println(temp);
            return;
        }

        for (int i = 1; i <= 9; i++) {
            int next = temp * 10 + i;
            if (isPrime(next)) {
                go(depth + 1, next);
            }
        }
    }

    public static void solve() {
        go(0, 0);
    }
}