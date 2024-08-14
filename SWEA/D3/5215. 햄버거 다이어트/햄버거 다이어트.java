import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static int TC, N, L, T, K;
    static BufferedReader br = new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));
    static StringTokenizer st;
    static Info maxIngredient;
    static ArrayList<Info> info = new ArrayList<>();
    static ArrayList<Info> ingredient = new ArrayList<>();
    static boolean[] visited = new boolean[21];
    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for(int i = 1; i <= TC; i++){
            Init();
            solve(0);
            System.out.println("#" + i + " " + maxIngredient.score);
        }
    }

    static void Init() throws IOException {
        info.clear();
        maxIngredient = new Info(0,0);
        for(int i = 0; i < 21; i++)
            visited[i] = false;

        st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            T = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            info.add(new Info(T,K));
        }
    }

    static void cal(){
        int calSum = 0;
        int favoriteSum = 0;
        for(int i = 0; i < ingredient.size(); i++){
            calSum += ingredient.get(i).cal;
            favoriteSum += ingredient.get(i).score;
        }

        if(calSum <= L){
            if(maxIngredient.score < favoriteSum) {
                maxIngredient.score = favoriteSum;
            }
        }
    }

    static void solve(int idx){
        if(ingredient.size() != 0) {
            cal();
        }

        for(int i = idx; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                ingredient.add(info.get(i));
                solve(i+1);
                ingredient.remove(ingredient.size()-1);
                visited[i] = false;
            }
        }
    }

}

class Info{
    int score,cal;

    public Info(int T, int K) {
        this.score = T;
        this.cal = K;
    }
}