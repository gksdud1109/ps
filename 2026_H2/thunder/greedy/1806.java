import java.util.*;
import java.io.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int s = Integer.parseInt(st.nextToken());

    int[] arr = new int[n+1];


    st = new StringTokenizer(br.readLine());
    for(int i=0; i<n; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    int left =0;
    long sum =0;
    int answer = n+1;

    for(int right=0; right<n; right++){
      sum += arr[right];

      while(sum>=s){
        answer = Math.min(answer, right-left+1);

        sum -= arr[left];
        left++;
      }
    }

    if(answer == n+1){
      System.out.println(0);
    } else {
      System.out.println(answer);
    }

  }
}