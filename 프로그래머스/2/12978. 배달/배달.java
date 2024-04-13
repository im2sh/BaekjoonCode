import java.util.*;

class Solution {
    static LinkedList<Node>[] graph;
    static int[] dist;
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        graph = new LinkedList[N+1];
        dist = new int[N+1];
        for(int i = 0; i <= N; i++){
            graph[i] = new LinkedList<>();
        }
        Arrays.fill(dist,(int)1e9);
        dist[1] = 0;
        for(int i = 0; i < road.length; i++){
            graph[road[i][0]].add(new Node(road[i][1], road[i][2]));
            graph[road[i][1]].add(new Node(road[i][0], road[i][2]));
        }
        bfs(K);
        for(int i = 1; i <= N; i++){
            if(dist[i] <= K)
                answer++;
        }

        return answer;
    }
    public void bfs(int K){
        PriorityQueue<Node> q = new PriorityQueue<>(new pqComparator());
        q.offer(new Node(1,0));
        
        while(!q.isEmpty()){
            Node cur = q.poll();
            if(dist[cur.e] < cur.w)
                continue;
            for(int i = 0; i < graph[cur.e].size(); i++){
                int next = graph[cur.e].get(i).e;
                int weight = graph[cur.e].get(i).w;
                
                if(dist[next] > cur.w + weight){
                    q.offer(new Node(next, cur.w + weight));
                    dist[next] = cur.w + weight;
                }
            }
        }
    }
}



class Node{
    int e;
    int w;
    
    public Node(int e, int w){
        this.e = e;
        this.w = w;
    }
}

class pqComparator implements Comparator<Node>{
    @Override
    public int compare(Node a, Node b){
        return a.w - b.w;
    }
}
