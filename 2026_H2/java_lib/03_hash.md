# 03. HashMap · HashSet

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/03_hash.md)

사용 신호: 이름으로 조회, 빈도 세기, 중복 제거, 이미 나온 값인지 확인.
HashMap/HashSet은 삽입순·정렬순을 보장하지 않는다. 출력 순서가 필요하면 별도로 정렬한다.

## HashMap: 주요 함수를 한 번에

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("apple", 3);                  // 저장
        map.put("banana", 2);
        map.put("apple", 5);                  // 같은 키는 덮어쓰기
        System.out.println(map.get("apple")); // 5
        System.out.println(map.get("pear"));  // null
        System.out.println(map.getOrDefault("pear", 0)); // 0, 저장되지는 않음
        System.out.println(map.containsKey("pear"));     // false
        map.putIfAbsent("apple", 99);         // 기존 값 유지
        map.putIfAbsent("pear", 1);           // 없으면 저장

        String word = "banana";
        map.put(word, map.getOrDefault(word, 0) + 1); // 빈도 증가 → 3
        System.out.println(map.size());       // 3: 서로 다른 키 수
        System.out.println(map.isEmpty());    // false
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            System.out.println(e.getKey() + " " + e.getValue());
        }
        // 출력 순서는 일정하지 않다.
        for (String key : map.keySet()) System.out.println(key);
        for (int value : map.values()) System.out.println(value);
        System.out.println(map.remove("pear")); // 삭제한 값 1
        System.out.println(map.remove("none")); // 없으면 null
        map.clear();
        System.out.println(map.isEmpty());    // true
    }
}
```

- 없는 키를 `int x = map.get(key)`로 받으면 null 자동 언박싱으로 예외가 난다.
- 없는 키를 0으로 볼 때는 `getOrDefault(key, 0)`를 사용한다.
- `containsKey`는 평균 O(1), `containsValue`는 O(n)이다.
- `get`/`put`/`remove`는 일반적인 해시 분포에서 평균 O(1)이다.
- 순회 중 키를 추가/삭제하려면 iterator 등 적절한 방법을 사용한다.

## HashSet: 중복 제거 · 존재 확인

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        System.out.println(set.add("apple")); // true: 처음 추가
        System.out.println(set.add("apple")); // false: 중복
        set.add("banana");
        System.out.println(set.contains("apple")); // true
        System.out.println(set.size());            // 2
        System.out.println(set.remove("banana"));  // true
        System.out.println(set.remove("pear"));    // false
        List<String> sorted = new ArrayList<>(set);
        Collections.sort(sorted);                 // 정렬 출력이 필요할 때
        for (String s : sorted) System.out.println(s);
        set.clear();
        System.out.println(set.isEmpty());         // true
    }
}
```

## 1620 패턴: 배열 + 맵으로 양방향 조회

번호가 연속된 정수면 그 방향은 배열로 처리할 수 있다. 매 질문마다 배열 전체를 검색하지 않는다.

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        String[] i2s = {"", "Bulbasaur", "Ivysaur", "Pikachu"};
        Map<String, Integer> s2i = new HashMap<>();
        for (int i = 1; i < i2s.length; i++) s2i.put(i2s[i], i);

        String[] queries = {"3", "Ivysaur"};
        for (String query : queries) {
            if (Character.isDigit(query.charAt(0))) {
                System.out.println(i2s[Integer.parseInt(query)]); // Pikachu
            } else {
                System.out.println(s2i.get(query));              // 2
            }
        }
    }
}
```

배열을 키로 사용할 때는 주의한다. `int[]`는 내용이 아니라 참조 기준으로 비교된다.
좌표 방문 여부는 boolean 격자, 안전한 정수 인코딩, equals/hashCode가 정의된 객체 중 하나를 쓴다.

## 닫고 다시 작성하기

- 문자열 배열의 빈도를 세고, 없는 단어는 0으로 조회하기.
- 등장한 단어를 중복 없이 사전순으로 출력하기.
- 1620에서 번호 질문과 이름 질문을 모두 처리하기.
