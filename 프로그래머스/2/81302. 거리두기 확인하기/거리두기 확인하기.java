import java.util.*;

class Solution {
    int[] dy = {-1, 1, 0, 0};
    int[] dx = {0, 0, -1, 1};
    
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        
        for(int i=0; i<places.length; i++){
            answer[i] = checkRoom(places[i]) ? 1 : 0;
        }
        
        return answer;
    }
    
    private boolean checkRoom(String[] room){
        for(int y=0; y<5; y++){
            for(int x=0; x<5; x++){
                if(room[y].charAt(x) != 'P') continue;
                if(!bfs(room, y, x)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private boolean bfs(String[] room, int startY, int startX){
        boolean[][] vis = new boolean[5][5];
        Queue<int[]> q = new ArrayDeque<>();
        
        vis[startY][startX] = true;
        q.offer(new int[]{startY, startX, 0});
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            int y = cur[0];
            int x = cur[1];
            int distance = cur[2];
            
            if(distance == 2) continue;
            
            for(int dir=0; dir<4; dir++){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                
                if(ny<0 || ny>= 5 || nx<0 || nx>=5) continue;
                if(vis[ny][nx]) continue;
                
                char next = room[ny].charAt(nx);
                
                if(next == 'X') continue;
                
                if(next == 'P') return false;
                
                vis[ny][nx] = true;
                q.offer(new int[]{ny, nx, distance + 1});
            }
        }
        
        return true;
    }
}