#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//void solve()
//{
//	string s;
//	cin >> s;
//	int grade;
//	if(s == "tourist")
//			grade = 3858;
//	else if("ksun48" ==s)
//			grade = 3679;
//
//	else if("Benq" ==s)
//			grade = 3658;
//
//	else if(s =="apiad")
//			grade = 3638;
//
//	else if(s =="Um_nik")
//			grade = 3648;
//
//	else if(s =="Stonefeang")
//			grade = 3630;
//
//	else if("ecnerwala" == s)
//			grade = 3613;
//
//	else if("mnbvmar" == s)
//			grade = 3555;
//
//	else if(s =="newbiedmy")
//			grade = 3516;
//
//	else if(s =="semiexp")
//			grade = 3481;
//
//	cout << grade << endl;
//}


char getMinj(int i, int n)
{
	int m = 10;
	bool flag = false;
	for (int k = 1; k < 10; k++)
	{
		if (n%k==0&&(i%(n/k)==0))
		{
			flag = true;
			m = min(m, k);
		}
	}

	if (!flag)
	{
		return '-';
	}
	return m + '0';
}

int  minNum(int x, int y)
{
	return x > y ? x : y;
}

void solve()
{
	int n = 0;
	cin >> n;
	string s = "";
	int j = 0, i = 0;
	int jMin = 10;
	for (int m = 0; m <= n; m++)
	{
		s += getMinj(m, n);
	}
	cout << s << endl;
}





int main()
{
	solve();
	return 0;
}