import java.util.*;
import java.io.*;

class Main {

  static int n;
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    n = Integer.parseInt(br.readLine());

    List<int[]> list = new ArrayList<>();

    for(int i=0; i<n; i++){
      st = new StringTokenizer(br.readLine());
      int stt = Integer.parseInt(st.nextToken());
      int en = Integer.parseInt(st.nextToken());
      list.add(new int[]{stt, en});
    }

    Collections.sort(list, (a,b) -> {
      if(a[1] == b[1])
        return Integer.compare(a[0], b[0]);
      return Integer.compare(a[1], b[1]);
    });

    int count =0;
    int lastEnd =0;

    for(int[] meeting: list){
      int stt = meeting[0];
      int en = meeting[1];

      if(stt >= lastEnd){
        count++;
        lastEnd = en;
      }
    }

    System.out.println(count);
    
  }
}