#include <iostream>
#include <sstream>
#include "emoji.h"

int main()
{
    ////shift-jis -> char マルチバイト文字
    //std::cout << "きずなあい\n";

    ////unicode -> wchar_t ワイド文字
    //setlocale(LC_CTYPE, "");
    //std::wcout << L"にじさんじ\n";

    ////絵文字
    print(L"😵‍💫\n");

    //int n = 4;
    //for (int i = 1; i <= n; ++i) {
    //    for (int k = 0; k < n - i; ++k) {
    //        print(L" ");
    //    }
    //    for (int j = 0; j < i; ++j) {
    //        print(L"🍌");
    //    }
    //    print(L"\n");
    //}

    //int 💩 = 931;
    //int  🍓 = 15;
    //std::wostringstream woss;
    //woss << L"💩 + 🍓 = " << 💩 + 🍓 << std::endl;
    //print(woss);
    system("pause>0");
}
