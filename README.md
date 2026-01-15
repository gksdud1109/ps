# ps (Problem Solving Archive)

BaekjoonHub로 자동 업로드되는 PS(Problem Solving) 풀이 아카이브입니다.  
주로 바킹독 커리큘럼 단원(`0x??`) 기준으로 정리합니다.

---

## Directory Structure

- `2025/0x??/` : 2025년에 풀이/아카이빙한 문제
- `2026/0x??/` : 2026년 학습 및 신규 풀이

---

## Build & Run (C++)

### Compile (recommended)
실행 파일은 `bin/`에 생성하는 것을 권장합니다. (`bin/`은 gitignore 처리됨)

```bash
mkdir -p bin
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o bin/app path/to/file.cpp
```

### Run

```bash
g++-15 -std=c++17 -O2 -Wall -Wextra -pedantic -o bin/app path/to/file.cpp
```

---

## Workflow (recommended)
1. 문제 풀이 후 제출
2. BaekjoonHub가 자동 커밋/푸시
3. (선택) 재풀이/리팩토링을 별도 커밋으로 남김

---

## Commit Message Convention (optional)
•	solve(boj): {id} ... [0x??|2026|C++]
•	review(boj): {id} ... [0x??|2026]

```bash
review(boj): 2178 재풀이 - BFS 템플릿 적용 [0x09|2026]
```