#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;

#if 0
//�ַ������ҳ�����������ִ�

int Max(int& x, int& y)
{
	return x >= y ? x : y;
}

void MaxLengthNumString()
{
	string str;
	getline(cin, str);
	int max = 0;         //������¼������ַ����ĳ���

	int count = 0;   //������¼��ǰ����ͳ�Ƶ������ַ����ĳ���
	string NumString("");  //���������������ַ�����
	
	size_t i = 0;
	while (i<str.size())
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			string s("");
			while (i < str.size())
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					s += str[i];
					count++;
					i++;
				}
				else
				{
					break;
				}
			}

			max = Max(max, count);
			if (max == count)
			{
				NumString = s;
			}
			count = 0;

		}
		if(i<str.size())
			i++;
	}


	cout << NumString << endl;


}
#endif



class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param numbers int����vector
	 * @return int����
	 */
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		// write code here
		vector<int> v(10000,0);
		for (size_t i = 0; i < numbers.size(); i++)
		{
			v[numbers[i]]++;
		}

		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] > (numbers.size() / 2))
				return i;
		}

		return -1;
	}
};




int main()
{
	//MaxLengthNumString();
	Solution sol;
	vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	cout<<sol.MoreThanHalfNum_Solution(v)<<endl;
	return 0;
}