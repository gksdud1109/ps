# 09. DP · 그리디

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/09_dp_greedy.md)

DP: 같은 부분문제의 답을 저장하고 상태 전이로 답을 만든다.
그리디: 지금의 선택이 최적해를 해치지 않는 이유가 있을 때 선택을 확정한다.
정렬해서 하나씩 고른다고 항상 그리디가 정답인 것은 아니다.

## 1차원 DP: 1로 만들기

```java
class Main {
    public static void main(String[] args) {
        int n = 10;
        int[] dp = new int[n + 1];
        // dp[i]: i를 1로 만드는 최소 연산 횟수
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0) dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            if (i % 3 == 0) dp[i] = Math.min(dp[i], dp[i / 3] + 1);
        }
        System.out.println(dp[n]); // 3: 10 → 9 → 3 → 1
    }
}
```

연습 순서: 상태를 한 문장으로 정의 → 초기값 → 전이 → 계산 순서 → 답의 위치.
이 예제는 시간 O(n), 공간 O(n)이다.

## 2차원 DP: 마지막 선택을 상태에 추가

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[][] cost = {{26, 40, 83}, {49, 60, 57}, {13, 89, 99}};
        int n = cost.length;
        int[][] dp = new int[n][3];
        // dp[i][c]: 0~i번 집을 칠하고, i번 집 색이 c일 때 최소 비용
        dp[0] = cost[0].clone();
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }
        System.out.println(Arrays.stream(dp[n - 1]).min().getAsInt()); // 96
    }
}
```

직전 집의 색을 알아야 다음 선택이 가능하므로 상태에 색을 포함한다.
그냥 dp[i] 하나만 저장하면 필요한 정보가 사라진다.

## 0/1 배낭: 각 물건을 최대 한 번 사용

```java
class Main {
    public static void main(String[] args) {
        int[] weight = {6, 4, 3, 5};
        int[] value = {13, 8, 6, 12};
        int capacity = 7;
        int[] dp = new int[capacity + 1];
        // dp[w]: 지금까지 본 물건으로 총 무게 w 이하에서 얻을 최대 가치
        for (int i = 0; i < weight.length; i++) {
            for (int w = capacity; w >= weight[i]; w--) {
                dp[w] = Math.max(dp[w], dp[w - weight[i]] + value[i]);
            }
        }
        System.out.println(dp[capacity]); // 14: 무게 4와 3
    }
}
```

무게를 큰 값부터 갱신해야 이번 물건을 여러 번 사용하는 일이 없다. 시간 O(n·capacity).
무게 오름차순 갱신은 같은 물건을 반복 사용할 수 있는 다른 문제의 전이가 된다.
`정확히 w` 상태라면 도달 불가를 음의 무한대로 초기화하고 dp[0]=0으로 두는 등 처리가 달라진다.
현재 저장소의 12865는 greedy 폴더에 있어도 DP 문제다.

## 그리디: 종료 시간이 빠른 회의부터 선택

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[][] meetings = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
        // [시작, 종료]. 종료 오름차순, 같으면 시작 오름차순
        Arrays.sort(meetings, (a, b) -> {
            if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });
        int end = Integer.MIN_VALUE, count = 0;
        for (int[] meeting : meetings) {
            if (meeting[0] < end) continue;
            count++;
            end = meeting[1];
        }
        System.out.println(count); // 3
    }
}
```

같은 개수를 골랐다면 마지막 종료가 빠른 선택이 이후 회의를 넣을 여지를 가장 많이 남긴다.
회의별 보상까지 최대화해야 하면 같은 규칙으로 해결되지 않을 수 있다.
동전에서도 큰 단위부터 선택하는 방식은 모든 동전 체계에 성립하지 않는다.

## 닫고 다시 작성하기

- dp 배열을 선언하기 전에 각 칸의 의미를 주석 한 줄로 적기.
- 퇴사(14501)를 `오늘 상담하기 / 건너뛰기` 두 선택으로 표현하기.
- 12865의 무게 루프 방향을 바꾸면 어떤 중복 사용이 생기는지 예를 들기.
- 그리디는 규칙만 외우지 말고 왜 안전한 선택인지 설명하기.
