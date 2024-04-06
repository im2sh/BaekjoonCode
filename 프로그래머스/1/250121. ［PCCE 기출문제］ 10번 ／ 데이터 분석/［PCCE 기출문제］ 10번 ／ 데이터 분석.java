import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        int[][] answer;
       
        List<Data> dataList = new ArrayList();
        for(int i = 0; i < data.length; i++){
            if(ext.equals("code")){
                if(data[i][0] < val_ext){
                    dataList.add(new Data(data[i]));
                }    
            }else if(ext.equals("date")){
                if(data[i][1] < val_ext){
                    dataList.add(new Data(data[i]));
                }
            }else if(ext.equals("maximum")){
                if(data[i][2] < val_ext){
                    dataList.add(new Data(data[i]));
                }
            }else{
                if(data[i][3] < val_ext){
                    dataList.add(new Data(data[i]));
                }
            }
        }
        answer = new int[dataList.size()][4];
        
        if(sort_by.equals("code")){
            Collections.sort(dataList, new codeComparator());
        }else if(sort_by.equals("date")){
            Collections.sort(dataList, new dateComparator());
        }else if(sort_by.equals("maximum")){
            Collections.sort(dataList, new maximumComparator());
        }else{
            Collections.sort(dataList, new remainComparator());
        }
        
        for(int i = 0; i < dataList.size(); i++){
            answer[i][0] = dataList.get(i).getCode();
            answer[i][1] = dataList.get(i).getDate();
            answer[i][2] = dataList.get(i).getMaximum();
            answer[i][3] = dataList.get(i).getRemain();
        }
        return answer;
    }
}

class Data{
    int code;
    int date;
    int maximum;
    int remain;
    
    Data(int[] data){
        this.code = data[0];
        this.date = data[1];
        this.maximum = data[2];
        this.remain = data[3];
    }
    
    int getCode(){
        return code;
    }
    
    int getDate(){
        return date;
    }
    
    int getMaximum(){
        return maximum;
    }
    
    int getRemain(){
        return remain;
    }
}

class codeComparator implements Comparator<Data> {
    @Override
    public int compare(Data a, Data b){
        if(a.getCode() > b.getCode()){
            return 1;
        }else if(a.getCode() < b.getCode()){
            return -1;
        }
        return 0;
    }
}

class dateComparator implements Comparator<Data> {
    @Override
    public int compare(Data a, Data b){
        if(a.getDate() > b.getDate()){
            return 1;
        }else if(a.getDate() < b.getDate()){
            return -1;
        }
        return 0;
    }
}

class maximumComparator implements Comparator<Data> {
    @Override
    public int compare(Data a, Data b){
        if(a.getMaximum() > b.getMaximum()){
            return 1;
        }else if(a.getMaximum() < b.getMaximum()){
            return -1;
        }
        return 0;
    }
}

class remainComparator implements Comparator<Data> {
    @Override
    public int compare(Data a, Data b){
        if(a.getRemain() > b.getRemain()){
            System.out.println(a.getRemain());
            System.out.println(b.getRemain());
            return 1;
        }else if(a.getRemain() < b.getRemain()){
            return -1;
        }
        return 0;
    }
}