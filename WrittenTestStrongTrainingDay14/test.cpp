#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

//计算日期到天数转换
void solve()
{
    int year, month, day;
    cin >> year >> month >> day;

    int MonthofDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int countDay = 0;

    for (int i = 1; i < month; i++)
    {
        if (IsLeapYear(year) && i == 2)
            countDay += 29;
        else countDay += MonthofDay[i];
    }

    countDay += day;
    cout << countDay << endl;
}




int main() {

    solve();
    return 0;  
}

