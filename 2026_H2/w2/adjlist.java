import java.util.*;

class Main {
    static final int V = 10;
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] vis = new boolean[V];

    public static void go(int u) {
        vis[u] = true;
        System.out.println(u);

        for (int v : adj.get(u)) {
            if (vis[v])
                continue;
            go(v);
        }
    }

    public static void main(String args[]) {
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());

        adj.get(1).add(2);
        adj.get(2).add(1);

        adj.get(1).add(3);
        adj.get(3).add(1);

        adj.get(3).add(4);
        adj.get(4).add(3);

        for (int i = 0; i < V; i++) {
            if (!adj.get(i).isEmpty() && !vis[i]) {
                go(i);
            }
        }
    }
}