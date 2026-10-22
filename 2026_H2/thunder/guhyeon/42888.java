import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        
        Map<String, String> user = new HashMap<>();
        
        for(String r : record){
            String[] parts = r.split(" ");
            String comm = parts[0];
            String uid = parts[1];
            
            if(comm.equals("Enter") || comm.equals("Change")){
                String name = parts[2];
                user.put(uid, name);
            }
        }
        
        List<String> result = new ArrayList<>();
        for(String r : record){
            String[] parts = r.split(" ");
            String comm = parts[0];
            String uid = parts[1];
            
            if(comm.equals("Enter")){
                result.add(user.get(uid) + "님이 들어왔습니다.");
            } else if(comm.equals("Leave")){
                result.add(user.get(uid) + "님이 나갔습니다.");
            }    
        }
        
        
        return result.toArray(new String[0]);
    }
}