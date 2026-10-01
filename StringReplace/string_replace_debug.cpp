/*
    substr 와 문자열 덧셈을 이용한 문자열 대치

    replace() 멤버 함수를 쓰지 않고, 문자열 s 에서 f 를 모두 찾아 r 로 바꾼다.
    f 가 두 번 이상 나타나면 올바른 결과가 나오지 않는다.

        s = "one cat and two cats", f = "cat", r = "chicken"
        원하는 결과 : "one chicken and two chickens"

    코드 추적표를 작성하여 논리 오류를 찾아 수정하시오.
*/

#include <iostream>
#include <string>
using namespace std;


// 문자열 s 안의 f 를 모두 r 로 바꿔서 돌려준다.
string replaceAll(string s, string f, string r)
{
    int startIndex = 0;                             // 다음 검색을 시작할 위치

    while (true) {
        size_t fIndex = s.find(f, startIndex);      // f 를 찾은 위치
        if (fIndex == string::npos)                 // 더 없으면 종료
            break;

        string first = s.substr(startIndex, fIndex - startIndex);   // f 앞부분
        string second = s.substr(fIndex + f.length());              // f 뒷부분
        s = first + r + second;                                     // 다시 조립
        startIndex = fIndex + r.length();           // 바꿔 넣은 r 다음으로 이동
    }

    return s;
}


// 테스트 한 건을 돌리고 기대값과 비교한다.
bool runTest(int no, string s, string f, string r, string expected)
{
    string actual = replaceAll(s, f, r);
    bool ok = (actual == expected);

    cout << "[테스트 " << no << "]\n";
    cout << "  입력        : s=\"" << s << "\", f=\"" << f << "\", r=\"" << r << "\"\n";
    cout << "  원하는 결과 : \"" << expected << "\"\n";
    cout << "  실제 결과   : \"" << actual << "\"\n";
    cout << "  판정        : " << (ok ? "통과" : "실패") << "\n\n";
    return ok;
}


int main()
{
    int pass = 0;
    int total = 0;

    // 워크시트의 예제
    total++; pass += runTest(1, "one cat and two cats", "cat", "chicken",
                                "one chicken and two chickens");

    // 바꿀 것이 세 개인 경우
    total++; pass += runTest(2, "a b a b a", "a", "X", "X b X b X");

    // 찾는 문자열이 없는 경우
    total++; pass += runTest(3, "hello world", "z", "y", "hello world");

    // 바꿔 넣을 문자열 안에 찾는 문자열이 들어 있는 경우
    total++; pass += runTest(4, "aaa", "a", "aa", "aaaaaa");

    cout << "========================================\n";
    cout << "  " << total << "개 중 " << pass << "개 통과\n";
    cout << "========================================\n";

    return 0;
}
