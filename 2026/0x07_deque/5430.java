import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws IOException{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int T = Integer.parseInt(br.readLine());

    for(int t=0; t<T; t++){
      String commands = br.readLine();
      int n = Integer.parseInt(br.readLine());
      String arrayStr = br.readLine();

      Deque<Integer> deque = new ArrayDeque<>();

      arrayStr = arrayStr.substring(1, arrayStr.length() - 1);

      int (n > 0){
        String[] nums = arrayStr.split(",");
        for(String num : nums){
          deque.add(Integer.parseInt(num));
        }
      }

      boolean isReversed = false;
      boolean isError = false;

      for(char cmd : commands.toCharArray()){
        if(cmd == 'R'){
          isReversed = !isReversed;
        } else if(cmd == 'D'){
          if (deque.isEmpty()) {
            isError = true;
            break; // 더 이상 수행할 필요 없음
          }
          // 방향에 따라 앞 혹은 뒤에서 데이터를 뺌 (O(1))
          if (isReversed) {
            deque.pollLast();
          } else {
            deque.pollFirst();
          }
        }
      }

      if (isError) {
        sb.append("error\n");
      } else {
        sb.append("[");
        while (!deque.isEmpty()) {
          sb.append(isReversed ? deque.pollLast() : deque.pollFirst());
          if (!deque.isEmpty()) {
            sb.append(",");
          }
        }
        sb.append("]\n");
      }
    }
    System.out.print(sb);
  }
}