#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Gift {
public:
    //Î¢ÐÅºì°ü
    int getValue(vector<int> gifts, int n) {
        // write code here
        unordered_map<int, int> hash;
        for (auto e : gifts) hash[e]++;
        for (auto x : hash) if (x.second > n / 2) return x.first;
        return 0;
    }
};

//¼ÆËã×Ö·û´®µÄ±à¼­¾àÀë
int DistanceOfStr(string& s1, string& s2, vector<vector<int>>& dp)
{
    
    int n1 = s1.length()+1, n2 = s2.length()+1;
    if (n1 * n2 == 0) return n1+n2;
    for (int i = 1; i < n1; i++)
    {
        dp[i][0] = i;
        for (int j = 1; j < n2; j++)
        {
            dp[0][j] = j;
            if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = min(min(dp[i][j - 1]+1, dp[i - 1][j] + 1), dp[i-1][j-1]);
            else 
                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1]+1);
        }
    }

    return dp[n1-1][n2-1];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1));
    cout << DistanceOfStr(s1, s2, dp) << endl;
	return 0;
}