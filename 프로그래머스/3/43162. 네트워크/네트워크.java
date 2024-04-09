class Solution {
    static boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[computers.length];
        
        for(int i = 0; i < computers.length; i++){
            if(!visited[i]){
                dfs(i, computers);
                answer++;
            }
        }
        return answer;
    }
    
    public void dfs(int start, int[][] computers){
        visited[start] = true;
        for(int i = 0; i < computers[start].length; i++){
            int next = i;
            if(computers[start][i] == 0)
                continue;
            System.out.println(next);
            if(!visited[next]){
                dfs(next, computers);
            }
        }
    }
}