import java.io.*;
import java.util.*;

class Main {
  static int m, n;
  static int[][] board;
  static boolean[][] vis;

  static int dx[] = {-1, 0, 1, 0};
  static int dy[] = {0, 1, 0, -1};

  static int bfs(int y, int x){
    ArrayDeque<int[]> q = new ArrayDeque<>();

    vis[y][x] = true;
    q.offer(new int[]{y, x});

    int area = 0;

    while(!q.isEmpty()){
      int[] cur = q.poll();
      int curY = cur[0];
      int curX = cur[1];
      area++;

      for(int dir = 0; dir<4; dir++){
        int ny = curY + dy[dir];
        int nx = curX + dx[dir];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (board[ny][nx] == 1 || vis[ny][nx]) continue;

        vis[ny][nx] = true;
        q.offer(new int[]{ny, nx});
      }
    }

    return area;
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());

    int k = Integer.parseInt(st.nextToken());

    board = new int[m][n];
    vis = new boolean[m][n];

    for(int i=0; i<k; i++){
      st = new StringTokenizer(br.readLine());

      int x1 = Integer.parseInt(st.nextToken());
      int y1 = Integer.parseInt(st.nextToken());
      int x2 = Integer.parseInt(st.nextToken());
      int y2 = Integer.parseInt(st.nextToken());
      
      for(int y=y1; y<y2; y++){
        for(int x=x1; x<x2; x++){
          board[y][x] = 1;
        }
      }
    }

    ArrayList<Integer> areas = new ArrayList<>();

    for(int y=0; y<m; y++){
      for(int x=0; x<n; x++){
        if(board[y][x] == 1 || vis[y][x]) continue;

        areas.add(bfs(y,x));
      }
    }

    Collections.sort(areas);

    StringBuilder sb = new StringBuilder();

    sb.append(areas.size()).append('\n');
    for(int area: areas){
      sb.append(area).append(' ');
    }

    System.out.println(sb);
  }
}