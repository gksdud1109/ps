import java.io.*;
import java.util.*;

class Main{

  static int n, m;
  static int[] path;
  static boolean[] used;
  static StringBuilder sb = new StringBuilder();

  static void func(int depth){
    if(depth == m){
      for(int i=0; i<m; i++){
        if(i>0) sb.append(' ');
        sb.append(path[i]);
      }

      sb.append('\n');
      return;
    }

    for(int i=1; i<=n; i++){
      if(used[i]) continue;

      used[i] = true;
      path[depth] = i;
      func(depth+1);
      used[i] = false;
    }
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    path = new int[m];
    used = new boolean[n+1];

    func(0);

    System.out.println(sb);
  }
}