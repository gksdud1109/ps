import java.io.*;
import java.util.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int w = Integer.parseInt(st.nextToken());
    int l = Integer.parseInt(st.nextToken());

    Queue<Integer> truck = new ArrayDeque<>();

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<n; i++){
      truck.offer(Integer.parseInt(st.nextToken()));
    }

    Queue<Integer> bridge = new ArrayDeque<>();
    for(int i=0; i<w; i++){
      bridge.offer(0);
    }

    int time = 0;
    int weight = 0;
    while(!truck.isEmpty() || weight > 0){
      time++;

      weight -= bridge.poll();

      if(!truck.isEmpty() && weight + truck.peek() <= l){
        int cur = truck.poll();
        bridge.offer(cur);
        weight += cur;
      } else {
        bridge.offer(0);
      }
    }
    System.out.println(time);
  }
}