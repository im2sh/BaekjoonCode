class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        if(left == 1 && right == 1)
            return -1;
        for(int i = left; i <= right; i++){
            if(check(i)){
                answer += i;    
            }else{
                answer -= i;
            }      
        }    
        return answer;
    }
    
    public boolean check(int num) {
        int sum = 0;
        for(int i = 1; i <= Math.sqrt(num); i++){
            if(num % i == 0){
                if(i * i == num)
                    sum++;
                else
                    sum += 2;
            }
        }        
        if(sum % 2 == 0)
            return true;
        return false;
    }
}