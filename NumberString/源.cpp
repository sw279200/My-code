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
                res[i + j + 1] = temp % 10 + '0';//��ǰλ
                res[i + j] += temp / 10; //ǰһλ���Ͻ�λ��res[i+j]�Ѿ���ʼ��Ϊ'0'������int�����Զ�ת��Ϊchar�����Դ˴�����'0'
            }
        }

        //ȥ����λ'0'
        for (int i = 0; i < n1 + n2; i++) {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";

    }

    string addStrings(string num1, string num2)
    {
        // ���������ַ����� �±� ����
        int end1 = num1.size() - 1, end2 = num2.size() - 1;

        // ��λ�������
        int next = 0;
        // �����ַ��� 
        string a;
        // ��ʼ��ӣ�ֱ�������ַ���������Ϊֹ 
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = 0;
            if (end1 >= 0)
            {
                // ���ַ�ת��Ϊ����
                val1 = num1[end1--] - '0';
            }

            int val2 = 0;
            if (end2 >= 0)
            {
                val2 = num2[end2--] - '0';
            }

            int ret = val1 + val2 + next;
            // �����λ
            next = ret / 10;
            ret = ret % 10;
            // д���ַ���
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