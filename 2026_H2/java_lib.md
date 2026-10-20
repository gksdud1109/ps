# Java 코딩테스트 라이브러리 · 유형별 타이핑 노트

목표: API 이름을 읽고 끝내지 않고, 코드 블록 하나를 직접 작성하고 실행하기.
Java 11 이상 문법을 사용한다. 각 `java` 블록은 다른 블록과 합치지 않는 독립 실행 예제다.

## 사용하는 법

1. 필요한 주제의 코드 블록 하나를 `practice.java`에 직접 입력한다.
2. `java practice.java`로 실행한다. 입출력 예제 외에는 별도 입력이 필요 없다.
3. 주석에 적힌 결과를 먼저 예상하고, 실제 결과와 비교한다.
4. 값을 바꾸고 한 번 더 실행한 뒤, 마지막에는 예제를 닫고 다시 작성한다.

`class Main`을 사용하므로 소스 파일 실행 모드에서는 파일명을 자유롭게 정할 수 있다.
`javac`로 빌드한다면 `javac -d <출력폴더> practice.java` 후 `java -cp <출력폴더> Main`으로 실행한다.
자료구조 예제는 주요 함수를 한 블록에 모았고, 알고리즘은 최소 상태와 반복문을 연습하도록 구성했다.
모든 문서는 300줄 이하로 나눴다. 반대 언어는 [C++ 목차](cpp_stl.md)를 참고한다.

## 목차

| 순서 | 주제 | 따라 칠 내용 | 기존 문제 연결 |
|---|---|---|---|
| 01 | [입출력·배열·문자열](java_lib/01_basics.md) | BufferedReader, 배열 복사/초기화, String, StringBuilder | 10808, 1543, 2941 |
| 02 | [리스트·정렬](java_lib/02_list_sort.md) | ArrayList, ListIterator, 다중 조건 Comparator | 1406, 10825 |
| 03 | [해시맵·해시셋](java_lib/03_hash.md) | put/get/remove, 빈도 세기, 양방향 조회, 중복 제거 | 1620, 7785, 9375 |
| 04 | [스택·큐·덱](java_lib/04_stack_queue_deque.md) | ArrayDeque의 양끝 API, 괄호 검사, 단조 스택 | 4949, 2164, 5430, 2493 |
| 05 | [힙·정렬된 집합/맵](java_lib/05_heap_ordered.md) | PriorityQueue, TreeSet, TreeMap, 경계값 조회 | 1715, 11286 |
| 06 | [누적합·이분 탐색·투 포인터](java_lib/06_search_patterns.md) | 구간합, lower/upper bound, 매개변수 탐색, 가변 창 | 11659, 10816, 1654, 1806 |
| 07 | [그래프·격자 BFS/DFS](java_lib/07_graph.md) | 인접 리스트, 거리, 연결 요소, 방문 시점 | 1260, 2667, 2583 |
| 08 | [완전탐색·백트래킹·비트](java_lib/08_backtracking.md) | 순열, 조합, 부분집합, nextPermutation | 15649, 15650, 1182 |
| 09 | [DP·그리디](java_lib/09_dp_greedy.md) | 1차원/2차원 상태, 0/1 배낭, 회의 선택 | 1463, 1149, 12865, 1931 |
| 10 | [다익스트라·유니온 파인드](java_lib/10_shortest_union_find.md) | 거리 우선 힙, 오래된 상태 제거, 집합 합치기 | 1753, 연결 여부 판정 |

시험 직전에는 01~04 → 06~09 → 05·10 순으로 확인한다. 이미 익숙한 블록은 건너뛰어도 된다.
이는 라이브러리 숙련용 참고서이지, 모든 블록을 외워야 하는 과제는 아니다.

## 자료구조 선택·복잡도 빠른 표

`n`은 원소 수다. 해시는 키 비교 비용을 제외한 평균 비용, 동적 배열의 뒤 추가는 분할상환 비용이다.

| 필요한 일 | 선택 | 대표 비용 |
|---|---|---|
| 연속된 번호로 조회 | 배열 | 인덱스 조회 O(1) |
| 가변 길이·인덱스 조회 | ArrayList | get/set O(1), 뒤 add 분할상환 O(1), 중간 삽입/삭제 O(n) |
| 커서 위치 앞 삽입/삭제 | LinkedList + ListIterator | 위치 확보 후 O(1), 인덱스로 위치 찾기는 O(n) |
| 이름으로 조회·빈도 | HashMap | get/put 평균 O(1), containsValue는 O(n) |
| 중복 제거·존재 확인 | HashSet | add/contains 평균 O(1) |
| 스택·큐·양끝 처리 | ArrayDeque | 양끝 연산 분할상환 O(1), contains/remove(Object)는 O(n) |
| 최솟값을 반복 추출 | PriorityQueue | peek O(1), offer/poll O(log n) |
| 정렬된 키·이웃값 탐색 | TreeSet / TreeMap | 삽입/삭제/키 탐색 O(log n) |

## 특히 헷갈리는 것

- 배열은 `a.length`, 문자열은 `s.length()`, 컬렉션은 `list.size()`다.
- 문자열 내용 비교는 `equals`, 사전순 비교는 `compareTo`다. `==`는 참조 비교다.
- `HashMap<String, Integer>`처럼 제네릭에는 `int` 대신 `Integer`를 쓴다.
- `PriorityQueue`는 기본이 최소 힙이다. C++ 기본 힙과 반대다.
- 비교 함수는 `a - b`보다 `Integer.compare(a, b)`를 사용해 오버플로를 피한다.
- 합계·거리·곱은 범위를 계산하고 `long`을 쓴다. `1L * a * b`로 곱하기 전부터 승격한다.
- `Arrays.asList(int배열)`은 정수 목록이 아니다. `int[]` 한 개를 가진 목록이다.
- 그래프의 번호가 1부터 시작하면 길이를 `n + 1`로 잡는다.
- API 타이핑 후에는 관련 문제를 코드 없이 다시 풀어야 실전 복습이 된다.

## 참고한 기존 파일·공식 문서

- [Java 기본 입력](../2026/javatemplate.java), [그래프 템플릿](../2026/graphjavatemplate.java)
- [C++ 자료구조 예제](../2026/0x15_hash/stl_example.cpp)를 같은 주제로 옮겼다.
- [Oracle Java 11 API](https://docs.oracle.com/en/java/javase/11/docs/api/index.html)
- [HashMap](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/HashMap.html), [ArrayDeque](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/ArrayDeque.html)
- [Arrays](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/Arrays.html), [NavigableSet](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/NavigableSet.html)
