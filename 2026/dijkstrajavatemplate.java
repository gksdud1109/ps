import java.util.*;

class Node implements Comparable<Node>{
  int x, y, cost;
  public Node(int x, int y, int cost){
    this.x = x;
    this.y = y;
    this.cost = cost;
  }

  @Override
  public int compareTo(Node other){
    return this.cost - other.cost;
  }
}

public class Main {
  public static void main(String[] args) {
    ArrayList<Node> list = new ArrayList<>();
    list.add(new Node(1,2,10));

    Collections.sort(list);

    PriorityQueue<Node> pq = new PriorityQueue<>();
    pq.add(new Node(3, 4, 5));
    Node cur = pq.poll();
  }
}