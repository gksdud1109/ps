class Solution {
    public String solution(String s) {
        
        String[] strNums = s.split(" ");
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for(String str: strNums){
            int num = Integer.parseInt(str);
            
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        
        return min + " " + max;
    }
}