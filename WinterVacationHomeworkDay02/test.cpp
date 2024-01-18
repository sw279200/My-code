#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    //2068. 检查两个字符串是否几乎相等
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<char> v1(26, 0), v2(26, 0);
        int n = word1.size();
        for (int i = 0; i < n; i++)
        {
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
        }

        for (int i = 0; i < v1.size(); i++)
        {
            if (abs(v1[i] - v2[i]) > 3) return false;
        }
        return true;
    }


    //394. 字符串解码
    string decodeString(string s) {
        string res = "";
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res = res + s[i];
            }
            else if (s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j)
                    strs.top() += res;
                res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                //若是左括号，res会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return res;
    }

};


int main()
{
    Solution sol;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
	return 0;
}