class Solution {
    static int N, ret;
    public int solution(int[] numbers, int target) {
        int answer = 0;
        N = numbers.length;
        dfs(0, numbers, target, 0);
        return ret;
    }
    
    public void dfs(int depth, int[] numbers, int target, int temp){
        if(depth == N){
            if(temp == target)
                ret++;
            return;
        }
        
        dfs(depth + 1, numbers, target, temp - numbers[depth]);
        dfs(depth + 1, numbers, target, temp + numbers[depth]);
    }
}