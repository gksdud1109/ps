# 02. ArrayList · LinkedList · 정렬

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/02_list_sort.md)

## ArrayList: add/get/set/remove/contains/size/clear

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        list.add(10);                 // [10]
        list.add(30);                 // [10, 30]
        list.add(1, 20);              // [10, 20, 30]
        System.out.println(list.get(1)); // 20
        list.set(1, 25);              // [10, 25, 30]
        System.out.println(list.contains(25)); // true, O(n)
        System.out.println(list.indexOf(30));  // 2, 없으면 -1
        System.out.println(list.size());      // 3
        list.remove(0);               // 인덱스 0 삭제 → [25, 30]
        list.remove(Integer.valueOf(30)); // 값 30 삭제 → [25]
        list.addAll(Arrays.asList(5, 15));     // [25, 5, 15]
        list.sort(Integer::compare);         // [5, 15, 25]
        Collections.reverse(list);           // [25, 15, 5]
        for (int x : list) System.out.print(x + " ");
        System.out.println();
        List<Integer> copied = new ArrayList<>(list);
        copied.clear();                      // 원본은 유지
        System.out.println(copied.isEmpty()); // true
        System.out.println(list.size());      // 3
    }
}
```

`remove(숫자)`는 인덱스 삭제다. 값 삭제는 `remove(Integer.valueOf(값))`이다.
중간 삽입/삭제는 O(n). 인덱스로 자주 접근한다면 LinkedList보다 ArrayList가 적합하다.

## LinkedList + ListIterator: 커서 앞 삽입/삭제

1406 에디터처럼 커서 위치를 유지할 때 쓴다. iterator는 원소가 아니라 원소 사이의 커서로 생각한다.

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        LinkedList<Character> list = new LinkedList<>();
        list.add('a');
        list.add('b');
        ListIterator<Character> cursor = list.listIterator(list.size());
        // a b | (맨 끝)
        if (cursor.hasPrevious()) cursor.previous(); // a | b
        cursor.add('x');                             // a x | b
        if (cursor.hasPrevious()) {
            cursor.previous();                      // a | x b
            cursor.remove();                        // a | b, 직전 반환 원소 삭제
        }
        if (cursor.hasNext()) cursor.next();        // a b |
        StringBuilder sb = new StringBuilder();
        for (char c : list) sb.append(c);
        System.out.println(sb);                     // ab
    }
}
```

`remove()`는 `next()`/`previous()`로 반환받은 원소에만 가능하다.
iterator 사용 중 `list.add/remove`를 섞지 않고 iterator의 메서드로 수정한다.
LinkedList의 `get(i)`/`listIterator(i)`로 위치를 찾는 작업 자체는 O(n)이다.

## 정렬: 기본형 배열 · 리스트 · 다중 조건

```java
import java.util.*;

class Main {
    static class Student {
        String name;
        int kor, eng, math;
        Student(String name, int kor, int eng, int math) {
            this.name = name;
            this.kor = kor;
            this.eng = eng;
            this.math = math;
        }
    }

    public static void main(String[] args) {
        int[] a = {3, 1, 2};
        Arrays.sort(a);                     // [1, 2, 3]
        Integer[] b = {3, 1, 2};
        Arrays.sort(b, Comparator.reverseOrder()); // [3, 2, 1]
        // int[]에는 Comparator를 직접 전달할 수 없다.

        Student[] stu = {
            new Student("Kim", 90, 70, 80),
            new Student("Lee", 90, 60, 80),
            new Student("Ahn", 90, 60, 90)
        };
        Arrays.sort(stu, (x, y) -> {
            if (x.kor != y.kor) return Integer.compare(y.kor, x.kor);
            if (x.eng != y.eng) return Integer.compare(x.eng, y.eng);
            if (x.math != y.math) return Integer.compare(y.math, x.math);
            return x.name.compareTo(y.name);
        });
        for (Student s : stu) System.out.println(s.name); // Ahn, Lee, Kim

        List<String> words = new ArrayList<>(Arrays.asList("bb", "c", "aa"));
        words.sort(Comparator.comparingInt(String::length)
                             .thenComparing(Comparator.naturalOrder()));
        System.out.println(words);          // [c, aa, bb]
    }
}
```

- 비교 결과가 음수면 첫 번째 인자를 앞에, 양수면 뒤에 둔다. 같으면 0이다.
- 정렬 기준이 같을 때만 다음 기준으로 넘어간다. 10825의 핵심이다.
- 합계처럼 계산한 값을 비교할 때도 범위에 맞춰 `Long.compare`를 사용한다.
- 객체 배열과 List의 이 정렬은 안정 정렬이다. 같은 기준의 원소 순서를 유지한다.

## 닫고 다시 작성하기

- 학생을 점수 내림차순, 이름 오름차순으로 정렬하기.
- 정수 리스트에서 인덱스 1과 값 1을 각각 삭제하기.
- 1406의 L/D/B/P 동작을 ListIterator로 구현하기.
