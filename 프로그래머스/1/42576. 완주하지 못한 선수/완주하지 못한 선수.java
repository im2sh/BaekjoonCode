import java.util.*;

class Solution {
    static HashMap<String, Integer> race = new HashMap<>();
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        for(int i = 0; i < participant.length; i++){
            if(race.containsKey(participant[i])){
                int cnt = race.get(participant[i]);
                race.replace(participant[i], cnt + 1);
            }else{
                race.put(participant[i], 1);
            }
        }
        
        for(int i = 0; i < completion.length; i++){
            int cnt = race.get(completion[i]);
            race.replace(completion[i], cnt-1);
        }
        
        for(Map.Entry<String, Integer> e : race.entrySet()){
            if(e.getValue() == 1)
                return e.getKey();
        }
        
        return answer;
    }
}