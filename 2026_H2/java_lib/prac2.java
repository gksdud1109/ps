import java.util.*;

class Main {
  public static void main(String[] args) {
    List<Integer> list = new ArrayList<>();

    list.add(10); // 10
    list.add(30); // 10 30
    list.add(1, 20); // 10 20 30
    System.out.println(list.get(1)); // 20
    list.set(1,25); // 10 25 30
    System.out.println(list.contains(25)); // true
    System.out.println(list.indexOf(30)); // 2, 없으면 -1
    System.out.println(list.size()) // 3
    list.remove(0); // 인덱스 0 삭제 -> 25, 30
    list.remove(Integer.valueOf(30)); // 값 30 삭제 -> 25
    list.addAll(Arrays.asList(5, 15));
    list.sort(Integer::compare);
    Collections.reverse(list);
    for(int x : list) System.out.print(x + " ");
    System.out.println();

    List<Integer> copied = new ArrayList<>(list);
    copied.clear();

    System.out.println(copied.isEmpty());
    System.out.println(list.size());
  }
}