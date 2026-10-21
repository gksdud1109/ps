import java.util.*;
import java.io.*;

class Main{

  static int n, m, st;
  static List<List<Integer>> adj = new ArrayList<>();
  static boolean[] vis;
  static StringBuilder sb = new StringBuilder();

  static void dfs(int cur){
    vis[cur] = true;
    sb.append(cur).append(' ');

    for(int nxt : adj.get(cur){
      if(vis[nxt]) continue;
      dfs(nxt);
    })
  }

  static void bfs(){
    Queue<Integer> q = new ArrayDeque<>();

    vis[st] = true;
    q.offer(st);

    while(!q.isEmpty()){
      int cur = q.poll();
      sb.append(cur).append(' ');

      for(int nxt: adj.get(cur)){
        if(vis[nxt]) continue;

        vis[nxt] = true;
        q.offer(nxt);
      }
    }
  }

  public static void main(String[] args){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    st = Integer.parseInt(st.nextToken());

    vis = new boolean[n+1];

    for(int i=0; i<=n; i++) adj.add(new ArrayList<>());

    for(int i=0; i<m; i++){
      token = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(token.nextToken());
      int b = Integer.parseInt(token.nextToken());

      adj.get(a).add(b);
      adj.get(b).add(a);
    }

    for(int i=1; i<=n; i++){
      Collections.sort(adj.get(i));
    }

    dfs(st);
    sb.append('\n');

    // DFS에서 사용한 방문 기록 초기화
    Arrays.fill(vis, false);

    bfs();
    sb.append('\n');

    System.out.print(sb);
  }
}

