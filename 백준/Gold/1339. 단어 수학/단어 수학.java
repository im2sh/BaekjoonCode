import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Main {
    static int N, cnt, val = 9;
    static int ret = -1;
    static ArrayList<String> str = new ArrayList<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static Map<Character, Integer> M = new HashMap<>();
    static Map<Integer, Character> alpha = new HashMap<>();
    static boolean[] visited = new boolean[11];

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++) {
            str.add(br.readLine());
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < str.get(i).length(); j++) {
                M.put(str.get(i).charAt(j), 0);
            }
        }

        cnt = M.size();
        int idx = 0;
        for(Entry<Character, Integer> e : M.entrySet()) {
            alpha.put(idx++, (Character) e.getKey());
        }
    }

    public static int calcu() {
        int sum = 0;
        for(int i = 0; i < str.size(); i++) {
            int a = 0;
            int mul = 10;
            for(int j = 0; j < str.get(i).length(); j++) {
                int temp = M.get(str.get(i).charAt(j));
                a *= mul;
                a += temp;
            }
            sum += a;
        }
        return sum;
    }

    public static void go(int depth) {
        if(depth == cnt) {
            ret = Math.max(ret, calcu());
            return;
        }

        for(int i = 0; i < cnt; i++) {
            if(!visited[i]) {
                visited[i] = true;
                Character al = alpha.get(i);
                M.put(al, val--);
                go(depth+1);
                val++;
                M.put(al, 0);
                visited[i] = false;
            }
        }
    }

    public static void solve() {
        go(0);
        System.out.println(ret);
    }
}