# C++ STL Vector 사용법

## 선언 및 초기화

```cpp
vector<int> v1;           // 빈 벡터
vector<int> v2(5);        // 크기 5, 모두 0으로 초기화
vector<int> v3(3, 7);     // 크기 3, 모두 7로 초기화
vector<int> v4 = {1,2,3}; // 초기화 리스트
```

## 주요 함수

| 함수 | 설명 | 시간복잡도 |
|------|------|-----------|
| `v.size()` | 원소 개수 반환 | O(1) |
| `v.empty()` | 비어있으면 true | O(1) |
| `v.push_back(x)` | 맨 뒤에 x 추가 | O(1) |
| `v.pop_back()` | 맨 뒤 원소 제거 | O(1) |
| `v.clear()` | 모든 원소 제거 | O(N) |
| `v.front()` | 첫 번째 원소 | O(1) |
| `v.back()` | 마지막 원소 | O(1) |

## 삽입 & 삭제

```cpp
v.insert(v.begin() + i, x);  // i번째 위치에 x 삽입
v.erase(v.begin() + i);      // i번째 원소 삭제
```
> 둘 다 O(N) - 원소 이동 발생

## 접근

```cpp
v[i]      // i번째 원소 (범위 체크 X)
v.at(i)   // i번째 원소 (범위 체크 O)
```

## 순회

```cpp
// 인덱스
for (int i = 0; i < v.size(); i++)
    cout << v[i];

// range-based for
for (int x : v)
    cout << x;
```

## 복사

```cpp
vector<int> v2 = v1;  // 깊은 복사 (O(N))
```
