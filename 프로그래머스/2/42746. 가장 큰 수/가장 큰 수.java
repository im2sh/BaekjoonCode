import java.util.*;

class Solution {
    static String[] nums;
    public String solution(int[] numbers) {
        String answer = "";
        nums = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++){
            nums[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(nums, new StringComparator());
        
        for(int i = 0; i < nums.length; i++){
            answer += nums[i];
        }
        if(answer.charAt(0) == '0')
            return "0";
        return answer;
    }
}

class StringComparator implements Comparator<String>{
        @Override
        public int compare(String a, String b) {
        return (b+a).compareTo(a+b);
    }
}