#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

//计算日期到天数转换
int main() {
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year, month, day;
    cin >> year >> month >> day;
    int sum = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        arr[1] = 29;
        int i = 0;

        for (i = 0; i < month - 1; i++) {
            sum += arr[i];
        }
        sum += day;
        printf("%d", sum);
    }
    else {
        int i = 0;
        for (i = 0; i < month - 1; i++) {
            sum += arr[i];
        }
        sum += day;
        printf("%d", sum);
    }
    return 0;
}
#endif


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int M[13][2] = {
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31}
};

int is_leap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
    return 0;
}

int main() {
    int s1, s2;
    int y1, m1, d1, y2, m2, d2;
    cin >> s1 >> s2;
    if (s1 > s2)  swap(s1, s2);
    y1 = s1 / 10000, m1 = s1 % 10000 / 100, d1 = s1 % 100;
    y2 = s2 / 10000, m2 = s2 % 10000 / 100, d2 = s2 % 100;
    int s = 0;
    int year1 = is_leap(y1);
    for (int i = 0; i < m1 - 1; i++) {
        s -= M[i][year1];
    }
    s -= d1;
    for (int i = y1; i < y2; i++) {
        if (is_leap(i))  s += 366;
        else s += 365;
    }
    int year2 = is_leap(y2);
    for (int i = 0; i < m2 - 1; i++) {
        s += M[i][year2];
    }
    s += d2;
    cout << s + 1 << endl;
    return 0;
}