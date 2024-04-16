#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param number int����
     * @return int����
     */

    int jumpFloorII(int number) {
        if (number <= 0) return -1;
        else if (number == 1)return 1;
        else return 2 * jumpFloorII(number - 1);
    }
};

int main() {
    double n, r;
    while (cin >> n >> r) { // ע�� while ������ case
        if (n < 2 * r * 3.14) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
// 64 λ������� printf("%lld")