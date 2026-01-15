# ps (Problem Solving Archive)

BaekjoonHub로 자동 업로드되는 PS(Problem Solving) 풀이 아카이브입니다.  
주로 바킹독 커리큘럼 단원(`0x??`) 기준으로 정리합니다.

---

## Directory Structure

- `2025/0x??/` : 2025년에 풀이/아카이빙한 문제
- `2026/0x??/` : 2026년 학습 및 신규 풀이

---

## Build & Run (C++)

### Compile

```bash
g++-15 -o 0x01/example 0x01/example.cpp
```

### Run

```bash
./0x01/example
```

> 실행파일은 `.gitignore`에서 자동 제외됩니다.

---

## Workflow (recommended)
1. 문제 풀이 후 제출
2. BaekjoonHub가 자동 커밋/푸시
3. (선택) 재풀이/리팩토링을 별도 커밋으로 남김

---

## Commit Message Convention (optional)

-	`solve(boj): {id} ... [0x??|2026|C++]`
-	`review(boj): {id} ... [0x??|2026]`

```bash
review(boj): 2178 재풀이 - BFS 템플릿 적용 [0x09|2026]
```