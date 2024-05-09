#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param param string�ַ���
     * @return string�ַ���
     */
    //ѹ���ַ�����һ��
    string compressString(string param) {
        // write code here
        int n = param.size(), count = 1;
        if (n == 0||n==1)return param;
        string str;
        str += param[0];
        for (int i = 1; i < n;)
        {
            if (param[i] != param[i - 1])
            {
                str += param[i];
                i++;
            }
            else
            {
                while (i < n && param[i] == param[i - 1])
                {
                    count++;
                    i++;
                }
                str += to_string(count);
                count = 1;
            }

        }

        return str;
    }
};

//chika���۸�
#define ll long long
int n;
// ��C++���﷨���棬����ֱ���� �ṹ�������������������������typedef������ 
struct migan {
    ll sweet;
    ll sour;
};
bool cmp(migan a, migan b) {
    if (a.sweet == b.sweet) {
        return a.sour < b.sour;
    }
    else {
        return a.sweet > b.sweet;
    }
}
int k;
migan nums[200005];
ll sumSweet;
ll sumSour;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].sour;
    }
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].sweet;
    }

    sort(nums, nums + n, cmp);

    for (int i = 0; i < k; ++i) {
        sumSweet += nums[i].sweet;
        sumSour += nums[i].sour;
    }

    cout << sumSour << ' ' << sumSweet;
    return 0;
}


//01����

int main()
{
    Solution sol;
    cout << sol.compressString("aabcccccaaa") << endl;
	return 0;
}