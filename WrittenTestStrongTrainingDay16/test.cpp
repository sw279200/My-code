#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include<stdio.h>
#include<string.h>

char* deleteAndReplace(char* s1, char* s2,int n)
{
	int left = 0, right = n - 1;//leftָ��s1�������±꣬rightָ��s1�Ҳ���±�
	int i = 0;//������s2������Ƹ�ֵ
	//����������s1ǰ���*��
	while (left < right && s1[left] == '*') left++;
	//����left���ַ�������this��'t'�ַ����±�
	//Ȼ����right����s1�����*��
	while (right > left && s1[right] == '*')right--;
	//����left���ַ�������program��'m'�ַ����±�

	//Ȼ���ٸ�ֵ
	while (left <= right)
	{
		//����*��ֱ�Ӹ�ֵ��s2������
		if (s1[left] != '*') s2[i++] = s1[left++];
		else
		{
			//�м��*�滻��һ���ո�
			while (left <= right && s1[left] == '*') left++;
			s2[i++] = ' ';
		}
	}
	//���ظ��ַ�����
	return s2;
}

int main()
{
	char arr1[] = "*****this*is****C****program****";
	int len = sizeof(arr1) / sizeof(arr1[0]);
	char arr2[40] = { 0 };
	printf("%s\n", deleteAndReplace(arr1, arr2,len));
	return 0;
}



#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


//��ȫ������
bool perfectNumber(int n)
{
	int count = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) count += i + (n / i);
	}

	return count == n;
}

void solve()
{
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 2; i <= n; i++)
		if (perfectNumber(i)) count++;

	cout << count << endl;
}

//�˿��ƴ�С


int main()
{
	solve();
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    string card = "345678910JKQA2";
    vector<string> v;
    v.push_back("joker JOKER");
    v.push_back("JOKER joker");
    string input;
    while (getline(cin, input))
    {
        unsigned int pos = input.find('-');
        int len = input.size();
        string s1 = input.substr(0, pos);
        string s2 = input.substr(pos + 1, len - pos - 1);
        int n1 = count(s1.begin(), s1.end(), ' ');
        int n2 = count(s2.begin(), s2.end(), ' ');
        if (s1 == v[0] || s1 == v[1])
        {
            cout << s1 << endl;
            continue;
        }
        if (s2 == v[0] || s2 == v[1])
        {
            cout << s2 << endl;
            continue;
        }
        if (n1 == n2)
        {
            int l = card.find(s1[0]);
            int r = card.find(s2[0]);
            string ans = l > r ? s1 : s2;
            cout << ans << endl;
            continue;
        }
        if (n1 == 3 && n2 != 3)
        {
            cout << s1 << endl;
            continue;
        }
        else if (n1 != 3 && n2 == 3)
        {
            cout << s2 << endl;
            continue;
        }
        cout << "ERROR" << endl;
    }
}

int main()
{
	solve();
    return 0;
}
