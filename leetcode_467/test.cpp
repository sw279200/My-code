#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //»·ÈÆ×Ö·û´®ÖÐÎ¨Ò»µÄ×Ó×Ö·û´®
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] = dp[i - 1] + 1;

        int hash[26] = { 0 };

        for(int i = 0;i<n;i++)
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);

        int sum = 0;
        for (auto x : hash) sum += x;

        return sum;
    }
};

int main()
{

	return 0;
}