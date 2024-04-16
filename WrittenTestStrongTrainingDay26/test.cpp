#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number int整型
     * @return int整型
     */

    int jumpFloorII(int number) {
        if (number <= 0) return -1;
        else if (number == 1)return 1;
        else return 2 * jumpFloorII(number - 1);
    }
};

int main() {
    double n, r;
    while (cin >> n >> r) { // 注意 while 处理多个 case
        if (n < 2 * r * 3.14) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")