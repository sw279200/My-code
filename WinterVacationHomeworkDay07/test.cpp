#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //2022. ��һά����ת��ɶ�ά����
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        vector<vector<int>> vv;
        if (len != m * n) return vv;
        for (int i = 0; i < len;)
        {
            vector<int> v(n, 0);
            for (int j = 0; j < n; j++)
            {
                v[j] = original[i++];
            }
            vv.push_back(v);
        }
        return vv;
    }
    //1441. ��ջ������������
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int now = 1;
        for (int ta : target) {
            while (now < ta) {
                ans.push_back("Push");
                ans.push_back("Pop");
                now++;
            }
            now++;
            ans.push_back("Push");
        }
        return ans;

    }
};

int main()
{

	return 0;
}