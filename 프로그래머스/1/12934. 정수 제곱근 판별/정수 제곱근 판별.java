class Solution {
    public long solution(long n) {
        long answer = 0;
        double temp = Math.sqrt(n);
    
        if(temp % 1 == 0){
            return (long) Math.pow(temp + 1, 2);
        }
        return -1;
    }
}