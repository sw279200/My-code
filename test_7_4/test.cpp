#if 1

#include <iostream>
using namespace std;

/// <summary>
/// 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
//
/// </summary>
class Solution {
public:

    bool canPermutePalindrome(string s) {
        int a[128] = { 0 };
        int i, cnt = 0, len = s.length();

        for (i = 0; i < len; i++)
            a[s[i]]++;

        for (i = 0; i < 128; i++) {
            if (a[i] % 2 == 1)
                cnt++;
            if (cnt >= 2)
                return false;
        }

        return true;

    }
};
int main()
{
   
    string s = "tact";
    Solution sol;
    cout << sol.canPermutePalindrome(s) << endl;
	return 0;
}

#endif