import java.util.*;

class Solution {
    static int N;
    static int idx = 0;
    static Map<Integer,Integer> c = new HashMap<>();
    public int solution(int coin, int[] cards) {
        int answer = 0;
        int round = 0;
        LinkedList<Integer> myCard = new LinkedList<>();
        for(int i = 0; i < cards.length; i++){
            N = Math.max(N, cards[i]);
        }
        for(int i = 0; i < N/3; i++){
            myCard.add(cards[i]);
        }
        
        idx = N/3;
        
        for(round = 0; round < N/3; round++){
            myCard.add(cards[idx]);
            c.put(cards[idx], 1);
            idx++;
            myCard.add(cards[idx]);
            c.put(cards[idx], 1);
            idx++;
            
            boolean findCoin = false;
            for(int i = 0; i < myCard.size(); i++){
                for(int j = i + 1; j < myCard.size(); j++){
                    if(myCard.get(i) + myCard.get(j) == N + 1){
                        if(!c.containsKey(myCard.get(i)) && !c.containsKey(myCard.get(j))){
                            findCoin = true;
                            myCard.remove(i);
                            myCard.remove(j-1);
                        }else if(c.containsKey(myCard.get(i)) && !c.containsKey(myCard.get(j)) && coin >= 1){
                            coin--;
                            findCoin = true;
                            myCard.remove(i);
                            myCard.remove(j-1);
                        }else if(!c.containsKey(myCard.get(i)) && c.containsKey(myCard.get(j)) && coin >= 1){
                            coin--;
                            findCoin = true;
                            myCard.remove(i);
                            myCard.remove(j-1);
                        }
                        else if(c.containsKey(myCard.get(i)) && c.containsKey(myCard.get(j)) && coin >= 2){
                            coin-=2;
                            findCoin = true;
                            myCard.remove(i);
                            myCard.remove(j-1);
                        }
                    }
                    if(findCoin){
                        break;
                    }
                }
                if(findCoin)
                    break;
            }
            
            if(!findCoin){        
                break;
            }
        }
        answer = round + 1;
        return answer;
    }
}