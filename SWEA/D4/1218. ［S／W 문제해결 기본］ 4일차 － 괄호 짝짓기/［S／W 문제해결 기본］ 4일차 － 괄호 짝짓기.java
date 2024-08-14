import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
    static int N;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String str;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        for (int i = 1; i <= 10; i++) {
            Init();
            System.out.println("#" + i + " " + solve());
        }
    }

    static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        str = br.readLine();
    }

    static int solve() {
        Stack<Character> stack = new Stack<>();
        char[] strArr = str.toCharArray();
        for (int i = 0; i < str.length(); i++) {
            if (strArr[i] == '(' || strArr[i] == '{' || strArr[i] == '[' || strArr[i] == '<') {
                stack.push(strArr[i]);
            } else {
                Character left = stack.peek();
                if (strArr[i] == ')' && left == '(')
                    stack.pop();
                else if (strArr[i] == '}' && left == '{')
                    stack.pop();
                else if (strArr[i] == ']' && left == '[')
                    stack.pop();
                else if (strArr[i] == '>' && left == '<')
                    stack.pop();
                else
                    return 0;
            }
        }
        if (stack.isEmpty())
            return 1;
        return 0;
    }
}