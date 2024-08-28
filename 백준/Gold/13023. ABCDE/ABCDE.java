import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M;
    static boolean flag = false;
    static StringTokenizer st;
    static ArrayList<Integer>[] graph = new ArrayList[2001];
    static Set<Integer> vertex = new HashSet<>();
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < 2001; i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            vertex.add(a);
            vertex.add(b);
            graph[a].add(b);
            graph[b].add(a);
        }
    }

    public static void dfs(int v, int cnt){
        visited[v] = true;
        if(flag)
            return;
        if(cnt == 4){
            flag = true;
            return;
        }

        for(int i = 0; i < graph[v].size(); i++){
            int next = graph[v].get(i);
            if(!visited[next]){
                dfs(next, cnt + 1);
            }
        }
        visited[v] = false;
    }

    public static void solve(){
        for(Integer v : vertex){
            if(flag)
                break;
            visited = new boolean[2001];
            dfs(v, 0);
        }
        if (flag)
            System.out.print("1");
        else {
            System.out.print("0");
        }
    }

}