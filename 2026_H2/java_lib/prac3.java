import java.util.*;

class Main{
  public static void main(String[] args){
    Map<String, Integer> map = new HashMap<>();

    map.put("apple", 3);
    map.put("banana", 2);
    map.put("apple", 5);

    System.out.println(map.get("apple"));
    System.out.println(map.get("pear"));
    System.out.println(map.getOrDefault("pear", 0));
    System.out.println(map.containsKey("pear"));

    map.putIfAbsent("apple", 99);
    map.putIfAbsent("pear", 1);

    String word = "banana";
    map.put(word, map.getOrDefault(word, 0)+1);
    System.out.println(map.size());
    System.out.println(map.isEmpty());

    for(Map.Entry<String,Integer> e: map.entrySet()){
      System.out.println(e.getKey() + " " + e.getValue());
    }

    for(String key : map.keySey()) System.out.println(key);
    for(int value : map.values()) System.out.println(value);

    System.out.println(map.remove("pear"));
    System.out.println(map.remove("none"));
    map.clear();

    System.out.println(map.isEmpty());
  }
}