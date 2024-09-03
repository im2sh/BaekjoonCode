import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, M, ret;
    static int[][] BOARD;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Pos> homeList;
    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for(int i = 1; i <= TC; i++){
            Init();
            solve();
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        ret = 0;
        BOARD = new int[N+1][N+1];
        homeList = new ArrayList<>();
        for(int y = 0; y < N; y++){
            st = new StringTokenizer(br.readLine());
            for(int x = 0; x < N; x++){
                BOARD[y][x] = Integer.parseInt(st.nextToken());
                if(BOARD[y][x] == 1)
                    homeList.add(new Pos(y,x));
            }
        }
    }

    public static void solve(){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                int k = 0;
                while(true){
                    if(k > N)
                        break;
                    int houseCnt = 0;
                    int serviceAmount = ((k + 1) * (k + 1)) + (k * k);
                    for(int h = 0; h < homeList.size(); h++){
                        int hy = Math.abs(homeList.get(h).y - y);
                        int hx = Math.abs(homeList.get(h).x - x);
                        if(hy + hx <= k)
                            houseCnt++;
                    }
                    int profit = M * houseCnt - serviceAmount;
                    if(profit >= 0){
                        ret = Math.max(ret, houseCnt);
                    }
                    k++;
                }
            }
        }
    }
}

class Pos{
    int y,x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}