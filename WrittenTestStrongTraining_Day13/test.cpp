#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string result;
    cin >> result;
    int starCount = result[0] == 'W' ? 1 : -1;
    result[1] == 'W' ? starCount++ : starCount--;
    for (int i = 2; i < n; i++) {
        if (result[i] == result[i - 1] && result[i] == result[i - 2] && result[i] == 'W')starCount += k;
        else if (result[i] == 'W') starCount++;
        else starCount--;
    }
    cout << starCount << endl;
}

//����ظ�������
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param arr int����vector the array
     * @return int����
     */
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_map<int, int>hash;
        int left = 0, right = 0, ret = 0, n = arr.size();
        while (right < n)
        {
            hash[arr[right]]++; //�����ַ����ϣ��
            while (hash[arr[right]] > 1)  //ɾ���ظ��Ĺ�ϣ��Ԫ��
            {
                hash[arr[left]]--;
                left++;
            }
            ret = max(ret, right - left + 1);  //���½��
            right++;   //����һ���ַ����뻬������
        }

        return ret;
    }
};

const int defaultsize = 26;
//�����ַ���
void changeString()
{
    int n = 0;
    cin >> n;
    string res;
    vector<int> v(defaultsize);
    cin >> res;
    for (int i = 0; i < n; i++)
    {
        v[res[i] - 'a']++;
    }
    int Max = INT_MIN;
    for (auto& x : v)if (Max < x)Max = x;
    if (n % 2 == 0)
    {
        if (Max <= n / 2) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    else
    {
        if (Max <= n / 2+1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}


int main() {
   /* int T = 0;
    cin >> T;
    while (T--) {
        solve();
    }*/
    Solution sol;
    
    /*int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];*/
    vector<int> v{ 1,1, 1,1,1,1,1,1 };
    cout << sol.maxLength(v) << endl;
}