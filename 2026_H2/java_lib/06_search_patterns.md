# 06. 누적합 · 이분 탐색 · 투 포인터

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/06_search_patterns.md)

자료구조 함수뿐 아니라 문제에서 자주 반복되는 짧은 틀을 연습한다.

## 누적합: 여러 구간의 합

```java
class Main {
    public static void main(String[] args) {
        int[] a = {3, 1, 4, 2};
        long[] prefix = new long[a.length + 1];
        // prefix[i]: 앞의 i개 합. a는 0-index, prefix는 한 칸 더 둔다.
        for (int i = 0; i < a.length; i++) prefix[i + 1] = prefix[i] + a[i];
        int left = 1, right = 3;  // a[1]부터 a[3]까지, 양끝 포함
        long sum = prefix[right + 1] - prefix[left];
        System.out.println(sum);  // 7
    }
}
```

전처리 O(n), 구간합 O(1). `prefix[r] - prefix[l]`은 반열린 구간 `[l, r)`의 합이다.

## lower bound / upper bound / 정확한 값 조회

Java에는 배열용 lower_bound/upper_bound가 없으므로 짧은 함수를 직접 구현한다.
범위는 `[left, right)`로 통일한다. 정렬된 배열에만 사용한다.

```java
import java.util.*;

class Main {
    static int lowerBound(int[] a, int target) {
        int left = 0, right = a.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left; // target 이상인 첫 위치. 없으면 a.length
    }

    static int upperBound(int[] a, int target) {
        int left = 0, right = a.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left; // target 초과인 첫 위치
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 2, 2, 5};
        int lo = lowerBound(a, 2), hi = upperBound(a, 2);
        System.out.println(lo + " " + hi + " " + (hi - lo)); // 1 4 3
        int pos = lowerBound(a, 4);
        boolean exists = pos < a.length && a[pos] == 4;
        System.out.println(exists); // false
        int result = Arrays.binarySearch(a, 4);
        int insertionPoint = -result - 1; // 미발견(result < 0)일 때만
        System.out.println(insertionPoint); // 4
    }
}
```

Arrays.binarySearch는 발견하면 인덱스, 못 찾으면 `-(삽입 위치) - 1`을 반환한다.
중복이 있으면 어느 인덱스를 찾을지 보장하지 않으므로 개수/첫 위치는 bound 함수를 쓴다.

## 매개변수 탐색: 가능한 길이의 최댓값

1654 랜선 자르기 패턴. 길이를 늘릴수록 만들 수 있는 개수는 줄어든다.
`가능/불가능`의 경계가 한 번만 바뀌는 단조성이 핵심이다.

```java
class Main {
    static boolean possible(int[] cable, long length, long need) {
        long count = 0;
        for (int x : cable) count += x / length;
        return count >= need;
    }

    public static void main(String[] args) {
        int[] cable = {802, 743, 457, 539};
        long need = 11, left = 1, right = 802, answer = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (possible(cable, mid, need)) {
                answer = mid;
                left = mid + 1;   // 더 큰 답 시도
            } else {
                right = mid - 1;
            }
        }
        System.out.println(answer); // 200
    }
}
```

길이 0으로 나누지 않도록 left는 1부터 시작한다. 개수 합과 탐색 경계는 long으로 둔다.

## 투 포인터: 합이 target 이상인 가장 짧은 연속 구간

1806 패턴. 아래 방식은 모든 원소가 양수일 때 적용한다.
음수가 섞이면 오른쪽 확장/왼쪽 축소에 따른 합의 단조성이 깨진다.

```java
class Main {
    public static void main(String[] args) {
        int[] a = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
        int target = 15, left = 0, answer = a.length + 1;
        long sum = 0;
        for (int right = 0; right < a.length; right++) {
            sum += a[right];
            while (sum >= target) {
                answer = Math.min(answer, right - left + 1);
                sum -= a[left++];
            }
        }
        System.out.println(answer == a.length + 1 ? 0 : answer); // 2
    }
}
```

각 포인터가 최대 n번 이동하므로 O(n). 이중 반복문이라고 무조건 O(n²)는 아니다.

## 고정 길이 슬라이딩 윈도우

```java
class Main {
    public static void main(String[] args) {
        int[] a = {2, 1, 5, 1, 3, 2};
        int k = 3;                     // 1 <= k <= a.length 전제
        long sum = 0, best = Long.MIN_VALUE;
        for (int right = 0; right < a.length; right++) {
            sum += a[right];
            if (right >= k) sum -= a[right - k];
            if (right >= k - 1) best = Math.max(best, sum);
        }
        System.out.println(best);      // 9
    }
}
```

이 고정 길이 합 갱신은 음수가 있어도 가능하다. 가변 길이 투 포인터의 양수 조건과 구분한다.

## 닫고 다시 작성하기

- 중복 원소의 개수를 upperBound - lowerBound로 구하기.
- 이분 탐색에서 찾는 것이 최소 가능값인지, 최대 가능값인지 먼저 적기.
- 투 포인터에서 현재 구간의 양끝 포함 여부를 명시하기.
