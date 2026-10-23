import java.util.*;
import java.io.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int n = Integer.parseInt(br.readLine());

    int[][] cost = new int[n][3];
    int[][] dp = new int[n][3];

    for(int i=0; i<n; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());
      cost[i][0] = Integer.parseInt(st.nextToken());
      cost[i][1] = Integer.parseInt(st.nextToken());
      cost[i][2] = Integer.parseInt(st.nextToken());
    }

    for(int j=0; j<3; j++){
      dp[0][j] = cost[0][j];
    }

    for(int i=1; i<n; i++){
      dp[i][0] = cost[i][0] + Math.min(dp[i-1][1], dp[i-1][2]);
      dp[i][1] = cost[i][1] + Math.min(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = cost[i][2] + Math.min(dp[i-1][0], dp[i-1][1]);
    }

    int answer = Math.min(
      dp[n-1][0],
      Math.min(dp.[n-1][1], dp[n-1][2])
    );

    System.out.println(answer);
  }
}