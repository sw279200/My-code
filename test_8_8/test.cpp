#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<iostream>
using namespace std;

class Solution {

    class A
    {
    public:
        A()
        {
            sum += x;
            x++;
        }
    };
public:
    static int x;
    static int sum;
    int Sum_Solution(int n) {
        A* a = new A[n];
        return sum;
    }
};
int Solution::sum = 0;
int Solution::x = 1;

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.Sum_Solution(n) << endl;
	return 0;
}
#endif


#include<iostream>
using namespace std;

class Date
{
public:

    Date(int year = 1, int month = 1, int day = 1)
    {
        this->mYear = year;
        this->mMonth = month;
        this->mDay = day;
    }

    int getYear()
    {
        return mYear;
    }
    int getMonth()
    {
        return mMonth;
    }

    int getDay()
    {
        return mDay;
    }

    int getMonthOfDay(int year,int month)
    {
        int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        if (month==2&&((year % 4 == 0&&year % 100 != 0) || (year % 400 == 0)))
        {
            return 29;
        }

        return Month[month];
    }

    //把一年的第多少天转化成对应的日期
    Date& dateConversion(int year,int day)
    {
        this->mYear = year;
        this->mDay = day;
        this->mMonth = 1;
        while (this->mDay> getMonthOfDay(mYear, mMonth))
        {
           
            this->mDay -= getMonthOfDay(mYear, mMonth);
            this->mMonth++;
            if (mMonth == 13)
            {
                this->mYear++;
                this->mMonth = 1;
            }
        }
        return *this;
    }


    // 日期+=天数

    Date& operator+=(int day)
    {
        this->mDay += day;

        while (this->mDay > getMonthOfDay(this->mYear, this->mMonth))
        {
            this->mDay -= getMonthOfDay(this->mYear, this->mMonth);
            this->mMonth++;

            if (this->mMonth == 13)
            {
                this->mYear++;
                this->mMonth = 1;
            }

        }

        return *this;
    }


private:
    int mYear;
    int mMonth;
    int mDay;
};

int main()
{
    
   /* int year = 0;
    int day = 0;
    while (cin >> year >> day)
    {      
        printf("%d-%02d-%02d\n", date.dateConversion(year, day).getYear(),
            date.dateConversion(year, day).getMonth(), date.dateConversion(year, day).getDay());
    }*/

    int m = 0;
    cin >> m;
    while (m--)
    {
        int day = 0;
        int Year;
        int Month;
        int Day;
        cin >> Year >> Month >> Day >> day;
        Date date(Year,Month,Day);
        date += day;
        printf("%d-%02d-%02d\n", date.getYear(), date.getMonth(), date.getDay());
    }
    return 0;
}