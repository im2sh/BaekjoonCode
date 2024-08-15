import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer> temp = new ArrayList<>();
    static boolean[] visited = new boolean[8];
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        go(0,0);
        System.out.print(sb);
    }

    public static void go(int depth, int idx){
        if(depth == M){
            for(int i = 0; i < M; i++){
                sb.append(temp.get(i)).append(" ");
            }
            sb.append("\n");
            return;
        }

        for(int i = idx; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                temp.add(i+1);
                go(depth + 1, i + 1);
                temp.remove(temp.size()-1);
                visited[i] = false;
            }
        }
    }
}