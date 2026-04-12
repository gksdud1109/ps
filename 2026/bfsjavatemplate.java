import java.util.*;

class Point{
  int x, y;
  Point(int x, int y) {this.x=x; this.y=y;}
}

public class Main{
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, 1, -1};

  public static void main(String[] args){
    Queue<Point> q = new LinkedList<>();
    boolean[][] vis = new boolean[100][100];

    q.offer(new Point(0,0));
    vis[0][0] = true;

    while(!q.isEmpty()){
      Point cur = q.poll();
      for(int dir = 0; dir <4; dir++){
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];

        if(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
        if(vis[nx][ny]) continue;

        vis[nx][ny] = true;
        q.offer(new Point(nx, ny));
      }
    }
  }
}