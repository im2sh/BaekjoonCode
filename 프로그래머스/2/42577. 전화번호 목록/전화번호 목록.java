import java.util.*;

class Solution {
    
    HashMap<String, Integer> phone = new HashMap<>();
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        for(int i = 0; i < phone_book.length; i++){
            phone.put(phone_book[i], 1);
        }

        for(int i = 0; i < phone_book.length; i++){
            String temp = "";
            for(int j = 0; j < phone_book[i].length() - 1; j++){
                temp += phone_book[i].charAt(j);
                if(phone.containsKey(temp)){
                    return false;
                }
            }
        }
        return true;
    }
}