#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>

using namespace std;
////1、字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
//比如，字符串 aabcccccaaa 会变为 a2b1c5a3 。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字
//符串中只包含大小写英文字母（a至z）
class Solution {
public:
    string compressString(string S) {
        string str = "";
        for (int i = 0; i < S.length(); i++)
        {
            str += S[i];
            int count = 1;
            for (int j = i; j < S.length(); j++)
            {
                if (j + 1 < S.length() && S[j] == S[j + 1]) {
                    count++;
                }
                else
                {
                    char arr[6];
                    str += _itoa(count, arr, 10);
                    i += count - 1;
                    break;
                }
            }

        }

        return str.length() < S.length() ? str : S;
    }
};
int main()
{
    Solution sol;
    string s = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    cout << sol.compressString(s) << endl;
    return 0;
}
#endif


#include <iostream>
using namespace std;
//配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位
//2与位3交换，以此类推）。
class Solution {
public:
    int exchangeBits(int num) {
        int arr[32];
        for (int i = 0; i < 32; i++)
        {
            arr[i] = num >> i & 1;
        }
        for (int i = 0; i < 32; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            sum += arr[i] * pow(2, i);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.exchangeBits(100) << endl;
    return 0;
}