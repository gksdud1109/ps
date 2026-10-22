import java.io.*;
import java.util.*;

class Main {

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    String s = st.nextToken();

    char[] arr = s.toCharArray();
    int[] cnt = new int[26];

    for(char c : arr){
      cnt[c-'a']++;
    }

    StringBuilder sb = new StringBuilder();

    for(int c : cnt){
      sb.append(c).append(" ");
    }

    System.out.println(sb);
  }
}