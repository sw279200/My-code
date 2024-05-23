#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//������̨����չ����
void solution()
{
    int n = 0;
    cin >> n;
    cout << (1 << (n - 1)) << endl;
}

const int N = 26;
//���������������ַ�����ִ�
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
    int hash[26] = { 0 };//ͳ�ƴ�����ÿ���ַ������˶��ٴ�
    int count = 0;//ͳ�ƴ�����һ���ж������ַ�
    int ret = 0;//��Ž��
    while (right < n)
    {
        if (hash[s[left] - 'a']++ == 0)count++;//�����ڶ���һ���ַ�
        while (count > 2)
        {
            if (hash[s[left++] - 'a']-- == 1)count--;//����������һ���ַ�

        }
        ret = max(ret, right - left + 1);
        right++;
    }
    cout << ret << endl;
}

//�ַ���������
class Solution
{
public:
    vector<string> ret;//�ռ�Ҷ�ӽڵ�
    string path;//��¼·������Ϣ
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

        //��posλ��
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (i > 0 && s[i] == s[i - 1] && !vis[i - 1])continue;
                path.push_back(s[i]);
                vis[i] = true;
                dfs(pos + 1);

                //�ָ��ֳ�
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