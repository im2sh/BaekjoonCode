class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int sum = 0;
        int temp = x;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        x = temp;
        if(x % sum != 0){
            answer = false;
        }
        
        return answer;
    }
}