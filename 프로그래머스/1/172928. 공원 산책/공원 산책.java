import java.util.*;

class Solution {
    static char[][] BOARD = new char[51][51];
    static People start;
    int N, M;
    private static int dy[] = {0,0,-1,1};
    private static int dx[] = {1,-1,0,0};
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];
        N = park.length;
        M = park[0].length();
        for(int i = 0; i < park.length; i++){
            for(int j = 0; j < park[i].length(); j++){
                BOARD[i][j] = park[i].charAt(j);
                if(BOARD[i][j] == 'S'){
                    start = new People(i,j);
                }
            }
        }
        
        for(int j = 0; j < routes.length; j++){
            int cy = start.y;
            int cx = start.x;
            String arr[] = routes[j].split(" ");

            if(arr[0].equals("E")){
                moving(cy, cx, 0, Integer.parseInt(arr[1]));
            }else if(arr[0].equals("W")){
                moving(cy, cx, 1, Integer.parseInt(arr[1]));
            }else if(arr[0].equals("N")){
                moving(cy, cx, 2, Integer.parseInt(arr[1]));
            }else{
                moving(cy, cx, 3, Integer.parseInt(arr[1]));
            }
        }
        answer[0] = start.y;
        answer[1] = start.x;
        
        return answer;
    }
    
    boolean check(int y, int x){
        if(y < 0 || y >= N || x < 0 || x >= M || BOARD[y][x] == 'X')
            return false;
        return true;
    }
    
    void moving(int y, int x, int dir, int cnt){
        int ny = 0;
        int nx = 0;
        boolean moving = true;
        for(int i = 0; i < cnt; i++){
            ny = y + dy[dir];
            nx = x + dx[dir];
                    
            if(!check(ny,nx)){
                moving = false;
                break;
            }
            y = ny;
            x = nx;
        }
        if(moving){
            start.y = ny;
            start.x = nx;
        }
    }
}

class People{
    int y;
    int x;
    
    public People(int y, int x){
        this.y = y;
        this.x = x;
    }
}