class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        int[] temp = new int[12];
        int cnt = 0;
 
        while(n > 0){
            temp[cnt] = (int) (n%10);
            cnt++;
            n/=10;
        }
        int t = 0;
        answer = new int[cnt];

        for(int i = 0; i < cnt; i++){
            System.out.print(temp[i] + " ");
            answer[t++] = temp[i];
        }
    
        return answer;
    }
}