#define _CRT_SECURE_NO_WARNINGS 1


#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
class Date
{

public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month)
	{
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}

		return Month[month];
	}

	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;

		return *this;
	}



	// 析构函数

	~Date()
	{

	}



	// 日期+=天数

	Date& operator+=(int day)
	{
		this->_day += day;

		while (this->_day > GetMonthDay(this->_year, this->_month))
		{
			this->_day -= GetMonthDay(this->_year, this->_month);
			this->_month++;

			if (this->_month == 13)
			{
				this->_year++;
				this->_month = 1;
			}

		}

		return *this;
	}


	// 日期+天数

	Date operator+(int day)
	{
		*this += day;
		Date tmp(*this);
		return tmp;

	}



	// 日期-天数

	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day;
		return tmp;

	}



	// 日期-=天数

	Date& operator-=(int day)
	{
		if (day < this->_day)
		{
			this->_day -= day;
			
		}
		else
		{
			while (day >= this->_day)
			{
				if (this->_month == 1)
				{
					this->_year--;
					this->_month = 13;
				}

				this->_month--;
				this->_day += GetMonthDay(this->_year, this->_month);
			}

			this->_day -= day;
		}
		return *this;
	}



	// 前置++

	Date& operator++()
	{
		this->_day++;

		if (this->_day > GetMonthDay(this->_year, this->_month))
		{
			this->_day -= GetMonthDay(this->_year, this->_month);
			this->_month++;

			if (this->_month == 13)
			{
				this->_year++;
				this->_month = 1;
			}

		}

		return *this;
	}



	// 后置++

	Date operator++(int)
	{
		Date tmp(*this);
		++tmp._day;
		if (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			tmp._month++;

			if (tmp._month == 13)
			{
				tmp._year++;
				tmp._month = 1;
			}

		}
		return tmp;
	}



	// 后置--

	Date operator--(int)
	{
		Date tmp(*this);
		if (this->_day > 1)
		{
			this->_day--;
		}
		else
		{
			if (this->_month == 1)
			{
				this->_year--;
				this->_month = 13;
			}
			this->_month--;
			this->_day = this->_day + GetMonthDay(this->_year, this->_month) - 1;

		}
		return tmp;
	}



	// 前置--

	Date& operator--()
	{
		if (this->_day > 1)
		{
			this->_day--;
		}
		else
		{
			if (this->_month == 1)
			{
				this->_year--;
				this->_month = 13;
			}
			this->_month--;
			this->_day = this->_day + GetMonthDay(this->_year, this->_month) - 1;

		}

		return *this;
	}



	// >运算符重载

	bool operator>(const Date& d)
	{
		if (this->_year > d._year)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month > d._month)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month == d._month && this->_year > d._year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	// ==运算符重载

	bool operator==(const Date& d)
	{
		return this->_year == d._year &&
			this->_month == d._month &&
			this->_day == d._day;
	}



	// >=运算符重载

	bool operator >= (const Date& d)
	{
		return (*this > d || *this == d);
	}



	// <运算符重载

	bool operator < (const Date& d)
	{
		if (this->_year < d._year)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month < d._month)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month == d._month && this->_year < d._year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	// <=运算符重载

	bool operator <= (const Date& d)
	{
		return (*this < d || *this == d);
	}



	// !=运算符重载

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// 日期-日期 返回天数

//日期相减  相差天数
	int operator-(const Date& d)
	{
		//小日期经过多少次自加与大日期相同
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}
		return flag * day;
	}

	int getyear()
	{
		return this->_year;
	}

	int getmonth()
	{
		return this->_month;
	}

	int getday()
	{
		return this->_day;
	}

private:

	int _year;

	int _month;

	int _day;

};


int main()
{
	Date date2(1970, 1, 1);
	Date date1(2023, 7, 22);
	cout << "当前日期为：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	date1 += 1;
	cout << "当前日期后1天为：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	date1 += 30;
	cout << "当前日期后30天为：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	date1 += 90;
	cout << "当前日期后90天为：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	date1 += 360;
	cout << "当前日期后360天为：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;

	cout << "当前日期为：" << date2.getyear() << "-" << date2.getmonth() << "-" << date2.getday() << endl;
	date2 += 1;
	cout << "当前日期后1天为：" << date2.getyear() << "-" << date2.getmonth() << "-" << date2.getday() << endl;
	date2 += 30;
	cout << "当前日期后30天为：" << date2.getyear() << "-" << date2.getmonth() << "-" << date2.getday() << endl;
	date2 += 90;
	cout << "当前日期后90天为：" << date2.getyear() << "-" << date2.getmonth() << "-" << date2.getday() << endl;
	date2 += 360;
	cout << "当前日期后360天为：" << date2.getyear() << "-" << date2.getmonth() << "-" << date2.getday() << endl;

	cout << "date1 - date2: " << (date1 - date2) << "天" << endl;
	cout << "date1 < date2: " << (date1 < date2) << endl;
	cout << "date1 <= date2: " << (date1 <= date2) << endl;
	cout << "date1 == date2: " << (date1 == date2) << endl;
	cout << "date1 > date2: " << (date1 > date2) << endl;
	cout << "date1 >= date2: " << (date1 >= date2) << endl;
	(date1++);
	cout << "date1++ ：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	date1--;
	cout << "date1-- ：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	--date1;
	cout << "--date1 ：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;
	++date1;
	cout << "++date1 ：" << date1.getyear() << "-" << date1.getmonth() << "-" << date1.getday() << endl;

}