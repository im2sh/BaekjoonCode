class Solution {
    static int N, ret = 987654321;
    static boolean[] visited;
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        N = words.length;
        visited = new boolean[N];
        dfs(0, begin, words, target);
        if(ret == 987654321)
            return 0;
        return ret;
    }
    
    public void dfs(int depth, String a, String[] words, String target){
        if(a.equals(target)) {
            ret = Math.min(ret, depth);
            return;
        }
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                if(check(a, words[i])){
                    visited[i] = true;
                    dfs(depth+1, words[i], words, target);
                    visited[i] = false;
                }
            }
        }
    }
    
    public boolean check(String a, String b){
        int diff = 0;
        for(int i = 0; i < a.length(); i++){
            if(a.charAt(i) != b.charAt(i))
                diff++;
        }
        if(diff == 1)
            return true;
        return false;
    }
}