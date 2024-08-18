import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class Main {
    static int S, P, ret;
    static String password;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashMap<Character, Integer> M = new HashMap<>();
    static HashMap<Character, Integer> required = new HashMap<>();

    public static void main(String[] args) throws IOException {
        Init();
        solve();
    }

    private static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        password = br.readLine();
        st = new StringTokenizer(br.readLine());
        M.put('A', Integer.parseInt(st.nextToken()));
        M.put('C', Integer.parseInt(st.nextToken()));
        M.put('G', Integer.parseInt(st.nextToken()));
        M.put('T', Integer.parseInt(st.nextToken()));
        for (Entry<Character, Integer> entry : M.entrySet()) {
            if(entry.getValue() > 0)
                required.put(entry.getKey(), entry.getValue());
        }
    }

    private static boolean check(){
        for (Integer value : M.values()) {
            if(value > 0)
                return false;
        }
        return true;
    }
    private static void solve() {
        for(int i = 0; i < P; i++){
            Character temp = password.charAt(i);
            if(required.containsKey(temp)){
                Integer value = M.get(temp);
                M.put(temp, --value);
            }
        }
        if(check())
            ret++;

        int start = 0;
        int end = P;
        while(end < S){
            Character startKey = password.charAt(start);
            Character endKey = password.charAt(end);

            if(required.containsKey(startKey)){
                int value = M.get(startKey);
                M.put(startKey, ++value);
            }
            if(required.containsKey(endKey)){
                int value = M.get(endKey);
                M.put(endKey, --value);
            }

            if(check())
                ret++;
            start++;
            end++;
        }
        System.out.print(ret);
    }
}