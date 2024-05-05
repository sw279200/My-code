#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
using namespace std;
#include<vector>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串 原串
     * @param arg char字符型vector 需替换数组
     * @return string字符串
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


//神奇数
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