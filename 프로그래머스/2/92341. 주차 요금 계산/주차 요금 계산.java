import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> inTime = new HashMap<>();
        Map<String, Integer> totalTime = new TreeMap<>();
        
        for(String record : records){
            String[] parts = record.split(" ");
            String[] times = parts[0].split(":");
            int time = Integer.parseInt(times[0])*60 + Integer.parseInt(times[1]);
            String car = parts[1];
            String action = parts[2];
            
            if(action.equals("IN")){
                inTime.put(car, time);
            } else {
                int start = inTime.remove(car);
                int duration = time - start;
                
                totalTime.put(car, totalTime.getOrDefault(car, 0)+duration);
            }
        }
        
        int endTime = 23*60+59;
        for(Map.Entry<String, Integer> entry: inTime.entrySet()){
            String car = entry.getKey();
            int duration = endTime - entry.getValue();
            
            totalTime.put(car, totalTime.getOrDefault(car, 0)+duration);
        }
        
        int[] answer = new int[totalTime.size()];
        
        int idx = 0;
        
        for(int time : totalTime.values()){
            int cost = fees[1];
            if(time > fees[0]){
                int extraTime = time - fees[0];
                int units = (extraTime + fees[2] - 1) / fees[2];
                
                cost += units*fees[3];
            }
            answer[idx++] = cost;
        }
        
        return answer;
    }
}