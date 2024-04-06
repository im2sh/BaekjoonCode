import java.util.*;

class Solution {
    HashMap<String,Integer> score = new HashMap<>();
    
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        for(int i = 0; i < name.length; i++){
            score.put(name[i], yearning[i]);
        }
        
        for(int i = 0; i < photo.length; i++){
            int sum = 0;
            for(int j = 0; j < photo[i].length; j++){
                String n = photo[i][j];
                if(score.containsKey(n))
                    sum += score.get(n);
            }
            answer[i] = sum;
        }
        return answer;
    }
}