import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, L, ret;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Food> foodList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for(int T = 1; T <= TC; T++){
            Init();
            solve();
            sb.append("#").append(T).append(" ").append(ret).append("\n");
        }
        System.out.print(sb);
    }

    private static void Init() throws IOException {
        ret = 0;
        foodList.clear();
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            Food food = new Food(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            foodList.add(food);
        }
    }

    private static void solve(){
        for(int i = 0; i < (1 << N); i++){
            int taste = 0;
            int cal = 0;
            boolean flag = true;

            for(int j = 0; j < N; j++){
                if((i & (1 << j)) != 0){
                    taste += foodList.get(j).taste;
                    cal += foodList.get(j).cal;
                    if(cal > L) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                ret = Math.max(ret, taste);
        }
    }
}

class Food {
    int taste, cal;

    public Food(int taste, int cal) {
        this.taste = taste;
        this.cal = cal;
    }
}