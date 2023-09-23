#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //删除有序数组中的重复项
    int removeDuplicates(vector<int>& nums) {
        int newSize = 0;
        int index = 0;

        while (index < nums.size())
        {
            if (nums[newSize] == nums[index])
            {
                index++;
            }
            else
            {
                newSize++;
                nums[newSize] = nums[index];
            }
        
        }

        nums.resize(newSize+1);
        return newSize+1;
    }


    //只出现一次的数字II
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int k = 0; k < 32; k++)
        {
            int x = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                x += (nums[i] >> k) & 1;

            }
            sum += (x % 3)*pow(2, k);
        }

        return sum;
    }

    //电话号码的数字组合
   vector<string> vstr = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        if (digits == "")
        {
            return v;
        }
        _letterCombinations(v, digits, 0, "");
        return v;
    }

    void _letterCombinations(vector<string>& v, string digits, size_t i, string str)
    {
        if (digits.size() == i)
        {
            v.push_back(str);
            return;
        }

        for (size_t j = 0; j < vstr[digits[i] - '0'].size(); j++)
        {
            _letterCombinations(v, digits, i + 1, str + vstr[digits[i] - '0'][j]);
        }
    }

    //数组中出现次数超过一半的数字
        /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here

        vector<int> v(10001, 0);
        for (size_t i = 0; i < numbers.size(); i++)
        {
            v[numbers[i]]++;
        }
        int  x = 0;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] > (numbers.size() / 2))
            {
                x = i;
            }
        }

        return x;
    }
};


int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(99);

    Solution sol;
    //cout<<sol.removeDuplicates(v) << endl;
    cout << sol.singleNumber(v)<<endl;

    vector<string> vs(sol.letterCombinations("258"));
    for (size_t i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << endl;
    
	return 0;
}