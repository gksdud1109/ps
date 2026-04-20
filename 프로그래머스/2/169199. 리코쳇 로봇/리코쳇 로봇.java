import java.util.*;

class Solution {
    
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    static class Node{
        int x, y, depth;
        Node(int x, int y, int depth){
            this.x = x;
            this.y = y;
            this.depth = depth;
        }
    }
    
    public int solution(String[] board) {
        int n = board.length;
        int m = board[0].length();
        
        Queue<Node> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i].charAt(j) == 'R'){
                    q.offer(new Node(i, j, 0));
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.isEmpty()){
            Node cur = q.poll();
            if(board[cur.x].charAt(cur.y) == 'G'){
                return cur.depth;
            }
            
            for(int i=0; i<4; i++){
                int nx = cur.x;
                int ny = cur.y;
                
                while(nx+dx[i] >= 0 && nx+dx[i]<n &&
                     ny+dy[i] >= 0 && ny+dy[i]<m &&
                     board[nx+dx[i]].charAt(ny+dy[i]) != 'D'){
                    nx += dx[i];
                    ny += dy[i];
                }
                
                if(!vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.offer(new Node(nx, ny, cur.depth+1));
                }
            }
        }
        return -1;
    }
}