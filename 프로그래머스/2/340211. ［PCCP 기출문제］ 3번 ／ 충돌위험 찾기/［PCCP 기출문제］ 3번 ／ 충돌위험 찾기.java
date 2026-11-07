import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int n = routes.length;
        
        int[] row = new int[n];
        int[] col = new int[n];
        int[] next = new int[n];
        boolean[] finished = new boolean[n];
        
        for(int i=0; i<n; i++){
            int[] start = points[routes[i][0] - 1];
            
            row[i] = start[0];
            col[i] = start[1];
            next[i] = 1;
        }
        
        int remaining = n;
        int answer = 0;
        
        while(remaining > 0){
            Map<Integer, Integer> count = new HashMap<>();
            
            for(int i=0; i<n; i++){
                if(finished[i]) continue;
                
                int key = row[i]*101 + col[i];
                int robots = count.getOrDefault(key, 0) + 1;
                count.put(key, robots);
                
                if(robots==2){
                    answer++;
                }
                
                if(next[i] == routes[i].length){
                    finished[i] = true;
                    remaining--;
                }
            }
            
            for(int i=0; i<n; i++){
                if(finished[i]) continue;
                
                int[] target = points[routes[i][next[i]] - 1];
                
                if(row[i] != target[0]){
                    row[i] += Integer.compare(target[0], row[i]);
                } else {
                    col[i] += Integer.compare(target[1], col[i]);
                }
                
                if(row[i] == target[0] && col[i] == target[1]){
                    next[i]++;
                }
            }
        }
        
        return answer;
    }
}