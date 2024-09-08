import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, M, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static int[] taller;
    static int[] smaller;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int i = 1; i <= TC; i++) {
            Init();
            solve();
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        ret = 0;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        taller = new int[N+1];
        smaller = new int[N+1];
        graph = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++){
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            graph[start].add(end);
        }
    }

    public static void go(int start, int now){
        visited[now] = true;

        for(Integer next : graph[now]){
            if(visited[next])
                continue;
            taller[start]++;
            smaller[next]++;
            go(start,next);
        }
    }

    public static void solve () {
        for(int i = 1; i <= N; i++){
            visited = new boolean[N+1];
            go(i,i);
        }

        for(int i = 1; i <= N; i++){
            if(taller[i] + smaller[i] == N - 1)
                ret++;
        }
    }
}