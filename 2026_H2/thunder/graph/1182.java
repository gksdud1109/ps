import java.io.*;
import java.util.*;

class Main{
  static int n, s;
  static int[] arr = new int[30];
  static int cnt=0;
  StringBuilder sb = new StringBuilder();

  static void func(int cur, int tot){
    if(cur == n){
      if(tot == s) cnt++;
      return;
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    s = Integer.parseInt(st.nextToken());


    st = new StringTokenizer(br.readLine());
    for(int i=0; i<n; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    func(0, 0);

    if(s == 0) cnt--;
    System.out.println(cnt);
  }
}