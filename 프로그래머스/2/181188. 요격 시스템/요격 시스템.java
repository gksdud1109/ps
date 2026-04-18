import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        Arrays.sort(targets, (o1, o2) ->{
            if(o1[1] == o2[1]){
                return o1[0] - o2[0];
            }
            return o1[1] - o2[1];
        });
        
        int answer = 0;
        int lastMissile = -1;
        
        for(int[] target: targets){
            int s = target[0];
            int e = target[1];
            
            if(s>= lastMissile){
                answer++;
                
                lastMissile = e;
            }
        }
        return answer;
    }
}