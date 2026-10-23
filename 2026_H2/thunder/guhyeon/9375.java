import java.io.*;
import java.util.*;

class Main{

  public static void main(String args[]) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    StringBuilder sb = new StringBuilder();


    for(int i=0; i<n; i++){
      int m = Integer.parseInt(br.readLine());
      Map<String, Integer> clothes = new HashMap<>();
      for(int j=0; j<m; j++){
        StringTokenizer st = new StringTokenizer(br.readLine());
        String a = st.nextToken();
        String category = st.nextToken();

        clothes.put(category, clothes.getOrDefault(category, 0)+1);
      }

      int sum = 1;
      for(String key : clothes.keySet()){
        sum *= (clothes.get(key) + 1);
      }

      sb.append(sum-1).append('\n');
    }
    System.out.println(sb);
  }
}