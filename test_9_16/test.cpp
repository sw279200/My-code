#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
    //反转字符串II
    string reverseStr(string s, int k) {
        string::iterator it = s.begin();
        int count = s.size();

        while (count >= 2 * k)
        {
            reverse(it, it + k);
            it = it + 2 * k;
            count -= 2 * k;
        }
        if (count < k)
        {
            reverse(it, s.end());

        }
        else if (count >= k && count < 2 * k)
        {
            reverse(it, it + k);

        }
        return s;

    }

    //翻转字符串III：翻转字符串中的单词
    string reverseWords(string s) {
        string str = "";
        str.reserve(s.size() + 1);
        int count = 0;
        string::iterator it = str.begin();
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                str += s[i];
                count++;

            }
            else
            {

                reverse(it, it + count);
                str += ' ';
                it = it + count + 1;
                count = 0;
            }
        }

        reverse(it, it + count);
        return str;
    }

    //字符串相乘
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0');
        for (int i = n2 - 1; i >= 0; i--) {
            for (int j = n1 - 1; j >= 0; j--) {
                int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = temp % 10 + '0';//当前位
                res[i + j] += temp / 10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }

        //去除首位'0'
        for (int i = 0; i < n1 + n2; i++) {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";


    }


    string addStrings(string num1, string num2) {
        string str;
        string::reverse_iterator rit1 = num1.rbegin();
        string::reverse_iterator rit2 = num2.rbegin();
        int ret = 0;

        while (rit1 != num1.rend() || rit2 != num2.rend())
        {
            if (rit1 != num1.rend())
            {
                ret += (*rit1) - '0';
                rit1++;
            }

            if (rit2 != num2.rend())
            {
                ret += (*rit2) - '0';
                rit2++;
            }

            str += ret % 10 + '0';
            ret /= 10;
        }

        if (ret != 0)
        {
            str += ret % 10 + '0';
        }
        reverse(str.begin(), str.end());
        return str;
    }

};

int main()
{
    Solution sol;
    string str("abcdefg");
    cout << sol.reverseStr(str, 2) << endl;

    str = "Let's take LeetCode contest";
    cout << sol.reverseWords(str) << endl;
    return 0;
}