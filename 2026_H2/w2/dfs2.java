import java.io.*;
import java.util.*;

class Main{

  static int dx[] = {-1, 0, 1, 0};
  static int dy[] = {0, 1, 0, -1};

  public static void main(String args[]) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int ret=0;
    int board[][] = new int[m][n];
    boolean vis[][] = new boolean[m][n];

    for(int i=0; i<m; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<n; j++){
        board[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        if(board[i][j]==1 && !vis[i][j]) {
          dfs(j, i, board, vis);
          ret++;
        }
      }
    }

    System.out.println(ret);
    
  }

  public static void dfs(int x, int y, int[][] board, boolean[][] vis){
    vis[y][x] = true;

    for(int dir=0; dir<4; dir++){
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if(nx < 0 || nx >= board[0].length || ny < 0 || ny >= board.length) continue;
      if(vis[ny][nx] || board[ny][nx]==0) continue;
      
      dfs(nx, ny, board, vis);
    }
  }
}