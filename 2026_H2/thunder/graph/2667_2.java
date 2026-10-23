import java.util.*;
import java.io.*;

class Main{

  static int dx[] = {1, 0, -1, 0};
  static int dy[] = {0, -1, 0, 1};

  static String[] board;
  static boolean[][] vis;

  static int n;

  static int bfs(int y, int x){
    Queue<int[]> q = new ArrayDeque<>();
    vis[y][x] = true;
    q.offer(new int[]{y, x});

    int curArea=1;

    while(!q.isEmpty()){
      int[] cur = q.poll();
      int curY = cur[0];
      int curX = cur[1];
      
      for(int dir = 0; dir<4; dir++){
        int ny = curY + dy[dir];
        int nx = curX + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(board[ny].charAt(nx)=='0' || vis[ny][nx]) continue;

        vis[ny][nx] = true;
        q.offer(new int[]{ny, nx});

        curArea++;
      }
    }

    return curArea;
  }
  
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());
    board = new String[n+1];
    vis = new boolean[n+1][n+1];
    List<Integer> count = new ArrayList<>();
    
    for(int i=0; i<n; i++){
      board[i] = br.readLine();
      Arrays.fill(vis[i], false);
    }

    int area = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(board[i].charAt(j)=='0' || vis[i][j]) continue;
        area++;
        count.add(bfs(i, j));
      }
    }

    Collections.sort(count);

    StringBuilder sb = new StringBuilder(String.valueOf(area));
    sb.append('\n');
    
    for(int cnt : count){
      sb.append(cnt).append('\n');
    }

    System.out.println(sb);
  }
}