import java.util.*;

class Solution {
    static class Task{
        String name;
        int start;
        int remaining;
        
        Task(String name, int start, int remaining){
            this.name = name;
            this.start = start;
            this.remaining = remaining;
        }
    }
    
    public String[] solution(String[][] plans) {
        int n = plans.length;
        Task[] tasks = new Task[n];
        
        for(int i=0; i<n; i++){
            tasks[i] = new Task(
                plans[i][0], toMinutes(plans[i][1]), Integer.parseInt(plans[i][2])
            );
        }
        
        Arrays.sort(tasks, (a, b) -> Integer.compare(a.start, b.start));
        
        Deque<Task> stack = new ArrayDeque<>();
        List<String> answer = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            stack.push(tasks[i]);
            
            if(i==n-1) break;
            
            // 다음 과제 시작시간까지 가용시간
            int available = tasks[i+1].start - tasks[i].start;
            
            while(available > 0 && !stack.isEmpty()){
                Task cur = stack.peek();
                // 완료하고 남은 시간에 다른 과제도 진행
                if(cur.remaining <= available){
                    available -= cur.remaining;
                    answer.add(stack.pop().name);
                } else {
                    cur.remaining -= available;
                    break;
                }
            }
        }
        
        while(!stack.isEmpty()){
            answer.add(stack.pop().name);
        }
        
        return answer.toArray(new String[0]);
    }
    
    private int toMinutes(String time){
        int hour = Integer.parseInt(time.substring(0,2));
        int minute = Integer.parseInt(time.substring(3, 5));
        return hour*60 + minute;
    }
}