#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return int整型
     */
    char FirstNotRepeatingChar(string str) {
        // write code here
        int len = str.size();
        for (int i = 0; i < len; i++) {
            if (str.find_first_of(str[i]) == str.find_last_of(str[i])) {
                return str[i];
            }
        }
        return -1;
    }
};

//小易的升级之路
int getP(int i, int j)
{
    int minimal = min(i, j);
    for (int k = 2; k <= minimal; k++)
    {
        if (i % k == 0 && j % k == 0)
        {
            return k * getP(i / k, j / k);
        }
    }
    return 1;
}
int main()
{
    int n, c;
    while (cin >> n >> c)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= c)
            {
                c += nums[i];
            }
            else
            {
                c += getP(c, nums[i]);
            }
        }
        cout << c << endl;
    }

}
