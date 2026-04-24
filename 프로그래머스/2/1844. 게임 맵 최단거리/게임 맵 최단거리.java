import java.util.*;

class Solution {
    
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    static class Node {
        int x, y, dist;
        Node(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        Queue<Node> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][m];
        
        q.offer(new Node(0, 0, 1));
        vis[0][0] = true;
        
        while (!q.isEmpty()) {
            Node cur = q.poll();
            
            if (cur.x == n - 1 && cur.y == m - 1) {
                return cur.dist;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (maps[nx][ny] == 1 && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.offer(new Node(nx, ny, cur.dist + 1));
                    }
                }
            }
        }
        
        return -1;
    }
}