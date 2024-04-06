import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        int turn = 0;
        int maxHp = health;
        for(int i = 0; i < attacks.length; i++){
            turn = (attacks[i][0] - turn) - 1;
            if(health == maxHp){
                health -= attacks[i][1];
            }else{
                if(turn >= bandage[0]){
                    int cycle = turn / bandage[0];
                    health += (cycle * bandage[2]) + (turn * bandage[1]);
                    if(health > maxHp)
                        health = maxHp;
                }else{
                    health += turn * bandage[1];
                    if(health > maxHp)
                        health = maxHp;
                }
                health -= attacks[i][1];
            }
            turn = attacks[i][0];
            if(health <= 0)
                break;
        }
        answer = health;
        if(answer <= 0)
            answer = -1;
        return answer;
    }
}