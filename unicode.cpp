#include <iostream>
#include <sstream>
#include "emoji.h"

//配列に記憶されているデータ（０ｏｒ１）にしたがって絵文字を表示する
void print(const wchar_t* m0, const wchar_t* m1, int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            print(a[n * i + j] ? m0 : m1);
        }
        printf("\n");
    }
    printf("\n");
}

//エントリーポイント
int main()
{
    //縦ｎ個×横ｎ個のデータ配列を用意する
    const int n = 7;
    //１次元配列ａは２次元配列として扱う。
    int a[n * n]{};
    //２次元配列の添え字。行ｉ、列ｊ。
    int i, j;
    //中央値 center value
    int c = n / 2;
    //最大値 maximum of i and j
    int m = n - 1;

    //全て０で初期化しているので🍌だけ表示される
    print(L"🍌", L"🍓", a, n);

    //全て１
    for (i = 0; i < n * n; i++)a[i] = 1;
    print(L"🍌", L"🍓", a, n);

    //０と１を交互にセット
    for (i = 0; i < n * n; i++)a[i] = i % 2;
    print(L"🍌", L"🍓", a, n);

    //奇数行に１を偶数行に０をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] = (i % 2) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //奇数列に１を偶数列に０をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] = (j % 2) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //中央列と中央行に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] = (j == c || i == c) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //左上から右下の対角線上に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] = (j == i) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //上記に加え、右上から左下の対角線上にも１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] = (j == i || j == m - i) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //周囲に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] =
                (i == 0 || i == m || j == 0 || j == m) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //ひし形の輪郭に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] =
                (abs(i - c) + abs(j - c) == c) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //ひし形塗りつぶし
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[n * i + j] =
                (abs(i - c) + abs(j - c) > c) ? 1 : 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    system("pause>0");
}
