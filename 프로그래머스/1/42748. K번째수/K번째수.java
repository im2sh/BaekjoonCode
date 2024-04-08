import java.util.*;

class Solution {
    
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i = 0; i < commands.length; i++){
            int s = commands[i][0];
            int e = commands[i][1];
            int idx = commands[i][2];
            
            ArrayList<Integer> list = new ArrayList<>();
            for(int j = s - 1; j < e; j++){
                list.add(array[j]);
            }
            Collections.sort(list);
            answer[i] = list.get(idx-1);
        }
        return answer;
    }
}