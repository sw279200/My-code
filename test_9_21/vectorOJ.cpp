#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //只出现一次的数字i
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
        }
        return x;
    }

    //杨辉三角
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        
        for (size_t i = 0; i < numRows; i++)
        {
            vector<int> v;
            for (size_t j = 0; j <= i; j++)
            {
                v.push_back(0);
            }
            vv.push_back(v);
        }

        for (size_t i = 0; i < numRows; i++)
        {
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }

        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < vv[i].size(); j++)
            {
                if (vv[i][j] == 0)
                {
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }
        return vv;
    }

   
};


int main()
{
    Solution sol;

    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    cout<<sol.singleNumber(v)<<endl;

    vector<vector<int>> vv(sol.generate(10));
    for (size_t i = 0; i < vv.size(); i++)
    {
        for (size_t j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
