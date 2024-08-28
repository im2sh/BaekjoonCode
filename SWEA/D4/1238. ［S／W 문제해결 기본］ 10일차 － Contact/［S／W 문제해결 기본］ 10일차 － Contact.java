import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static int N, start, ret = -1;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static ArrayList<VisitedHistory> result;

    public static void main(String[] args) throws IOException {
        for (int i = 1; i <= 10; i++) {
            Init();
            solve();
            sb.append("#").append(i).append(" ").append(ret).append("\n");
        }
        System.out.println(sb);
    }

    public static void Init() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(st.nextToken());
        graph = new ArrayList[101];
        visited = new boolean[101];
        result = new ArrayList<>();
        ret = -1;
        for (int i = 0; i < 101; i++) {
            graph[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N / 2; i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
        }
    }

    public static void bfs() {
        Queue<VisitedHistory> q = new ArrayDeque<>();
        q.offer(new VisitedHistory(1, start));
        visited[start] = true;

        while (!q.isEmpty()) {
            VisitedHistory cur = q.poll();
            boolean isEnd = true;

            for (int i = 0; i < graph[cur.num].size(); i++) {
                int next = graph[cur.num].get(i);
                if (visited[next])
                    continue;

                q.offer(new VisitedHistory(cur.sequence + 1, next));
                visited[next] = true;
                isEnd = false;
            }
            if(isEnd)
                result.add(cur);
        }
    }

    public static void solve() {
        bfs();
        Collections.sort(result, new VisitedHistoryComparator());
        ret = result.get(0).num;
    }
}

class VisitedHistory {
    int sequence;
    int num;

    public VisitedHistory(int sequence, int num) {
        this.sequence = sequence;
        this.num = num;
    }
}

class VisitedHistoryComparator implements Comparator<VisitedHistory> {
    @Override
    public int compare(VisitedHistory o1, VisitedHistory o2) {
        if (o1.sequence == o2.sequence) {
            return o2.num - o1.num;
        }
        return o2.sequence - o1.sequence;
    }
}