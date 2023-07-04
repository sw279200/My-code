#if 1

#include <iostream>
using namespace std;

/// <summary>
/// ����һ���ַ�������дһ�������ж����Ƿ�Ϊĳ�����Ĵ�������֮һ��
//���Ĵ���ָ������������һ���ĵ��ʻ���������ָ��ĸ���������С�
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