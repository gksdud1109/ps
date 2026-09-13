# ps (Problem Solving Archive)

BaekjoonHub로 자동 업로드되는 PS(Problem Solving) 풀이 아카이브입니다.  
주로 바킹독 커리큘럼 단원(`0x??`) 기준으로 정리합니다.

---

## Directory Structure

- `2025/0x??/` : 2025년에 풀이/아카이빙한 문제
- `2026_H2/` : 2026년 하반기 학습 및 신규 풀이

---

## Build & Run (C++)

### Prerequisites

- macOS Apple Silicon
- Homebrew GCC 16: `g++-16`
- Antigravity IDE: `clangd` extension (현재 설치됨)
- VS Code를 쓸 때: `ms-vscode.cpptools` extension

Antigravity IDE와 VS Code에서는 이 README와 `.vscode`가 있는 저장소 루트를 열어야 설정이 적용됩니다.

```bash
code /Users/hanyoung-jeong/Desktop/algorithm/barkingdog
```

### Compile

```bash
g++-16 -o 2026_H2/combination 2026_H2/combination.cpp
```

### Run

```bash
./2026_H2/combination
```

> 실행파일은 `.gitignore`에서 자동 제외됩니다.

### Antigravity IDE / VS Code

- 빌드: C++ 파일을 연 뒤 `⌘⇧B`
- 빌드 후 실행: 명령 팔레트에서 `Tasks: Run Task` → `C++: 활성 파일 빌드 및 실행`
- 디버그(VS Code + `ms-vscode.cpptools`): C++ 파일을 연 뒤 `F5`
- Code Runner를 설치한 VS Code: 우측 상단 `Run Code` 버튼

모든 방식은 활성 `.cpp` 파일과 같은 폴더에 확장자 없는 실행파일을 만듭니다.
실행 가능한 C++ 파일에는 반드시 `main()` 함수가 있어야 합니다.

Antigravity의 clangd는 저장소 루트 `compile_flags.txt`를 사용합니다. 이 파일은
GCC 16의 표준 라이브러리 경로를 알려 주므로 `#include <bits/stdc++.h>`도 IDE에서
정상 해석됩니다. VS Code의 C/C++ 확장은 `.vscode/c_cpp_properties.json`을 사용합니다.

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
