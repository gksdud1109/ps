# 08. 완전탐색 · 백트래킹 · 비트마스크

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/08_backtracking.md)

먼저 탐색 규모를 계산한다. 부분집합은 2^n, 순열은 최대 n!이므로 작은 입력에 적용한다.
백트래킹의 핵심은 선택 → 재귀 → 선택 복구다. 가지치기는 답이 될 수 없는 경우만 제거한다.

## 순열: 서로 다른 n개 중 m개를 순서 있게 고르기

```java
import java.util.*;

class Main {
    static int n = 3, m = 2;
    static int[] path = new int[m];
    static boolean[] used = new boolean[n + 1];

    static void dfs(int depth) {
        if (depth == m) {
            System.out.println(Arrays.toString(path));
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            used[i] = true;
            path[depth] = i;
            dfs(depth + 1);
            used[i] = false; // 다른 경로를 위해 복구
        }
    }

    public static void main(String[] args) {
        dfs(0); // [1, 2], [1, 3], [2, 1], [2, 3], [3, 1], [3, 2]
    }
}
```

원소 중복 선택이 허용되면 used 검사를 제거한다.
선택할 값 자체에 중복이 있으면 별도의 중복 결과 방지 조건이 필요하다.

## 조합: 순서 없이 고르기

```java
import java.util.*;

class Main {
    static int n = 4, m = 2;
    static int[] path = new int[m];

    static void dfs(int depth, int start) {
        if (depth == m) {
            System.out.println(Arrays.toString(path));
            return;
        }
        for (int i = start; i <= n; i++) {
            path[depth] = i;
            dfs(depth + 1, i + 1); // 이후에는 더 큰 값만 고른다
        }
    }

    public static void main(String[] args) {
        dfs(0, 1); // 6개: [1,2], [1,3], [1,4], [2,3], [2,4], [3,4]
    }
}
```

중복 조합은 다음 시작점을 `i + 1` 대신 `i`로 한다.

## 비트마스크: 집합 연산과 모든 부분집합

```java
class Main {
    public static void main(String[] args) {
        int mask = 0, i = 1;
        mask |= 1 << i;                   // i번 원소 추가
        System.out.println((mask & (1 << i)) != 0); // true: 포함 확인
        mask ^= 1 << i;                   // 토글: 이번에는 제거
        mask |= 1 << 2;
        mask &= ~(1 << 2);                // 2번 원소 제거
        System.out.println(Integer.bitCount(mask)); // 0

        int[] a = {1, 2, 3};
        int target = 3, count = 0;
        for (int subset = 1; subset < (1 << a.length); subset++) {
            int sum = 0;
            for (int j = 0; j < a.length; j++) {
                if ((subset & (1 << j)) != 0) sum += a[j];
            }
            if (sum == target) count++;
        }
        System.out.println(count);        // 2: {3}, {1,2}
    }
}
```

빈 부분집합을 제외하려고 subset=1부터 시작했다. 전체 시간은 O(n·2^n)이다.
위 int 열거 틀은 n<31인 작은 입력용이다. 더 넓은 마스크는 `1L << i`를 쓰되 탐색량은 별도로 계산한다.

## nextPermutation: 사전순 다음 순열

Java 표준 라이브러리에는 C++ next_permutation 대응 함수가 없어 직접 구현하거나 재귀로 생성한다.

```java
import java.util.*;

class Main {
    static boolean nextPermutation(int[] a) {
        int i = a.length - 2;
        while (i >= 0 && a[i] >= a[i + 1]) i--;
        if (i < 0) return false;
        int j = a.length - 1;
        while (a[j] <= a[i]) j--;
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        for (int l = i + 1, r = a.length - 1; l < r; l++, r--) {
            tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 3};
        Arrays.sort(a); // 모든 순열을 보려면 오름차순부터
        do {
            System.out.println(Arrays.toString(a));
        } while (nextPermutation(a)); // 6개
    }
}
```

이 구현은 마지막 순열에서 false를 반환할 때 배열을 초기 순열로 돌리지 않는다.
C++ next_permutation의 마지막 상태 처리와 다르므로 반복 이후 배열을 재사용한다면 주의한다.

## 닫고 다시 작성하기

- 15649와 15650의 차이를 used와 start의 역할로 설명하기.
- 1182를 재귀로도, 비트마스크로도 작성하기.
- 순열의 개수 n!을 계산해서 제한 시간에 가능한지 먼저 판단하기.
