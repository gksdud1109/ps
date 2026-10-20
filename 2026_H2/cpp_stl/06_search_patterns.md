# 06. 누적합 · 이분 탐색 · 투 포인터

[목차](../cpp_stl.md) · [Java 대응](../java_lib/06_search_patterns.md)

## 누적합: 구간합 O(1)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {3, 1, 4, 2};
    vector<long long> prefix(a.size() + 1);
    // prefix[i]: 앞의 i개 원소 합
    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    int left = 1, right = 3;          // 양끝 포함 a[1..3]
    cout << prefix[right + 1] - prefix[left] << '\n'; // 7
}
```

`prefix[r] - prefix[l]`은 `[l, r)`의 합이다. 인덱스 규칙을 섞지 않는다.

## binary_search / lower_bound / upper_bound

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 2, 5};  // 반드시 정렬된 범위
    auto lo = lower_bound(a.begin(), a.end(), 2); // >=2인 첫 위치
    auto hi = upper_bound(a.begin(), a.end(), 2); // >2인 첫 위치
    cout << lo - a.begin() << ' ' << hi - a.begin() << '\n'; // 1 4
    cout << hi - lo << '\n';         // 3: 2의 개수
    cout << binary_search(a.begin(), a.end(), 4) << '\n'; // 0
    auto it = lower_bound(a.begin(), a.end(), 4);
    bool exists = it != a.end() && *it == 4;
    cout << exists << '\n';          // 0

    int b[] = {1, 3, 5};
    int index = lower_bound(b, b + 3, 4) - b;
    cout << index << '\n';           // 2
}
```

배열/vector의 bound는 O(log n). 결과가 end일 수 있으므로 역참조 전에 검사한다.
좌표 압축은 정렬·중복 제거한 vector에서 lower_bound 인덱스를 구하는 방식으로 구현할 수 있다.

## 직접 이분 탐색: 경계 규칙 익히기

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 2, 5};
    int target = 2, left = 0, right = static_cast<int>(a.size());
    while (left < right) {            // 미확정 범위 [left, right)
        int mid = left + (right - left) / 2;
        if (a[mid] >= target) right = mid;
        else left = mid + 1;
    }
    cout << left << '\n';            // 1: lower_bound 위치
}
```

아래 매개변수 탐색은 `[left, right]` 포함 구간 방식이다. 두 틀의 갱신 규칙을 섞지 않는다.

## 매개변수 탐색: 가능한 길이의 최댓값

```cpp
#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& cable, long long length, long long need) {
    long long count = 0;
    for (int x : cable) count += x / length;
    return count >= need;
}

int main() {
    vector<int> cable = {802, 743, 457, 539};
    long long need = 11, left = 1, right = 802, answer = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (possible(cable, mid, need)) {
            answer = mid;
            left = mid + 1;          // 더 큰 길이 시도
        } else {
            right = mid - 1;
        }
    }
    cout << answer << '\n';          // 200
}
```

가능 여부가 단조롭게 바뀌어야 이분 탐색할 수 있다. 분모 length가 0이 되지 않게 한다.
가능한 최소값을 찾는 문제라면 가능할 때 더 작은 쪽으로 가야 한다.

## 투 포인터: 합이 target 이상인 최소 길이

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int n = static_cast<int>(a.size());
    int target = 15, left = 0, answer = n + 1;
    long long sum = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= target) {
            answer = min(answer, right - left + 1);
            sum -= a[left++];
        }
    }
    cout << (answer == n + 1 ? 0 : answer) << '\n'; // 2
}
```

모든 원소가 양수라는 전제다. 음수가 있으면 이 방식의 합 단조성이 성립하지 않는다.
양 포인터가 각각 최대 n번 이동하므로 전체 O(n)이다.

## 고정 길이 슬라이딩 윈도우

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 1, 5, 1, 3, 2};
    int k = 3;                       // 1 <= k <= a.size() 전제
    long long sum = 0, best = LLONG_MIN;
    for (int right = 0; right < static_cast<int>(a.size()); right++) {
        sum += a[right];
        if (right >= k) sum -= a[right - k];
        if (right >= k - 1) best = max(best, sum);
    }
    cout << best << '\n';            // 9
}
```

고정 길이 창의 합 갱신은 음수가 있어도 가능하다. 가변 길이 투 포인터와 구분한다.

## 닫고 다시 작성하기

- bound 결과가 begin/end인 경우를 둘 다 검사하기.
- 1654의 가능한 길이 범위가 왜 1부터인지 설명하기.
- 양수 배열에서 포인터를 한쪽 방향으로만 이동할 수 있는 이유 설명하기.
