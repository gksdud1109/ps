import java.util.*;

class Solution {
    public int solution(int[][] info, int n, int m) {
        int INF = 987654321;
        
        int[] dp = new int[m];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        
        for(int[] item: info){
            int traceA = item[0];
            int traceB = item[1];
            
            int[] nextDp = new int[m];
            Arrays.fill(nextDp, INF);
            
            for(int j=0; j<m; j++){
                if(dp[j] == INF) continue;
                
                nextDp[j] = Math.min(nextDp[j], dp[j] + traceA);
                
                if(j+traceB < m){
                    nextDp[j+traceB] = Math.min(nextDp[j+traceB], dp[j]);
                }
            }
            
            dp = nextDp;
        }
        
        int answer = INF;
        for(int j=0; j<m; j++){
            if(dp[j] < n){
                answer = Math.min(answer, dp[j]);
            }
        }
        
        return answer == INF ? -1 : answer;
    }
}