# 05. PriorityQueue · TreeSet · TreeMap

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/05_heap_ordered.md)

최솟값만 계속 꺼낼 때는 힙, 정렬된 키의 이웃까지 찾아야 하면 TreeSet/TreeMap을 쓴다.

## PriorityQueue: 최소 힙 · 최대 힙 · 사용자 기준

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.offer(10);
        minHeap.offer(2);
        minHeap.offer(5);
        System.out.println(minHeap.peek());   // 2: 조회 O(1)
        System.out.println(minHeap.poll());   // 2: 추출 O(log n)
        System.out.println(minHeap.size());   // 2
        while (!minHeap.isEmpty()) System.out.println(minHeap.poll()); // 5, 10
        System.out.println(minHeap.poll());   // 비어 있으면 null

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        maxHeap.offer(2);
        maxHeap.offer(10);
        System.out.println(maxHeap.peek());   // 10
        maxHeap.clear();

        // [우선순위, 번호]: 우선순위 오름차순, 같으면 번호 오름차순
        PriorityQueue<int[]> jobs = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        jobs.offer(new int[]{5, 2});
        jobs.offer(new int[]{3, 1});
        System.out.println(Arrays.toString(jobs.poll())); // [3, 1]

        PriorityQueue<Integer> absHeap = new PriorityQueue<>((a, b) -> {
            int cmp = Long.compare(Math.abs((long) a), Math.abs((long) b));
            return cmp != 0 ? cmp : Integer.compare(a, b);
        });
        absHeap.offer(1);
        absHeap.offer(-1);
        System.out.println(absHeap.poll());   // -1, 절댓값 같으면 작은 수
    }
}
```

- offer/poll은 O(log n), peek는 O(1), 특정 값 contains/remove는 O(n)이다.
- 힙을 for-each로 순회하면 정렬순이 아니다. 정렬순 추출은 poll을 반복한다.
- 넣어 둔 객체의 우선순위 필드를 외부에서 바꾸지 않는다. 힙이 자동 재정렬되지 않는다.

## TreeSet: 정렬 · 중복 제거 · 경계값

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        TreeSet<Integer> set = new TreeSet<>();
        set.add(10);
        set.add(20);
        set.add(30);
        set.add(20);                         // 중복 무시
        System.out.println(set.contains(20)); // true
        System.out.println(set.first());     // 10, 빈 집합이면 예외
        System.out.println(set.last());      // 30
        System.out.println(set.lower(20));   // 10: < 20 중 최대
        System.out.println(set.floor(20));   // 20: <= 20 중 최대
        System.out.println(set.ceiling(20)); // 20: >= 20 중 최소
        System.out.println(set.higher(20));  // 30: > 20 중 최소
        System.out.println(set.ceiling(99)); // 없으면 null
        System.out.println(set.pollFirst()); // 10: 최소값 삭제 후 반환
        System.out.println(set.pollLast());  // 30: 최대값 삭제 후 반환
        set.remove(20);
        System.out.println(set.isEmpty());   // true
    }
}
```

lower/floor/ceiling/higher가 null을 반환할 수 있으므로 `Integer`로 받거나 null을 먼저 확인한다.
정렬 기준상 비교 결과가 0인 원소는 중복으로 취급된다. 객체 정렬에는 필요한 동점 기준을 넣는다.

## TreeMap: 정렬된 키 + 값 · 중복 개수 관리

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        TreeMap<Integer, Integer> count = new TreeMap<>();
        int[] values = {20, 10, 20, 30};
        for (int x : values) count.put(x, count.getOrDefault(x, 0) + 1);
        System.out.println(count.get(20));           // 2
        System.out.println(count.firstKey());        // 10
        System.out.println(count.lastKey());         // 30
        System.out.println(count.floorKey(25));      // 20
        System.out.println(count.ceilingKey(25));    // 30
        Map.Entry<Integer, Integer> e = count.floorEntry(25);
        if (e != null) System.out.println(e.getKey() + " " + e.getValue()); // 20 2

        int x = 20;                                 // 중복 중 하나만 삭제
        int c = count.getOrDefault(x, 0);
        if (c > 1) count.put(x, c - 1);
        else if (c == 1) count.remove(x);
        System.out.println(count.get(20));           // 1
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }                                           // 키 오름차순
        count.clear();
        System.out.println(count.isEmpty());         // true
    }
}
```

TreeSet은 중복을 저장하지 않는다. 중복 값의 정렬된 관리가 필요하면 TreeMap에 개수를 저장한다.
TreeMap의 size는 전체 원소 수가 아니라 서로 다른 키의 수다.

## 닫고 다시 작성하기

- 최소 힙으로 카드 두 묶음을 꺼내 합친 뒤 다시 넣기: 1715.
- 절댓값이 같을 때 작은 수가 먼저 나오는 힙 만들기: 11286.
- 집합에서 x 이상인 가장 작은 값을 찾고, 없으면 별도로 처리하기.
