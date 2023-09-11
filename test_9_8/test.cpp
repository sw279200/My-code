#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include <iostream>
#include<algorithm>
using namespace std;

//字符串相加
class Solution {
public:
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
    string s1("456");
    string s2("77");
    cout << sol.addStrings(s1, s2) << endl;

	return 0;
}

#endif

//字符串里面最后一个单词的长度


#if 1
#include <iostream>
#include <string>
using namespace std;

int lastWordLength()
{
    string str;
    getline(std::cin, str);
    size_t p = str.find_last_of(' ');
    return str.size() - p-1;
}
int main()
{
    cout << lastWordLength() << endl;
    return 0;
}
#endif
