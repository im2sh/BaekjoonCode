class Solution {
    static int ocnt = 0;
    static int xcnt = 0;
    static boolean oBingo = false;
    static boolean xBingo = false;
    public int solution(String[] board) {
        int answer = 1;
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length(); j++){
                if(board[i].charAt(j) == 'O')
                    ocnt++;
                else if(board[i].charAt(j) == 'X')
                    xcnt++;
            }
        }
        
        if(ocnt == 0 && xcnt == 0)
            return answer;
        
        if(ocnt < xcnt)
            return 0;
        if((ocnt - xcnt) >= 2)
            return 0;
        
        if(board[0].charAt(0) == board[0].charAt(1) && board[0].charAt(0) == board[0].charAt(2))
            judge(board[0].charAt(0));
        if(board[0].charAt(0) == board[1].charAt(0) && board[0].charAt(0) == board[2].charAt(0))
            judge(board[0].charAt(0));
        if(board[0].charAt(0) == board[1].charAt(1) && board[0].charAt(0) == board[2].charAt(2))
            judge(board[0].charAt(0));
        if(board[0].charAt(1) == board[1].charAt(1) && board[0].charAt(1) == board[2].charAt(1))
            judge(board[0].charAt(1));
        if(board[1].charAt(0) == board[1].charAt(1) && board[1].charAt(0) == board[1].charAt(2))
            judge(board[1].charAt(0));
        if(board[2].charAt(0) == board[2].charAt(1) && board[2].charAt(0) == board[2].charAt(2))
            judge(board[2].charAt(0));
        if(board[0].charAt(2) == board[1].charAt(2) && board[1].charAt(2) == board[2].charAt(2))
            judge(board[0].charAt(2));
        if(board[0].charAt(2) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(0))
            judge(board[0].charAt(2));
        
    
        if(oBingo && ocnt == xcnt)
            return 0;
        if(xBingo && ocnt > xcnt)
            return 0;
        if(oBingo && xBingo)
            return 0;
        return answer;
    }
    
    public void judge(char target){
        if(target == '.')
            return;
        if(target == 'O')
            oBingo = true;
        else
            xBingo = true;
        
    }
}