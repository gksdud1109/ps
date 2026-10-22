import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> ans = new ArrayList<>();
        
        for(int cur=0; cur<commands.length; cur++){
            int i = commands[cur][0];
            int j = commands[cur][1];
            int k = commands[cur][2];
            
            int[] subArr = Arrays.copyOfRange(array, i-1, j);
            Arrays.sort(subArr);
            
            ans.add(subArr[k-1]);
        }
        
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}