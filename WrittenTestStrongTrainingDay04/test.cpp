#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//计算糖果
void  Calculate_candy()
{
	int A, B, C;
	vector<int> v;
	v.resize(4);
	for (size_t i = 0; i < 4; i++)
	{
		cin >> v[i];
	}

	A = (v[0] + v[2]) / 2;
	B = (v[1] + v[3]) / 2;
	C = (v[3] - v[1]) / 2;

	if ((A - B == v[0]) && (B - C == v[1]) &&( A + B == v[2]) && (B + C == v[3]))
	{
		cout << A <<" "<< B<<" " << C << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}

int NumOfGreaterNine(int x)
{
	int m = 0;
	switch (x)
	{
		case 10:
		{
			m = 65;
			break;
		}
		case 11:
		{
			m = 66;
			break;
		}
		case 12:
		{
			m = 67;
			break;
		}
		case 13:
		{
			m = 68;
			break;
		}
		case 14:
		{
			m = 69;
			break;
		}
		case 15:
		{
			m = 70;
			break;
		}
		default:
		{
			break;
		}
	}
	return m;
}

void ConversionOfNumberSystems(int n,int inNum,vector<int>& v)
{

	int remainder = 0;//余数

	while (n != 0)
	{
		remainder = n % inNum;
		if (remainder > 9)
		{
			v.push_back(NumOfGreaterNine(remainder));
		}
		else
		{
			v.push_back(remainder);
		}
		n /= inNum;
	}
	reverse(v.begin(), v.end());
}

//进制转换
void solve()
{
	int M, N;
	cin >> M>>N;
	if (M == 0)
	{
		cout << M;
		return;
	}

	int flag = -1;
	if (M < 0)
	{
		M *= flag;
		flag = 0;
	}
	vector<int> vc;
	ConversionOfNumberSystems(M, N,vc);
	
	vector<int>::iterator it = vc.begin();
	if (flag == 0)
	{
		cout << "-";
	}
	while (it != vc.end())
	{
		if (*it >= 65 && *it <= 70)
		{
			cout << (char)*it;
		}
		else
		{
			cout << *it;
		}
		it++;
	}

	cout << endl;

}

int main()
{

	solve();
	//Calculate_candy();
	return 0;

}