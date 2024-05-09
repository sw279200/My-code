#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param param string字符串
     * @return string字符串
     */
    //压缩字符串（一）
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

//chika和蜜柑
#define ll long long
int n;
// 在C++的语法里面，可以直接用 结构体名字来定义变量，而无需用typedef重命名 
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


//01背包

int main()
{
    Solution sol;
    cout << sol.compressString("aabcccccaaa") << endl;
	return 0;
}