#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:
    //557.反转字符串中的单词
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

    //1446.连续字符
    int maxPower(string s) {
        int n = s.size(),count = 1,MaxPower = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == s[i]) count++;         
            else
            {
                if (count > MaxPower) MaxPower = count;
                count = 1;
            }
        }
        if (count > MaxPower) MaxPower = count;
        return MaxPower;
    }
};

int main(void)
{
	return 0;
}