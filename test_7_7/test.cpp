#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

//递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。
//可以使用加号、减号、位移，但要吝啬一些。
class Solution {
public:
    int multiply(int A, int B) {
        if (A != 0 && B != 0)
            return A > B ? A + multiply(A, B - 1) : B + multiply(A - 1, B);
        else
            return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply(918795921, 1) << endl;
	return 0;
}

#endif;

#include <iostream>
using namespace std;

//输出 1到n之间 的与 7 有关数字的个数。
//一个数与7有关是指这个数是 7 的倍数，
//或者是包含 7 的数字（如 17 ，27 ，37 ... 70 ，71 ，72 ，73...）

bool isInclude7(int n)
{
    
    while (n > 0)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0 || isInclude7(i))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}