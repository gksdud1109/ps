import java.util.*;

class Solution {
    public String solution(String new_id) {
        String id = new_id.toLowerCase(Locale.ROOT);
        
        StringBuilder sb = new StringBuilder();
        
        for(char c : id.toCharArray()){
            boolean valid = (c>='a' && c <='z')
                || (c>='0' && c <= '9')
                || c == '-' || c == '_' || c == '.';
            
            if(!valid) continue;
            if(c == '.' && sb.length() > 0
              && sb.charAt(sb.length()-1) == '.') continue;
            
            sb.append(c);
        }
        // 4
        if(sb.length() > 0 && sb.charAt(0) == '.') 
            sb.deleteCharAt(0);
        
        if(sb.length() > 0 && sb.charAt(sb.length()-1) == '.') 
            sb.deleteCharAt(sb.length()-1);
        
        // 5
        if(sb.length() == 0){
            sb.append('a');
        }
        
        // 6
        if(sb.length() > 15){
            sb.setLength(15);
        }
        if(sb.charAt(sb.length() -1)== '.')
            sb.deleteCharAt(sb.length()-1);
        
        // 7
        while(sb.length() < 3){
            sb.append(sb.charAt(sb.length()-1));
        }
        
        return sb.toString();
    }
}