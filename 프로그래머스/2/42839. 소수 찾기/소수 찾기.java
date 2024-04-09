import java.util.*;

class Solution {
    static boolean[] visited;
    static int N;
    static int ret = 0;
    static Set<Integer> existN = new HashSet<>();
    public int solution(String numbers) {
        int answer = 0;
        N = numbers.length();
        visited = new boolean[numbers.length()];
        String temp = "";
        go(0, numbers, temp);
        answer = ret;
        return answer;
    }
    
    public boolean isPrime(String temp){
        int num = Integer.parseInt(temp);
        if(existN.contains(num)){
            return false;    
        }
        existN.add(num);

        if(num < 2)
            return false;
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
    
    public void go(int depth, String numbers, String temp){
        if(temp.length() > N)
            return;
        if(depth != 0){
            if(isPrime(temp)){
                ret++;
            }
        }
        
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                go(depth+1, numbers, temp + numbers.charAt(i));
                visited[i] = false;
            }
        }
    }
}