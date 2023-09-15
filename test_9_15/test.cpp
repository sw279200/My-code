#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //反转字符串
    void reverseString(vector<char>& s) {
        int end = s.size();
        int begin = 0;

        while (begin < end)
        {
            swap(s[begin], s[end - 1]);
            begin++;
            end--;
        }
    }
    //字符串转整型数字
    int StrToInt(string str) {
        int ans = 0; int isplus = 1;
        for (char ch : str) {
            if (isalpha(ch)) {
                return 0;
            }if (ch == '+' || ch == '-') {
                isplus = (ch == '+') ? 1 : -1;
            }if (isdigit(ch)) {
                ans = ans * 10 + ch - '0';
            }
        }return isplus * ans;
    }

    //387. 字符串中的第一个唯一字符

    int firstUniqChar(string s) {
        int num[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            num[s[i] - 'a']++;
        }


        for (int i = 0; i < s.size(); i++)
        {
            if (num[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
    //125. 验证回文串

    bool isPalindrome(string s) {
        string str("");
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    str += s[i] + 32;
                else
                    str += s[i];
            }
        }

        return  _isPalindrome(str);

    }

    bool _isPalindrome(string s) {
        if (s == "")
            return true;

        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                return false;
            }

            begin++;
            end--;
        }
        return true;
    }

};

int main()
{
    vector<char> s = { 'h','e','l','l','o' };
    Solution sol;
    sol.reverseString(s);
    for (char ch : s)
    {
        cout << ch << " ";
    }
    cout << endl;

    string str("loveleetcode");
    cout << sol.firstUniqChar(str) << endl;
	return 0;
}