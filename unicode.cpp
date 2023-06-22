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
            if (i % 2)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //奇数列に１を偶数列に０をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j % 2)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //中央列と中央行に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == n / 2 || i == n / 2)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //左上から右下の対角線上に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //上記に加え、右上から左下の対角線上にも１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int right = n - 1;
            if (j == i || j == right - i)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //周囲に１をセット
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 ||
                j == 0 || j == n - 1)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //ひし形の輪郭に１をセット
    for (i = 0; i < n; i++) {
        /*
        n=5の場合
        0,1,2,3,4...i
        2,1,0,1,2...left = abs(i-n/2)
        2,3,4,3,2...right = n-1-left
        */
        int left = abs(i - n / 2);
        int right = n - 1 - left;
        for (j = 0; j < n; j++) {
            if (j == left || j == right)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    //ひし形塗りつぶし
    for (i = 0; i < n; i++) {
        int left = abs(i - n / 2);
        int right = n - 1 - left;
        for (j = 0; j < n; j++) {
            //left～rightの範囲に１をセット
            if (j >= left && j <= right)
                a[n * i + j] = 1;
            else
                a[n * i + j] = 0;
        }
    }
    print(L"🍌", L"🍓", a, n);

    system("pause>0");
}
