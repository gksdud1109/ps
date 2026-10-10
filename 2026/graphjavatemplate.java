import java.io.*;
import java.util.*;

class Main {
    static int n, m;
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] vis;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u); // 방향 그래프면 이 줄 삭제
        }

        // 작은 번호부터 방문해야 하는 문제라면 정렬
        // for (int i = 1; i <= n; i++) Collections.sort(adj.get(i));

        vis = new boolean[n + 1];
        int components = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            components++;
            dfs(i); // 또는 bfs(i);
        }
        System.out.print(sb);
    }

    static void dfs(int u) {
        vis[u] = true;
        sb.append(u).append('\n');
        for (int v : adj.get(u)) {
            if (!vis[v]) dfs(v);
        }
    }

    static void bfs(int start) {
        Deque<Integer> q = new ArrayDeque<>();
        vis[start] = true;
        q.offer(start);
        while (!q.isEmpty()) {
            int u = q.poll();
            sb.append(u).append('\n');
            for (int v : adj.get(u)) {
                if (vis[v]) continue;
                vis[v] = true; // 큐에 넣을 때 방문 표시
                q.offer(v);
            }
        }
    }
}
