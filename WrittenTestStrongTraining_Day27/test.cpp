#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
using namespace std;


//kotory和气球
// 快速幂算法  
long long fast_power(long long base, long long exponent, int mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        // 如果当前位是1，则将当前的base值乘入结果  
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1; // 指数右移一位，相当于除以2  
        base = (base * base) % mod; // base自乘  
    }
    return result;
}

long long solve()
{
	long long n, m;
	cin >> n >> m;
	return (n* fast_power(n-1,m-1,109))%109;
}
int main()
{
	cout << solve() << endl;
	return 0;
}