class Solution {
    static int[][] DP;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        DP = new int[n+1][m+1];
        
        for(int i = 0; i < puddles.length; i++){
            DP[puddles[i][1]][puddles[i][0]] = -1;
        }
        DP[1][1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == 1 && j == 1)
                    continue;
                if(DP[i][j] == -1)
                    continue;
                if(DP[i-1][j] == -1)
                    DP[i][j] = DP[i][j-1];
                else if(DP[i][j-1] == -1)
                    DP[i][j] = DP[i-1][j];
                else
                    DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007;
            }
        }
        
        return DP[n][m];
    }
}