#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//青蛙跳台阶扩展问题
void solution()
{
    int n = 0;
    cin >> n;
    cout << (1 << (n - 1)) << endl;
}

const int N = 26;
//包含不超过两种字符的最长字串
void solve() {
   /* string s;
    getline(cin, s);
    int n = s.size(), count = 0, maxLen = -0x3f3f3f3f;
    vector<int> v(N);
    char first = s[0], second = ' ';
    v[s[0] - 'a']++, count++;
    int left = 0, right = 1;
    for (; right < n;) {
        if (s[right] != first && count < 2) {
            v[s[right] - 'a']++;
            second = s[right];
            count++;
        }
        else if (first == s[right] || s[right] == second) {
            v[s[right] - 'a']++;
        }
        else if (s[right] != first && s[right] != second && count == 2) {
            maxLen = max(right - left, maxLen);
            second = s[right];
            count++;
            while (left < right && count != 2) {
                v[s[left] - 'a']--;
                if (v[s[left] - 'a'] <= 0)
                {
                    count--;
                    left++;
                    first = s[left];
                }
                else left++;
            }
        }
        right++;
    }
    maxLen = max(right - left, maxLen);
    cout << maxLen << endl;*/

    string s;
    cin >> s;

    int left = 0, right = 0, n = s.size();
    int hash[26] = { 0 };//统计窗口内每种字符出现了多少次
    int count = 0;//统计窗口内一共有多少种字符
    int ret = 0;//存放结果
    while (right < n)
    {
        if (hash[s[left] - 'a']++ == 0)count++;//窗口内多了一种字符
        while (count > 2)
        {
            if (hash[s[left++] - 'a']-- == 1)count--;//窗口内少了一种字符

        }
        ret = max(ret, right - left + 1);
        right++;
    }
    cout << ret << endl;
}

//字符串的排列
class Solution
{
public:
    vector<string> ret;//收集叶子节点
    string path;//记录路径的信息
    bool vis[11] = { 0 };
    int n;
    string s;

    vector<string> Permutation(string str)
    {
        n = str.size();
        sort(str.begin(), str.end());
        s = str;

        dfs(0);
        return ret;
    }

    void dfs(int pos)
    {
        if (pos == n)
        {
            ret.push_back(path);
            return;
        }

        //填pos位置
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (i > 0 && s[i] == s[i - 1] && !vis[i - 1])continue;
                path.push_back(s[i]);
                vis[i] = true;
                dfs(pos + 1);

                //恢复现场
                vis[i] = false;
                path.pop_back();
            }
        }
    }

};

int main() {
    //solve();
    solution();
    return 0;
}