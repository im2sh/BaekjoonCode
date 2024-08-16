import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, ret = Integer.MAX_VALUE;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static List<Ingredient> ingredients = new ArrayList<>();
    static boolean first = true;
    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    public static void Init() throws IOException {
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            ingredients.add(new Ingredient(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
    }

    public static void go(int idx, int S, int B){
        if(!first)
            ret = Math.min(ret, Math.abs(S- B));

        for(int i = idx; i < N; i++){
            first = false;
            go(i + 1, S * ingredients.get(i).S, B + ingredients.get(i).B);
        }
    }

    public static void solve(){
        go(0,1,0);
        System.out.print(ret);
    }
}

class Ingredient{
    int S;
    int B;

    public Ingredient(int s, int b) {
        S = s;
        B = b;
    }
}