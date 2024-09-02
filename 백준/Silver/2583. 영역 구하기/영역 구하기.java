import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static final int[] dy = {-1,1,0,0};
	static final int[] dx = {0,0,-1,1};
	
	static int M, N, K, ret;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[][] BOARD;
	static boolean[][] visited;
	static ArrayList<Integer> islands = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		Init();
		solve();
	}

	
	public static void Init() throws IOException {
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		BOARD = new int[M+1][N+1];
		visited = new boolean[M+1][N+1];
		
		for(int i = 0; i < K; i++) {
			int y1,y2,x1,x2;
			st = new StringTokenizer(br.readLine());
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			
			for(int y = y1; y < y2; y++) {
				for(int x = x1; x < x2; x++) {
					BOARD[y][x] = 1;
				}
			}
		}
	}
	
	public static int go(int y, int x) {
		int cnt = 1;
		Queue<Pos> q = new ArrayDeque<>();
		q.offer(new Pos(y,x));
		visited[y][x] = true;
		
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			int cy = cur.y;
			int cx = cur.x;
			
			for(int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				
				if(ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == 1)
					continue;
				q.offer(new Pos(ny,nx));
				visited[ny][nx] = true;
				cnt++;
			}
		}
		return cnt;
	}
	
	public static void solve() {
		for(int y = 0; y < M; y++) {
			for(int x = 0; x < N; x++) {
				if(!visited[y][x] && BOARD[y][x] == 0) {
					islands.add(go(y,x));
					ret++;
				}
			}
		}
		Collections.sort(islands);
		System.out.println(ret);
		for(int i = 0; i < islands.size(); i++) {
			System.out.print(islands.get(i) + " ");
		}
	}
}


class Pos{
	int y, x;
	
	Pos(int y, int x){
		this.y = y;
		this.x = x;
	}
}