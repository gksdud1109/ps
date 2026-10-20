# 04. 스택 · 큐 · 덱

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/04_stack_queue_deque.md)

코테에서는 스택·큐·덱 모두 ArrayDeque로 구현할 수 있다.
스택은 같은 끝에서 넣고 빼기, 큐는 서로 다른 끝에서 넣고 빼기다.
ArrayDeque에는 null을 넣을 수 없다.

## 스택: push/peek/pop

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(10);                      // 앞에 추가
        stack.push(20);
        System.out.println(stack.peek());    // 20: 조회만
        System.out.println(stack.pop());     // 20: 꺼내면서 삭제
        System.out.println(stack.size());    // 1
        System.out.println(stack.isEmpty()); // false
        if (!stack.isEmpty()) System.out.println(stack.pop()); // 10
        System.out.println(stack.peek());    // 비어 있으면 null
        // 빈 스택에서 pop()은 예외. int x = stack.peek()도 null 언박싱 예외.
    }
}
```

## 큐: offer/peek/poll

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(10);                         // 뒤에 추가
        q.offer(20);
        System.out.println(q.peek());        // 10: 조회만
        System.out.println(q.poll());        // 10: 앞에서 꺼내기
        System.out.println(q.size());        // 1
        while (!q.isEmpty()) System.out.println(q.poll()); // 20
        System.out.println(q.poll());        // 비어 있으면 null
    }
}
```

## 덱: 양끝 추가/조회/삭제

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offerFirst(10);                   // [10]
        dq.offerLast(20);                    // [10, 20]
        dq.offerFirst(5);                    // [5, 10, 20]
        System.out.println(dq.peekFirst());  // 5
        System.out.println(dq.peekLast());   // 20
        System.out.println(dq.pollFirst());  // 5, [10, 20]
        System.out.println(dq.pollLast());   // 20, [10]
        System.out.println(dq.size());       // 1
        for (int x : dq) System.out.println(x); // 10
        dq.clear();
        System.out.println(dq.isEmpty());    // true
    }
}
```

ArrayDeque는 C++ deque와 달리 `get(i)` 같은 인덱스 조회 API가 없다.
5430의 R은 실제로 뒤집지 않고 방향 boolean을 바꾸고, D는 방향에 맞는 끝에서 삭제할 수 있다.

## 빈출 패턴: 괄호 검사

```java
import java.util.*;

class Main {
    static boolean valid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[') stack.push(c);
            else if (c == ')' || c == ']') {
                if (stack.isEmpty()) return false;
                char open = stack.pop();
                if (c == ')' && open != '(') return false;
                if (c == ']' && open != '[') return false;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(valid("([])")); // true
        System.out.println(valid("([)]")); // false
    }
}
```

## 빈출 패턴: 왼쪽에서 가장 가까운 더 큰 값의 위치

2493 탑과 같은 단조 스택. 인덱스를 저장하고 더 이상 답이 될 수 없는 후보를 제거한다.

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] height = {6, 9, 5, 7, 4};
        int[] answer = new int[height.length];
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < height.length; i++) {
            while (!stack.isEmpty() && height[stack.peek()] <= height[i]) {
                stack.pop();
            }
            answer[i] = stack.isEmpty() ? 0 : stack.peek() + 1;
            stack.push(i);
        }
        System.out.println(Arrays.toString(answer)); // [0, 0, 2, 2, 4]
    }
}
```

각 인덱스는 한 번 들어가고 최대 한 번 빠지므로 전체 O(n)이다.
같은 높이를 답으로 인정하는 문제라면 제거 조건을 `<`로 바꾸는 등 정의를 먼저 확인한다.

## 닫고 다시 작성하기

- 같은 입력을 스택과 큐에서 꺼냈을 때 순서 비교하기.
- 덱과 방향 boolean으로 뒤집기·삭제 구현하기.
- 괄호 문제에서 여는 괄호만 남는 경우와 닫는 괄호가 먼저 오는 경우 검사하기.
