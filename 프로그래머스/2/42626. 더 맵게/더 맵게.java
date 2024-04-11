import java.util.*;

class Solution {
    static PriorityQueue<Long> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        for(int i = 0; i < scoville.length; i++){
            pq.offer(Long.valueOf(scoville[i]));
        }
        
        while(!pq.isEmpty()){
            if(pq.peek() >= K){
                return answer;
            }
            Long one = pq.poll();
            if(pq.isEmpty())
                return -1;
            Long two = pq.poll();
            Long sum = one + (two * 2);
            pq.offer(sum);
            answer++;
        }
        return -1;
    }
}