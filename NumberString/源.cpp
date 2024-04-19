#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
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

    string addStrings(string num1, string num2)
    {
        // 计算两个字符串的 下标 长度
        int end1 = num1.size() - 1, end2 = num2.size() - 1;

        // 进位换算符号
        int next = 0;
        // 最终字符串 
        string a;
        // 开始相加，直到两个字符串都加完为止 
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = 0;
            if (end1 >= 0)
            {
                // 将字符转换为数字
                val1 = num1[end1--] - '0';
            }

            int val2 = 0;
            if (end2 >= 0)
            {
                val2 = num2[end2--] - '0';
            }

            int ret = val1 + val2 + next;
            // 计算进位
            next = ret / 10;
            ret = ret % 10;
            // 写入字符串
            a += ret + '0';
        }
        if (next == 1)
        {
            a += "1";
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

int main()
{

    return 0;
}