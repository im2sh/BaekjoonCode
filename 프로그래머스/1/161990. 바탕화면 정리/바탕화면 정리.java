import java.util.*;

class Solution {
    public int[] solution(String[] wallpaper) {
        int[] answer = new int[4];
        int sy = 51;
        int sx = 51;
        int ey = 0;
        int ex = 0;

        for(int i = 0; i < wallpaper.length; i++){
            for(int j = 0; j < wallpaper[i].length(); j++){
                if(wallpaper[i].charAt(j) == '#'){
                    if(sy > i)
                        sy = i;
                    if(sx > j)
                        sx = j;
                    if(ey < i)
                        ey = i;
                    if(ex < j)
                        ex = j;
                }
            }
        }
        answer[0] = sy;
        answer[1] = sx;
        answer[2] = ey + 1;
        answer[3] = ex + 1;
        return answer;
    }
}

