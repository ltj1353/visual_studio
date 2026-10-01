# substr와 문자열 덧셈을 이용한 문자열 대치 코드 추적

**분반:** \_\_\_\_\_\_\_\_  **학번:** \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_  **이름:** \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

## 문제

다음 코드는 예제 4-13을 `replace()` 멤버 함수를 사용하지 않고, 문자열 `s`에서 `f`를 모두 찾아 `r`로 바꾸려고 작성한 코드이다. 그러나 `f`가 두 번 이상 나타나면 올바른 결과가 나오지 않는다. 주어진 입력 예시에 대해 코드 추적표를 작성하여 논리 오류를 찾아 수정하시오.

```cpp
int startIndex = 0;
while (true) {
    size_t fIndex = s.find(f, startIndex);
    if (fIndex == string::npos)
        break;

    string first = s.substr(startIndex, fIndex - startIndex);
    string second = s.substr(fIndex + f.length());
    s = first + r + second;
    startIndex = fIndex + r.length();
}
```

| 항목 | 내용 |
| --- | --- |
| 입력 예시 | `s = "one cat and two cats"`, `f = "cat"`, `r = "chicken"` |
| 원하는 결과 | `"one chicken and two chickens"` |
| 실제 결과 |  |
| 추적할 변수 | `s`, `startIndex`, `fIndex`, `first`, `second` |

## 코드 추적표

| 반복 | 검색 전 s | startIndex | fIndex | first | second | 변경 후 s |
| --- | --- | --- | --- | --- | --- | --- |
| 1회 |  |  |  |  |  |  |
| 2회 |  |  |  |  |  |  |
| 종료 검사 |  |  |  |  |  |  |

## 생각해 보기

1. 두 번째 반복에서 문자열의 어느 부분이 사라지는가?

   ---
2. 그 부분이 사라지는 이유를 `substr()`의 시작 위치와 길이를 이용하여 설명하시오.

   ---
3. 세 문장 중 잘못된 한 문장을 찾아 올바르게 수정하시오.

   ---

---

*C++ 프로그래밍 · string 클래스 코드 추적 활동*
