import java.io.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int k = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());
    

    long[] cable = new long[k];
    long max =0;

    for(int i=0; i<k; i++){
      cable[i] = Long.parseLong(br.readLine());
      max = Math.max(max, cable[i]);
    }

    long left = 1;
    long right = max;
    long answer = 0;

    while(left <= right){
      long mid = left + (right-left)/2;
      long count = 0;

      for(int i=0; i<k; i++){
        count += cable[i] / mid;
      }

      if(count >= n){
        answer = mix;
        left = mid+1;
      } else {
        right = mid-1;
      }
    }

    System.out.println(answer);
  }
}