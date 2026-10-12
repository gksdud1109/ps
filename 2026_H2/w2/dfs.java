import java.util.*;

class Main {

    static int n = 10;
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] vis = new boolean[n];

    public static void main(String args[]) {
        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<>());

        adj.get(1).add(2);
        adj.get(2).add(1);
        adj.get(1).add(3);
        adj.get(3).add(1);
        adj.get(2).add(4);
        adj.get(4).add(2);
        adj.get(2).add(5);
        adj.get(5).add(2);

        dfs(1);

    }

    static void dfs(int u) {
        vis[u] = true;
        System.out.println(u);

        for (int v : adj.get(u)) {
            if (!vis[v])
                dfs(v);
        }

        System.out.println(u + "로부터 시작된 함수가 종료되었습니다.\n");
        return;
    }
}