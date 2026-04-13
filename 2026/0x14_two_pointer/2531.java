import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int d = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());


    int[] sushi = new int[N];
    for(int i=0; i<N; i++){
      sushi[i] = Integer.parseInt(br.readLine());
    }

    int[] eatCount = new int[d+1];
    int uniqueCount = 0;

    eatCount[c]++;
    uniqueCount++;

    for(int i=0; i<k; i++){
      if(eatCount[sushi[i]] == 0){
        uniqueCount++;
      }
      eatCount[sushi[i]]++;
    }

    int maxSushi = uniqueCount;

    for(int i=0; i<N; i++){
      int removeSushi = sushi[i];
      eatCount[removeSushi]--;
      if(eatCount[removeSushi] == 0) uniqueCount--;

      int addSushi = sushi[(i+k)%N];
      if(eatCount[addSushi] == 0){
        uniqueCount++;
      }

      maxSushi = Math.max(maxSushi, uniqueCount);

      if (maxSushi == k + 1) break;
    }

    System.out.println(maxSushi);
  }
}