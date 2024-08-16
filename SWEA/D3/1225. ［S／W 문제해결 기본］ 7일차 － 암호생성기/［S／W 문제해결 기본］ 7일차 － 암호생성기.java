import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static int TC;
    static BufferedReader br = new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int[] password = new int[9];
    static Queue<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        for (int i = 1; i <= 10; i++) {
            Init();
            solve();
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        TC = Integer.parseInt(br.readLine());
        q.clear();
        for (int i = 0; i < 9; i++) {
            password[i] = 0;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 8; i++) {
            password[i] = Integer.parseInt(st.nextToken());
        }
    }


    public static boolean check(){
        boolean flag = false;
        boolean zeroFlag = false;
        for(int i = 0; i < 8; i++){
            Integer cur = q.poll();
            q.offer(cur);
            if(cur >= 10)
                flag = true;
            if(cur <= 0)
                zeroFlag = true;
        }
        if(flag)
            return true;
        if(!zeroFlag)
            return true;
        return false;
    }

    public static void solve() {
        for (int i = 0; i < 8; i++) {
            password[i] %= 60;
            q.offer(password[i]);
        }

        int minusNum = 1;
        while (check()) {
            int cur = q.poll();
            cur -= minusNum;
            if (cur <= 0) {
                q.offer(0);
            }else{
                q.offer(cur);
            }
            minusNum = (minusNum % 5) + 1;
        }
        sb.append("#").append(TC).append(" ");
        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(" ");
        }
        sb.append("\n");
    }
}