import java.io.*;
import java.util.*; 

class Main {

  static int[] dx = {-1, 0, 1, 0};
  static int[] dy = {0, 1, 0, -1};

  static String[] board;
  static int n;
  static boolean[][] vis;

  static int bfs(int y, int x){
    Queue<int[]> q = new ArrayDeque<>();

    vis[y][x] = true;
    q.offer(new int[]{y, x});

    int width = 0;

    while(!q.isEmpty()){
      int[] cur = q.poll();
      int curY = cur[0];
      int curX = cur[1];

      width++;

      for(int dir = 0; dir<4; dir++){
        int ny = curY+dy[dir];
        int nx = curX+dx[dir];

        if(ny<0 || ny>=n || nx <0 || nx >=n) continue;
        if(board[ny].charAt(nx) == '0' || vis[ny][nx]) continue;

        vis[ny][nx] true;
        q.offer(new int[]{ny, nx});
      }
    }

    return width;
  }

  public static void main(String[] args){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    n = Integer.pareseInt(br.readLine());
    board = new String[n];
    vis = new boolean[n][n];

    for(int i=0; i<n; i++) board[i] = br.readLine();

    List<Integer> answer = new ArrayList<>();

    for(int y=0; y<n; y++){
      for(int x=0; x<n; x++){
        if(board[y].charAt(x) == '0' || vis[y][x]) continue;

        answer.add(bfs(y,x));
      }
    }

    Collections.sort(answer);
    StringBuilder sb = new StringBuilder();
    sb.append(answer.size()).append('\n');

    for(int size: answer){
      sb.append(size).append('\n');
    }

    System.out.print(sb);
  }
}