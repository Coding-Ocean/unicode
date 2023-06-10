#include <iostream>
#include <sstream>
#include "emoji.h"

int main()
{
    //絵文字を変数として使う
    int 💩 = 931;
    int 🍌 = 877;
    std::wostringstream woss;
    woss << L"💩 + 🍌 = " << 💩 + 🍌 << std::endl;
    print(woss);

    ////shift-jis -> char マルチバイト文字
    //std::cout << "きずなあい\n";

    ////unicode -> wchar_t ワイド文字
    //setlocale(LC_CTYPE, "");
    //std::wcout << L"にじさんじ\n";

    ////絵文字
    //int n = 4;
    //for (int i = 1; i <= n; ++i) {
    //    for (int k = 0; k < n - i; ++k) {
    //        print(L" ");//半角スペース
    //    }
    //    for (int j = 0; j < i; ++j) {
    //        print(L"🍌");
    //    }
    //    print(L"\n");
    //}

    system("pause>0");
}
