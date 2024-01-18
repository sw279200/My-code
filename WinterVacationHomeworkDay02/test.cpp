#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    //2068. ��������ַ����Ƿ񼸺����
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


    //394. �ַ�������
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
            else if (s[i] == '[') //����[��ǰ������ѹ��numsջ�ڣ� ��ĸ�ַ���ѹ��strsջ��
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else //������]��ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
            {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j)
                    strs.top() += res;
                res = strs.top(); //֮����������ĸ���ͻ�ֱ�Ӽӵ�res֮����Ϊ������ͬһ��������
                //���������ţ�res�ᱻѹ��strsջ����Ϊ��һ�������
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