class Solution {
    public long solution(long n) {
        long answer = 0;
        int[] digits = new int[10];
        
        while(n > 0){
            digits[(int) (n % 10)]++;
            n /= 10;
        }

        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < digits[i]; j++){
                answer = (answer * 10) + i;
                System.out.println(answer);
            }
        }
        return answer;
    }
}