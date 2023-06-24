#include <iostream>
#include "emoji.h"
void nextl() 
{ 
    print(L"\n");
}
void emoji(int sw)
{
    print(sw ? L"🍌" : L"🐵");
}
int main()
{
    int n = 5;
    int c = n / 2;//中央値
    int m = n - 1;//ｘ、ｙの最大値


    int numPattern = 9;
    for (int pattern = 0;  pattern < numPattern; pattern++) {
        printf("Pattern%d\n", pattern);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                switch (pattern) {
                case 0: emoji(x % 2); break;
                case 1: emoji(y % 2); break;
                case 2: emoji((x + y) % 2); break;
                case 3: emoji(x == c || y == c); break;
                case 4: emoji(x == 0 || y == 0 || x == m || y == m); break;
                case 5: emoji(x == y); break;
                case 6: emoji(x == y || x == m - y); break;
                case 7: emoji(abs(x - c) + abs(y - c) == c); break;
                case 8: emoji(abs(x - c) + abs(y - c) >= c); break;
                }
            }
            nextl();
        }
        nextl();
    }

    ////参考
    //for (int y = 0; y < n; y++) {
    //    for (int x = 0; x < n; x++) {
    //        printf("%2d", abs(x - c));
    //    }
    //    nextl();
    //}
    //nextl();
    //for (int y = 0; y < n; y++) {
    //    for (int x = 0; x < n; x++) {
    //        printf("%2d", abs(y - c));
    //    }
    //    nextl();
    //}
    //nextl();
    //for (int y = 0; y < n; y++) {
    //    for (int x = 0; x < n; x++) {
    //        printf("%2d", abs(x - c) + abs(y - c));
    //    }
    //    nextl();
    //}
    //nextl();

    system("pause>0");
}
