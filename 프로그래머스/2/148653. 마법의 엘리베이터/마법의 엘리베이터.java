import java.util.*;

class Solution {
    static int[] arr;
    public int solution(int storey) {
        String temp = Integer.toString(storey);
        arr = new int[temp.length()];
        int answer = 0;
        for(int i = 0; i < temp.length(); i++){
            arr[i] = temp.charAt(i) - '0';
        }
        for(int i = temp.length() -1; i >= 0; i--){
            if(arr[i] > 5){
                answer += (10 - arr[i]);
                if(i != 0){
                    arr[i-1]++;
                }else{
                    answer++;
                }
            }else if(arr[i] < 5){
                answer += arr[i];
            }else{
                if(i==0){
                    answer += 5;
                }else{
                    if(arr[i-1] >= 5){
                        answer+=(10-arr[i]);
                        arr[i-1]++;
                    }else{
                        answer += arr[i];
                    }   
                }
            }
        }
        return answer;
    }
}