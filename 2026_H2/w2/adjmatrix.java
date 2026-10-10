class Main {
    static final int V = 10;

    public static void main(String[] args) {
        boolean vis[] = new boolean[V];
        boolean adj[][] = new boolean[V][V];

        adj[1][2] = true;
        adj[2][1] = true;
        adj[1][3] = true;
        adj[3][1] = true;
        adj[3][4] = true;
        adj[4][3] = true;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] && !vis[i]) {
                    go(i, adj, vis);
                }
            }
        }
    }

    public static void go(int u, boolean adj[][], boolean vis[]) {
        vis[u] = true;
        System.out.println(u);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && adj[u][i]) {
                go(i, adj, vis);
            }
        }
    }
}