import java.util.*;

class Solution {
    
    static HashMap<Integer,Integer> mon = new HashMap<>();
    static int target;
    public int solution(int[] nums) {
        int answer = 0;
        target = nums.length / 2;
        for(int i = 0; i < nums.length; i++){
            mon.put(nums[i], nums[i]);
        }
        
        if(mon.size() >= target)
            return target;
        
        return mon.size();
    }
}