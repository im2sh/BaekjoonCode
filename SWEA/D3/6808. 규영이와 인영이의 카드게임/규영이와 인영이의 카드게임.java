import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution {
	static int TC, oneRet, twoRet;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> cardList = new ArrayList<>();
	static ArrayList<Integer> yourCardList = new ArrayList<>();
	static boolean[] card = new boolean[19];
	static boolean[] visited = new boolean[9];
	static ArrayList<Integer> tempCardList = new ArrayList<>();
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		st = new StringTokenizer(br.readLine());
		TC = Integer.parseInt(st.nextToken());
		
		for(int i = 1; i <= TC; i++) {
			Init();
			solve();
			//System.out.println("#"+i +" " + oneRet + " " + twoRet);
			sb.append("#").append(i).append(" ").append(oneRet).append(" ").append(twoRet).append('\n');
		}
		System.out.println(sb);
	}

	static void Init() throws IOException {
		cardList.clear();
		yourCardList.clear();
		for(int i = 0; i < 19; i++) {
			card[i] = false;
		}
		oneRet = 0;
		twoRet = 0;
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i < 9; i++) {
			cardList.add(Integer.parseInt(st.nextToken()));
			card[cardList.get(i)] = true;
		}
		
		for(int i = 1; i <= 18; i++) {
			if(!card[i])
				yourCardList.add(i);
		}
	}
	
	static void cal() {
		int one = 0;
		int two = 0;
		for(int i = 0; i < 9; i++) {
			if(cardList.get(i) > tempCardList.get(i)) {
				one += cardList.get(i) + tempCardList.get(i);
			} else {
				two += cardList.get(i) + tempCardList.get(i); 
			}
		}
		if(one > two)
			oneRet++;
		else
			twoRet++;
	}
	
	static void go(int depth) {
		if(depth == 9) {
			cal();
			return;
		}
		
		for(int i = 0; i < 9; i++) {
			if(!visited[i]) {
				visited[i] = true;
				tempCardList.add(yourCardList.get(i));
				go(depth + 1);
				tempCardList.remove(tempCardList.size()-1);
				visited[i] = false;
			}
		}
	}
	static void solve() {
		go(0);
	} 
}