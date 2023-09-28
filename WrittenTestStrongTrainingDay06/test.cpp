#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //把字符串转换成整数
    int StrToInt(string str) {

        int flag = 1;

        if (str[0] == '+' || str[0] == '-')
        {
            if (str[0] == '-')
            {
                flag = -1;
            }

            str.erase(str.begin());
        }
        size_t n = str.size();
        if (n > 11)
        {
            return 0;
        }
        long long num = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (str[i] < '0' || str[i]>'9' || num > INT_MAX || num < INT_MIN)
            {
                num = 0;
                break;
            }
            cout << num << " ";
            num += (str[i] - '0');
            if (i < n - 1)
                num *= 10;
        }
        return (int)num * flag;
    }
};


//不要二
void solve()
{
    int W, H;
    cin >> H >> W;
    int w = W + 4;
    int h = H + 4;
    vector<int>v(w, 0);//初始化为W个0
    vector<vector<int>> vv(h, v);//初始化有H个v
    int count = 0;
    for (int i = 2; i < h - 2; i++)
    {
        for (int j = 2; j < w - 2; j++)
        {
            if (vv[i][j] == 0 && vv[i - 2][j] == 0 && vv[i + 2][j] == 0
                && vv[i][j - 2] == 0 && vv[i][j + 2] == 0)
            {
                vv[i][j]++;
                count++;
            }
        }
    }

    cout << count << endl;
}


int main()
{
    /*string str("+2147483647");
    Solution sol;
    cout << sol.StrToInt(str) << endl;;*/

    solve();
    return 0;
}