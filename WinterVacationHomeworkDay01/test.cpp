#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //有效的字母异位词
    bool isAnagram(string s, string t) {
        vector<int> v1(26, 0), v2(26, 0);
        int n = v1.size();
        for (auto& e : s) v1[e - 'a']++;
        for (auto& e : t) v2[e - 'a']++;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }


    // 1704.判断字符串的两半是否相似
    bool halvesAreAlike(string s) {
        vector<char> vc = { 'a','e','i','o','u','A','E','I','O','U' };
        int n = s.size();
        int prevcount = 0, nextcount = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (auto e : vc) if (e == s[i])prevcount++;
        }

        for (int i = n / 2; i < n; i++)
        {
            for (auto e : vc) if (e == s[i])nextcount++;
        }

        return prevcount == nextcount;
    }
};


int main()
{
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;

	return 0;
}

