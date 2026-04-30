import java.util.*;

class Solution {
    
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    static class Node {
        int r, c, dist;
        Node(int r, int c, int dist) {
            this.r = r;
            this.c = c;
            this.dist = dist;
        }
    }

    public int solution(String[] maps) {
        Node start = null;
        Node lever = null;
        Node exit = null;
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[0].length(); j++) {
                char ch = maps[i].charAt(j);
                if (ch == 'S') start = new Node(i, j, 0);
                else if (ch == 'L') lever = new Node(i, j, 0);
                else if (ch == 'E') exit = new Node(i, j, 0);
            }
        }
        
        int timeToLever = bfs(maps, start, lever);
        if (timeToLever == -1) return -1;
        
        int timeToExit = bfs(maps, lever, exit);
        if (timeToExit == -1) return -1;
        
        return timeToLever + timeToExit;
    }
    
    private int bfs(String[] maps, Node start, Node target) {
        int n = maps.length;
        int m = maps[0].length();
        
        Queue<Node> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][m]; 
        
        q.offer(new Node(start.r, start.c, 0));
        vis[start.r][start.c] = true;
        
        while (!q.isEmpty()) {
            Node cur = q.poll();
            
            if (cur.r == target.r && cur.c == target.c) {
                return cur.dist;
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dx[i];
                int nc = cur.c + dy[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (maps[nr].charAt(nc) != 'X' && !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.offer(new Node(nr, nc, cur.dist + 1));
                    }
                }
            }
        }
        return -1;
    }
}