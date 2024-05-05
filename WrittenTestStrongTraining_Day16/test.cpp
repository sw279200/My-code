#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
using namespace std;
#include<vector>

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ��� ԭ��
     * @param arg char�ַ���vector ���滻����
     * @return string�ַ���
     */
    string formatString(string str, vector<char>& arg) {
        // write code here
        string res;
        int index = 0,n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '%') res += str[i];
            else
            {
                res += arg[index++];
                i++;
            }
        }
        for (int i = index; i < arg.size(); i++) res += arg[i];
        return res;

    }
};

bool isPrime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)return false;
    }
    return true;
}

int getCount(int n)
{
    int num = 0;
    vector<int> v;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }

}


//������
void solve()
{
    int a, b, int count = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        count += getCount(i);
    }
    cout << count << endl;

}

int main()
{
    solve();
	return 0;
}