#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    //面试题01.06 字符串压缩
    string compressString(string S) {
        int n = S.size(), i = 1,count = 1;
        string str = "";
        if (n == 0)return str;    
        str += S[0];
        while (true)
        {
            if (i >= n)
            {
                str += to_string(count);
                break;
            }
            else if (i < n && S[i] == S[i - 1])
            {
                count++;
                i++;
            }
            else if(S[i]!=S[i-1])
            {
                str += to_string(count);
                str += S[i++];
                count = 1;
            }
        }

        return n > str.size() ? str : S;
    }
    //43.字符串相乘
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
};