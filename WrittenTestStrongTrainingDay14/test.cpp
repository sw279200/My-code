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


//幸运的袋子
int  n;
int arr[1010] = {0};
int dfs(int index,int sum,int mul)
{
    int ret = 0;
    for (int i = index + 1; i < n; i++)
    {
        int Sum = sum + arr[i], Mul = mul * arr[i];
        if (Sum > Mul) ret += dfs(i, Sum, Mul) + 1;
        else if (arr[i] == 1) ret += dfs(i, Sum, Mul);
        else break;
        Sum -= arr[i], Mul /= mul;
        while (i < n - 1 && arr[i] == arr[i + 1])i++;
    }
    return ret;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cout << dfs(0, 1, 1)<<endl;
    return 0;  
}

