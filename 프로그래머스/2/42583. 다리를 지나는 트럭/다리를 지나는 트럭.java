import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<int[]> bridge = new ArrayDeque<>();
        int time=0;
        int bridgeWeight=0;
        
        for(int truck : truck_weights) {
            time++;
            
            while(!bridge.isEmpty() && bridge.peek()[1] <= time){
                bridgeWeight -= bridge.poll()[0];
            }
            
            while(bridgeWeight + truck > weight){
                int[] leaving = bridge.poll();
                bridgeWeight -= leaving[0];
                time = leaving[1];
            }
            
            bridge.offer(new int[]{truck, time + bridge_length});
            bridgeWeight += truck;
        }
        
        return time + bridge_length;
    }
}