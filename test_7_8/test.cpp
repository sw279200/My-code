#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
// ���һ���㷨����� n �׳��ж��ٸ�β���㡣
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
    /*д��һ�����򣬽���һ����������ֵ���������ֵ�Ľ�������ֵ��
        ���С�������ֵ���ڵ��� 0.5, ����ȡ����С�� 0.5 ��������ȡ����*/
    double n;
    cin >> n;
    int x = (int)(n + 0.5);
    cout << x << endl;
    return 0;
}