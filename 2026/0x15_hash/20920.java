import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    Map<String, Integer> wordCound = new HashMap<>();

    for(int i=0; i<n; i++){
      String word = br.readLine();

      if(word.length() >= m){
        wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
      }
    }

    List<String> words = new ArrayList<>(wordCount.keySet());

    words.sort((w1, w2) ->{
      int c1 = wordCount.get(w1);
      int c2 = wordCount.get(w2);

      // 조건 1. 자주 나오는 단어일수록 앞에 배치 (빈도수 내림차순)
      if(c1 != c2) return c2 - c1;
      // 조건 2. 해당 단어의 길이가 길수록 앞에 배치 (길이 내림차순)
      if(w1.length() != w2.length()) return w2.length() - w1.length();
      // 조건 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치 (사전 오름차순)
      return w1.compareTo(w2);
    });

    StringBuilder sb = new StringBuilder();
    for(String word : words){
      sb.append(word).append("\n");
    }

    System.out.print(sb);
  }
}