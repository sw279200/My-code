#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
using namespace std;


//kotory������
// �������㷨  
long long fast_power(long long base, long long exponent, int mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        // �����ǰλ��1���򽫵�ǰ��baseֵ������  
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1; // ָ������һλ���൱�ڳ���2  
        base = (base * base) % mod; // base�Գ�  
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