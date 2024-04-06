import java.util.*;

class Solution {
    LinkedHashMap<String,Integer> rankingPlayer = new LinkedHashMap<>();
    LinkedHashMap<Integer,String> rankingNumber = new LinkedHashMap<>();
    TreeMap<Integer, String> ranking = new TreeMap<>();
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        for(int i = 0; i < players.length; i++){
            rankingPlayer.put(players[i], i+1);
            rankingNumber.put(i+1,players[i]);
        }
    
        
        for(int i = 0; i < callings.length; i++){
            Integer rank = rankingPlayer.get(callings[i]);  
            Integer replaceRank = rank - 1;
            String replacePlayer = rankingNumber.get(replaceRank);
            
            rankingPlayer.put(callings[i], replaceRank);
            rankingPlayer.put(replacePlayer, rank);
            
            rankingNumber.put(replaceRank, callings[i]);
            rankingNumber.put(rank, replacePlayer);
        }
        
        for(Map.Entry<String,Integer> entry : rankingPlayer.entrySet()){
            ranking.put(entry.getValue(), entry.getKey());
        }
        
        int idx = 0;
        for(Map.Entry<Integer, String> entry : ranking.entrySet()){
            answer[idx] = entry.getValue();
            idx++;
        }
        return answer;
    }
}