class Solution {
    static boolean[] visited; 
    static int ret;
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        visited = new boolean[dungeons.length];
        go(k, 0, dungeons);
        answer = ret;
        return answer;
    }
    
    public void go(int hp, int depth, int[][] dungeons){
        if(depth > dungeons.length)
            return;
        ret = Math.max(ret, depth);
        for(int i =0; i < dungeons.length; i++){
            if(!visited[i]){
                visited[i] = true;
                if(hp >= dungeons[i][0])
                    go(hp - dungeons[i][1], depth + 1, dungeons);
                visited[i] = false;
            }
        }
        
    }
}