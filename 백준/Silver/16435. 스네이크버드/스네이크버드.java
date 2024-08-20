import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N, L, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Integer> snake = new ArrayList<>();
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            snake.add(Integer.parseInt(st.nextToken()));
        }
    }

    public static void solve() {
        Collections.sort(snake);
        ret = L;

        for (int i = 0; i < snake.size(); i++) {
            if (ret + 1 > snake.get(i)) {
                ret++;
            } else {
                break;
            }
        }
        System.out.print(ret);
    }
}