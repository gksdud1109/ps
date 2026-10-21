import java.io.*;
import java.util.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    String[] i2s = new String[n+1];
    Map<String, Integer> s2i = new HashMap<>();

    for(int i=1; i<=n; i++){
      String name = br.readLine();
      i2s[i] = name;
      s2i.put(name, i);
    }

    StringBuilder sb = new StringBuilder();

    for(int i=0; i<m; i++){
      String query = br.readLine();

      if(Character.isDigit(query.charAt(0))){
        int number = Integer.parseInt(query);
        sb.append(i2s[number]);
      } else {
        sb.append(s2i.get(query));
      }

      sb.append('\n');
    }

    System.out.print(sb);
  }
}