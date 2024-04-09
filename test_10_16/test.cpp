#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


class Solution {
public:
    //单词拆分
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (auto x : wordDict) hash.insert(x);
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        s = ' ' + s;  ///与dp表进行映射

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<string> vs;
    vs.push_back("cats");
    vs.push_back("cat");
    vs.push_back("dog");
    vs.push_back("sand");
    vs.push_back("and");
    cout<<sol.wordBreak("catsandog",vs)<<endl;
	return 0;
}