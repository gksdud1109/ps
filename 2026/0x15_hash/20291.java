import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());

    Map<String, Integer> extMap = new TreeMap<>();

    for(int i=0; i<n; i++){
      String file = br.readLine();

      int dotIndex = file.indexOf('.');
      String ext = file.substring(dotIndex + 1);

      extMap.put(ext, extMap.getOrDefault(ext, 0)+1);
    }

    StringBuilder sb = new StringBuilder();

    for(Map.Entry<String, Integer> entry : extMap.entrySet()) {
      sb.append(entry.getKey()).append(" ").append(entry.getValue()).append("\n");
    }
    
    System.out.print(sb);
  }
}