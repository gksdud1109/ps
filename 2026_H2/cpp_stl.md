# C++ 코딩테스트 STL · 유형별 타이핑 노트

목표: 자료구조마다 주요 함수를 한 코드 블록으로 직접 작성하고 실행하기.
C++17과 저장소의 Homebrew GCC 환경을 기준으로 한다. 각 `cpp` 블록은 독립 실행 예제다.

## 사용하는 법

1. 코드 블록 하나를 `practice.cpp`에 직접 입력한다.
2. 기존처럼 `g++-16 -o practice practice.cpp`로 컴파일하고 `./practice`로 실행한다.
3. 주석의 결과를 예상한 뒤 확인하고, 값을 바꿔 다시 실행한다.
4. 마지막에는 예제를 닫고 같은 기능을 재작성한다.

각 블록에 `main()`이 있으므로 여러 블록을 한 파일에 그대로 합치면 안 된다.
`<bits/stdc++.h>`는 GCC에서 제공하는 헤더이며 모든 C++ 컴파일러의 표준 헤더는 아니다.
모든 문서는 300줄 이하로 나눴다. 반대 언어는 [Java 목차](java_lib.md)를 참고한다.

## 목차

| 순서 | 주제 | 따라 칠 내용 | 기존 문제 연결 |
|---|---|---|---|
| 01 | [입출력·배열·문자열](cpp_stl/01_basics.md) | cin/getline, fill/copy, string, 문자열 분리 | 10808, 1543, 2941 |
| 02 | [vector·list·정렬](cpp_stl/02_list_sort.md) | 삽입/삭제, iterator, pair/tuple, 다중 조건 정렬 | 1406, 10825 |
| 03 | [해시맵·해시셋](cpp_stl/03_hash.md) | unordered_map/set/multiset, 빈도, 양방향 조회 | 1620, 7785, 9375 |
| 04 | [스택·큐·덱](cpp_stl/04_stack_queue_deque.md) | push/pop/top/front/back, 괄호 검사, 단조 스택 | 4949, 2164, 5430, 2493 |
| 05 | [힙·정렬된 집합/맵](cpp_stl/05_heap_ordered.md) | priority_queue, set/multiset/map, lower/upper_bound | 1715, 11286 |
| 06 | [누적합·이분 탐색·투 포인터](cpp_stl/06_search_patterns.md) | 구간합, 경계 탐색, 매개변수 탐색, 가변 창 | 11659, 10816, 1654, 1806 |
| 07 | [그래프·격자 BFS/DFS](cpp_stl/07_graph.md) | 인접 리스트, 거리, 연결 요소, 방문 시점 | 1260, 2667, 2583 |
| 08 | [완전탐색·백트래킹·비트](cpp_stl/08_backtracking.md) | 순열, 조합, 부분집합, next_permutation | 15649, 15650, 1182 |
| 09 | [DP·그리디](cpp_stl/09_dp_greedy.md) | 1차원/2차원 상태, 0/1 배낭, 회의 선택 | 1463, 1149, 12865, 1931 |
| 10 | [다익스트라·유니온 파인드](cpp_stl/10_shortest_union_find.md) | 거리 우선 힙, 오래된 상태 제거, 집합 합치기 | 1753, 연결 여부 판정 |

시험 직전에는 01~04 → 06~09 → 05·10 순으로 확인한다. 알고 있는 블록을 모두 반복할 필요는 없다.
API 암기용이 아니라, 문제를 풀 때 필요한 구문을 바로 꺼내 쓰는 연습용이다.

## 자료구조 선택·복잡도 빠른 표

`n`은 원소 수다. 해시는 키 비교 비용을 제외한 평균 비용, 동적 배열의 뒤 추가는 분할상환 비용이다.

| 필요한 일 | 선택 | 대표 비용 |
|---|---|---|
| 고정/가변 배열과 인덱스 조회 | 배열 / vector | 조회 O(1), vector 뒤 추가 분할상환 O(1), 중간 삽입/삭제 O(n) |
| 커서 앞 삽입/삭제 | list + iterator | 위치 확보 후 O(1), 위치를 걸어서 찾으면 O(n) |
| 이름으로 조회·빈도 | unordered_map | 조회/삽입 평균 O(1), 최악 O(n) |
| 중복 제거·존재 확인 | unordered_set | 조회/삽입 평균 O(1), 최악 O(n) |
| 후입선출 / 선입선출 | stack / queue | 기본 컨테이너에서 양끝 연산 O(1) |
| 양끝 처리·인덱스 조회 | deque | 양끝 삽입/삭제·인덱스 조회 O(1), 중간 삽입/삭제 O(n) |
| 최댓값/최솟값 반복 추출 | priority_queue | top O(1), push/pop O(log n) |
| 정렬된 키·경계값 탐색 | set / multiset / map | 삽입/삭제/키 탐색 O(log n) |

## 특히 헷갈리는 것

- `pop()`은 값을 반환하지 않는다. `top()`/`front()`를 먼저 읽고 `pop()`한다.
- 빈 컨테이너의 `top()`/`front()`/`back()` 호출은 금지한다.
- `m[key]`는 없는 키를 조회하면 기본값으로 삽입한다. 존재 확인은 `find`/`count`다.
- `erase(it)`의 인자가 `end()`가 아닌지 먼저 확인한다.
- `priority_queue<int>`는 기본이 최대 힙이다. 최소 힙은 `greater<int>`다.
- `sort`의 비교 함수는 `a < b`처럼 엄격해야 한다. `a <= b`는 쓰지 않는다.
- `unique`만으로 vector 크기가 줄지 않는다. `erase(unique(...), end())`까지 해야 한다.
- 합계·거리·곱은 `long long`. `1LL * a * b`로 곱하기 전부터 승격한다.
- `lower_bound`/`upper_bound`는 정렬된 범위에 사용한다.
- 반복문으로 컨테이너를 수정할 때 iterator 무효화 조건을 확인한다.

## 참고한 기존 파일·공식 문서

- [vector](../2026/0x03_array/vector_example.cpp), [list](../2026/0x04_linked_list/list_example.cpp), [string](../2026/appendixA/string_example.cpp)
- [해시](../2026/0x15_hash/stl_example.cpp), [stack](../2026/0x05_stack/stack_example.cpp), [queue](../2026/0x06_queue/queue_example.cpp)
- [deque](../2026/0x07_deque/deque_example.cpp), [heap](../2026/0x17_priority_queue/heap_example.cpp), [순열](../2026/0x0C_backtrack/next_permutation_example.cpp)
- [GCC libstdc++ 컨테이너](https://gcc.gnu.org/onlinedocs/libstdc++/manual/containers.html)
- [GCC libstdc++ 알고리즘](https://gcc.gnu.org/onlinedocs/libstdc++/manual/algorithms.html)
