#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
// 设计一个算法，算出 n 阶乘有多少个尾随零。
class Solution {
public:

 int trailingZeroes(int n) {
     int ans = 0;
     while (n > 0) {
         n /= 5;
         ans += n;
     }
     return ans;
    }
};

int main()
{
    /*写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。
        如果小数点后数值大于等于 0.5, 向上取整；小于 0.5 ，则向下取整。*/
    double n;
    cin >> n;
    int x = (int)(n + 0.5);
    cout << x << endl;
    return 0;
}